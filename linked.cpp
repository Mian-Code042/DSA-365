#include <iostream>
using namespace std;

struct Node{
   int data;
   Node *next;
   };

   Node *head= NULL;

   void append(int n){
      Node *newNode=new Node;
      newNode->data=n;
      newNode->next=NULL;

      if(head==NULL){
        head=newNode;
      }else{
        Node *nodePtr =head;
        while(nodePtr->next != NULL){
            nodePtr=nodePtr->next;
        }
        nodePtr->next=newNode;
      }
   }

   void print(){
    cout<<"All Elements of the Single Linked list : ";
    Node *nodePtr = head;
    while(nodePtr!=NULL){
        cout<<nodePtr->data<<" ";
        nodePtr = nodePtr->next;
    }
   }

   int main(){
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);
    append(6);
     print();
   }