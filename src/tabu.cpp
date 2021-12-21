#include "libs/tabu.h"
#include "libs/2dkp.h"

int getSolutionValue(vi &bits, Knapsack2D *&k)
{
    int value = 0;
    for (int i = 0; i < k->getN(); i++)
    {
        value += (bits[i] * k->items[i]->getV());
    }
    return value;
}

int compareSolution(Solution &a, Solution &b)
{
    return a.getSumProfits() > b.getSumProfits();
}

int tryInsert(Knapsack2D *&kp, Solution *lastSol, KPItem &it, int id_item, deque<KPItem> &tl, deque<int> &timer)
{ 
    /*
    Flow is:
        - check colision on initial point
            - if yes
                - change points until it hits a point where there is no colision
                or until checks all points
                - if finds a spot of no colision return a Solution *.
                - else returns NULL
            - else (doesnt need else clause i think)
                - return Solution * with initial point
    */
   /* -> STARTS HERE */
    vector<KPItem> kpitemsCopy (lastSol->kpitems);
    int colidiu = allColisions(it, kpitemsCopy, kpitemsCopy.size());
    if (colidiu)
    {
        // tenta inserir
        while (colidiu && withinBorders(kp, it))
        {
            colidiu = allColisions(it, kpitemsCopy, kpitemsCopy.size());
            if (!colidiu)
            {
               
                return 1;
            }
            
            // need to know which item collided with kpitem
            // or upgrade in 1 each time
            it.ponto->x++;

            if (!withinBorders(kp, it) && it.ponto->y-it.item->w+1 > 0)
            {
                it.ponto->x = 1;
                it.ponto->y -= 1;
            }
        }
    }
    else 
    {
        // insert in standard
        return 1;
        // cout << "insert1\n";
    }
    return 0;
}

