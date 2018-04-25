#ifndef GRAF_H
#define GRAF_H
#include "Matrice.h"
#include "Lista.h"

using namespace std;

template <class T>
class Graf {
    public:
        Graf();
        Graf(int nrNoduri);
        virtual ~Graf();
        Vector<T> DFS(int nod);
        Lista<T> componenteConexe();
        bool conexitate();
        virtual void BFS(int nod) = 0;
        Vector<T> getDads(int nod);

    protected:
        virtual void DFSUtils(int nod, bool *visited, Vector<T>& dfsRes) = 0;
        virtual void getDadsUtils(int dad, int nod, bool *visited, Vector<T>& dads) = 0;
        int nrNoduri;
};

template <class T>
class GrafNeorientat : public Graf<T> {
    public:
        GrafNeorientat();
        GrafNeorientat(int nrNoduri, Lista<T> list);
        void BFS(int nod);
        template <class U> friend istream& operator>>(istream& in, GrafNeorientat<U>& other);
        template <class U> friend ostream& operator<<(ostream& out, const GrafNeorientat<U>& other);
        bool operator==(const GrafNeorientat<T>& other);
        bool operator!=(const GrafNeorientat<T>& other);
        GrafNeorientat<T>& operator=(const GrafNeorientat<T>& other);
        GrafNeorientat<T> operator+(const GrafNeorientat<T>& other);
        ~GrafNeorientat();
    private:
        void getDadsUtils(int dad, int nod, bool *visited, Vector<T>& dads);
        void DFSUtils(int nod, bool *visited, Vector<T>& dfsRes);
        Lista<T> listAdiacenta;
};

template <class T>
class GrafOrientat : public Graf<T> {
    public:
        GrafOrientat();
        GrafOrientat(int nrNoduri, Matrice<T> matrix);
        void BFS(int nod);
        template <class U> friend istream& operator>>(istream& in, GrafOrientat<U>& other);
        template <class U> friend ostream& operator<<(ostream& out, const GrafOrientat<U>& other);
        bool operator==(const GrafOrientat<T>& other);
        bool operator!=(const GrafOrientat<T>& other);
        GrafOrientat<T>& operator=(const GrafOrientat<T>& other);
        GrafOrientat<T> operator+(const GrafOrientat<T>& other);
        ~GrafOrientat();
    private:
        void getDadsUtils(int dad, int nod, bool *visited, Vector<T>& dads);
        void DFSUtils(int nod, bool *visited, Vector<T>& dfsRes);
        Matrice<T> matriceAdiacenta;
};

#endif // GRAF_H
