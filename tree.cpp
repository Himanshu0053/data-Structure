#include <iostream>
using namespace std;
template<class T>
class tree{
    public :
    T key;
    tree *left;
    tree *right;
    int Height;

tree* create(T val){
    tree *a=new tree();
    a->key=val;
    a->left=NULL;
    a->right=NULL;
    return a;

}
tree* insert(tree*&a, T val){
   

if(a==NULL){
    return(a=create(val));
}
if(a!=NULL){
    if((a->key)>val){
     a->left=insert(a->left,val);
      
    }
    else if ((a->key)<val){
     a->right=insert(a->right,val);
  
    }
}
return a;
}
void inorder(tree*&r){
    tree *a=r;
    if(a==NULL){
        return;}
    
    
    inorder(a->left);
    cout<<" "<<(a->key);
    
    inorder(a->right);
    
}
void postorder(tree*&r){
        tree *a=r;
    if(a==NULL){
        return;}
    
    
   postorder(a->left);
    
   postorder(a->right);
    cout<<" "<<(a->key);
}
void preorder(tree*&r){
        tree *a=r;
    if(a==NULL){
        return;}
    
    
    cout<<" "<<(a->key);
    preorder(a->left);
    
    preorder(a->right);
}

};
int main(){
tree<int>p;
tree<int>*root;
root=NULL;
p.insert(root,30);
p.insert(root,20);
p.insert(root,40);
cout<<"inoreder \n";
 p.inorder(root);
p.insert(root,15);
cout<<"inoreder \n";
 p.inorder(root);
p.insert(root,25);
p.insert(root,35);
p.insert(root,45);


cout<<"inoreder \n";
 p.inorder(root);
 cout<<"\npreorde";
 p.preorder(root);
 cout<<"\npostorder";
 p.postorder(root);
    return 0;
}
