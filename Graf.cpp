#include <iostream>
#include <cstring>
#include "Graf.h"

//GRAF NEORIENTAT
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

bool GrafNeorientat::conexitate() {
    int viz[nrNoduri];
    memset(viz, 0, sizeof(viz));

    for()
}

void GrafNeorientat::DFS(int nod, int& viz[]) {
}

//GRAF ORIENTAT
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


