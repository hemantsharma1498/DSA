#include<bits/stdc++.h>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    
    
    unordered_map<int, int>umap;
    int sum=0, max_length=0;
    
    
 	for(int i=0;i<n;i++){
        sum+=arr[i];
        
        
        if(umap.count(sum)==0){
            umap[sum]=i;
        }
        else{
            int length=i-umap[sum];
            max_length=max(length, max_length);
            
        }
        if(sum==0){
            max_length=max(max_length, i+1);
        }
        
    }
    
	return max_length;
}





