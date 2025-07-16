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
     
     if(top==NULL){
        pop(top);
        return;
     }
    
   cout<<"The Stack are : ";
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
n->data=val;
n->next=top;
top=n;
size=size+1;
    }

}
T pop(Node* &top){
    if(size<=-1){
        cout<<"\nstack is underflow\n";
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


    return 0;}