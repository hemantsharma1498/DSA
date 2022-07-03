//Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.



int minCount(int n)
{
	int arr[n+1];
    
    
    arr[0]=0;
    arr[1]=1;
    
    for(int i=2;i<=n;i++){
    	int mini=INT_MAX;
		        
        for(int j=1;j*j<=i;j++){
            
            mini=min(mini, arr[i-j*j]);
        }
        arr[i]=mini+1;
    }
    
    return arr[n];
    
}
