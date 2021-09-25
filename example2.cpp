#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    class Node* next;

    //constructor
    Node(int val,Node* next)
    :data(val)
    ,next(next)
    {}

    void printlist(){
        Node* node=this;
        while(node != NULL){
            cout <<node->data<<" ";
            node=node->next;
        }
        cout <<endl;
    }
};

void swap(Node*& a,Node*& b){
    Node* temp=a;
    a=b;
    b=temp;
}

void swapnode(Node** head_ref, int x, int y){
    if(x==y){
        return;
    }

    Node **a=NULL,**b=NULL;
    
    while(*head_ref){
        if(x == (*head_ref)->data){
            a = head_ref;
        }
        else if(y == (*head_ref)->data){
            b = head_ref;
        }
        head_ref = &((*head_ref)->next);
    }

    if(a && b){
          swap(*a, *b);
          swap(((*a)->next),((*b)->next));
    }
}

void push(Node** head_ref, int new_data){
    (*head_ref)=new Node(new_data, *head_ref);
}

int main(){
    Node* head=NULL;

    for(int i=0;i<10;i++){
        push(&head,i);
    }
    swapnode(&head,5,8);

    head->printlist();
}

