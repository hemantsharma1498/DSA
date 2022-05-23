 
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


Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    if(head==NULL)return NULL;
    if(pos==0){
        head=(*head).next;
    }
    
    Node *current=head;
    int i=0;
    while(i<pos&&(*current).next!=NULL){
        
        if(i==pos-1){
            Node *temp=(*current).next;
            Node *next=(*temp).next;
            (*current).next=(*temp).next;
            break;
            
        }
        i++;
        current=(*current).next;
    }
    
    
    
    return head;
	    
}

