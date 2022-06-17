#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
    
	unordered_map<int, int> umap;
	int count=0;
   	
    for(int i=0;i<n;i++){
        umap[arr[i]]++;
    }
   
    if(k==0){
        for(auto x:umap){
            if(umap.size()==1){ 
                count+=((x.second)*(x.second-1))/2;
                return count;
            }
            else{
                if(x.second>1) count++;
            }
            
        }
        
        return count;
    }
    else{

        for(auto x:umap){
            if(umap.count(x.first-k)) count+=x.second*(umap[x.first-k]);
        }


        return count;

    }
}
