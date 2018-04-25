#include <iostream>
#include "Lista.h"

template <class T>
Lista<T>::Lista() {
    list = new Vector<T>;
    listLength = 0;

}

template <class T>
Lista<T>::~Lista() {
    if(listLength > 0) delete[] list;

    listLength = 0;
}

template <class T>
Vector<T>* Lista<T>::getFirst() {
    return list;
}

template <class T>
int Lista<T>::size() const {
    return listLength;
}

template <class T>
void Lista<T>::setSize(int size) {
    listLength = size;
}

template <class T>
void Lista<T>::push_back(Vector<T> other) {
    Vector<T> copy[listLength+1];
    for(int i=0; i<listLength; i++)
        copy[i] = list[i];

    if(listLength > 0) delete[] list;
    list = new Vector<T>[++listLength];
    for(int i=0; i<listLength - 1; i++)
        list[i] = copy[i];

    list[listLength - 1] = other;
}

template <class T>
Lista<T>::Lista(const Lista<T>& other) {
    listLength = other.listLength;

    list = new Vector<T>[listLength];
    for(int i=0; i<listLength; ++i)
        list[i] = other.list[i];
}

template <class T>
istream& operator>>(istream& in, Lista<T>& other) {
    in>>other.listLength;

    other.list = new Vector<T>[other.listLength];
    for(int i=0; i<other.listLength; ++i)
        in>>other.list[i];

    return in;
}

template <class T>
ostream& operator<<(ostream& out, const Lista<T>& other) {
    out<<"List length: "<<other.listLength<<"\n";

    for(int i=0; i<other.listLength; ++i)
        out<<other.list[i];

    return out;
}

template <class T>
Lista<T>& Lista<T>::operator=(const Lista<T>& other) {
    if(listLength > 0) delete[] list;

    listLength = other.listLength;
    list = new Vector<T>[other.listLength];
    for(int i=0; i<listLength; ++i)
        list[i] = other.list[i];

    return *this;
}

template <class T>
Vector<T>& Lista<T>::operator[](int i) const {
    if(i < 0 || i >= listLength) {
        throw "Invalid access!";
    }

    return list[i];
}
