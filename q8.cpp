#include <bits/stdc++.h>
using namespace std;
template <class T>

class quque1{
    int f=-1,r=-1;
    int size;
    T arr[];
    public:
    quque1(int a){
        size=a;
        arr[size];
    }
    void enqueue(T data){
        if(f==((r+1)%size)) {
            cout<<"\nQuque is overflow\n";
        }    
        else if(f==-1)   {
            f=(f+1)%size;
            r=(r+1)%size;
            arr[r]=data;
        } 
        else{
         r=(r+1)%size;
            arr[r]=data;
          }
    }
    T dequeue(){
        if(r==-1 && f==-1 ){
            cout<<"Queue is underflow\n";
            return -1;
        }
        else if(f==r && f!=-1){
          T v=  arr[f];
          r=-1;
          f=-1;
          return v;
        }

        
        else{
            T v=arr[f];
            f=(f+1)%size;
            return v;
        }
    }
    void display(){
        if(r==-1 && f==-1){
            cout<<"\nQueue is underflow\n";
            return;
        }
        cout<<"element of Queue is  ";
        // cout<<s;
        for(int i=f;i>-1;i=(i+1)%size){
            cout<<arr[i]<<"  ";
            if(i==r)
            {
                break;
            }
        }
        cout<<endl;
    }

};
int main(){
    //stack <int> s(6) ;
    int b;
    string str;
    str="y";

    cout<<"enter the size of array : ";
    cin>>b;
    quque1 <int>s(b);
string s1="y";
int op;
int  x;
cout<<"\nEnter 1 for enqueue "<<"\nEnter 2 for dequeue "<<"\nEnter 3 for display  "<<endl;
while(s1=="y" || s1=="Y"){
    cout<<"\nEnter the operator : ";
    cin>>op;
    if(op==1){
        cout<<"\nEnter the value you want to enqueue  ";
        cin>>x;
        s.enqueue(x);
    }
    else if(op==2){
     int b1= s.dequeue();
     if(b1!=-1){
     cout<<"the dequeue element is "<<b1<<endl;}
    }
    else if(op==3){
   s.display();
    }
        else{
        cout<<"\n Invalid choice";
    }
cout<<"\n you want to execute again Y/N : ";
cin>>s1;
    }
    
   
    return 0;
}
