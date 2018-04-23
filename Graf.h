#ifndef GRAF_H
#define GRAF_H
#include "Matrice.h"
#include "Lista.h"

using namespace std;

class Graf {
    public:
        Graf();
        Graf(int nrNoduri);
        virtual ~Graf();
        Vector DFS(int nod);
        Lista componenteConexe();
        bool conexitate();
        virtual void BFS(int nod) = 0;

    protected:
        virtual void DFSUtils(int nod, bool *visited, Vector& dfsRes) = 0;
        int nrNoduri;
};

class GrafNeorientat : public Graf {
    public:
        GrafNeorientat(int nrNoduri, Lista list);
        void BFS(int nod);
        friend istream& operator>>(istream& in, GrafNeorientat& other);
        friend ostream& operator<<(ostream& out, const GrafNeorientat& other);
        GrafNeorientat& operator=(const GrafNeorientat& other);
        GrafNeorientat operator+(const GrafNeorientat& other);
        ~GrafNeorientat();
    private:
        void DFSUtils(int nod, bool *visited, Vector& dfsRes);
        Lista listAdiacenta;
};

class GrafOrientat : public Graf {
    public:
        GrafOrientat(int nrNoduri, Matrice matrix);
        void BFS(int nod);
        friend istream& operator>>(istream& in, GrafOrientat& other);
        friend ostream& operator<<(ostream& out, const GrafOrientat& other);
        GrafOrientat& operator=(const GrafOrientat& other);
        GrafOrientat operator+(const GrafOrientat& other);
        ~GrafOrientat();
    private:
        void DFSUtils(int nod, bool *visited, Vector& dfsRes);
        Matrice matriceAdiacenta;
};

#endif // GRAF_H
