#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    int p;
};
void creat(Node *&head, int data)
{
    head->data = data;

    head->next = head;
}
void display(Node *&head)
{
    if (head->next == NULL)
    {
        cout << "\nCircular Linked list is empty or not create\n";
        return;
    }
    cout << "The Circular linked list are : ";
    Node *p = new Node();
    p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << "\n";
}
void insertatfront(Node *&head, int data1)
{
    if (head->next == NULL)
    {
        creat(head, data1);
        return;
    }
    Node *p = new Node();
    Node *p1 = new Node();

    p->data = data1;
    p1 = head->next;
    while (p1->next != head)
    {
        p1 = p1->next;
    }
    p1->next = p;
    p->next = head;
    head = p;
}
void addend(Node *&head, int data1)
{
    if (head->next == NULL)
    {
        creat(head, data1);
        return;
    }
    Node *p = new Node();
    Node *p1 = new Node();

    p->data = data1;
    p1 = head->next;
    while (p1->next != head)
    {
        p1 = p1->next;
    }
    p1->next = p;
    p->next = head;
}
void insertatbet(Node *&head, int data1, int position)
{
    if (head->next == NULL)
    {
        creat(head, data1);
        return;
    }
    Node *p = new Node();
    Node *p1 = new Node();
    Node *p2 = new Node();
    Node *p3 = new Node();
    p3 = head->next;
    p = head;
    p2->data = data1;
    if (p3 == head)
    {
        cout << "\nthe Circular linked list have only one node\n";
        return;
    }
    if (position == 1)
    {
        insertatfront(head, data1);
        return;
    }
    else
    {
        int j = 1;

        while (p3 != head && j < position - 1)
        {

            p3 = p3->next;
            j++;
        }
    }
    if (p3 == head)
    {
        addend(head, data1);
        return;
    }
    int i = 1;
    while (i < position - 1)
    {
        p = p->next;
        i++;
    }
    p1 = p->next;
    p->next = p2;
    p2->next = p1;
}

void deletefront(Node *&head)
{
    if (head->next == head)
    {
        head->next = NULL;
        return;
    }
    Node *p = new Node();
    Node *p1 = new Node();
    Node *p2 = new Node();
    p = head;
    p1 = p->next;
    p2 = p->next;
    while (p1->next != head)
    {
        p1 = p1->next;
    }
    p1->next = p2;
    head = p2;
    free(p);
}
void deleteend(Node *&head)
{
    if (head->next == head)
    {
        head->next = NULL;
        return;
    }
    Node *p = new Node();
    Node *p1 = new Node();
    Node *p2 = new Node();
    p2 = head->next;
    if (p2 == head)
    {
        cout << "\nCircular Linked list can not be empty\n";
        return;
    }

    p = head;
    while (p->next != head)
    {

        p1 = p;
        p = p->next;
    }
    p1->next = head;
    free(p);
}
void deletbyposition(Node *&head, int position)
{
    Node *p3 = new Node();
    p3 = head->next;
    if (p3 == head)
    {
        cout << "\n Circular Linked list can not be empty\n";
        return;
    }

    else
    {
        int j = 1;
        while (j < position - 1 && p3 != head)
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
    else if (p3 == head)
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
    p2 = p->next;
    free(p);
    p1->next = p2;
}
void search(Node *&head, int data)
{
    Node *p = new Node();
    p = head;
    bool f = true;
    do
    {
        if (p->data == data)
        {
            f = false;
        }
        else
        {
            p = p->next;
        }
    } while (p != head && f);
    if (f != true)
    {
        cout << "\n"
             << data << " present at address " << p << endl;
        ;
    }
    else
    {
        cout << "\n"
             << data << " is not present in this Circular linked list\n";
    }
}
int main()
{
    Node *head;
    head->next = NULL;

    cout << "\nEnter 1 for creation a Circular linked list "
         << "\nEnter 2 for insert at front "
         << "\nEnter 3 for insert at end "
         << "\nEnter 4 for insert at any position "
         << "\nEnter 5 for delete from front "
         << "\nEnter 6 for delete from end "
         << "\nEnter 7 for delete from any position "
         << "\nEnter 8 for searching a element from Circular linked-list "
         << "\nEnter 9 for display Circular linked list " << endl;

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
            insertatfront(head, x);
        }
        else if (op == 3)
        {
            cout << "\nEnter the value for insertion : ";
            cin >> x;
            addend(head, x);
        }
        else if (op == 4)
        {
            cout << "\nEnter the value for insertion : ";
            cin >> x;
            cout << "\nEnter the position  where insert  : ";
            cin >> y;
            insertatbet(head, x, y);
        }
        else if (op == 5)
        {
            if (head->next == NULL)
            {
                cout << "\nCircular Linked liste is empty or nor create";
            }
            else
            {
                deletefront(head);
            }
        }
        else if (op == 6)
        {
            if (head->next == NULL)
            {
                cout << "\nCircular Linked liste is empty or nor create";
            }
            else
            {
                deleteend(head);
            }
        }
        else if (op == 7)
        {
            if (head->next == NULL)
            {
                cout << "\nCircular Linked liste is empty or nor create";
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
            if (head->next == NULL)
            {
                cout << "\nCircularLinked liste is empty or nor create";
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