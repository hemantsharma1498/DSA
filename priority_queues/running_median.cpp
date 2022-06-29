//You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
//Print only the integer part of the median.

#include<queue>
void findMedian(int *arr, int n)
{
    priority_queue<int>smaller_half;
    priority_queue<int, vector<int>, greater<int>> larger_half;
    
    
    
    for(int i=0;i<n;i++){
        if(larger_half.empty()&&smaller_half.empty()){
			larger_half.push(arr[i]);
        }
        else{    
            if(arr[i]<larger_half.top()) smaller_half.push(arr[i]);
            else larger_half.push(arr[i]);
        }
        
        if(int(larger_half.size()-smaller_half.size())>1){
            smaller_half.push(larger_half.top()); larger_half.pop();
        }
        else if(int(smaller_half.size()-larger_half.size())>1){
            larger_half.push(smaller_half.top()); smaller_half.pop();
        }
        
        
        int size=larger_half.size()+smaller_half.size();
        
        if(size%2==0){
            cout<<(larger_half.top()+smaller_half.top())/2<<" ";
        }
        else{
            if(larger_half.size()>smaller_half.size()){
                cout<<larger_half.top()<<" ";
            }
            else cout<<smaller_half.top()<<" ";
        }
        
    }
}
