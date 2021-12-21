#include "./libs/functions.h"

int profitComparator(Item *&a, Item *&b)
{
    return a->p > b->p;
}

Knapsack2D *initInput( )
{
    int n, w, l;
    cin >> n >> l >> w;
    Knapsack2D *k = new Knapsack2D(n, w, l);
    for (int i = 0; i < n; i++)
    {
        int itemW, itemL;
        f64 v;
        cin >> itemL >> itemW>> v;
        if (k->addItem(itemW, itemL, v) == HEAP_OVERFLOW ) return NULL;
    }
    sort(k->items.begin(), k->items.begin(), &profitComparator);
    return k;
}

void showKnapsack(Knapsack2D *&k)
{
    for (int i = 0; i < k->getN(); i++)
    {
        cout << k->items[i]->getProfit() << " ";
    }
    cout << "\n";
}

void showKPItems(vector<KPItem> kpitems)
{
    cout << (int)kpitems.size() << endl;
    for (int i = 0; i < (int)kpitems.size(); i++ )
    {
        // remember, this is down-left vertex
        cout << kpitems[i].item->p << " || Point: " << kpitems[i].ponto->x << " " << kpitems[i].ponto->y << "\n" ;
    }
}

int lessThanP(Item *&a, Item *&b)
{
    int a_value = a->getProfit();
    int b_value = b->getProfit();
    return ( a_value < b_value );
}
int lessThanL(Item *&a, Item *&b)
{
    return ( a->l < b->l );
}
int moreThanL(Item *&a, Item *&b)
{
    return ( a->l > b->l );
}

int lessThanW(Item *&a, Item *&b)
{
    return ( a->w < b->w );
}

vi createInitialSolutionV2(Knapsack2D *&k)
{
    vi bits(k->n, 0);
    vector<Item *> item_copy = k->items;
    map<Item *, int> mapa;
    for (int i = 0; i < k->n; i++)
    {
        mapa[item_copy[i]] = i;
    }
    // cout << mapa[item_copy[1]] << "\n";
    sort(item_copy.begin(), item_copy.end(), &lessThanL);
    int L_j = 0;
    for (int i = 0; i < k->n; i++)
    {
        if (L_j + item_copy[i]->l < k->l)
        {
            L_j += item_copy[i]->l;
            bits[mapa[item_copy[i]]] = 1;
            // k->kpitems.push_back(KPItem(item_copy[i], new Point(L_j, k->getW())));
            k->addKpItem(L_j , k->getW(), item_copy[i]);
        }
    }
    return bits;
}