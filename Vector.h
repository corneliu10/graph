#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

class Vector {
    public:
        Vector();
        Vector(int dim);
        ~Vector();
        Vector(const Vector& other);
        int size() const;
        void setSize(int size);
        void push_back(int nr);
        void clear();
        friend istream& operator>>(istream& in, Vector& other);
        friend ostream& operator<<(ostream& out, const Vector& other);
        Vector& operator=(const Vector& other);
        int& operator[](int i);
    private:
        int *v;
        int dim;
};

#endif //VECTOR_H
