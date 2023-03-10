#include "Solution3.hpp"

Solution::Solution(int P, int N, int M, double k,
                   double (&Border1)(double, double),
                   double (&Border2)(double, double),
                   double (&Border3)(double, double),
                   double (&Border4)(double, double)) : grid1(P, N, M),grid2(P, N, M), k(k),
                                                           Border1(Border1),
                                                           Border2(Border2),
                                                           Border3(Border3),
                                                           Border4(Border4)
{


}

Solution::~Solution(){};

void Solution::Memory()
{
    A = new double [GetN()]
}

void Solution::ABCDX()
{

}

void Solution::ABCDY()
{

}

void Solution::TriDiag()
{
    for (int p = 1; p <= GetP(); ++p)
    {
        for (int m = 1; m <= GetM(); ++m)
        {
            double g;
            double a = -k * GetDt() / GetDx() / GetDx(), b = (1 + 2 * k * GetDt() / GetDx() / GetDx()), c = -k * GetDt() / GetDx() / GetDx();
            for (int n = 1; n <= GetN(); ++n)
            {

                g = A[i] / B[i - 1]; //=a/b/;
                B[i] = B[i] - g * C[i - 1];
                D[i] = D[i] - g * D[i - 1];
            }
            Y[N] = (pt2GL)(t);
            for (int i = N-1 ; i > 0; --i)
            {
                Y[i] = (D[i] - C[i] * Y[i + 1]) / B[i];
            }
            Y[0] = (pt2G0)(t);
        }
    }
}

int Solution::GetP()
{
    return grid1.GetP();
}
int Solution::GetN()
{
    return grid1.GetN();
}
int Solution::GetM()
{
    return grid1.GetM();
}

double Solution::GetDx()
{
    return grid1.Getdx();
}
double Solution::GetDy()
{
    return grid1.Getdy();
}
double Solution::GetDt()
{
    return grid1.Getdt();
}