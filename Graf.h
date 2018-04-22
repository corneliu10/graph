#ifndef GRAF_H
#define GRAF_H
#include "Matrice.h"
#include "Lista.h"

using namespace std;

class Graf {
    public:
        Graf();
        Graf(int nrNoduri);
        ~Graf();
        virtual void BFS() = 0;
        virtual void DFS() = 0;
        virtual bool conexitate() = 0;

    protected:
        int nrNoduri;
};

class GrafNeorientat : public Graf {
    public:
        GrafNeorientat(int nrNoduri, Lista list);
        void BFS();
        void DFS();
        bool conexitate();
        friend istream& operator>>(istream& in, GrafNeorientat& other);
        friend ostream& operator<<(ostream& out, const GrafNeorientat& other);
        GrafNeorientat& operator=(const GrafNeorientat& other);
    private:
        Lista listAdiacenta;
};

class GrafOrientat : public Graf {
    public:
        GrafOrientat(int nrNoduri, Matrice matrix);
        void BFS();
        void DFS();
        bool conexitate();
        friend istream& operator>>(istream& in, GrafOrientat& other);
        friend ostream& operator<<(ostream& out, const GrafOrientat& other);
        GrafOrientat& operator=(const GrafOrientat& other);
    private:
        Matrice matriceAdiacenta;

};

#endif // GRAF_H
