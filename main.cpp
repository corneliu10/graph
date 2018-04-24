#include <iostream>
#include <fstream>
#include "Matrice.h"
#include "Vector.h"
#include "Lista.h"
#include "Graf.h"

using namespace std;

int main()
{
    ifstream f("/Users/cdumitru/Desktop/graph/data.in");
    
    Matrice M;
    f>>M;
    cout<<M<<"\n";

    Vector V;
    f>>V;
    cout<<V<<"\n";

    Lista L;
    f>>L;
    cout<<L<<"\n";
    
    GrafNeorientat G,G1;
    f>>G;
    cout<<G<<"\n";
    
    Graf *g = new GrafNeorientat(G);
    
    g->BFS(0);
    G.DFS(2);
    
    cout<<"Componente conexe:\n";
    G.componenteConexe();
    
    cout<<"\nConexitate:\n";
    cout<<g->conexitate()<<"\n";
    
    f>>G1;
    cout<<G+G1<<"\n";
    
    GrafOrientat G2(M.size(), M),G3;
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
    
    return 0;
}
