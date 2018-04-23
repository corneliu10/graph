#ifndef LISTA_H
#define LISTA_H
#include "Vector.h"
#include <iostream>

class Lista {
    public:
        Lista();
        ~Lista();
        Lista(const Lista& other);
        Vector* getFirst();
        int size() const;
        void setSize(int size);
        void push_back(Vector other);
        friend istream& operator>>(istream& in, Lista& other);
        friend ostream& operator<<(ostream& out, const Lista& other);
        Lista& operator=(const Lista& other);
        Vector& operator[](int i) const;
    private:
        Vector *list;
        int listLength;
};

#endif //LISTA_H
