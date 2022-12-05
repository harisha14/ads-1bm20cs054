#include<bits/stdc++.h>
#include<inttypes.h>
 using namespace std;
 
 class node
 {
     public:
     int data;
     node* npx;
 };
 
 node* Xor(node* a,node* b)
 {
     return (node*)((uintptr_t) (a)^(uintptr_t)(b));
 }
 
 void insert(node **head,int key)
{
 node *new_node=new node();
 new_node->data=key;
 new_node->npx=*head;
 if(*head!=NULL)
 {
 (*head)->npx=Xor(new_node,(*head)->npx);
 }
*head=new_node;
}
 
 void print(node *head)
{
 node *curr=head;
 node *prev=NULL;
 node *next;
 cout<<"The Linked List as follows: "<<endl;
 while(curr!=NULL)
 {
  cout<<curr->data<<" ";
 next=Xor(prev,curr->npx);
 prev=curr;
 curr=next;
 }
}
int main()
{
    int n,i,a[100];
    node* head = NULL;
    cout<<"Enter the number of nodes:";
    cin>>n;
    cout<<"Enter the list:";
    for(i=0;i<n;i++){
    cin>>a[i];
    insert(&head,a[i]);}
    print(head);
 
    return (0);
}
