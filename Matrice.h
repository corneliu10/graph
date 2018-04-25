#ifndef MATRICE_H
#define MATRICE_H
#include <iostream>
using namespace std;

template <class T>
class Matrice {
    public:
        Matrice();
        Matrice(int length);
        ~Matrice();
        int size() const;
        Matrice(const Matrice<T>& other);
        void addEdge(int from, int to);
        template <class U> friend ostream& operator<<(ostream& out, const Matrice<U>& other);
        template <class U> friend istream& operator>>(istream& in, Matrice<U>& other);
        Matrice& operator= (const Matrice<T>& other);
        int operator()(int x, int y) const;
    private:
        T **matrix;
        int matrixLength;
};

#endif //MATRICE_H
