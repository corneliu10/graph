#include <iostream>
#include <cstring>
#include "Graf.h"

/////GRAF
template <class T>
Graf<T>::Graf() {
}

template <class T>
Graf<T>::Graf(int nrNoduri) : nrNoduri(nrNoduri) {
}

template <class T>
Graf<T>::~Graf() {

}

template <class T>
Vector<T> Graf<T>::DFS(int nod) {
    bool *visited = new bool[nrNoduri+1];
    Vector<T> dfsRes;

    for(int i=0; i<=nrNoduri; ++i)
        visited[i] = false;

    DFSUtils(nod, visited, dfsRes);
    cout<<"\n";

    delete[] visited;
    return dfsRes;
}

template <class T>
Lista<T> Graf<T>::componenteConexe() {
    Lista<T> compConexe;
    Vector<T> comp;
    bool *visited = new bool[nrNoduri + 1];
    for(int i=0; i<=nrNoduri; ++i)
        visited[i] = false;

    for(int i=0; i<nrNoduri; ++i)
        if(!visited[i]) {
            DFSUtils(i, visited, comp);
            compConexe.push_back(comp);

            comp.clear();
            cout<<"\n";
        }

    delete[] visited;
    return compConexe;
}

template <class T>
bool Graf<T>::conexitate() {
    Lista<T> compConexe = componenteConexe();
    if(compConexe.size() > 1)
        return false;
    else
        return true;
}



/////GRAF NEORIENTAT
template <class T>
GrafNeorientat<T>::GrafNeorientat() : Graf<T>() {
}

template <class T>
GrafNeorientat<T>::GrafNeorientat(int nrNoduri, Lista<T> list) : Graf<T>(nrNoduri) {
    listAdiacenta = list;
}

template <class T>
GrafNeorientat<T>::~GrafNeorientat() {
}

template <class T>
istream& operator>>(istream& in, GrafNeorientat<T>& other) {
    in>>other.listAdiacenta;
    other.nrNoduri = other.listAdiacenta.size();

    return in;
}

template <class T>
ostream& operator<<(ostream& out,const GrafNeorientat<T>& other) {
    //out<<"Nr. noduri: "<<other.nrNoduri<<"\n";
    out<<other.listAdiacenta;

    return out;
}

template <class T>
GrafNeorientat<T>& GrafNeorientat<T>::operator=(const GrafNeorientat<T>& other) {
    this->nrNoduri = other.nrNoduri;
    listAdiacenta = other.listAdiacenta;

    return *this;
}

template <class T>
bool GrafNeorientat<T>::operator==(const GrafNeorientat<T>& other) {
    Matrice<T> matrix(this->nrNoduri);

    for(int i=0; i<listAdiacenta.size(); ++i)
        for(int j=0; j<listAdiacenta[i].size(); ++j)
            matrix.addEdge(i, (listAdiacenta[i])[j]);

    for(int i=0; i<other.listAdiacenta.size(); ++i)
        for(int j=0; j<other.listAdiacenta[i].size(); ++j)
            if(matrix(i, (other.listAdiacenta[i])[j]) == 0) return false;

    return true;
}

template <class T>
bool GrafNeorientat<T>::operator!=(const GrafNeorientat<T>& other) {
    if(*this == other) return 0;

    return 1;
}

template <class T>
void GrafNeorientat<T>::DFSUtils(int nod, bool *visited, Vector<T>& dfsRes) {
    visited[nod] = true;

    cout<<nod<<" ";
    dfsRes.push_back(nod);

    for(int i=0; i<listAdiacenta[nod].size(); ++i)
        if(!visited[(listAdiacenta[nod])[i]])
            DFSUtils((listAdiacenta[nod])[i], visited, dfsRes);
}

template <class T>
void GrafNeorientat<T>::BFS(int nod) {
    int queue[10001],front=0,back=0; //TODO: implement queue class
    bool *visited = new bool[this->nrNoduri + 1];

    for(int i=0; i<=this->nrNoduri; ++i)
        visited[i] = false;

    queue[back++] = nod;
    visited[nod] = true;

    while(front < back) {
        int nod = queue[front];
        front = (front + 1) % 10000;

        cout<<nod<<" ";
        for(int i=0; i<listAdiacenta[nod].size(); ++i)
            if(!visited[(listAdiacenta[nod])[i]]) {
                queue[back] = (listAdiacenta[nod])[i];
                visited[queue[back]] = true;
                back = (back + 1) % 10000;
            }
    }

    cout<<"\n";
    delete[] visited;
}

