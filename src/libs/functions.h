#include "2dkp.h"

#define FUNCTIONS_H
#ifdef FUNCTIONS_H

Knapsack2D *initInput( );
vi greedyStandardKnapsack(Knapsack2D *&k);
vi greedyKnapsack2D(Knapsack2D *&k, int alpha);
vi *getNeightboors(vi tabu_list);
void tabuSearch(int constraits_mode);
void initializeKnapsack(Knapsack2D *&k);
#endif