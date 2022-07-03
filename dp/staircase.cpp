//A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.


#include<vector>

long staircase(int n)
{
	if(n==1||n==0) return 1;
	
    if(n<0) return 0;
    
    
    long steps=staircase(n-1)+staircase(n-2)+staircase(n-3);
    
    return steps;
}


vector helper(int n, )


long staircase(int n){

	vector<int>* arr=new vector<int>();
    
    
    
}
