#pragma once
#include <iostream>
#include <cmath>

namespace mbox{
    template <typename T, int size>
    class vec;
}

namespace mbox{

template <typename T, int row, int column>
class mat{
    private:

    T** matrix;
    int m, n;
    T& getElementMem(int i, int j){return matrix[i][j];};

    public:
    
    mat(): m(row), n(column){createMatrix();};
    mat(T val): m(row), n(column){createMatrix(); createIdentity(val);};
    mat(const mat& other);

    mat& operator=(const mat& other);

    mat operator+(const mat& other);
    mat operator-(const mat& other);
    mat& operator*(T val){mulnum(val); return *this;};

    template <typename U, int row2, int column2>
    mat<T, row, column2> operator*(const mat<U, row2, column2>& other);

    void mulnum(T val);

    int rows()const{return m;};
    int cols()const{return n;};

    void createMatrix();

    void createIdentity();
    void createIdentity(T val);

    void transpose();
    T minor(int, int);
    T cofactor(int, int);
    T determinant()const;

    mat<T, row-1, column-1> 
    createMinor(int a, int b)const;

    void cpyMatToArr(T cpy[row][column]);
    void updateFromArray(T* arr);

    void updateElement(int, int, T);
    T getElement(int i, int j)const{return matrix[i][j];};

    template <int size = row * column>
    vec<T, size> tovec();

    void printmat();

    ~mat();
};

typedef mat<float, 4, 4> mat4, mat4x4;
typedef mat<float, 3, 3> mat3, mat3x3;
typedef mat<float, 2, 2> mat2, mat2x2;
typedef mat<float, 1, 2> mat1x2;
typedef mat<float, 1, 3> mat1x3;
typedef mat<float, 1, 4> mat1x4;
typedef mat<float, 2, 1> mat2x1;
typedef mat<float, 2, 3> mat2x3;
typedef mat<float, 2, 4> mat2x4;
typedef mat<float, 3, 1> mat3x1;
typedef mat<float, 3, 2> mat3x2;
typedef mat<float, 3, 4> mat3x4;
typedef mat<float, 4, 1> mat4x1;
typedef mat<float, 4, 2> mat4x2;
typedef mat<float, 4, 3> mat4x3;

}

#include "matrix.tpp"
