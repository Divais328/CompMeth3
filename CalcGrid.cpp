#include "CalcGrid.hpp"

//3D Matrix realisation
Matrix3D(Matrix3D const &A): P(A.P), N(A.N), M(A.M)
{
    Matrix = new double **[P];
    Matrix[0] = new double *[(P) * (N)];
    for (int j = 1; j < N; ++j)
    {
        Matrix[0][j] = Matrix[0][j - 1] + M;
        for (int k = 0; k < M; ++k)
        {
            Matrix[0][j][k] = A.Matrix[0][j][k];
        }
    }
    Matrix[0][0] = new double[(P) * (N) * (M)];
    for (int i = 1; i < P; ++i)
    {
        Matrix[i] = Matrix[i - 1] + N;
        for (int j = 1; j < N; ++j)
        {
            Matrix[i][j] = Matrix[i][j - 1] + M;
            for (int k = 0; k < M; ++k)
            {
                Matrix[i][j][k] = A.Matrix[i][j][k];
            }
        }
    }

}
Matrix3D(int P, int N, int M): P(P), N(N), M(M)
{
    Matrix = new double **[P];
    Matrix[0] = new double *[(P) * (N)];
    for (int j = 1; j < N; ++j)
    {
        Matrix[0][j] = Matrix[0][j - 1] + M;
        for (int k = 0; k < M; ++k)
        {
            Matrix[0][j][k] = 0;
        }
    }
    Matrix[0][0] = new double[(P) * (N) * (M)];
    for (int i = 1; i < P; ++i)
    {
        Matrix[i] = Matrix[i - 1] + N;
        for (int j = 1; j < N; ++j)
        {
            Matrix[i][j] = Matrix[i][j - 1] + M;
            for (int k = 0; k < M; ++k)
            {
                Matrix[i][j][k] = 0;
            }
        }
    }
}

~Matrix3D()
{
    delete[] Matrix[0][0];
    delete[] Matrix[0];
    delete[] Matrix;
}

int GetP()
{
    return P;
}
int GetN()
{
    return N;
}
int GetM()
{
    return M;
}
double GetValue(int p, int n, int m)
{
    return Matrix[p][n][m];
}

void SetValue(int p, int n, int m, double const &value)
{
    Matrix[p][n][m] = value;
}

void SetLayer(int p, Matrix2D const &A)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            Matrix[p][i][j] = A.GetValue(i,j);
        }
    }
}
Matrix2D& GetLayer(int p)
{
    Matrix2D A(N, M);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
           A.SetValue(i,j, Matrix[p][i][j]);
        }
    }
    return A;
}

//2D Matrix realisation
Matrix2D(Matrix2D const& A): N(A.N), M(A.M)
{
    Matrix = new double *[N];
    Matrix[0] = new double [(N) * (M)];
    for (int j = 0; j < M; ++j)
        {
            Matrix[0][j] = A.Matrix[0][j];
        }
    for (int i = 1; i < N; ++i)
    {
        Matrix[i] = Matrix[i-1] + M;
        for (int j = 0; j < M; ++j)
        {
            Matrix[i][j] = A.Matrix[i][j];
        }
    }

}
Matrix2D(int N, int M): N(N), M(M)
{
    Matrix = new double *[N];
    Matrix[0] = new double [(N) * (M)];
    for (int j = 0; j < M; ++j)
        {
            Matrix[0][j] = 0;
        }
    for (int i = 1; i < N; ++i)
    {
        Matrix[i] = Matrix[i-1] + M;
        for (int j = 0; j < M; ++j)
        {
            Matrix[i][j] = 0;
        }
    }
    
}

~Matrix2D()
{
    delete[] Matrix[0];
    delete[] Matrix;
}


int GetN()
{
    return N;
}
int GetM()
{
    return M;
}
double GetValue(int n, int m)
{
    return Matrix[n][m];
}

void SetValue(int n, int m, double const value)
{
    Matrix[n][m] = value;
}