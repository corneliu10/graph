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

int Vector::size() {
    return dim;
}

void Vector::setSize(int size) {
    dim = size;
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
