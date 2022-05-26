//You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.

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


Node* mid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL and fast->next->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* rev(Node* head){
    if(head==NULL or head->next == NULL){
        return head;
    }
    else{
        Node* smallhead=rev(head->next);
        Node* tail=head->next;
        head->next=NULL;
        tail->next=head;
        return smallhead;
    }
}
bool isPalindrome(Node *head)
{
    //Write your code here
    if(head==NULL) return true;
	Node* midNode=mid(head);
    Node* head2=midNode->next;
    midNode->next=NULL;
    Node* revHead2=rev(head2);
    while(revHead2!=NULL){
        if(head->data!=revHead2->data){
            return false;
        }
   		head=head->next;
        revHead2=revHead2->next;
    }
    return true;
}
