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
        int size();
        void setSize(int size);
        friend istream& operator>>(istream& in, Lista& other);
        friend ostream& operator<<(ostream& out, const Lista& other);
        Lista& operator=(const Lista& other);
    private:
        Vector *list;
        int listLength;
};

#endif //LISTA_H
