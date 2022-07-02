

int balancedBTs(int n){
    int arr[n+1];
    
    arr[0]=1;
    arr[1]=1;
    
    int mod=(int)(pow(10, 9))+7;
    
    for(int i=2;i<n+1;i++){
        int temp1=(int)(((long)(arr[i-1])*arr[i-1])%mod);
        int temp2=(int)(((long)(arr[i-2])*arr[i-1]*2)%mod);
       	arr[i]=(temp1+temp2)%mod;
    }
    
    return arr[n];
}
