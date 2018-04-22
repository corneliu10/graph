#include <iostream>
#include "Lista.h"

Lista::Lista() {
    list = new Vector;
}

Lista::~Lista() {
    delete[] list;
}

Vector* Lista::getFirst() {
    return list;
}

int Lista::size() {
    return listLength;
}

void Lista::setSize(int size) {
    listLength = size;
}

Lista::Lista(const Lista& other) {
    listLength = other.listLength;

    list = new Vector[listLength];
    for(int i=0; i<listLength; ++i)
        list[i] = other.list[i];
}

istream& operator>>(istream& in, Lista& other) {
    in>>other.listLength;

    other.list = new Vector[other.listLength];
    for(int i=0; i<other.listLength; ++i)
        in>>other.list[i];

    return in;
}

ostream& operator<<(ostream& out, const Lista& other) {
    out<<other.listLength<<"\n";

    for(int i=0; i<other.listLength; ++i)
        out<<other.list[i];

    return out;
}

Lista& Lista::operator=(const Lista& other) {
    delete[] list;

    listLength = other.listLength;
    list = new Vector[other.listLength];
    for(int i=0; i<listLength; ++i)
        list[i] = other.list[i];

    return *this;
}
