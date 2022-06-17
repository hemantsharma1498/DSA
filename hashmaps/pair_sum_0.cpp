#include<unordered_map>
int pairSum(int *arr, int n) {
    unordered_map<int, int> check;
    int count=0;
    
    for(int i=0;i<n;i++){
        if(check.find(-1*arr[i])!=check.end()){
            count+=check[-1*arr[i]];
        }
        
        
        
        check[arr[i]]++;
            
        
    }
    
    return count;
}
