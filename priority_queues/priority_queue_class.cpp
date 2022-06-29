#include<vector>
class PriorityQueue {
    vector<int> pq;

   public:
    PriorityQueue() {
    
    }
    void insert(int element) {
        
        pq.push_back(element);
        
        int child_index=pq.size()-1;
        
        while(child_index>0){
            int parent_index=(child_index-1)/2;
            
            if(pq[child_index]>pq[parent_index]){
                int temp=pq[parent_index];
                pq[parent_index]=pq[child_index];
                pq[child_index]=temp;
            }
            else break;
            
            child_index=parent_index;
        }
    }

    int getMax() {
        if(isEmpty()){
            return 0;
        }
        
        return pq[0];
    }

    int removeMax() {
        
        if(isEmpty()) return 0;
        
        int returnval=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        
        int lci, rci, pi=0, max_index;
        
        lci=pi*2+1;
        rci=pi*2+2;
        
        while(lci<pq.size()){
            max_index=pi;
            
            if(pq[max_index]<pq[lci]){
                max_index=lci;
            }
            
            if(pq[max_index]<pq[rci]){
                max_index=rci;
            }
            
            if(max_index==pi) break;
            
            
            int temp=pq[pi];
            pq[pi]=pq[max_index];
            pq[max_index]=temp;
            
            pi=max_index;
            
            lci=pi*2+1;
        	rci=pi*2+2;
            
            
        }
        
        return returnval;
        
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size()==0;
    }
};
