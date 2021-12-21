#include "includes.h"

#ifndef TABU_H
#define TABU_H

#define TABU_LIST_MAX 20

vector<Solution> getNeighborhood(vi &tabu, Solution actualSolution, Knapsack2D *&k);
vi tabuSearch(Knapsack2D *&k, int iter, int alpha);
int valueComparator(Item *&a, Item *&b);
int compareSolution(Solution &a, Solution &b);

#endif