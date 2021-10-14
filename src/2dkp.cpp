#include "libs\2dkp.h"

Item::Item(int w, int l, int v)
{
    this->w = w;
    this->l = l;
    this->v = v == 0 ? w*l : v;
}

int Backpack2D::createItems(int w, int l, f64 v)
{
    return 1;
}

int Backpack2D::initializeItems()
{
    //create every item and push into vector of items
    for (int i = 0; i < this->n; i++)
    {
        int w, l, v;
        cin >> w >> l >> v;
        Item *item = new Item(w, l, v);
        this->items.push_back(item);
    }
}

Backpack2D::Backpack2D()
{
    cin >> this->n;
    bits.resize(n, 0);
    Backpack2D::initializeItems();
}
