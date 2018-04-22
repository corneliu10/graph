#include <iostream>
#include "Matrice.h"

using namespace std;

Matrice::Matrice(int length) {
    matrixLength = length;
    matrix = new int*[matrixLength];

    for(int i=0; i<matrixLength; ++i)
        matrix[i] = new int[matrixLength];
}

Matrice::~Matrice() {
    delete[] matrix;
}

Matrice::Matrice() {
}

Matrice::Matrice(const Matrice& other) {
    matrixLength = other.matrixLength;

    matrix = new int*[matrixLength];

    for(int i=0; i<matrixLength; ++i)
        matrix[i] = new int[matrixLength];

    for(int i=0; i<matrixLength; ++i)
        for(int j=0; j<matrixLength; ++j)
            matrix[i][j] = other.matrix[i][j];
}

istream& operator>>(istream& in, Matrice& other) {
    int matrixLength;

    in>>matrixLength;
    other.matrixLength = matrixLength;
    other.matrix = new int*[matrixLength];

    for(int i=0; i<matrixLength; ++i)
        other.matrix[i] = new int[matrixLength];


    for(int i=0; i<other.matrixLength; ++i)
        for(int j=0; j<other.matrixLength; ++j)
            in>>other.matrix[i][j];

    return in;
}

ostream& operator<<(ostream& out, const Matrice& other) {
    out<<other.matrixLength<<"\n";

    for(int i=0; i<other.matrixLength; ++i, out<<"\n")
        for(int j=0; j<other.matrixLength; ++j)
            out<<other.matrix[i][j]<<" ";

    return out;
}

Matrice& Matrice::operator=(const Matrice& other) {
    delete[] matrix;

    matrixLength = other.matrixLength;
    matrix = new int*[matrixLength];

    for(int i=0; i<matrixLength; ++i)
        matrix[i] = new int[matrixLength];

    for(int i=0; i<other.matrixLength; ++i)
        for(int j=0; j<other.matrixLength; ++j)
            matrix[i][j] = other.matrix[i][j];

    return *this;
}
