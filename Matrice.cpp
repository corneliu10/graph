#include <iostream>
#include "Matrice.h"

using namespace std;

template <class T>
Matrice<T>::Matrice(int length) {
    matrixLength = length;
    matrix = new T*[matrixLength];

    for(int i=0; i<matrixLength; ++i)
        matrix[i] = new T[matrixLength];

    for(int i=0; i<matrixLength; ++i)
        for(int j=0; j<matrixLength; ++j)
            matrix[i][j] = 0;
}

template <class T>
Matrice<T>::~Matrice() {
    if(matrixLength > 0) delete[] matrix;

    matrixLength = 0;
}

template <class T>
Matrice<T>::Matrice() {
    matrixLength = 0;
}

template <class T>
int Matrice<T>::size() const {
    return matrixLength;
}

template <class T>
void Matrice<T>::addEdge(int from, int to) {
    matrix[from][to] = 1;
}

template <class T>
int Matrice<T>::operator()(int x, int y) const {
    if(x < 0 || x >= matrixLength || y < 0 || y >= matrixLength) {
        throw "Invalid access!";
    }

    return matrix[x][y];
}

template <class T>
Matrice<T>::Matrice(const Matrice<T>& other) {
    matrixLength = other.matrixLength;

    matrix = new T*[matrixLength];

    for(int i=0; i<matrixLength; ++i)
        matrix[i] = new T[matrixLength];

    for(int i=0; i<matrixLength; ++i)
        for(int j=0; j<matrixLength; ++j)
            matrix[i][j] = other.matrix[i][j];
}

template <class T>
istream& operator>>(istream& in, Matrice<T>& other) {
    int matrixLength;

    in>>matrixLength;
    other.matrixLength = matrixLength;
    other.matrix = new T*[matrixLength];

    for(int i=0; i<matrixLength; ++i)
        other.matrix[i] = new T[matrixLength];


    for(int i=0; i<other.matrixLength; ++i)
        for(int j=0; j<other.matrixLength; ++j)
            in>>other.matrix[i][j];

    return in;
}

template <class T>
ostream& operator<<(ostream& out, const Matrice<T>& other) {
    out<<other.matrixLength<<"\n";

    for(int i=0; i<other.matrixLength; ++i, out<<"\n")
        for(int j=0; j<other.matrixLength; ++j)
            out<<other.matrix[i][j]<<" ";

    return out;
}

template <class T>
Matrice<T>& Matrice<T>::operator=(const Matrice<T>& other) {
    delete[] matrix;

    matrixLength = other.matrixLength;
    matrix = new T*[matrixLength];

    for(int i=0; i<matrixLength; ++i)
        matrix[i] = new T[matrixLength];

    for(int i=0; i<other.matrixLength; ++i)
        for(int j=0; j<other.matrixLength; ++j)
            matrix[i][j] = other.matrix[i][j];

    return *this;
}

