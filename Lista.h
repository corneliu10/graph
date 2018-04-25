#ifndef LISTA_H
#define LISTA_H
#include "Vector.h"
#include <iostream>

template <class T>
class Lista {
    public:
        Lista();
        ~Lista();
        Lista(const Lista<T>& other);
        Vector<T>* getFirst();
        int size() const;
        void setSize(int size);
        void push_back(Vector<T> other);
        template <class U> friend istream& operator>>(istream& in, Lista<U>& other);
        template <class U> friend ostream& operator<<(ostream& out, const Lista<U>& other);
        Lista<T>& operator=(const Lista<T>& other);
        Vector<T>& operator[](int i) const;
    private:
        Vector<T> *list;
        int listLength;
};

#endif //LISTA_H
