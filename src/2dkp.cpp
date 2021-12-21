#include "libs/2dkp.h"

f64 itemProfit(Item *item, int W, int L)
{
    double w = item->w;
    double Wd = W;
    double l = item->l;
    double Ld = L;

    return (item->v/( ((w*100)/Wd) + ((l*100)/Ld) ));
}

Item::Item(int w, int l, f64 v)
{
    this->w = w;
    this->l = l;
    this->v = v? v : w*l;
}

int Item::getW()
{
    return this->w;
}

int Item::getL()
{
    return this->l;
}

int Item::getV()
{
    return (this->v);
}

f64 Item::getProfit()
{
    return this->p;
}

Solution::Solution(vi bits, vector<KPItem> kpitems)
{
    this->bits = bits;
    this->kpitems = kpitems;
}

f64 Solution::getSumProfits() 
{
    int size = this->kpitems.size();
    f64 sumProfits = 0.0;
    for (int i = 0; i < size; i++)
    {
        sumProfits += this->kpitems[i].item->p;
    }
    return sumProfits;
}

int Knapsack2D::addItem(int w, int l, f64 v)
{
    Item *item = new Item(w , l, v);

    item->p = itemProfit(item, this->w, this->l);

    if(!item) return HEAP_OVERFLOW;

    this->items.push_back( item );
    return 1;
}

Knapsack2D::Knapsack2D(int n, int w, int l)
{
    this->n = n;
    this->w = w;
    this->l = l;
    this->areaCovered = 0;

    this->bits.resize(n, 0);
}

int Knapsack2D::addKpItem(int x, int y, Item *item)
{
    this->kpitems.push_back(KPItem(item, new Point(x, y)));
    this->areaCovered += item->l*item->w;
    return 1;
}

int Knapsack2D::getKnapsackArea()
{
    return this->w*this->l;
}

int Knapsack2D::getN()
{
    return this->n;
}

int Knapsack2D::getW()
{
    return this->w;
}

int Knapsack2D::getL()
{
    return this->l;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

KPItem::KPItem(Item *item, Point *ponto)
{
    this->item = item;
    this->ponto = ponto;
}

int withinBorders(Knapsack2D *kp, KPItem &i)
{
    int x = i.ponto->x;
    int y = i.ponto->y;
    int w = i.item->getW();
    int l = i.item->getL();

    // pivot is down-left vertex
    if (y-w <= 0 )
        return 0;
    if (x+l > kp->getL())
        return 0;

    return 1;
}

int colisao(KPItem a, KPItem b)
{
    // check colision for all kpitens
    int x1 = a.ponto->x;
    int y1 = a.ponto->y;
    int w1 = a.item->w;
    int l1 = a.item->l;

    int x2 = b.ponto->x;
    int y2 = b.ponto->y;
    int w2 = b.item->getW();
    int l2 = b.item->getL();

    // checking colision with actual kpitem.
    // cout << "itemToEnter: " << x1 << " " << y1 << " " << l1 << " " << w1 << "\n";
    // cout << "itemToCOMPARE: " << x2 << " " << y2 << " " << l2 << " " << w2 << "\n";

    if (x1 + l1  < x2)
        return 0;
    if (x1 > x2+l2)
        return 0;
    if (y1-w1+1 > y2)
        return 0;
    if (y1 < y2-w2+1)
        return 0;
    
    return 1;
}

int allColisions(KPItem item, vector<KPItem> &kpitens, int n)
{
    for (int i = 0; i < n; i++)
        if(colisao(item, kpitens[i]))
            return 1;
    return 0;
}

// int deallocate(Knapsack2D *&kp)
// {
//     int kpItemSize = kp->kpitems.size();
//     int itemSize = kp->n;

//     kp->kpitems.clear();
//     return 1;
// }