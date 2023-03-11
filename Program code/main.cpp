#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include "CalcGrid.hpp"
#include "Solution3.hpp"
// #include "gnuplot-iostream.h"

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

double ExactSolution(double t, double x, double y)
{
    return exp(-pi * t) * sin(pi * x) * sin(pi * y);
}

double Error (Solution &S, int p)
{
    double Error = 0, MaxError = 0;
    for (int n = 0; n <= S.GetN(); ++n)
    {
        for (int m = 0; m <= S.GetM(); ++m)
        {
            Error = abs(ExactSolution(S.GetT(p), S.GetX(n), S.GetY(m)) - S.GetValue(p, n, m));
            if (Error > MaxError)
            {
                MaxError = Error;
            }
        }
    }
    return MaxError;
}

int P = 10, N = 5, M = 5;
const double k = 1. / 2. / pi;

int main (int argc, char *argv[])
{
    int I = 0;
    std::ofstream File;
    std::stringstream path;
    if (argc == 4)
    {
        P = atof(argv[1]);
        N = atof(argv[2]);
        M = atof(argv[3]);
    }
    Solution S1(P, N, M, k, InitialState, Border1, Border2, Border3, Border4);
    S1.Save();

    path << "Error_" << P << "_" << N << "_" << M << ".txt";
    File.open(path.str(), std::ios::out);
    if(!File.is_open())
    {
        std::cout << "Error!" << std::endl;
    }
    else
    {
        File << "T\tError" << std::endl;
        I = P / 10;
        for (int i = 1; i <= 10; ++i)
        {
            File << S1.GetT(i*I)<< "\t" << Error(S1, i * I)<<std::endl;
        }
        File.close();
    }
    return 0;
}