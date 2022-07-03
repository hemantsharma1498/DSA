//An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
//From a cell (i, j), you can move in three directions:
//1. ((i + 1),  j) which is, "down"
//2. (i, (j + 1)) which is, "to the right"
//3. ((i+1), (j+1)) which is, "to the diagonal"
//The cost of a path is defined as the sum of each cell's values through which the route passes.



int minCostPath(int **input, int m, int n)
{
    int arr[m+1][50];
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            arr[i][j]=INT_MAX;
        }
    }
    
    arr[0][0]=input[0][0];
    int j=0;
    for(int i=1;i<m+1;i++){
        int temp=0;
        for(j=0;j<i+1;j++){
            temp=min(temp, min(arr[i+1][j], arr[i][j+1]))+arr[i][j];
        }
        arr[i][j]=temp;
    }
    
    
    
    return arr[m][n];
}
