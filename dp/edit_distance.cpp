//Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
//Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
//1. Delete a character
//2. Replace a character with another one
//3. Insert a character


#include<bits/stdc++.h>


int editDistance(string s1, string s2, int** output){
    int m=s1.size();
    int n=s2.size();
    
    if(s1.size()==0||s2.size()==0){
        return max(s1.size(),s2.size());
    }
    
    if(output[m][n]!=-1) return output[m][n];
    
    if(s1[0]==s2[0]){
        output[m][n]= editDistance(s1.substr(1), s2.substr(1), output);
        return output[m][n];
    }
    else{
        //DELETE
        int option1=1+editDistance(s1, s2.substr(1), output);
        
        //REPLACE
        int option2=1+editDistance(s1.substr(1), s2.substr(1), output);

        //INSERT
        int option3=1+editDistance(s1.substr(1), s2, output);
        
        output[m][n]=min(option1, min(option2, option3));
        return output[m][n];
    }
}


int editDistance(string s1, string s2) {

    int**output=new int*[s1.size()+1];
    
	for(int i=0;i<s1.size()+1;i++){
        output[i]=new int[s2.size()+1];
        for(int j=0;j<s2.size()+1;j++){
            output[i][j]=-1;
        }
    }
    
    return editDistance(s1, s2, output);
    
}
