#include ".\libs\functions.h"


Knapsack2D *initInput( )
{
    int n, w, l;
    cin >> n >> w >> l;

    Knapsack2D *k = new Knapsack2D(n, w, l);

    for (int i = 0; i < n; i++)
    {
        int itemW, itemL;
        f64 v;
        cin >> itemW >> itemW >> v;
        addItem()
    }

}

bool comparator(Item *&a, Item *&b)
{
    return a->getProfit() < b->getProfit();
}

vi greedyStandardKnapsack(Knapsack2D *&k)
{
    // translate into normal knapsack greedy and return possible solution to avaliate.
    int sum_profit = 0;
    int sum_weigth = 0;
    sort(k->items.begin(), k->items.end(), &comparator);
    for (int i = 0; i < k->getN() && sum_weigth <= k->getKnapsackArea(); i++)
    {

    }
}
vi greedyKnapsack2D(Knapsack2D *&k, int alpha)
{
}

