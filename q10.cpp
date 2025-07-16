#include <iostream>
using namespace std;
template <class T>
class Node

{
private:
public:
    int size = -1;
    T data;
    Node *next;

    void display(Node *top)
    {

        cout << "The element of  Double ended queue are : ";
        Node<T> *top1 = top;
        while (top1 != NULL)
        {
            cout << top1->data << " ";
            top1 = top1->next;
        }
        cout << "\n";
    }
    void enqueuer(Node *&top, T val)
    {
        Node *n = new Node();

        if (size >= 9)
        {
            cout << "\nDouble ended queue is overflow\n";
            return;
        }
        if (size <= -1)
        {
            n->data = val;
            n->next = NULL;
            top = n;

            size++;
        }
        else
        {
            Node *p = new Node();
            Node *p1 = new Node();
            p1->data = val;
            p1->next = NULL;
            p = top;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = p1;
            size = size + 1;
        }
    }
    T dequeuef(Node *&top)
    {
        if (size <= -1)
        {
            cout << "\nDouble ended queue is underflow\n";
            return -1;
        }
        else
        {
            Node *p = top;
            T x = p->data;
            top = top->next;
            free(p);
            size = size - 1;
            return x;
        }
    }
    void enqueuef(Node * &top,T val){
    Node*n=new Node();
    
    if(size>=9){
        cout<<"\nDouble ended queueis overflow\n";
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
T dequeuer(Node* &top){
    if(size<=-1){
        cout<<"\nDouble ended queue is underflow\n";
        return -1;
    }
    else{
    Node*p=top;
    Node*p1=new Node();
    Node*p2=new Node();
    
    while(p->next!=NULL){
        p1=p;
        p=p->next;
    }
    T x=p->data;
    p1->next=NULL;
    free(p);
    size=size-1;
    return x;}
}
};

Node<int> *top;

int main()
{
    Node<int> head;
    Node<int> *h;

    string s = "y";
    int op;
    int x;
    cout << "\nEnter 1 for enqueuerare "
         << "\nEnter 2 dequeuefront  "
         << "\nEnter 3 for enqueuefront  "
         << "\nEnter 4 for dequeuerare  "
         << "\nEnter 5 for display  " << endl;
    while (s == "y" || s == "Y")
    {
        cout << "\nEnter the operator : ";
        cin >> op;
        if (op == 1)
        {
            cout << "\nEnter the value you want to enqueuer ";
            cin >> x;
            head.enqueuer(top, x);
        }
        else if (op == 2)
        {
            int b = head.dequeuef(top);
            if (b != -1)
            {
                cout << "the dequeue felement is " << b << endl;
            }
        }
         else if (op == 3)
        {
            cout << "\nEnter the value you want to enqueuef";
            cin >> x;
            head.enqueuef(top, x);
        }
          else if (op == 4)
        {
            int b = head.dequeuer(top);
            if (b != -1)
            {
                cout << "the dequeuer element is " << b << endl;
            }
        }
        else if (op == 5)
        {
            head.display(top);
        }
        else
        {
            cout << "\n Invalid choice";
        }
        cout << "\n you want to execute again Y/N : ";
        cin >> s;
    }
  

    return 0;
}