#include<vector>
#include <iostream>
using namespace std;

vector<int>* get_path(int**graph, int n, int start, int end, bool*visited){
    if(start==end){
        vector<int>*path= new vector<int>();
        path->push_back(start);
        return path;
    }
    
    visited[start]=true;
    
    for(int i=0;i<n;i++){
        if(!visited[i]&&graph[start][i]){
        	vector<int>* getpath=get_path(graph, n, i, end, visited);
			if(getpath!=NULL){
                getpath->push_back(start);
    			return getpath;    
                
            }        	
        }
    }
    
    return NULL;
    
}


void bfs(int**graph, int n, int start, int end){
    
    bool* visited=new bool[n];
    
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    
    vector<int>* ans;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
    		ans=get_path(graph, n, start, end, visited);
            if(ans!=NULL)break;
            visited[i]=true;
        }
    }
    
    if(ans==NULL){
        return;
    }
    else{
        for(int i=0;i<ans->size();i++){
            cout<<ans->at(i)<<" ";
        }
    }
    
    return;
}


int main() {
    // Write your code here
    
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
    
    int start, end;
    cin>>start>>end;
    
    bfs(graph, n, start, end);
    
    return 0;
    
    
}
