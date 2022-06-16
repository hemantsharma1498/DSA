#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *a, int n) {
    unordered_map<int,int> m;
    pair<int,int>  ans={0,0};
    pair<int,int> temp={0,0};
    for(int i=0;i<n;i++){
        m[a[i]]++;
    } 

    int j=0;
    for(int i=0;i<n;i++){
        if(m[a[i]-1]==0){
            j=0;
            while(m[a[i]+j]>0){
                ++j;
            }
            temp.first=a[i];
            temp.second=j;
        }else{
            continue;

        }
        if(ans.second < temp.second){
            ans.first=temp.first;
            ans.second=temp.second;
            temp={0,0};
        }

    }
    vector<int> output;
    output.push_back(ans.first);
    if(ans.second==1){
        return output;
    }
    output.push_back(ans.first+ans.second-1);
    return output;
}
