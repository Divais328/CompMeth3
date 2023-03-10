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
double k = 1. / 2. / pi;

int main (int argc, char *argv[])
{
    std::cout << "Starting of PZDC Program" << std::endl;
    Solution S1(P, N, M, k, InitialState, Border1, Border2, Border3, Border4);
    std::cout << S1.GetP() << " " << S1.GetN() << " " << S1.GetM() << std::endl;
    std::cout << "(0,0,0) = " << S1.GetValue(0, 0, 0) << std::endl;
    std::cout << "(0,2,3) = " << S1.GetValue(0, 2, 3) << std::endl;
    std::cout << "(P,0,0) = " << S1.GetValue(P, 0, 0) << std::endl;
    std::cout << "(P,2,3) = " << S1.GetValue(P, 2, 3) << std::endl;
    return 0;
}