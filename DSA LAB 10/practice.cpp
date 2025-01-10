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

    void insert(int val){
        Node*newNode=new Node();
        newNode->data=val;
        newNode->left=nullptr;
        newNode->right=nullptr;

        if(root==nullptr){
            root=newNode;
        }else{
            Node*current=root;
            while(true){
                if(val < current->data){
                    if(current->left==nullptr){
                        current->left=newNode;
                        break;
                    }
                    current=current->left;
                }else{
                    if(current->right==nullptr){
                        current->right=newNode;
                        break;
                    }
                    current=current->right;
                }
            }
        }
    }

    bool search(int val){
        Node*current=root;
        while(current!=nullptr){
            if(val==current->data){
                return true;
            }else if(val < current->data){
                current=current->left;
            }else{
                current=current->right;
            }
        }
        return false;
    }

    Node*Delete(Node*root , int data){
        if(root==nullptr){
            return nullptr;
        }else if(root->data > data){
            root->left=Delete(root->left, data);
        }else if(root->data < data){
            root->right= Delete(root->right , data);
        }else{
            if(root->left==nullptr&&root->right==nullptr){
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
                root->right=Delete(root->right, temp->data);
            }
        }
        return root;
    }

    void Delete(int data){
        root=Delete(root, data);
    }

    void inorder(){
        Node*current=root;
        while(current!=nullptr){
            if(current->left==nullptr){
                cout<<current->data<<" ";
                current=current->right;
            }else{
                Node*predecessor=current->left;
                while(predecessor->right!=nullptr&&predecessor->right!=current){
                    predecessor=predecessor->right;
                }
                if(predecessor->right==nullptr){
                    predecessor->right=current;
                    current=current->left;
                }else{
                    predecessor->right=nullptr;
                    cout<<current->data<<" ";
                    current=current->right;
                }
            }
        }
    }

    
};
int main(){
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.inorder();
    cout<<endl;
    tree.Delete(3);
    tree.inorder();
    cout<<endl;
    return 0;
}