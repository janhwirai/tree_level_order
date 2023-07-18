#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        //This class will represent a single node in a particular tree
        int data;
        Node* left;
        Node* right;

        //Constructor
        Node(int val){
            this->data=val;
            this->left=NULL;
            this->right=NULL;
        }
};

Node* buildTree(Node* root){
    cout<<"Enter value:"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for right of   "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){  //Previous level traversal done
            cout<<endl;
            if(!q.empty()){ //Queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    } 
}

int main(){
    Node* root=NULL;
    root=buildTree(root);
    cout<<"Printing level order Traversal: \n";
    levelOrderTraversal(root);
    return 0;
}