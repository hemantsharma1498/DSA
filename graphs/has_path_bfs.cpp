//Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.

#include <iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>

vector<int>* getPath(int **edges,int n,int v1,int v2){
    
      bool* visited=new bool[n];
    for(int i=0;i<n;i++){
    	visited[i]=false;
	}
	if(v1==v2){
		vector<int>* v=new vector<int>(n);
		v->push_back(v1);
		return v;
	}
	queue<int> q;
	q.push(v1);
	visited[v1]=true;
	unordered_map<int,int> m;
 	m[v1]=-1;
	bool gotv2=false;
	while(!q.empty() && !gotv2){
		int curr=q.front();
		q.pop();
		for(int i=0;i<n;i++){
			if(i==curr) continue;
			if(edges[curr][i]==1 && !visited[i]){
				visited[i]=true;
				m[i]=curr;
				q.push(i);
				if(i==v2){
					gotv2=true;
					break;
				}
			}
		}
	}
	vector<int>* v=new vector<int>();
	if(gotv2){
		for(int i=v2;i!=-1;){
			v->push_back(i);
			i=m[i];
		}
		return v;
	} 
	else return NULL;
}

int main() {
    
    int n;//number of vertices
	int e;//number of edges
	cin >> n >> e;
	//matrix which will store all the edges 
	//like 0 or 1 (0 for no edge is not ther and 1 for there
	//like this matrix is for between what 2 elements edge is there
	int **edges = new int*[n];
	for(int i=0;i<n;i++){
		edges[i] = new int[n];
		for(int j=0;j<n;j++){
			edges[i][j] = 0;
		}
	}
	
	// now taking the verices input 
	for(int i=0;i<e;i++){
		int vertex1, vertex2;
		cin>> vertex1 >> vertex2;
		edges[vertex1][vertex2] = 1;// edges between 2 element as true marked
		edges[vertex2][vertex1] = 1;
	}
    
    int v1,v2;
    cin >> v1 >> v2;
    
	vector<int>*ans = getPath(edges,n,v1,v2);
	if(ans!=NULL){
        for(int i=0;i<ans->size();i++){
            cout << ans->at(i) << " ";
        }
    }
    
//	delete visited;
	for(int i=0;i<n;i++){
		delete edges[i];
	}
	delete edges;
}
