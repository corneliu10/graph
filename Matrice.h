#ifndef MATRICE_H
#define MATRICE_H
#include <iostream>
using namespace std;

class Matrice {
    public:
        Matrice();
        Matrice(int length);
        ~Matrice();
        Matrice(const Matrice& other);
        friend ostream& operator<<(ostream& out, const Matrice& other);
        friend istream& operator>>(istream& in, Matrice& other);
        Matrice& operator=(const Matrice& other);
    private:
        int **matrix;
        int matrixLength;
};

#endif //MATRICE_H
