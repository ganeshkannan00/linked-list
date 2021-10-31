#include <iostream>

using namespace std;

struct lnode{
    int data;
    struct lnode* next;
};
typedef struct lnode node;

node* head =NULL;


void insertAtBeginning(int a)
{
    node* newnode=(node*) malloc(sizeof(node));
    if(newnode==NULL){
        cout<<"out of space";
        return;
    }
    newnode -> data = a;
    if(head==NULL){
        newnode ->next =NULL;
        head=newnode;
    }
    else{
        newnode -> next= head;
        head = newnode;
    }
}

void display(){
    
    node* temp=head;
    if(head==NULL){
        cout<<"list is empty";
        return;
    }
    cout<<"element in the list are";
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
}
void insertWithPosition(int pos,int val){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    node* temp=head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    cout<<"inserted at"<<pos;
}
void deleteAtPosition(int pos){
    if(head==NULL){
        cout<<"nothing to delete";
        return;
    }
    node* temp=head;
    node* prev;
    for(int i=0;i<=pos-1;i++){
        prev=temp;
        temp=temp->next;
        if(head==NULL){
            cout<<"list is empty";
            return;
        }
    }
    prev->next = temp ->next;
    cout<<"deleted"<<temp -> data;
    free(temp);
}
int main()
{
    cout<<"Linked List Implementation"<<endl;
    int choice,val,pos;
    while(true)
    {
        cout<<"1.insert at beginning"<<endl;
        cout<<"2.display"<<endl;
        cout<<"3.insert with position"<<endl;
        cout<<"4.delete"<<endl;
        cout<<"5.exit"<<endl;
        cout<<"enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"enter the number to be inserted"<<endl;
                    cin>>val;
                    insertAtBeginning(val);
                    break;
            case 2: cout<<"display the elements";
                    display();
                    break;
            case 3: cout<<"enter the position";
                    cin>>pos;
                    
                    if(pos<0){
                        cout<<"invalid position";
                        break;
                    }
                    cout<<"enter the data";
                    cin>>val;
                    if(pos==0)
                        insertAtBeginning(val);
                    
                    else
                        
                        insertWithPosition(pos,val);
                    
                    break;
            case 4 :cout<<"delete the position";
                    cin>>pos;
                    if(pos<0){
                        cout<<"invalid position";
                        break;
                    }
                    deleteAtPosition(pos);
                    break;
            case 5 :exit(0);
            
                    
            default:"olunga enter pannu";
        }
    }

    return 0;
}
