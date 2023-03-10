#pragma once

#include <iostream>
#include "CalcGrid.hpp"


//                   4
//     |---------------------------|
//     |                           |
//     |                           |
//     |                           |
//     |                           |
//  1  |                           |  2
//     |                           |
//     |                           |
//     |                           |
//     |                           |
//     |---------------------------|
//                   3



class Solution 
{
    CalcGrid2D grid1, grid2;
    double (&Border1)(double, double);
    double (&Border2)(double, double);
    double (&Border3)(double, double);
    double (&Border4)(double, double);
    const double k = 1;
    double *A, *B, *C, *D;

    void Memory();
    void TriDiag();
    void ABCDX();
    void ABCDY();

public:
    Solution(int P, int N, int M, double k,
             double (&Border1)(double, double),
             double (&Border2)(double, double),
             double (&Border3)(double, double),
             double (&Border4)(double, double));
    ~Solution();

    int GetP();
    int GetN();
    int GetM();

    double GetDx();
    double GetDy();
    double GetDt();
};