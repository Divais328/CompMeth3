#pragma once
#include <iostream>


class Matrix3D 
{
    double ***Matrix = NULL;
    const int P, N, M;
public:
    Matrix3D(Matrix3D const &A);
    Matrix3D(int P, int N, int M);

    ~Matrix3D();

    int GetP();
    int GetN();
    int GetM();

    double GetValue(int p, int n, int m);
    void SetValue(int p, int n, int m, double const value);

    void SetLayer(int p, Matrix2D const &A);
    Matrix2D& GetLayer(int p);
};

class Matrix2D 
{
    double **Matrix = NULL;
    const int N, M;

public:
    Matrix2D(Matrix2D const &A);
    Matrix2D(int N, int M);
    ~Matrix2D();

    int GetN();
    int GetM();
    double GetValue(int n, int m);
    void SetValue(int n, int m, double const value);
};