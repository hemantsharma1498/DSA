#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int, int> intersection;
    
	
    for(int i=0;i<n;i++){
        intersection[arr1[i]]++;
    }
    
    for(int i=0;i<m;i++){
        if(intersection[arr2[i]]>0){
            cout<<arr2[i]<<endl;;
            intersection[arr2[i]]--;
        }
    }
    
    
}
