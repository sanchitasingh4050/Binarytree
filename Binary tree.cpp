#include <iostream>
using namespace std;
#include<vector>//1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1
#include<queue>
//binary tree 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int d){
        data=d;
        left=right=NULL;
        
    }
};
Node *binarytree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    Node*n=new Node(d);
    n->left=binarytree();
    n->right=binarytree();
    return n;
}
void print_preorder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print_preorder(root->left);
    print_preorder(root->right);
}
void print_inorder(Node*root){
    if(root==NULL){
        return;
    }
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}
void print_postorder(Node*root){ //bottom up approach
    if(root==NULL){
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->data<<" ";
}
// bredth first seach , level order print
void level_order_print(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
       
        if(temp==NULL){
            cout<<endl;
            q.pop();
            // insert a new null
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}
//level order tree build
Node*build_level_tree(){
    int d;
    cin>>d;
    Node* root=new Node(d);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*current=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
            current->left=new Node(c1);
            q.push(current->left);
        }
        if(c2!=-1){
            current->right=new Node(c2);
            q.push(current->right);
        }
        
    }
    return root;
}
int height(Node*root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}
int tree_diameter(Node*root){
    if(root==NULL){
        return 0;
    }
    //rec case
    int D1=height(root->left)+height(root->right);
    int D2=tree_diameter(root->left);
    int D3=tree_diameter(root->right);
    return 1+max(D1,max(D1,D3));
}
void print_path(Node*root, vector<int>&path){
    if(root==nullptr){
        return ;
    }
    if(root->left==NULL and root->right==NULL){
        //print the vector
        for(int node:path){
            cout<<node<<" ";
        }
        cout<<root->data<<" ";
        return;
        cout<<endl;
        
    }
    //recursive case
    path.push_back(root->data);
    print_path(root->left,path);
    print_path(root->right,path);
    //backtracking
    path.pop_back();
    return;
}
int main() {
cout<<"BINARY TREE"<<endl;
Node*root=binarytree();
cout<<endl;
cout<<"PREORDER TRAVERSAL : "<<endl;
print_preorder(root);
cout<<endl;
cout<<"INORDER TRAVERSAL : "<<endl;
print_inorder(root);
cout<<endl;
cout<<"POSTORDER TRAVERSAL : "<<endl;
print_postorder(root);
cout<<endl;
cout<<"LEVEL ORDER BFS: "<<endl;
level_order_print(root);
cout<<endl;
cout<<"BUILD LEVEL ORDER TREE "<<endl;
Node*head=build_level_tree();
level_order_print(head);

    return 0;
}