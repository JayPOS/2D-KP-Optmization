#include "libs/2dkp.h"

Item::Item(int w, int l, f64 v)
{
    this->w = w;
    this->l = l;
    this->v = v;
}

int Item::getId()
{
    
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
    return (this->v) ? this->v : this->w*this->v;
}

int Item::getProfit()
{
    return this->getV()/(this->getW()*this->getL());
}

int Knapsack2D::addItem(int w, int l, f64 v)
{
    Item *item = new Item(w , l, v);

    if(!item) return HEAP_OVERFLOW;

    this->items.push_back( item );
    return 1;
}

Knapsack2D::Knapsack2D(int n, int w, int l)
{
    this->n = n;
    this->w = w;
    this->l = l;
}

int Knapsack2D::getKnapsackArea()
{
    return this->w*this->l;
}
int Knapsack2D::getN()
{
    return this->n;
}