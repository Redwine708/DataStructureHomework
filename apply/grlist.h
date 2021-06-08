#ifndef GRLIST
#define GRLIST

#include<cstdio>
#include<ctype.h>
#include<assert.h>

const int UNVISITED = 0;
const int VISITED = 0;

#include "link.h"
#include "llist.h"

#include "graph.h"

class Edge
{
    private:
        int vert,wt;
    public:
        Edge()
        {
            vert = -1;
            wt = -1;
        }
        Edge(int v,int w)
        {
            vert = v;
            wt = w;
        }
        int vertex() const
        {
            return vert;
        }
        int weight()const{
            return wt;
        }
};

class Graphl : public Graph{
    private:
        List<Edge>** vertex;
        int numVertex,numEdge;
        int * mark;

    public:
        Graphl(int numVert)
        {
            Init(numVert);
        }
        ~Graphl()
        {
            delete []mark;
            for(int i = 0 ; i < numVertex ; i ++)
            delete [] vertex[i];
            delete [] vertex;
        }
        void Init(int n)
        {
            int i ;
            numVertex = n;
            numEdge = 0;
            mark = new int[n];
            for(int i = 0 ; i < numVertex ; i++)
            mark[i] = UNVISITED;
            vertex = (List<Edge>**)new List<Edge>*[numVertex];
            for(int i = 0 ; i < numVertex ; i ++)
                vertex[i] = new LList<Edge>();
        }

        int n()const
        {
            return numVertex;
        }

        int e()const{
            return numEdge;
        }

        int first(int v)
        {
            if(vertex[v]->length() == 0)
                return numVertex;
            vertex[v]->moveToStart();
            Edge it = vertex[v]->getValue();
            return it.vertex();
        }

        int next(int v , int w)
        {
            Edge it;
            if(isEdge(v,w))
            {
                if((vertex[v]->currPos() + 1) < 
                        vertex[v]->length())
                {

                }
            }
        }
};

#endif 