Solution tryBetterSolution(Knapsack2D *&kp, Solution *lastSol, int alpha, deque<KPItem> &tl, deque<int> &timer)
{
    /*
        FLOW IS:
            - get all solutions valid
                - get the ones that removing item is needed
                    -add all of then into the 
                - get the ones that need to add item.
                    - tryInsert
            - order them by profit
            - sort one between the alpha better ones
                - add the item changed into tabu list
            - return the better solution found.
    */
    // cout << tl.size() << "\n";
    if (!lastSol)
    {
        lastSol = new Solution(kp->bits, kp->kpitems);
    }
   vector<Solution> solutions;

   for (int i = 0; i < (int)kp->n; i++)
   {
       vi copy(lastSol->bits);
       vector<KPItem> copyItems(lastSol->kpitems);
       Item *item = kp->items[i];
    //    cout << "item " << i << "\n";
       if (copy[i])
       {
        //    if (i == 6)
        //         cout << "6.1\n";
           copy[i] = 0;
           KPItem *kpitem = NULL;
           // create a copy of kp->kpitems, and then remove the kpitem with the item stored im Item *item (line 84)
           // after that push a Solution object into solutions.
        //    if (i == 6)
        //         cout << "6.2\n";
           int counter = 0;
           for (KPItem aux: copyItems)
           {
                // if (i == 6)
                //     cout << "6.3\n";
               if (aux.item->p == item->p)
               {
                   kpitem = &copyItems[i];
                   copyItems.erase(copyItems.begin()+counter);
                   break;
               }
               counter++;
           }
        //    if (i == 6)
        //         cout << "6.4\n";

            bool ok = true;
            // if (!kpitem)
            // {
            //     cout << "é aqui!\n";
            // }
            // if (i == 6)
            //         cout << "6.5\n";
            // cout << tl.size() << "\n";
            // cout << (tl.size() ? "0" : tl[0].item->p) << "\n";
            // for (int i = 0; i < tl.size(); i++)
            // {
            //     cout << "a1";
            //     if (kpitem->item->p == tl[i].item->p)
            //     {
            //         cout << "a2";
            //         if (kpitem->ponto->x == tl[i].ponto->x && kpitem->ponto->y == tl[i].ponto->y)
            //         {
                        // cout << "a3\n";
            //             ok = false;
            //         }
            //     }
            // }
            if (ok)
            {
                // cout << "a4";
                solutions.push_back(Solution(copy, copyItems));
                solutions[solutions.size()-1].variatedItem = kpitem;
            }
            // cout << "a5\n";
        //    cout << "case1\n";
       }
       else
       {
           // check if solution is valid.
            vi copy(lastSol->bits);
            // cout << "case2\n";
            if (kp->areaCovered >= (item->l)*(item->w))
            {
                KPItem it = KPItem(item, new Point(1, kp->w));
                if(tryInsert(kp, lastSol , it , i, tl, timer))
                {
                    bool ok = true;
                    // for (int i = 0; i < tl.size(); i++)
                    // {
                    //     cout << "b1 ";
                    //     if (it.item->p == tl[i].item->p)
                    //     {
                    //         cout << "b2 ";
                    //         if (it.ponto->x == tl[i].ponto->x && it.ponto->y == tl[i].ponto->y)
                    //         {
                    //             ok = false;
                    //         }
                    //     }
                    // }
                    if (ok)
                    {
                        
                        copy[i] = 1;
                        copyItems.push_back(it);
                        solutions.push_back(Solution(copy, copyItems));
                        solutions[solutions.size()-1].variatedItem = &it;
                        // cout << "b4 ";
                    }
                    // cout << "b5 ";
                }
                // else
                // {
                //     cout << "NOOOOO!\n";
                // }
            }
            // cout << "b6\n";
        }
        // cout << "item " << i << "\n";
    }
    // cout << solutions.size() << "\n";

    // GETTING SOLUTION PROFIT FOR EACH VALID SOLUTION
    // cout << "a\n";
    for (int i = 0; i < (int) solutions.size(); i++)
    {
        f64 sumProfits = 0.0;
        sumProfits = solutions[i].getSumProfits();

        // PRINTING STUFF TO TEST RESULTS OF THE ABOVE COMMANDS.
        /*cout << "profits " << sumProfits << "\n";

        for (int k = 0; k < kp->n; k++)
            cout << solutions[i].bits[k] << " ";
        cout << "\n";

        showKPItems(solutions[i].kpitems);
        cout << "\n";*/
    }
    // ORDERING SOLUTIONS BY PROFIT.
    // cout << "a\n";
    sort(solutions.begin(), solutions.end(), &compareSolution);

    // SELECTING RANDOM NUMBER % ALPHA 
    uniform_int_distribution<mt19937::result_type> udist(0, 10000);
    mt19937 rng;
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());
    mt19937::result_type randomNumber = udist(rng);
    int rd = static_cast<int>(randomNumber) % alpha;
    // cout << "rd = " << rd << "\n";
    // cout << "a\n";
    // cout << "solution size = " << solutions.size() << "\n";
    // tl.push_back(*solutions[rd].variatedItem);

    return solutions[rd];
}

vi tabuSearch(Knapsack2D *&kp, int iter, int alpha)
{
    // variables
    deque<KPItem> tl;
    deque<int> timer; // timer of any item on tl
    Solution *betterPossible = NULL;
    Solution *lastSol = NULL;
    vi bits;

    // main loop
    while (iter--)
    {
        // fluxo show be
        /*

        tryBetterSolution
            getNeighborhood
            select alpha better neighboors from the list (from the possible ones).
            get 1 random element from the alpha better neighboors.
            add the element of the solution choosen into the TL
        and remove after 5 iterations.
        
        */
        //getting better possible
        Solution iteration = tryBetterSolution(kp, lastSol, 1, tl, timer);
        if (!betterPossible)
        {
            betterPossible = new Solution(iteration);
        }
        else if (betterPossible->getSumProfits() < iteration.getSumProfits())
        {
            delete betterPossible;
            betterPossible = new Solution(iteration);
        }
        delete lastSol;
        lastSol = new Solution(iteration);

        // removing first tl item after "timer"
        // if(tl.size() > TABU_LIST_MAX)
        // {
        //     tl.pop_front();
        // }

        for (int i = 0; i < (int)lastSol->bits.size(); i++)
        {
            cout << lastSol->bits[i] << " ";
        }
        cout << "\n";
    }
    return bits;
}