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


void printReverse(Node *head)
{
    //Write your code here
    
    if(head==NULL) return;
    
    if((*head).next==NULL){
		cout<<(*head).data<<" ";
        return;
    }

    printReverse((*head).next);
    
    cout<<(*head).data<<" ";
}