template <class T>
GrafNeorientat<T> GrafNeorientat<T>::operator+(const GrafNeorientat<T>& other) {
    Lista<T> listCombined = listAdiacenta;
    Matrice<T> matrix(this->nrNoduri);

    for(int i=0; i<listAdiacenta.size(); ++i)
        for(int j=0; j<listAdiacenta[i].size(); ++j)
            matrix.addEdge(i, (listAdiacenta[i])[j]);

    for(int i=0; i<other.listAdiacenta.size(); ++i)
        for(int j=0; j<other.listAdiacenta[i].size(); ++j)
            if(!matrix(i, (other.listAdiacenta[i])[j])) {
                listCombined[i].push_back((other.listAdiacenta[i])[j]);
                matrix.addEdge(i, (other.listAdiacenta[i])[j]);
            }

    return GrafNeorientat(this->nrNoduri, listCombined);
}




/////GRAF ORIENTAT
template <class T>
GrafOrientat<T>::GrafOrientat() : Graf<T>() {

}

template <class T>
GrafOrientat<T>::GrafOrientat(int nrNoduri, Matrice<T> matrix) : Graf<T>(nrNoduri) {
    matriceAdiacenta = matrix;
}

template <class T>
GrafOrientat<T>::~GrafOrientat() {
}

template <class T>
istream& operator>>(istream& in, GrafOrientat<T>& other) {
    in>>other.matriceAdiacenta;
    other.nrNoduri = other.matriceAdiacenta.size();

    return in;
}

template <class T>
ostream& operator<<(ostream& out,const GrafOrientat<T>& other) {
    out<<"Nr. nodes: "<<other.nrNoduri<<"\n";
    out<<other.matriceAdiacenta;

    return out;
}

template <class T>
GrafOrientat<T>& GrafOrientat<T>::operator=(const GrafOrientat<T>& other) {
    this->nrNoduri = other.nrNoduri;
    matriceAdiacenta = other.matriceAdiacenta;

    return *this;
}

template <class T>
void GrafOrientat<T>::DFSUtils(int nod, bool *visited, Vector<T>& dfsRes) {
    visited[nod] = true;

    cout<<nod<<" ";
    dfsRes.push_back(nod);

    for(int i=0; i<this->nrNoduri; ++i)
        if(matriceAdiacenta(nod, i)==1 && !visited[i])
            DFSUtils(i, visited, dfsRes);
}

template <class T>
void GrafOrientat<T>::BFS(int nod) {
    int queue[10001],front=0,back=0; //TODO: implement queue class
    bool visited[this->nrNoduri + 1];

    for(int i=0; i<=this->nrNoduri; ++i)
        visited[i] = false;

    queue[back++] = nod;

    while(front < back) {
        int nod = queue[front];
        front = (front + 1) % 10000;

        cout<<nod<<" ";
        visited[nod] = true;
        for(int i=0; i<this->nrNoduri; ++i)
            if(matriceAdiacenta(nod, i)==1 && !visited[i]) {
                queue[back] = i;
                back = (back + 1) % 10000;
            }
    }

    cout<<"\n";
}

template <class T>
GrafOrientat<T> GrafOrientat<T>::operator+(const GrafOrientat<T>& other) {
    Matrice<T> finalMatrix(this->nrNoduri);

    for(int i=0; i<this->nrNoduri; ++i)
        for(int j=0; j<this->nrNoduri; ++j)
            if(this->matriceAdiacenta(i, j)==1)
                finalMatrix.addEdge(i, j);

    for(int i=0; i<this->nrNoduri; ++i)
        for(int j=0; j<this->nrNoduri; ++j)
            if(other.matriceAdiacenta(i, j)==1)
                finalMatrix.addEdge(i, j);

    return GrafOrientat(this->nrNoduri, finalMatrix);
}

template <class T>
bool GrafOrientat<T>::operator==(const GrafOrientat<T>& other) {
    for(int i=0; i<matriceAdiacenta.size(); ++i)
        for(int j=0; j<matriceAdiacenta.size(); ++j)
            if(this->matriceAdiacenta(i, j) != other.matriceAdiacenta(i, j) ) return false;

    return true;
}

template <class T>
bool GrafOrientat<T>::operator!=(const GrafOrientat<T>& other) {
    if(*this == other) return 0;

    return 1;
}

template <class T>
void GrafOrientat<T>::getDadsUtils(int dad, int nod, bool *visited, Vector<T>& dads) {
    visited[nod] = true;
    dads[nod] = dad;

    for(int i=0; i<this->nrNoduri; ++i)
        if(matriceAdiacenta(nod, i)==1 && !visited[i])
            getDadsUtils(nod, i, visited, dads);
}

template <class T>
Vector<T> GrafOrientat<T>::getDads(int nod) {
    bool *visited = new bool[this->nrNoduri+1];
    Vector<T> dads(this->nrNoduri);

    for(int i=0; i<=this->nrNoduri; ++i)
        visited[i] = false;

    delete[] visited;
    getDadsUtils(-1, nod, visited, dads);
    return dads;
}
