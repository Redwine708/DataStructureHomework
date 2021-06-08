#include "grlist.h"
#include "grmat.h"
#include "Graph_test.h"
#include<iomanip>
#include<iostream>
#include<cstdlib>
using namespace std;
void PreVisit(int v)
{
    cout << "PreVisit vertex " << v << "\n";
}

void PostVisit(int v)
{
    cout << "PostVisit vertex " << v << "\n";
}

void Visiting(int v)
{
    cout << "Visiting vertex " << v << "\n";
}

int main()
{
    Graphl* g;
    int n = 0; 
    cin>>n;
    g = new Graphl( n + 1);
    int m = 0;
    cin>>m;
    for(int i = 0 ; i < m ; i ++ )
    {
        double x,y,z;
        cin>>x>>y>>z;
        g->setEdge(x , y ,z);
        g->setEdge(y ,x ,z);
    }
    option op(g);
    long double* D = new long double[n + 1];
    fill(D, D + n + 1, INFINITY);
    int a,b;
    cin>>a>>b;
    D[a] = -100;
    op.Dijkstra1(D);
    double result = (10000.0 / - D[b] ) * 1000000000;
    cout << fixed<<setprecision(8)<<result / 1000000000 ;

}

