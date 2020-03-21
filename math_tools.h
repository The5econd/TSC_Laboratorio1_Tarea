//
// Created by dese2 on 3/20/2020.
//
#ifndef TAREA1_MATH_TOOLS_H
#define TAREA1_MATH_TOOLS_H
#endif //TAREA1_MATH_TOOLS_H

#include <vector>
#include "math.h"
#include "stdlib.h"
using namespace std;

typedef vector<float> Vector;
typedef vector<Vector> Matrix;

void zeroes(Matrix &M,int n){
    for(int i=0;i<n;i++){
        vector<float> row(n,0.0);
        M.push_back(row);
    }
}
void copyMatrix(Matrix A, Matrix &copy){
    zeroes(copy,A.size());
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A.at(0).size();j++)
            copy.at(i).at(j) = A.at(i).at(j);
}
void productRealMatrix(float real,Matrix M,Matrix &R){
    zeroes(R,M.size());
    for(int i=0;i<M.size();i++)
        for(int j=0;j<M.at(0).size();j++)
            R.at(i).at(j) = real*M.at(i).at(j);
}
void getMinor(Matrix &M,int i, int j){
    M.erase(M.begin()+i);
    for(int i=0;i<M.size();i++)
        M.at(i).erase(M.at(i).begin()+j);
}

float determinant(Matrix M){
    if(M.size() == 1) return M.at(0).at(0);
    else{
        float det=0.0;
        for(int i=0;i<M.at(0).size();i++){
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,0,i);
            det += pow(-1,i)*M.at(0).at(i)*determinant(minor);
        }
        return det;
    }
}
void cofactors(Matrix M, Matrix &Cof){
    zeroes(Cof,M.size());
    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,i,j);
            Cof.at(i).at(j) = pow(-1,i+j)*determinant(minor);
        }
    }
}

void transpose(Matrix M, Matrix &T){
    zeroes(T,M.size());
    for(int i=0;i<M.size();i++)
        for(int j=0;j<M.at(0).size();j++)
            T.at(j).at(i) = M.at(i).at(j);
}

Matrix invertedMatrix(Matrix B, Matrix &inverse){
    zeroes(inverse, B.size());
    Matrix cofactor_matrix, transpose_matrix, inverted_matrix;

    cofactors(B, cofactor_matrix);

    transpose(cofactor_matrix, transpose_matrix);

    productRealMatrix((1/determinant(B)), transpose_matrix, inverted_matrix);

    for (int i = 0; i < B.size(); ++i) {
        for (int j = 0; j < B.at(0).size() ; ++j) {
            inverse.at(i).at(j) = inverted_matrix.at(i).at(j);
        }
    }
    return inverse;
}