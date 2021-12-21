#ifndef __2DKP_H

#define __2DKP_H

#include "includes.h"

class Point
{
    private:
    public:
    int x, y;
    Point(int x, int y);
};
class Item
{
private:

public:
    int w; // width (y)
    int l; // length (x)
    f64 v; // value (should be area if 0)
    f64 p;
    Item(int w, int l, f64 v);

    int getW();
    int getL();
    int getV();
    f64 getProfit();
};

class KPItem
{
    private:
    public:
    Item *item;
    Point *ponto;
    KPItem(Item *item, Point *ponto);
};

class Solution {
private:
public:
    vi bits;
    vector<KPItem> kpitems;
    KPItem *variatedItem;
    Solution(vi bits, vector<KPItem> kpitems);
    f64 getSumProfits();
};
class Knapsack2D
{
private:

public:
    int n; // number of itens
    int w; // width (y)
    int l; // length (x)
    int areaCovered;
    vi bits;
    vector<Item *> items;
    vector<KPItem> kpitems;
    Solution *solution;

    Knapsack2D(int n, int w, int l);
    
    int addItem(int w, int l, f64 v);

    int addKpItem(int x, int y, Item *item);

    int getKnapsackArea();
    int getN();
    int getW();
    int getL();
};

int compare(Item *&a, Item *&b);


int withinBorders(Knapsack2D *kp, KPItem &item);
int lessThanProfit(Item *&a, Item *&b);

f64 itemProfit(Item *item, int W, int L);
int allColisions(KPItem item, vector<KPItem> &kpitens, int n);
int colision(KPItem a, KPItem b);
int deallocate(Knapsack2D *&kp);

#endif