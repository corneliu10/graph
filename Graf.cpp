#include <iostream>
#include <cstring>
#include "Graf.h"

/////GRAF
Graf::Graf() {
}

Graf::Graf(int nrNoduri) : nrNoduri(nrNoduri) {
}

Graf::~Graf() {

}

Vector Graf::DFS(int nod) {
    bool *visited = new bool[nrNoduri+1];
    Vector dfsRes;

    for(int i=0; i<=nrNoduri; ++i)
        visited[i] = false;

    DFSUtils(nod, visited, dfsRes);
    cout<<"\n";

    delete[] visited;
    return dfsRes;
}

Lista Graf::componenteConexe() {
    Lista compConexe;
    Vector comp;
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

bool Graf::conexitate() {
    Lista compConexe = componenteConexe();
    if(compConexe.size() > 1)
        return false;
    else
        return true;
}



/////GRAF NEORIENTAT
GrafNeorientat::GrafNeorientat() : Graf() {
}

GrafNeorientat::GrafNeorientat(int nrNoduri, Lista list) : Graf(nrNoduri) {
    listAdiacenta = list;
}

GrafNeorientat::~GrafNeorientat() {
}

istream& operator>>(istream& in, GrafNeorientat& other) {
    in>>other.listAdiacenta;
    other.nrNoduri = other.listAdiacenta.size();

    return in;
}

ostream& operator<<(ostream& out,const GrafNeorientat& other) {
    //out<<"Nr. noduri: "<<other.nrNoduri<<"\n";
    out<<other.listAdiacenta;

    return out;
}

GrafNeorientat& GrafNeorientat::operator=(const GrafNeorientat& other) {
    nrNoduri = other.nrNoduri;
    listAdiacenta = other.listAdiacenta;

    return *this;
}

void GrafNeorientat::DFSUtils(int nod, bool *visited, Vector& dfsRes) {
    visited[nod] = true;

    cout<<nod<<" ";
    dfsRes.push_back(nod);

    for(int i=0; i<listAdiacenta[nod].size(); ++i)
        if(!visited[(listAdiacenta[nod])[i]])
            DFSUtils((listAdiacenta[nod])[i], visited, dfsRes);
}

void GrafNeorientat::BFS(int nod) {
    int queue[10001],front=0,back=0; //TODO: implement queue class
    bool *visited = new bool[nrNoduri + 1];

    for(int i=0; i<=nrNoduri; ++i)
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

GrafNeorientat GrafNeorientat::operator+(const GrafNeorientat& other) {
    Lista listCombined = listAdiacenta;
    Matrice matrix(nrNoduri);

    for(int i=0; i<listAdiacenta.size(); ++i)
        for(int j=0; j<listAdiacenta[i].size(); ++j)
            matrix.addEdge(i, (listAdiacenta[i])[j]);

    for(int i=0; i<other.listAdiacenta.size(); ++i)
        for(int j=0; j<other.listAdiacenta[i].size(); ++j)
            if(!matrix(i, (other.listAdiacenta[i])[j])) {
                listCombined[i].push_back((other.listAdiacenta[i])[j]);
                matrix.addEdge(i, (other.listAdiacenta[i])[j]);
            }

    return GrafNeorientat(nrNoduri, listCombined);
}




/////GRAF ORIENTAT
GrafOrientat::GrafOrientat() : Graf() {

}

GrafOrientat::GrafOrientat(int nrNoduri, Matrice matrix) : Graf(nrNoduri) {
    matriceAdiacenta = matrix;
}

GrafOrientat::~GrafOrientat() {
}

istream& operator>>(istream& in, GrafOrientat& other) {
    in>>other.matriceAdiacenta;
    other.nrNoduri = other.matriceAdiacenta.size();
    
    return in;
}

ostream& operator<<(ostream& out,const GrafOrientat& other) {
    out<<"Nr. nodes: "<<other.nrNoduri<<"\n";
    out<<other.matriceAdiacenta;

    return out;
}

GrafOrientat& GrafOrientat::operator=(const GrafOrientat& other) {
    nrNoduri = other.nrNoduri;
    matriceAdiacenta = other.matriceAdiacenta;

    return *this;
}

void GrafOrientat::DFSUtils(int nod, bool *visited, Vector& dfsRes) {
    visited[nod] = true;

    cout<<nod<<" ";
    dfsRes.push_back(nod);

    for(int i=0; i<nrNoduri; ++i)
        if(matriceAdiacenta(nod, i)==1 && !visited[i])
            DFSUtils(i, visited, dfsRes);
}

void GrafOrientat::BFS(int nod) {
    int queue[10001],front=0,back=0; //TODO: implement queue class
    bool visited[nrNoduri + 1];

    for(int i=0; i<=nrNoduri; ++i)
        visited[i] = false;

    queue[back++] = nod;

    while(front < back) {
        int nod = queue[front];
        front = (front + 1) % 10000;

        cout<<nod<<" ";
        visited[nod] = true;
        for(int i=0; i<nrNoduri; ++i)
            if(matriceAdiacenta(nod, i)==1 && !visited[i]) {
                queue[back] = i;
                back = (back + 1) % 10000;
            }
    }

    cout<<"\n";
}

GrafOrientat GrafOrientat::operator+(const GrafOrientat& other) {
    Matrice finalMatrix(nrNoduri);

    for(int i=0; i<nrNoduri; ++i)
        for(int j=0; j<nrNoduri; ++j)
            if(this->matriceAdiacenta(i, j)==1)
                finalMatrix.addEdge(i, j);

    for(int i=0; i<nrNoduri; ++i)
        for(int j=0; j<nrNoduri; ++j)
            if(other.matriceAdiacenta(i, j)==1)
                finalMatrix.addEdge(i, j);

    return GrafOrientat(nrNoduri, finalMatrix);
}

