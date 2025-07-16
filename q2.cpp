#include <iostream>
using namespace std;
template<class T>
int binary(T arr[],int size, T num,int lower,int upper){
while(lower<=upper){
    int middle=(lower+upper)/2;
    if(arr[middle]==num){
        return middle;
    }
    else if(arr[middle]<num){
        lower=middle+1;

    }
    else{
        upper=middle-1;
    }
    return -1;
}
}
int main(){
   
    int size;
    cout<<"Enter the size of array  "<<endl;
    cin>>size;
    float arr[size];
    cout<<"Enter the element of array  in sorted order "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    float n;
    cout<<"Enter the number to search in array by binary sort"<<endl;
    cin>>n;
    int s=sizeof(arr)/sizeof(arr[0]);
    int a=binary(arr,s,n,0,s-1);
    if (a==-1){
        cout<<n<<" is not present in this array";
    }
    else{
        cout<<n<<" is present in this array at index "<<a;
    }
}