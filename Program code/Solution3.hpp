#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
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
    double (&Border1)(double);
    double (&Border2)(double);
    double (&Border3)(double);
    double (&Border4)(double);
    double (&InitialState)(double, double);
    const double k = 1.;
    double *Gx, *Bx, *Dx, *Gy, *By, *Dy;
    double ax = -k * GetDt() / GetDx() / GetDx(), bx = (1. + 2. * k * GetDt() / GetDx() / GetDx()), cx = -k * GetDt() / GetDx() / GetDx();
    double ay = -k * GetDt() / GetDy() / GetDy(), by = (1. + 2. * k * GetDt() / GetDy() / GetDy()), cy = -k * GetDt() / GetDy() / GetDy();

    void Memory();
    void TriDiag();
    void DX(int p, int m);
    void DY(int p, int n);

    double GetValue1(int p, int n, int m) const;
    void SetValue1(int p, int n, int m, double value);

    double GetValue2(int p, int n, int m) const;
    void SetValue2(int p, int n, int m, double value);

public:
    Solution(int P, int N, int M, double k,
             double (&InitialState)(double, double),
             double (&Border1)(double),
             double (&Border2)(double),
             double (&Border3)(double),
             double (&Border4)(double));
    ~Solution();

    double GetT(int p) const;
    double GetX(int n) const;
    double GetY(int m) const;

    int GetP() const;
    int GetN() const;
    int GetM() const;

    double GetDx() const;
    double GetDy() const;
    double GetDt() const;

    double GetValue(int p, int n, int m) const;
    void SetValue(int p, int n, int m, double value);

    friend std::ostream &operator<<(std::ostream &out, const Solution &S);
    void Save() const;
    void Save(std::string path) const;
};