#pragma once
#include <iostream>

//2D Matrix difinition
class Matrix2D 
{
    double **Matrix = NULL;
    const int N, M;

public:
    Matrix2D(Matrix2D const &A);
    Matrix2D(int N, int M);
    ~Matrix2D();

    int GetN() const;
    int GetM() const;
    double GetValue(int n, int m) const;
    void SetValue(int n, int m, double const value);
};

//3D Matrix difinition
class Matrix3D 
{
    double ***Matrix = NULL;
    const int P, N, M;
public:
    Matrix3D(Matrix3D const &A);
    Matrix3D(int P, int N, int M);

    ~Matrix3D();

    int GetP() const;
    int GetN() const;
    int GetM() const;

    double GetValue(int p, int n, int m) const;
    void SetValue(int p, int n, int m, double const value);

    void SetLayer(int p, Matrix2D const &A);
    Matrix2D& GetLayer(int p) const;
};

//2D Calculation Grid difinitio
class CalcGrid2D
{
    Matrix3D Matrix;
    const double dx, dy, dt;

public:
    CalcGrid2D(int P, int N, int M);
    ~CalcGrid2D();

    int GetP() const;
    int GetN() const;
    int GetM() const;

    double Getdx() const;
    double Getdy() const;
    double Getdt() const;

    double GetX(int n) const;
    double GetY(int m) const;
    double GetT(int p) const;

    void SetValue(int p, int n, int m, double value);
    double GetValue(int p, int n, int m) const;

    Matrix2D& GetLayer(int p) const;
    void SetLayer(int p, Matrix2D &A);
};


