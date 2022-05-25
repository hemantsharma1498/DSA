//For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.

class Node {
     public:
         int data;
         Node *next;
         Node(int data)
         {
             this->data = data;
		     this->next = NULL;
	        }
};


Node *evenAfterOdd(Node *head)
{
	//write your code here
    if(head==NULL) return head;
    
    Node *even_head=NULL, *even_tail=NULL, *odd_head=NULL, *odd_tail=NULL;
    Node *curr=head;
    
    while(curr!=NULL){
        if((*curr).data%2==0){
            if(even_head==NULL){
                even_head=curr;
                even_tail=curr;
        
            }
            else{
                (*even_tail).next=curr;
                even_tail=(*even_tail).next;
            }
        }
        else{
            if(odd_head==NULL){
                odd_head=curr;
                odd_tail=curr;
            }
            else{
                (*odd_tail).next=curr;
                odd_tail=(*odd_tail).next;
            }
        }
    	curr=(*curr).next;  
    }
  
    
    if(odd_head==NULL){
        (*even_tail).next==NULL;
        return even_head;
    }
    else if(even_head==NULL) {
        (*odd_tail).next==NULL; 
        return odd_head;
    }
    else{  
        (*odd_tail).next=even_head;
        (*even_tail).next=NULL;
        return odd_head;
    }
}

