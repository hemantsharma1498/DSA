//For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
//If the expression can't be balanced, return -1.i


#include<string.h>
#include<stack>
int countBracketReversals(string input) {
	// Write your code here
    
    int len=input.length();
    
    if(len==0){
        return 0;
    }
    else if(len%2!=0){
        return -1;
    }
    
    stack<char>s;

    
    for(int i=0;i<len;i++){
        char inp=input[i];
        
        if(input[i]=='{'){
            s.push(inp);
        }
        else {
            if(!s.empty()&&s.top()=='{'){
            s.pop();
        	}
        	else s.push(inp);
        }
    }
    
    char c1, c2;
    int count=0;
    
    
    while(!s.empty()){
        c1=s.top();
        s.pop();
        c2=s.top(); 
        if(c1==c2) count++;
        else if(c1!=c2) count+=2;
        s.pop();
        
    }
    
    
    return count;
    
    
}
