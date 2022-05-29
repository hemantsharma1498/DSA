//For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
//A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.

#include<stack>
bool checkRedundantBrackets(string exp) {
    stack<char> s;
    int i=0;
    while(exp[i]!='\0')
    {
        if(exp[i]==')'){
            int count=0;
            while(s.top()!='('){
                count++;
                s.pop();
            }
         s.pop();
            if(count==0||count==1){
                return true;
            }
            i++;
        }
        else{
            s.push(exp[i]);
            i++;
        }
    }
    return false;
}
