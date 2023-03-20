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
    Gx[0] = 0.;
    for (int n = 1; n < GetN(); ++n)
    {
        Gx[n] = ax / Bx[n - 1];
        Bx[n] =bx - Gx[n] * cx;
    }
    Bx[GetN()] = bx;
    Gx[GetN()] = ax / Bx[GetN() - 1];

    By[0] = by;
    Gy[0] = 0.;
    for (int m = 1; m < GetM(); ++m)
    {
        Gy[m] = ay / By[m - 1];
        By[m] = by - Gy[m] * cy;
    }
    By[GetM()] = by;
    Gy[GetM()] = ay / By[GetM() - 1];

    for (int n = 0; n <= GetN(); ++n)
    {
        for (int m = 0; m <= GetM(); ++m)
        {
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
    Dy[0] = GetValue1(p, n, 0);
    for (int m = 1; m <= GetM(); ++m)
    {
        Dy[m] = GetValue1(p, n, m) - Gy[m] * Dy[m - 1];
    }
}

void Solution::TriDiag()
{
    for (int p = 1; p <= GetP(); ++p)
    {
        for (int m = 1; m < GetM(); ++m)
        {
            DX(p - 1, m);
            //SetValue1(p - 1, GetN(), m, 0); //Border2(GetY(m)));
            for (int n = GetN() - 1; n > 0; --n)
            {
                SetValue1(p - 1, n, m, (Dx[n] - cx * GetValue1(p - 1, n + 1, m)) / Bx[n]);
            }
            //SetValue1(p - 1, 0, m, 0); //Border1(GetY(m)));
        }

        for (int n = 1; n < GetN(); ++n)
        {
            DY(p - 1, n);
            //SetValue2(p, n, GetM(), 0); // Border4(GetX(n)));
            for (int m = GetM() - 1; m > 0; --m)
            {
                SetValue2(p, n, m, (Dy[m] - cy * GetValue2(p, n, m + 1)) / By[m]);
            }
            //SetValue2(p, n, 0, 0); //Border3(GetX(n)));
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

void Solution::Save() const
{
    std::ofstream File;
    std::stringstream path;
    path << "Solution_" << GetP() << "_" << GetN() << "_" << GetM() << ".txt";

    File.open(path.str(),std::ios::out);
    if (!File.is_open())
    {
        std::cout << "Error!" << std::endl;
    }
    else
    {
        File << *this;
        File.close();
    }
}

void Solution::Save(std::string path) const
{
    std::ofstream File;
    File.open(path,std::ios::out);
    if (!File.is_open())
    {
        std::cout << "Error!" << std::endl;
    }
    else
    {
        File << *this;
        File.close();
    }
}

std::ostream& operator<< (std::ostream &out, const Solution &S)
{
    out << "X\tY";
    for (int p = 0; p <= S.GetP(); ++p)
    {
        out << "\tT = " << S.GetT(p);
    }
    out << std::endl;
    for (int n = 0; n <= S.GetN(); ++n)
    {
        for (int m = 0; m <= S.GetM(); ++m)
        {
            out << S.GetX(n) << "\t" << S.GetY(m);
            for (int p = 0; p <= S.GetP(); ++p)
            {
                out << "\t" << S.GetValue(p, n, m);
            }
            out << std::endl;
        }
        out << std::endl;
    }
    return out;
}
