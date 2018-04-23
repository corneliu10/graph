#include <iostream>
#include "Lista.h"

Lista::Lista() {
    //list = new Vector;
    listLength = 0;
}

Lista::~Lista() {
    if(listLength!=0)
        delete[] list;

    listLength =0;
}

Vector* Lista::getFirst() {
    return list;
}

int Lista::size() const {
    return listLength;
}

void Lista::setSize(int size) {
    listLength = size;
}

void Lista::push_back(Vector other) {
    Vector copy[listLength+1];
    for(int i=0; i<listLength; i++)
        copy[i] = list[i];

    delete[] list;
    list = new Vector[++listLength];
    for(int i=0; i<listLength - 1; i++)
        list[i] = copy[i];

    list[listLength - 1] = other;
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
    out<<"List length: "<<other.listLength<<"\n";

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

Vector& Lista::operator[](int i) const {
    if(i < 0 || i >= listLength) {
        throw "Invalid access!";
    }

    return list[i];
}
