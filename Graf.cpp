#include <iostream>
#include <cstring>
#include "Graf.h"

/////GRAF
Graf::Graf(int nrNoduri) : nrNoduri(nrNoduri) {
}

Graf::~Graf() {
    
}

Vector Graf::DFS(int nod) {
    bool *visited = new bool[nrNoduri+1];
    Vector dfsRes;

    for(int i=1; i<=nrNoduri; ++i)              
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
    for(int i=1; i<=nrNoduri; ++i)
        visited[i] = false;

    for(int i=1; i<nrNoduri; ++i)
        if(!visited[i]) {
            DFSUtils(i, visited, comp);
            compConexe.push_back(comp);

            comp.clear();
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
GrafNeorientat::GrafNeorientat(int nrNoduri, Lista list) : Graf(nrNoduri) {
    listAdiacenta = list;  
}

GrafNeorientat::~GrafNeorientat() {
}

istream& operator>>(istream& in, GrafNeorientat& other) {
    in>>other.nrNoduri;
    in>>other.listAdiacenta;

    return in;
}

ostream& operator<<(ostream& out,const GrafNeorientat& other) {
    out<<other.nrNoduri<<"\n";
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

    for(int i=1; i<=nrNoduri; ++i)
        visited[i] = false;

    queue[back++] = nod;

    while(front < back) {
        int nod = queue[front];
        front = (front + 1) % 10000;

        cout<<nod<<" ";
        visited[nod] = true;
        for(int i=0; i<listAdiacenta[nod].size(); ++i)
            if(!visited[(listAdiacenta[nod])[i]]) {
                back = (back + 1) % 10000;
                queue[back] = (listAdiacenta[nod])[i];
            }
    }

    delete[] visited;
}

GrafNeorientat GrafNeorientat::operator+(const GrafNeorientat& other) {
    Lista listCombined = listAdiacenta;
    Matrice matrix;

    for(int i=1; i<=listAdiacenta.size(); ++i)
        for(int j=0; j<listAdiacenta[i].size(); ++j)
            matrix.addEdge(i, (listAdiacenta[i])[j]);

    for(int i=1; i<=other.listAdiacenta.size(); ++i)
        for(int j=0; j<other.listAdiacenta[i].size(); ++j)
            if(!matrix(i, (listAdiacenta[i])[j])) {
                listCombined[i].push_back((listAdiacenta[i])[j]);
                matrix.addEdge(i, (listAdiacenta[i])[j]);
            }

    return GrafNeorientat(nrNoduri, listCombined);
}




/////GRAF ORIENTAT
GrafOrientat::GrafOrientat(int nrNoduri, Matrice matrix) : Graf(nrNoduri) {
    matriceAdiacenta = matrix;
}

GrafOrientat::~GrafOrientat() {
}

istream& operator>>(istream& in, GrafOrientat& other) {
    in>>other.nrNoduri;
    in>>other.matriceAdiacenta;

    return in;
}

ostream& operator<<(ostream& out,const GrafOrientat& other) {
    out<<other.nrNoduri<<"\n";
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

    for(int i=1; i<=nrNoduri; ++i)
        if(matriceAdiacenta(nod, i)==1 && !visited[i])
            DFSUtils(i, visited, dfsRes);
}

void GrafOrientat::BFS(int nod) {
    int queue[10001],front=0,back=0; //TODO: implement queue class
    bool visited[nrNoduri + 1];

    for(int i=1; i<=nrNoduri; ++i)
        visited[i] = false;

    queue[back++] = nod;

    while(front < back) {
        int nod = queue[front];
        front = (front + 1) % 10000;

        cout<<nod<<" ";
        visited[nod] = true;
        for(int i=1; i<=nrNoduri; ++i)
            if(matriceAdiacenta(nod, i)==1 && !visited[i]) {
                back = (back + 1) % 10000;
                queue[back] = i;
            }
    }
}

GrafOrientat GrafOrientat::operator+(const GrafOrientat& other) {
    Matrice finalMatrix(nrNoduri);

    for(int i=1; i<=nrNoduri; ++i)
        for(int j=1; j<=nrNoduri; ++j)
            if(this->matriceAdiacenta(i, j)==1)
                finalMatrix.addEdge(i, j);

    for(int i=1; i<=nrNoduri; ++i)
        for(int j=1; j<=nrNoduri; ++j)
            if(other.matriceAdiacenta(i, j)==1)
                finalMatrix.addEdge(i, j);

    return GrafOrientat(nrNoduri, finalMatrix);
}

