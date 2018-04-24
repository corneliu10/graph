#ifndef MATRICE_H
#define MATRICE_H
#include <iostream>
using namespace std;

class Matrice {
    public:
        Matrice();
        Matrice(int length);
        ~Matrice();
        int size() const;
        Matrice(const Matrice& other);
        void addEdge(int from, int to);
        friend ostream& operator<<(ostream& out, const Matrice& other);
        friend istream& operator>>(istream& in, Matrice& other);
        Matrice& operator= (const Matrice& other);
        int operator()(int x, int y) const;
    private:
        int **matrix;
        int matrixLength;
};

#endif //MATRICE_H
