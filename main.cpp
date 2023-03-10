#include <iostream>
#include "CalcGrid.hpp"
#include  <cmath>

#define pi = arcos(-1)

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


double Border1 (double y, double t)
{
    return 0;
}

double Border2 (double y, double t)
{
    return 0;
}

double Border3 (double x, double t)
{
    return 0;
}

double Border4 (double x, double t)
{
    return 0;
}

void TriDiag(double t)
{
    double g, a;
    for (int i = 1; i <= N; ++i)
    {
        g = A[i] / B[i - 1];
        B[i] = B[i] - g * C[i - 1];
        D[i] = D[i] - g * D[i - 1];
    }
    Y[N] = (pt2GL)(t);
    for (int i = N-1 ; i > 0; --i)
    {
        Y[i] = (D[i] - C[i] * Y[i + 1]) / B[i];
        a = Y[i];
    }
    Y[0] = (pt2G0)(t);
}


int main (int argc, char *argv[])
{
    std::cout << "Starting of PZDC Program" << std::endl;
     
    return 0;
}