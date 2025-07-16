#include<iostream>
using namespace std;
#include<cstring>
template<class T1>

class stack1{
    private:
     int size;
    public:
    T1 *stack2;
    T1 val;
    int top=-1;
    stack1(int a){
        size =a;
        stack2=new int[size];
     }
    void push( T1 val){
        if(top>=size){
            cout<<"Stack is overflow \n";

        }
        else{
            top++;

           stack2[top]=val;
        }}
         void pop( ){
        if(top<=-1){
            cout<<"\nStack is underflow \n";

        }
        else{
          
            cout<<"\n popped element is "<<stack2[top];
            top--;
        }

    }
    void display(){
        if(top<=-1){
            pop();
            return;
        }
        cout<<"\nelement in stack are: ";
        for(int i=top;i>=0;i--){
            cout<<"  "<< stack2[i];

        }
        cout<<"\n";
        


    }
    
  
};
int main(){
    int a;
    cout<<"Enter the size of stack ";
    cin>>a;
    stack1<int>p(a-1);
    string s="y";
      int choice;
    cout<<"enter 1 for push "<<"\nenter 2 for pop"<<"\nenter 3 for display\n";
while(s=="y" || s=="Y"){
    cout<<"\nyour choice : ";
    cin>>choice;
    if(choice==1){
        cout<<"\n enter val for push : ";
        int val;
        cin>>val;
        p.push(val);
     
    }
     else if(choice==2){
     p.pop();
    }
    else if(choice==3){
        p.display();
    }
    else{
        cout<<"\ninvalid choice";
  
    }
cout<<"\nyou want enter more data Y/N : ";
cin>>s;

}
return 0;
}