//Given an undirected graph G(V,E), find and print all the connected components of the given graph G.


#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(int** graph, int n, int sv, bool*visited, vector<int>*components){
    components->push_back(sv);
    visited[sv]=true;
    
    
    for(int i=0;i<n;i++){        
        if(!visited[i]&&graph[sv][i]==1){
            
            dfs(graph, n, i, visited, components);
        }
    }
}


void visited(int** graph, int n){
    
    bool*visited=new bool[n];
    
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int>*components=new vector<int>();
    		dfs(graph, n, i, visited, components);
            sort(components->begin(), components->end());
            for(int j=0;j<components->size();j++){
                cout<<components->at(j)<<" ";
            }
	        cout<<endl;
			delete components;
        }
    }
    
    
}



int main() {
    
    int n, e;
    cin>>n>>e;
    
    int**graph=new int*[n];
    
    for(int i=0;i<n;i++){
        graph[i]=new int[n];
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
    }
    
    for(int i=0;i<e;i++){
        int f, s;
        cin>>f>>s;
        
        graph[f][s]=1;
        graph[s][f]=1;
    }
    
    visited(graph, n);
}
