//Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
//Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
//Input Format :
//Line 1: Two Integers V and E (separated by space)
//Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)



#include<climits>
#include <iostream>
using namespace std;

int MinVertex(int* cost,bool*visited ,int v)
{
    int min=INT_MAX;
    int vertex=-1;
    for(int i=0 ;i<v ; i++)
        if(!visited[i] && cost[i]<min)
        { min=cost[i] ,vertex=i; }
            
    return vertex;
}
void Dijkstra(int **graph, int v)
{
   bool*visited =new bool[v];
   int * cost = new int[v];
    
    for(int i=0 ;i<v;i++)
    {
		visited[i]=false;
        cost[i]=INT_MAX;
    }
    cost[0]=0;  //satrting from 0;
    
    for(int i=0 ;i<v-1;i++)
    {
       int minvertex= MinVertex(cost,visited,v);
        visited[minvertex]=true;
        for(int j=0 ;j<v;j++)
        {
           if(!visited[j] && graph[minvertex][j] && cost[j] >(graph[minvertex][j] +cost[minvertex]))
               cost[j]=graph[minvertex][j] +cost[minvertex];
        }
    }
    for(int i=0 ;i<v ;i++)
        cout<<i<<" "<< cost[i]<<endl;
    
    delete []visited ;
    delete [] cost;
}
    

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
 int ** graph =new int* [V];
    for(int i=0 ;i<V ;i++)
    {
        graph[i]=new int [V];
        for(int j=0 ;j<V;j++)
            graph[i][j]=0;
    }
    
    for(int i =0 ;i<E ;i++)
    {
     	int s,e,w;
        cin>>s>>e>>w;
        graph[s][e]=w;
        graph[e][s]=w;
    }

    Dijkstra(graph,V);
  return 0;
}
