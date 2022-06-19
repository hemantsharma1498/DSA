//You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
//Time complexity should be O(n * logk) and space complexity should not be more than O(k).

#include<vector>
#include<queue>
vector<int> kSmallest(int arr[], int n, int k) {
    
   	priority_queue<int> pq;
    
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    vector<int> ans;
    for(int i=k;i<n;i++){
       if(arr[i]<pq.top()){
           pq.pop();
           pq.push(arr[i]);
       }
        
    }
    
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
	
    return ans;
        
}
