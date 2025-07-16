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
     
    
cout<<"The element of  queue are : ";
   Node<T>*top1=top;
    while (top1 != NULL)
    {
        cout << top1->data << " ";
        top1 = top1->next;
    }
    cout<<"\n";
}
void push(Node * &top,T val){
    Node*n=new Node();
    
    if(size>=9){
        cout<<"\nstack is overflow\n";
        return;

    }
    if(size<=-1){
        n->data=val;
        n->next=NULL;
        top=n;
    
        size++;
    }
    else{
Node*p=new Node();
Node*p1=new Node();
p1->data=val;
p1->next=NULL;
p=top;
while(p->next!=NULL){
    p=p->next;
}
p->next=p1;
size=size+1;
    }

}
T pop(Node* &top){
    if(size<=-1){
        cout<<"\nqueue is underflow\n";
        return -1;
    }
    else{
    Node*p=top;
    T x=p->data;
    top=top->next;
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
cout<<"\nEnter 1 for push "<<"\nEnter 2 for pop "<<"\nEnter 3 for display  "<<endl;
while(s=="y" || s=="Y"){
    cout<<"\nEnter the operator : ";
    cin>>op;
    if(op==1){
        cout<<"\nEnter the value you want to push ";
        cin>>x;
        head.push(top,x);
    }
    else if(op==2){
     int b= head.pop(top);
     if(b!=-1){
     cout<<"the popped element is "<<b<<endl;}
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
// head.push(h,78);
// head.push(h,718);

// head.display(h);
// int b=head.pop(h);
// cout<<"the popped element is "<<b<<endl;
// head.display(h);

    return 0;}