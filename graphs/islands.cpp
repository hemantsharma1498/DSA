//An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.


#include<bits/stdc++.h>

#include <iostream>
using namespace std;

void dfs(int**graph, int n, int sv, bool*visited){
    visited[sv]=true;
    
    for(int i=0;i<n;i++){
        if(i==sv) continue;
        
        if(!visited[i]&&graph[sv][i]==1){
             dfs(graph, n, i, visited);
        }
    }
    
    return;
}

int check_visited(int**graph, int n){
    bool*visited=new bool[n];
    
    memset(visited, 0, sizeof(visited));
    
    int sum=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
			dfs(graph, n, 0, visited);
            sum++;
        }
    }
  	return sum;
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
    
	return check_visited(graph, n);
    
    
    
}
