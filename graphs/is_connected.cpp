//Given an undirected graph G(V,E), check if the graph G is connected graph or not.


#include <iostream>
using namespace std;

void dfs(int** graph, int n, int sv, bool* visited){
    visited[sv]=true;
    
    for(int i=0;i<n;i++){
        if(i==sv) continue;
        
        if(graph[sv][i]==1&&!visited[i]){
            visited[i]=true;
            dfs(graph, n, i, visited); 
        }
    }
    
    return;
}

bool connected(int**graph, int n){
    bool*visited1=new bool[n];
    
    
    for(int i=0;i<n;i++){
        visited1[i]=false;
    }
    

    
    dfs(graph, n, 0, visited1);
    
    
    for(int i=0;i<n;i++){
        if(!visited1[i]){
            return false;
        }
    }
    
    return true;
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
    
    if(connected(graph, n)){
        cout<<"true";
        return 0;
    }
    
    cout<<"false";
    
}
