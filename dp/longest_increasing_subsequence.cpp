//Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.


int longestIncreasingSubsequence(int* arr, int n) {
    
    int output[n];
    
    output[0]=1;
    
    for(int i=1;i<n;i++){
        output[i]=1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>=arr[i]) continue;
            
            int ans=output[j]+1;
            if(output[i]<ans){
                output[i]=ans;
            }
        }
    }
    
    int best=0;
    
    for(int i=0;i<n;i++){
        if(best<output[i]) best=output[i];
    }
    
    return best;
}
