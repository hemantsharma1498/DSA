//Given an integer array of size N. Sort this array (in decreasing order) using heap sort.


void heapSort(int arr[], int n) {
    
    for(int i=1;i<n;i++){
        
        int child_index=i;
        
        while(child_index>0){
            int parent_index=(child_index-1)/2;
            
            if(arr[parent_index]>arr[child_index]){
                int temp=arr[parent_index];
                arr[parent_index]=arr[child_index];
                arr[child_index]=temp;
            }
            else break;
            
            child_index=parent_index;
            
        }
    }
    
    int size=n;
    
    while(size>1){
        
        int temp=arr[0];
        arr[0]=arr[size-1];
        arr[size-1]=temp;
        size--;
        
        int lci, rci, min_index, pi=0;
        
        lci=pi*2+1;
        rci=pi*2+2;
        
        while(lci<size){
            min_index=pi;
            
            if(arr[lci]<arr[min_index]){
                min_index=lci;
            }
            if(rci<size&&arr[rci]<arr[min_index]){
            	min_index=rci;
            }
            
            if(min_index==pi) break;

            int temp=arr[min_index];
        	arr[min_index]=arr[pi];
            arr[pi]=temp;
            
			pi=min_index;            
            
            lci=pi*2+1;
        	rci=pi*2+2;
        }
    
    }
    
}
