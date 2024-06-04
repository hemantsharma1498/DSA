from typing import Optional


class ListNode:
    def __init__(self, data=None) -> None:
        self.data=data
        self.next=None

class LinkedList:
    def __init__(self) -> None:
        self.head=None
    
    def add(self, data):
        if not self.head:
            self.head=ListNode(data)
        else:
            current=self.head
            while current.next:
                current=current.next
            current.next=ListNode(data) 
    
    def push(self, data):
        new_node=ListNode(data) 
        new_node.next=self.head
        self.head=new_node

def iterate_through_linked_list():
    linked_list=LinkedList()
    for i in range(0, 15):
        if i>=12:
            linked_list.push(i)
        else:
            linked_list.add(i)
    
    current=linked_list.head
    while current.next!=None:
        val=current.data
        print(val)
        current=current.next


# def addNumbers(node1, node2, carry):

def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    if l1==None and l2==None: return None
    if l1==None: return l2
    if l2==None: return l1

    result=LinkedList

    while l1 != None and l2 != None:


