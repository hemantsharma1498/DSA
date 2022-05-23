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

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if(head==NULL||n==0)
        return head;
    int length=0;
    Node *current=head;
    
    while(current!=NULL){
        length++;
        current=(*current).next;
    }
    
    current=head;
    
    int rotate=length-n;
    int i=0;
    Node *newHead=head;
    Node *prev=head;
    while(i<length){
        if(i==rotate){
            prev->next=NULL;
            newHead=current;
            break;
        }
        i++; 
        prev=current;
        current=(*current).next;
    }
    
    while((*current).next!=NULL){
        current=(*current).next;
    }
    
    (*current).next=head;
    
    return newHead;
}
