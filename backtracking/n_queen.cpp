#include<bits/stdc++.h>
using namespace std;

bool is_valid(int board[][9], int row, int col, int num){
    for(int i=0;i<9;i++){
        if(board[i][col]==num) return false;
        if(board[row][i]==num) return false;
    }
    
    
    int rstart=row-(row%3);
    int cstart=col-(col%3);
    
    for(int i=rstart;i<rstart+3;i++){
        for(int j=cstart;j<cstart+3;j++){
            if(board[i][j]==num) return false;
        }
    }
    
    return true;
}


bool helper(int board[][9], int row, int col){
    if(row==9) return true;
    
    if(col==9) return helper(board, row+1, 0);
    
    if(board[row][col]!=0) return helper(board, row, col+1);
    
    for(int i=1;i<=9;i++){
        if(is_valid(board, row, col, i)){
            board[row][col]=i;
            if(helper(board, row, col+1)){
                return true;
            }
        }
        board[row][col]=0;
    }
    
    return false;
}




int main(){
    
    int board[9][9];
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
        }
    }
    
    if(helper(board, 0, 0)){
        cout<<"true";
    }
    else cout<<"false";
    
    return 0;
}
