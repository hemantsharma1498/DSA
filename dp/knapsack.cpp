//A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.


int knapsack(int *weights, int *values, int n, int maxWeight)
{
    int **dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[maxWeight+1];
        for(int j=0;j<=maxWeight;j++){
            dp[i][j] = -1;
        }
    }
    
    dp[0][0]=0;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<maxWeight+1;j++){
            
            if(dp[i-1]<maxWeight){
                dp[i][j]=max(val)
            }
        }
    }
}
