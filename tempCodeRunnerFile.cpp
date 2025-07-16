#include <iostream>
using namespace std;
template<class T>
int lenearseach(T arr[],int size, T num){
    for(int i=0;i<size;i++){
        if (arr[i]==num){
            return i;
        }
    }
    return -1;
}
int main(){
    int size;
    cout<<"Enter the size of array  "<<endl;
    cin>>size;
    float arr[size];
    cout<<"Enter the element of array "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    float n;
    cout<<"Enter the number to search in array "<<endl;
    cin>>n;
    int s=sizeof(arr)/sizeof(arr[0]);
    int a=lenearseach(arr,s,n);
    if (a==-1){
        cout<<n<<" is not present in this array";
    }
    else{
        cout<<n<<" is present in this array at index "<<a;
    }
}