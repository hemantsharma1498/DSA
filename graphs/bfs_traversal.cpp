#include<queue>
#include <iostream>
using namespace std;



void print(int**edges, int n, int sv, bool*visited){
	if(n==0) return;
    queue<int> l_order;
    l_order.push(sv);
    visited[sv]=true;
    
    while(!l_order.empty()){
        
        int current=l_order.front();
        l_order.pop();
        cout<<current<<" ";
        
        for(int i=0;i<n;i++){
            if(current==i) continue;
            
            if(edges[current][i]==1&&!visited[i]){
                l_order.push(i);
                visited[i]=true;
            }
        }
        
    }
	
  
    
}

int main() {
    int n, e;
    cin>>n>>e;
    
    int**edges=new int*[n];
    
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    
    for(int i=0;i<e;i++){
        int f, s;
        
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
        
    }
    
    if(n==0) return 0;
    
    
    if(e==0){
        for(int i=0;i<n;i++){
            cout<<i<<" ";
        }
        return 0;
    }
    
    
    
    bool*visited=new bool[n];
    
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0; i<n; i++){
        if(visited[i]==false){
            visited[i]=1;
           print(edges, n, i, visited);
        }
    }
	
}
