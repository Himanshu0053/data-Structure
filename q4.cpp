#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *pre;
};
void creat(Node *&head, int data)
{
    Node *p = new Node();
    p->data = data;
    p->next = NULL;
    p->pre = NULL;
    head = p;
}
void display(Node *temp)
{
    if (temp == NULL)
    {
        cout << "\nDoubly list empty or not create\n";
        return;
    }
    cout << "The doubly linked list are : ";
    Node *p = new Node();
    while (temp != NULL)
    {
        cout << temp->data << " ";
        p = temp;
        temp = temp->next;
    }

    cout << "\n";
    cout << "\nDoubly linked list using pre pointer ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->pre;
    }
    cout << "\n";
}

void insertatfront(Node **headrefrence, int data1)
{
    if (*headrefrence == NULL)
    {
        creat(*headrefrence, data1);

        return;
    }
    Node *p = new Node();
    p->data = data1;
    p->pre = NULL;
    p->next = (*headrefrence);
    (*headrefrence)->pre = p;
    *headrefrence = p;
}
void addend(Node **headre, int data1)
{
    if (*headre == NULL)
    {
        creat(*headre, data1);

        return;
    }
    Node *nnode = new Node();
    Node *last = *headre;
    nnode->data = data1;
    nnode->next = NULL;
    if (*headre == NULL)
    {
        nnode->pre = NULL;
        *headre = nnode;
    }
    while (last->next != NULL)
    {

        last = last->next;
    }
    last->next = nnode;
    nnode->pre = last;
}
void insertatbet(Node *&head, int data1, int position)
{
    Node *p2 = new Node();
    p2 = head;
    if (head == NULL)
    {
        cout << "the given previous node cannot be NULL\n";
        return;
    }
    else
    {

        int j = 1;
        while (j < position && p2 != NULL)
        {
            p2 = p2->next;
            j++;
        }
    }

    if (position == 1)
    {
        insertatfront(&head, data1);
        return;
    }
    else if (p2 == NULL)
    {
        addend(&head, data1);
        return;
    }
    Node *p = new Node();

    Node *p1 = new Node();

    p = head;

    Node *new_node = new Node();
    new_node->data = data1;
    int i = 0;
    while (i < position - 1)
    {
        p1 = p;
        p = p->next;
        i++;
    }
    p1->next = new_node;
    new_node->pre = p1;
    p->pre = new_node;
    new_node->next = p;
}

void deletefront(Node *&head)
{
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    Node *p = new Node();
    Node *p1 = new Node();
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    p = head;
    p1 = p;
    p1 = p1->next;
    p1->pre = NULL;
    head = p1;
    free(p);
}
void deleteend(Node *&head)
{
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    Node *p = new Node();
    Node *p1 = new Node();
    if (head == NULL)
    {
        cout << "\n Doubly Linked list can not be empty\n";
        return;
    }
    p = head;

    while (p->next != NULL)
    {

        p1 = p;
        p = p->next;
    }
    free(p);
    p1->next = NULL;
}
void deletbyposition(Node *&head, int position)
{
    Node *p3 = new Node();
    p3 = head;
    if (head == NULL)
    {
        cout << "\nDoubly Linked list can not be empty\n";
        return;
    }

    else
    {
        int j = 0;
        while (j < position && p3 != NULL)
        {
            p3 = p3->next;
            j++;
        }
    }
    if (position == 1)
    {
        deletefront(head);
        return;
    }
    else if (p3 == NULL)
    {
        deleteend(head);
        return;
    }

    Node *p = new Node();
    Node *p2 = new Node();
    Node *p1 = new Node();

    p = head;
    int i = 0;
    while (i < position - 1)
    {

        p1 = p;
        p = p->next;
        i++;
    }
    p1->next = p->next;
    p2 = p->next;
    p2->pre = p1;

    free(p);
}
void search(Node *&head, int data)
{
    Node *p = new Node();
    p = head;
    bool f = true;
    while (p != NULL && f)
    {
        if (p->data == data)
        {
            f = false;
        }
        else
        {
            p = p->next;
        }
    }
    if (f != true)
    {
        cout << "\n"
             << data << " present at address " << p << endl;
        ;
    }
    else
    {
        cout << "\n"
             << data << " is not present in this linked list\n";
    }
}
int main()
{
    Node *head;
    head = NULL;

    cout << "\nEnter 1 for creation Doubly linked list "
         << "\nEnter 2 for insert at front of Doubly linked list "
         << "\nEnter 3 for insert at end of Doubly linked list "
         << "\nEnter 4 for insert at any position of Doubly linked list "
         << "\nEnter 5 for delete from front of Doubly linked list"
         << "\nEnter 6 for delete from end of Doubly linked list"
         << "\nEnter 7 for delete from any position of Doubly linked list "
         << "\nEnter 8 for searching a element from Doubly linked list "
         << "\nEnter 9 for display Doubly linked list" << endl;

    string s = "y";
    int op, x, y;
    while (s == "y" || s == "Y")
    {
        cout << "\nEnter the operator : ";
        cin >> op;
        if (op == 1)
        {
            cout << "\nEnter the data of first node ";
            cin >> x;
            creat(head, x);
        }
        else if (op == 2)
        {
            cout << "\nEnter the value for insertion : ";
            cin >> x;
            insertatfront(&head, x);
        }
        else if (op == 3)
        {
            cout << "\nEnter the value for insertion : ";
            cin >> x;
            addend(&head, x);
        }
        else if (op == 4)
        {
            if (head == NULL)
            {
                cout << "\nDoubly linked list is empty or not create\n";
            }
            else
            {
                cout << "\nEnter the value for insertion : ";
                cin >> x;
                cout << "\nEnter the position  where insert  : ";
                cin >> y;

                insertatbet(head, x, y);
            }
        }
        else if (op == 5)
        {
            if (head == NULL)
            {
                cout << "\nDoubly Linked liste is empty or nor create";
            }
            else
            {
                deletefront(head);
            }
        }
        else if (op == 6)
        {
            if (head == NULL)
            {
                cout << "\nDoubly Linked liste is empty or nor create";
            }
            else
            {
                deleteend(head);
            }
        }
        else if (op == 7)
        {
            if (head == NULL)
            {
                cout << "\nDoubly Linked liste is empty or nor create";
            }
            else
            {
                cout << "\nEnter the position of Node: ";
                cin >> y;
                deletbyposition(head, y);
            }
        }
        else if (op == 8)
        {
            if (head == NULL)
            {
                cout << "\nDoubly Linked list is empty or not create\n";
            }
            else
            {
                cout << "\nEnter the you want to serach: ";
                cin >> x;
                search(head, x);
            }
        }
        else if (op == 9)
        {
            display(head);
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