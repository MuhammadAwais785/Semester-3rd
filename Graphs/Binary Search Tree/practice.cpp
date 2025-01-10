#include<iostream>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
};

struct BST{
    Node*root;
    BST(){
        root=nullptr;
    }

    Node*insert(Node*root,int x){
        if(root==nullptr){
            Node*newNode=new Node();
            newNode->data=x;
            newNode->left=nullptr;
            newNode->right=nullptr;
            return newNode;
        }
        if(x<root->data){
            root->left=insert(root->left,x);
        }else{
            root->right=insert(root->right,x);
        }
        return root;
    }

    void Insert(int data){
        root=insert(root,data);
    }

    bool search(Node*root,int x){
        if(root==nullptr){
            return false;
        }

        if(x==root->data){
            return true;
        }
        if(x<root->data){
            return search(root->left,x);
        }else{
            return search(root->right,x);
        }
    }

    bool search(int data){
        return search(root,data);
    }


        void preorder(Node*root){
            if(root==nullptr){
                return;
            }
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }

        void preorder(){
            preorder(root);
        }

        Node*Delete(Node*root,int x){
            if(root==nullptr){
                return nullptr;
            }
            if(x<root->data){
                root->left=Delete(root->left,x);
            }else if(x>root->data){
                root->right=Delete(root->right,x);
            }else{
                if(root->left==nullptr && root->right==nullptr){
                    delete root;
                    return nullptr;
                }else if(root->left==nullptr){
                    Node*temp=root->right;
                    delete root;
                    return temp;
                }else if(root->right==nullptr){
                    Node*temp=root->left;
                    delete root;
                    return temp;
                }else{
                    Node*temp=root->right;
                    while(temp->left!=nullptr){
                        temp=temp->left;
                    }
                    root->data=temp->data;
                    root->right=Delete(root->right,temp->data);
                }
            }
            return root;
        }

        void Delete(int x){
            root=Delete(root,x);
        }
};
int main(){
    BST tree;
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(15);
    tree.Insert(3);
    tree.Insert(7);
    tree.preorder();
    return 0;
}