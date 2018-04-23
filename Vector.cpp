#include <iostream>
#include "Vector.h"

Vector::Vector() {
    dim = 0;
    v = new int[dim];
}

Vector::Vector(int dim) : dim(dim) {
    v = new int[dim];
}

Vector::~Vector() {
    delete[] v;
}

Vector::Vector(const Vector& other) {
    dim = other.dim;

    v = new int[dim];
    for(int i=0; i<dim; ++i)
        v[i] = other.v[i];
}

Vector& Vector::operator=(const Vector& other) {
    delete[] v;
    dim = other.dim;

    v = new int[dim];
    for(int i=0; i<dim; ++i)
        v[i] = other.v[i];

    return *this;
}

int Vector::size() const {
    return dim;
}

void Vector::setSize(int size) {
    dim = size;
}

void Vector::push_back(int nr) {
    int copy[dim+1];
    for(int i=0; i<dim; i++)
        copy[i] = v[i];

    delete[] v;
    v = new int[++dim];
    for(int i=0; i<dim - 1; i++)
        v[i] = copy[i];

    v[dim - 1] = nr;
}

void Vector::clear() {
    delete[] v;
    dim = 0;
}

istream& operator>>(istream& in, Vector& other) {
    in>>other.dim;

    other.v = new int[other.dim];

    for(int i=0; i<other.dim; ++i)
        in>>other.v[i];

    return in;
}

ostream& operator<<(ostream& out, const Vector& other) {
    out<<other.dim<<"\n";

    for(int i=0; i<other.dim; ++i)
        out<<other.v[i]<<" ";

    out<<"\n";

    return out;
}

int& Vector::operator[](int i) {
    if(i < 0 || i >= dim) {
        throw "Invalid access!";
    }

    return v[i];
}
