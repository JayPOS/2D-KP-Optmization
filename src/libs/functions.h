#include "2dkp.h"

#define FUNCTIONS_H
#ifdef FUNCTIONS_H

Knapsack2D *initInput( );
vi greedyStandardKnapsack(Knapsack2D *&k, int alpha);
void createInitialSolution(Knapsack2D *&k, vi &bits);
vi createInitialSolutionV2(Knapsack2D *&k);
int checkSolution(Knapsack2D *&k, vi &bits);
void initializeKnapsack(Knapsack2D *&k);
int insertItem(Knapsack2D *&k, int x, vector<vi> &linesPrefixSum, vector<vi> &matriz);

#endif