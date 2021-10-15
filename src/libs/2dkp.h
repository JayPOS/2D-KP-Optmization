#ifndef __2DKP_H

#define __2DKP_H

#include "includes.h"

class Item
{
private:
    int id;
    int w; // width (y)
    int l; // length (x)
    f64 v; // value (should be area if 0)

public:
    Item(int w, int l, f64 v);

    int getId();
    int getW();
    int getL();
    int getV();
    int getProfit();
};

class Knapsack2D
{
private:
    int n; // number of itens
    int w; // width (y)
    int l; // length (x)
public:
    vi bits;
    vector<Item *> items;

    Knapsack2D(int n, int w, int l);
    
    int addItem(int w, int l, f64 v);
    int getKnapsackArea();
    int getN();
    int getW();
    int getL();
};

int compare(Item *&a, Item *&b);

#endif