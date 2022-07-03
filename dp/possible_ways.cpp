//Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.


#include<vector>
#include<cmath>
int helper(int a, int b, int curr, int currSum){
   
    int result = 0;
    int p = pow(curr, b);
    
    while(p + currSum < a){
        result += helper(a, b, curr + 1, currSum + p);
        curr++;
        p = pow(curr, b);
    }
    if(p + currSum == a) {
        result++;
    }
    
    return result;   
}

int getAllWays(int a, int b) {
    return helper(a, b, 1, 0);
}

