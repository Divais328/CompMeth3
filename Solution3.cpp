#include "Solution3.hpp"

Solution::Solution(int P, int N, int M, double k,
                   double (&InitialState)(double, double),
                   double (&Border1)(double),
                   double (&Border2)(double),
                   double (&Border3)(double),
                   double (&Border4)(double)) : grid1(P, N, M), grid2(P, N, M), k(k),
                                                InitialState(InitialState),
                                                Border1(Border1),
                                                Border2(Border2),
                                                Border3(Border3),
                                                Border4(Border4)
{
    Memory();
    TriDiag();
}

Solution::~Solution()
{
    delete[] Gx;
    delete[] Bx;
    delete[] Dx;

    delete[] Gy;
    delete[] By;
    delete[] Dy;
}

void Solution::Memory()
{
    Gx = new double [GetN()+1];
    Bx = new double [GetN()+1];
    Dx = new double [GetN()+1];

    Gy = new double [GetM()+1];
    By = new double [GetM()+1];
    Dy = new double [GetM()+1];

    Bx[0] = bx;
    for (int n = 1; n <= GetN(); ++n)
    {
        Gx[n] = ax / Bx[n - 1];
        Bx[n] = Bx[n] - Gx[n] * cx;
    }
    By[0] = by;
    for (int m = 1; m <= GetM(); ++m)
    {
        Gy[m] = ay / By[m - 1];
        By[m] = By[m] - Gy[m] * cy;
    }
    for (int n = 0; n <= GetN(); ++n)
    {
        for (int m = 0; m <= GetM(); ++m)
        {
            double I = InitialState(GetX(n), GetY(m));
            SetValue2(0, n, m, InitialState(GetX(n), GetY(m)));
        }
    }
}

void Solution::DX(int p, int m)
{
    Dx[0] = GetValue2(p, 0, m);
    for (int n = 1; n <= GetN(); ++n)
    {
        Dx[n] = GetValue2(p, n, m) - Gx[n] * Dx[n - 1];
    }
}

void Solution::DY(int p, int n)
{
    Dx[0] = GetValue1(p, n, 0);
    for (int m = 1; m <= GetM(); ++m)
    {
        Dx[m] = GetValue1(p, n, m) - Gx[m] * Dx[m - 1];
    }
}

void Solution::TriDiag()
{
    for (int p = 1; p <= GetP(); ++p)
    {
        for (int m = 1; m < GetM(); ++m)
        {
            DX(p - 1, m);
            SetValue1(p - 1, GetN(), m, Border2(GetY(m)));
            for (int n = GetN() - 1; n > 0; --n)
            {
                SetValue1(p - 1, n, m, (Dx[n] - cx * GetValue2(p - 1, n + 1, m)) / Bx[n]);
            }
            SetValue1(p - 1, 0, m, Border1(GetY(m)));
        }

        for (int n = 1; n < GetN(); ++n)
        {
            DY(p - 1, n);
            SetValue2(p, n, GetM(), Border4(GetX(n)));
            for (int m = GetM() - 1; m > 0; --m)
            {
                SetValue2(p, n, m, (Dy[m] - cy * GetValue1(p - 1, n + 1, m)) / By[m]);
            }
            SetValue2(p, n, 0, Border3(GetX(n)));
        }
    }
}


double Solution::GetT(int p) const
{
    if ((p <= GetP()) && (p >= 0))
        return p * GetDt();
    else
        return -1;
}
double Solution::GetX(int n) const
{
    if ((n <= GetN()) && (n >= 0))
        return n * GetDx();
    else
        return -1;
}
double Solution::GetY(int m) const
{
    if ((m <= GetM()) && (m >= 0))
        return m * GetDy();
    else
        return -1;
}

int Solution::GetP() const
{
    return grid1.GetP();
}
int Solution::GetN() const
{
    return grid1.GetN();
}
int Solution::GetM() const
{
    return grid1.GetM();
}

double Solution::GetDx() const
{
    return grid1.Getdx();
}
double Solution::GetDy() const
{
    return grid1.Getdy();
}
double Solution::GetDt() const
{
    return grid1.Getdt();
}

double Solution::GetValue(int p, int n, int m) const
{
    return grid2.GetValue(p, n, m);
}
void Solution::SetValue(int p, int n, int m, double value)
{
    grid2.SetValue(p, n, m, value);
}

double Solution::GetValue1(int p, int n, int m) const
{
    return grid1.GetValue(p, n, m);
}
void Solution::SetValue1(int p, int n, int m, double value)
{
    grid1.SetValue(p, n, m, value);
}

double Solution::GetValue2(int p, int n, int m) const
{
    return grid2.GetValue(p, n, m);
}
void Solution::SetValue2(int p, int n, int m, double value)
{
    grid2.SetValue(p, n, m, value);
}


