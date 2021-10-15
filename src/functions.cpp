#include "./libs/functions.h"


Knapsack2D *initInput( )
{
    int n, w, l;
    cin >> n >> w >> l;

    Knapsack2D *k = new Knapsack2D(n, w, l);

    for (int i = 0; i < n; i++)
    {
        int itemW, itemL;
        f64 v;
        cin >> itemW >> itemL >> v;
        if (k->addItem(itemW, itemL, v) == HEAP_OVERFLOW ) return NULL;
    }
    return k;
}

vi greedyStandardKnapsack(Knapsack2D *&k)
{
    // translate into normal knapsack greedy and return possible solution to avaliate.
    int sum_profit = 0;
    int sum_weigth = 0;
    while(sum_weigth <= k->getKnapsackArea())
    {
        int most_valuable_item = -1;
        f64 greatest_profit = -1;
        for (int i = 0; i < k->getN(); i++)
        {
            if (!k->bits[i])
            {
                if (k->items[i]->getProfit() > greatest_profit)
                {
                    greatest_profit = k->items[i]->getProfit();
                    most_valuable_item = i;
                }
            }
        }
    }
}
vi greedyKnapsack2D(Knapsack2D *&k, int alpha)
{
}

