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
        int size();
        void setSize(int size);
        friend istream& operator>>(istream& in, Vector& other);
        friend ostream& operator<<(ostream& out, const Vector& other);
        Vector& operator=(const Vector& other);
    private:
        int *v;
        int dim;
};

#endif //VECTOR_H
