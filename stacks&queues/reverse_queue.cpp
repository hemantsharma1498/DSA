#include<queue>

void reverseQueue(queue<int> &input) {
    
    int size=input.size();
    int array[size];
    
    for(int i=0;i<size;i++){
        array[i]=input.front();
        input.pop();
    }
    
    for(int i=size-1;i>=0;i--){
        input.push(array[i]);
    }
    
    
}
