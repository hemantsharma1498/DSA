void reverseStack(stack<int> &input, stack<int> &extra) {
    
    int size=input.size();
    int array[size];
    
    
    for(int i=0;i<size;i++){
        array[i]=input.top();
        input.pop();
    }
    
    for(int i=0;i<size;i++){
        input.push(array[i]);
    }
}
