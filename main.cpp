#include <iostream>
#include <fstream>
#include "MatriceInternal.h"
#include "VectorInternal.h"
#include "ListaInternal.h"
#include "GrafInternal.h"

using namespace std;

int main()
{
    ifstream f("D:\\POO\\Tema 2\\data.in");

    Matrice<bool> M;
    f>>M;
    cout<<M<<"\n";


    Vector<int> V;
    f>>V;
    cout<<V<<"\n";

    Lista<int> L;
    f>>L;
    cout<<L<<"\n";

    GrafNeorientat<int> G,G1;
    f>>G;
    cout<<G<<"\n";

    Graf<int> *g = new GrafNeorientat<int>(G);

    g->BFS(0);
    G.DFS(2);

    cout<<"Componente conexe:\n";
    G.componenteConexe();

    cout<<"\nConexitate:\n";
    cout<<g->conexitate()<<"\n";

    f>>G1;
    cout<<G+G1<<"\n";

    cout<<(G == G) <<"\n\n";

    cout<<"Vector tati: "<<G.getDads(0)<<"\n";

    GrafOrientat<int> G2(M.size(), M),G3;
    cout<<G2<<"\n";
    g = &G2;

    g->BFS(3);
    G2.DFS(2);

    cout<<"Componente conexe:\n";
    G2.componenteConexe();

    cout<<"\nConexitate:\n";
    cout<<g->conexitate()<<"\n";

    f>>G3;
    cout<<G3+G2<<"\n";

    cout<<(G2 == G2)<<"\n";

    cout<<"Vector tati: "<<G2.getDads(0)<<"\n";

    return 0;
}
