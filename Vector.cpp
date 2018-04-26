#include <iostream>
#include "Vector.h"

template <class T>
Vector<T>::Vector() {
    dim = 0;
    //v = new int[dim];
}

template <class T>
Vector<T>::Vector(int dim) : dim(dim) {
    v = new T[dim];
}

template <class T>
Vector<T>::~Vector() {
    if(dim!=0 && v!=NULL) delete[] v;
    dim = 0;
}

template <class T>
Vector<T>::Vector(const Vector<T>& other) {
    dim = other.dim;

    v = new T[dim];
    for(int i=0; i<dim; ++i)
        v[i] = other.v[i];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if(dim > 0) delete[] v;
    dim = other.dim;

    v = new T[dim];
    for(int i=0; i<dim; ++i)
        v[i] = other.v[i];

    return *this;
}

template <class T>
int Vector<T>::size() const {
    return dim;
}

template <class T>
void Vector<T>::setSize(int size) {
    dim = size;
}

template <class T>
void Vector<T>::push_back(T nr) {
    T copy[dim+1];
    for(int i=0; i<dim; i++)
        copy[i] = v[i];

    if(dim > 0) delete[] v;
    v = new T[++dim];
    for(int i=0; i<dim - 1; i++)
        v[i] = copy[i];

    v[dim - 1] = nr;
}

template <class T>
void Vector<T>::clear() {
    if(dim > 0) delete[] v;
    dim = 0;
}

template <class T>
istream& operator>>(istream& in, Vector<T>& other) {
    if(other.dim > 0) delete[] other.v;

    in>>other.dim;

    other.v = new T[other.dim];

    for(int i=0; i<other.dim; ++i)
        in>>other.v[i];

    return in;
}

template <class T>
ostream& operator<<(ostream& out, const Vector<T>& other) {
    out<<other.dim<<": ";

    for(int i=0; i<other.dim; ++i)
        out<<other.v[i]<<" ";

    out<<"\n";

    return out;
}

template <class T>
T& Vector<T>::operator[](int i) {
    if(i < 0 || i >= dim) {
        throw "Invalid access!";
    }

    return v[i];
}
