#include <iostream>
#include "Matrixes.hpp"




Matrix2D& LambdaX(Matrix2D T, double dx)
{
    Matrix2D LxT = T;
    for (int i = 1; i < LxT.GetN()-1; ++i)
    {
        for (int j = 1; j < LxT.GetM()-1; ++j)
        {
            LxT.SetValue(i, j, (T.GetValue(i-1,j)-2*T.GetValue(i,j)+T.GetValue(i+1,j))/dx/dx);
        }
    }
    return LxT;
}
void LambdaX(Matrix3D T, Matrix3D LxT, int p, double dx)
{
    for (int i = 1; i < LxT.GetN()-1; ++i)
    {
        for (int j = 1; j < LxT.GetM()-1; ++j)
        {
            LxT.SetValue(p,i, j, (T.GetValue(p,i-1,j)-2*T.GetValue(p,i,j)+T.GetValue(p,i+1,j))/dx/dx);
        }
    }
}

Matrix2D& LambdaY(Matrix2D T, double dy)
{
    Matrix2D LyT = T;
    for (int i = 1; i < LyT.GetN()-1; ++i)
    {
        for (int j = 1; j < LyT.GetM()-1; ++j)
        {
            LyT.SetValue(i, j, (T.GetValue(i,j-1)-2*T.GetValue(i,j)+T.GetValue(i,j+1))/dy/dy);
        }
    }
    return LyT;
}

void LambdaY(Matrix3D T, Matrix3D LyT, int p, double dy)
{
    for (int i = 1; i < LyT.GetN()-1; ++i)
    {
        for (int j = 1; j < LyT.GetM()-1; ++j)
        {
            LyT.SetValue(p,i, j, (T.GetValue(p,i-1,j)-2*T.GetValue(p,i,j)+T.GetValue(p,i+1,j))/dy/dy);
        }
    }
}

int main ()
{
    std::cout << "PZDC" << std::endl;

    return 0;
}