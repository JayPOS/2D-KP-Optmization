#include "bits/stdc++.h"

using namespace std;

using f64 = double;
using f32 = float;
using i32 = long;
using i64 = long long;
using i = int;

using vi = vector<i>;
using ii = pair<i,i>;


class Item
{
private:
    int w; // width (y)
    int l; // length (x)
    f64 v; // value (should be area if 0)

public:
    Item(int w, int l, int v);
};

class Backpack2D
{
private:
    int n;
    vi bits;
    vector<Item *> items;
public:
    Backpack2D();
    int initializeItems();
    int createItems(int w, int l, f64 v);
};