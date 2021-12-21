#include "src/2dkp.cpp"
#include "src/functions.cpp"
#include "src/tabu.cpp"

int main()
{
    Knapsack2D *k = initInput();
    k->bits = createInitialSolutionV2(k);
    for (int i = 0; i < (int)k->bits.size(); i++)
    {
        cout << k->bits[i] << " ";
    }
    cout << "\n";
    // showKnapsack(k);
    // showKPItems(k);
    vector<KPItem> tl;
    vi bits = tabuSearch(k, 20, 1);
    cout << "aaaaaaaaaaaaaaaa\n";
    // for (int i = 0; i < (int)k->bits.size(); i++)
    // {
    //     cout << k->bits[i];
    // }
    // cout << "\n";
    // showKnapsack(k);
    // showKPItems(k->kpitems);
    // int n = solution.size();
    // for (int i = 0; i < n; i++)
    // {
    //     cout << solution[i] << " ";
    // }
    // cout << "\n";
    // cout << checkSolution(k, solution) << "\n";
    // tabuSearch(k, solution, 1);
    return 0;
}