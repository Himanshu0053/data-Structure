#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void creat(Node *&head,int data){
    Node *p=new Node();
    p->data=data;
    p->next=NULL;
    head=p;

}
void display(Node *temp)

{if(temp==NULL){
    cout<<"\nLinked List is empty cann't be display";
    return;
}
    cout<<"The linked list are : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<"\n";
}
void insertatfront(Node**headrefrence,int data1){
    Node*new_node=new Node();
    new_node->data=data1;
    new_node->next=(*headrefrence);
    *headrefrence=new_node;
}
void addend(Node** headre,int data1){
    Node* nnode=new Node();
    Node*last=*headre;
    nnode->data=data1;
    nnode->next=NULL;
    if(*headre==NULL){
        *headre=nnode;
    }
    while(last->next!=NULL){
         
      
               last=last->next;

    }
    last->next=nnode;
  
}
void insertatbet(Node*&head,int data1,int position){
    Node*p2=new Node();
    p2=head;
  if(head==NULL){
    cout<<"the given previous node cannot be NULL\n";
    return;
  }
  else{ 
    
    int j=1;
    while(j<position &&p2!=NULL){
        p2=p2->next;
        j++;
    }

  }
  Node*p=new Node();
  
  Node*p1=new Node();

  p=head;
 
  Node* new_node=new Node();
  new_node->data=data1;

if(position==1){
    insertatfront(&head,data1);
    return;
}
else if(p2==NULL){
    addend(&head,data1);
    return;
}
int i=1;
while(i<position-1){
p=p->next;
i++;
}
p1=p->next;
p->next=new_node;
new_node->next=p1;

}

void deletefront(Node *&head){
    Node *p=new Node();
    Node*p1=new Node();
    p=head;
    p1=p;
    p1=p1->next;
    head=p1;
    free(p);
}
void deleteend(Node *&head){
    Node *p=new Node();
    Node*p1=new Node();
    
    p=head;
  
if(head==NULL){
    cout<<"\nLinked list is  empty can not be delete\n";
    return;
}
else if(head->next==NULL){
deletefront(head);
return;
}


while(p->next!=NULL){

    p1=p;
    p=p->next;
}
free(p);
p1->next=NULL;


}
void deletbyposition(Node *&head,int position){
   Node *p3=new Node();
   p3=head;
if(head==NULL){
    cout<<"\nLinked list can not be empty\n";
    return;
}

else {
    int j=0;
    while(j<position && p3!=NULL){
        p3=p3->next;
        j++;
    }
}
if(position==1){
    deletefront(head);
    return;
}
else if(p3==NULL){
    deleteend(head);
    return;
}

    
Node *p=new Node();
Node *p2=new Node();
Node*p1=new Node();
p=head;
int i=0;
while(i<position-1){

    p1=p;
    p=p->next;
    i++;
}
p2=p->next;
free(p);
p1->next=p2;

}
void search(Node *&head,int data ){
    Node *p=new Node();
    p=head;
    bool f=true;
    while(p!=NULL &&f){
        if(p->data==data){
            f=false;
        }
        else{
        p=p->next;}
    }
    if(f!=true){
        cout<<"\n"<<data<<" present at address "<<p<<endl;;
    }
    else{
        cout<<"\n"<<data <<" is not present in this linked list\n";
    }
}
int main()
{
    Node *head;

    head=NULL;

cout<<"\nEnter 1 for creation a linked list "<<"\nEnter 2 for insert at front "<<"\nEnter 3 for insert at end "
    <<"\nEnter 4 for insert at any position "<<"\nEnter 5 for delete from front "<<"\nEnter 6 for delete from end "
    <<"\nEnter 7 for delete from any position "<<"\nEnter 8 for searching a element from linked-list "<<"\nEnter 9 for display linked list "<<endl;
    
string s="y";
int op,x,y;
while(s=="y" || s=="Y"){
    cout<<"\nEnter the operator : ";
    cin>>op;
    if(op==1){
        cout<<"\nEnter the data of first node ";
        cin>>x;
        creat(head,x);
    }
    else if(op==2){
        cout<<"\nEnter the value for insertion : ";
        cin>>x;
        insertatfront(&head,x);
    }
    else if(op==3){
         cout<<"\nEnter the value for insertion : ";
        cin>>x;
        addend(&head,x);
    }
    else if(op==4){
           cout<<"\nEnter the value for insertion : ";
        cin>>x;
           cout<<"\nEnter the position  where insert  : ";
        cin>>y;
        insertatbet(head,x,y);
    }
    else if(op==5){
          if(head==NULL){
            cout<<"\nLinked liste is empty or nor create";
        }
        else{
        deletefront(head);}
    }
    else if(op==6){
        if(head==NULL){
            cout<<"\nLinked liste is empty or nor create";
        }
        else{
        deleteend(head);}
    }
    else if(op==7){
          if(head==NULL){
            cout<<"\nLinked liste is empty or nor create";
        }
        else{
        cout<<"\nEnter the position of Node: ";
        cin>>y;
        deletbyposition(head,y);}
    }
    else if (op==8){
        if(head==NULL){
             cout<<"\nLinked liste is empty or nor create";
        }
        else{
        cout<<"\nEnter the you want to serach: ";
        cin>>x;
        search(head,x);}
    }
    else if(op==9){
    display(head);
    }
    else{
        cout<<"\n Invalid choice";
    }
cout<<"\n you want to execute again Y/N : ";
cin>>s; }
    return 0;}