#include <iostream>
#include "math_tools.h"
#include "display_tools.h"
using namespace std;
int main() {

    Matrix baseMatrix, inverted_matrix;
    zeroes(baseMatrix, 3);

    baseMatrix.at(0).at(0) = 2; baseMatrix.at(0).at(1) = 2; baseMatrix.at(0).at(2) = 3;
    baseMatrix.at(1).at(0) = 4; baseMatrix.at(1).at(1) = 5; baseMatrix.at(1).at(2) = 6;
    baseMatrix.at(2).at(0) = 7; baseMatrix.at(2).at(1) = 8; baseMatrix.at(2).at(2) = 9;
    //showMatrix(baseMatrix);

    //cout << determinant(baseMatrix); NO ES CERO asi que prosigo/////////

    showMatrix(invertedMatrix(baseMatrix, inverted_matrix));
    return 0;
}
