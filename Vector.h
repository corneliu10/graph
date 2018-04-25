#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

template <class T>
class Vector {
    public:
        Vector();
        Vector(int dim);
        ~Vector();
        Vector(const Vector<T>& other);
        int size() const;
        void setSize(int size);
        void push_back(T nr);
        void clear();
        template <class U> friend istream& operator>>(istream& in, Vector<U>& other);
        template <class U> friend ostream& operator<<(ostream& out, const Vector<U>& other);
        Vector& operator=(const Vector<T>& other);
        T& operator[](int i);
    private:
        T *v;
        int dim;
};

#endif //VECTOR_H
