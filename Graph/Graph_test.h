#ifndef GRAPH_TEST_H_INCLUDED
#define GRAPH_TEST_H_INCLUDED
#define INFINITY 1000000
#include <queue>

class option
{
private:
    Graph *G;
public:
// Start with some implementations for the abstract functions
    option(Graph *g)
    {
        G = g;
    }


    void DFS(int v, void (*PreVisit)(int v), void (*PostVisit)(int v), void (*Visiting)(int v))   // Depth first search
    {   
        PreVisit(v);
        G->setMark(v,VISITED);
        Visiting(v);
        for(int w = G->first(v) ; w < G->n() ; w = G->next(v,w))
        {
            if(G->getMark(w) == UNVISITED)
            {
                DFS(w,PreVisit,PostVisit,Visiting);
            }
        }
        PostVisit(v);
    }

    void BFS(int start, void (*PreVisit)(int v), void (*PostVisit)(int v), void (*Visiting)(int v))
    {
        queue<int> Q;
        Q.push(start);
        PreVisit(start);
        G->setMark(start,VISITED);
        while( !Q.empty())
        {
            int v = Q.front();
            Q.pop();
            Visiting(v);
            for(int w = G->first(v) ; w < G->n() ; w = G->next(v,w))
            {
                if(G->getMark(w) == UNVISITED)
                {
                    PreVisit(w);
                    Q.push(w);
                    G->setMark(w,VISITED);
                }
            }
            PostVisit(v);
        }

    }

    void Dijkstra1(long double* D)
    {
        for(int i = 0 ; i < G->n() ; i++)
        {
            int v = 0;
            v = minVertex(D);
            if(D[v] == INFINITY)return ;
            G->setMark(v,VISITED);
            for(int w = G->first(v) ; w < G->n() ; w = G->next(v,w))
            {
                if(D[w]  > D[v] * ( 100.0 - G->weight(v,w)) * 0.01)
                {
                    D[w] = D[v] * ( 100.0 - G->weight(v,w)) * 0.01;
                }
            } 
        }

    }

    int minVertex(long double* D)   // Find min cost vertex
    {
        int i, v = -1;
        // Initialize v to some unvisited vertex
        for (i = 0; i < G->n(); i++)
            if (G->getMark(i) == UNVISITED)
            {
                v = i;
                break;
            }
        for (i++; i < G->n(); i++) // Now find smallest D value
            if ((G->getMark(i) == UNVISITED) && (D[i] < D[v]))
                v = i;
        return v;
    }

    void  AddEdgetoMST (int v1, int v2)
    {
        cout << "Add edge " << v1 << " to " << v2 << "\n";
    }
    
};

#endif // GRAPH_TEST_H_INCLUDED
