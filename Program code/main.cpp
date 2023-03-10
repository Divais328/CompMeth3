#include <iostream>
#include <cmath>
#include "CalcGrid.hpp"
#include "Solution3.hpp"

long double pi = acos(-1);

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


double InitialState(double x, double y)
{
    return sin(pi * x) * sin(pi * y);
}

double Border1 (double y)
{
    return 0;
}
double Border2 (double y)
{
    return 0;
}
double Border3 (double x)
{
    return 0;
}
double Border4 (double x)
{
    return 0;
}


int P = 10, N = 5, M = 5;
const double k = 1. / 2. / pi;

int main (int argc, char *argv[])
{
    if (argc == 3)
    {
        P = atof(argv[1]);
        N = atof(argv[2]);
        M = atof(argv[3]);
    }
    std::cout << "Starting of PZDC Program" << std::endl;
    Solution S1(P, N, M, k, InitialState, Border1, Border2, Border3, Border4);
    return 0;
}