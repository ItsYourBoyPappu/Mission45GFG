/*Given two linked lists sorted in increasing order, 
create a new linked list representing the intersection of the 
two linked lists. The new linked list should be made with without
 changing the original lists.*/
#include <bits/stdc++.h>

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};


class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node* head = NULL;
        Node* temp = NULL;
        while(head1 != NULL && head2!=NULL){
            if(head1->data < head2->data) head1 = head1->next;
            else if(head1->data > head2->data) head2 = head2->next;
            else{
                Node* newnode = new Node(head1->data);
                if(!head){
                    head = newnode;
                    temp = head;
                }
                else{
                    temp->next = newnode;
                    temp = newnode;
                }
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        temp->next  = NULL;
        return head;
    }
};
