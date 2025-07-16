#include <iostream>
using namespace std;
template<class T>
class Node

{private:

 public:
 int size=-1;
    T data;
    Node *next;

    void display(Node*top){
     if(size==-1){
        cout<<" \nqueue is empty ";
        return;
     }
    
cout<<"The element of  queue are : ";
   Node<T>*top1=top;
   do{
      cout << top1->data << " ";
        top1 = top1->next;
   }
    while (top1 != top);
   
    cout<<"\n";
}
void enqueue(Node * &top,T val){
    Node*n=new Node();
    
    if(size>=9){
        cout<<"\nQueue  is overflow\n";
        return;

    }
    if(size<=-1){
        n->data=val;
        n->next=n;
        top=n;
        size++;
    }
    else{
Node*p=new Node();
Node*p1=new Node();
Node*p2=new Node();
p1->data=val;

p=top;
while(p->next!=top){
    p=p->next;
}
p2=p->next;
p1->next=p2;
p->next=p1;
size=size+1;
    }

}
T  denqueue(Node* &top){
    if(size<=-1){
        cout<<"\nqueue is underflow\n";
        return -1;
    }
    else{
    Node*p=top;
    Node*p1=p->next;
    Node *p2=p->next;
    while(p2->next!=top){
      p2=p2->next;
    }
    p2->next=p1;
    top=p1;
    T x=p->data;
  
    free(p);
    size=size-1;
    return x;}
}


};


Node<int >*top;


int main()
{
    Node <int >head;
    Node<int>*h;


    
string s="y";
int op;
int  x;
cout<<"\nEnter 1 for enqueue "<<"\nEnter 2 for denqueue "<<"\nEnter 3 for display  "<<endl;
while(s=="y" || s=="Y"){
    cout<<"\nEnter the operator : ";
    cin>>op;
    if(op==1){
        
        cout<<"\nEnter the value you want to enqueue ";
        cin>>x;
        head.enqueue(top,x);
    }
    else if(op==2){
     int b= head.denqueue(top);
     if(b!=-1){
     cout<<"the dequeue element is "<<b<<endl;}
    }
    else if(op==3){
    head.display(top);
    }
        else{
        cout<<"\n Invalid choice";
    }
cout<<"\n you want to execute again Y/N : ";
cin>>s;
    }


    return 0;}