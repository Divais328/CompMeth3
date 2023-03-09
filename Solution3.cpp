#include "Solution3.hpp"

Solution::Solution(int P, int N, int M, double k,
                   double (&Border1)(double, double),
                   double (&Border2)(double, double),
                   double (&Border3)(double, double),
                   double (&Border4)(double, double)) : grid(P, N, M), k(k),
                                                           Border1(Border1),
                                                           Border2(Border2),
                                                           Border3(Border3),
                                                           Border4(Border4)
{


}

Solution::~Solution(){};

void Solution::TriDiag()
{
    for (int p = 1; p <= grid.GetP(); ++p)
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
}

int Solution::GetP()
{
    return grid.GetP();
}
int Solution::GetN()
{
    return grid.GetN();
}
int Solution::GetM()
{
    return grid.GetM();
}
