#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
struct Tree{
    //insertion in BST
    Node* root;
    Tree(){
        root = nullptr;
    }

    Node* insert(Node* root, int data){
        if(root == nullptr){
            Node* temp = new Node();
            temp->data = data;
            temp->left = nullptr;
            temp->right = nullptr;
            return temp;
        }
        if(data < root->data){
            root->left = insert(root->left, data);
        }
        else{
            root->right = insert(root->right, data);
        }
        return root;
    }

    void insert(int data){
        root = insert(root, data);
    }

    void inorder(Node* root){
        if(root == nullptr){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void inorder(){
        inorder(root);
    }

    void preorder(Node* root){
        if(root == nullptr){
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void preorder(){
        preorder(root);
    }

    void postorder(Node* root){
        if(root == nullptr){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    void postorder(){
        postorder(root);
    }

    bool search(Node*root,int data){
        if(root == nullptr){
            return false;
            }
        if(root->data == data){
            return true;
        }
        if(data < root->data){
            return search(root->left,data);
            }
        else{
            return search(root->right,data);
            }
    }

    bool search(int data){
        return search(root,data);
    }

    Node*Delete(Node*root,int data){
        if(root == nullptr){
            return nullptr;
        }
        if(data < root->data){
            root->left = Delete(root->left,data);
        }
        else if(data > root->data){
            root->right = Delete(root->right,data);
        }
        else{
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr){
                Node*temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr){
                Node*temp = root->left;
                delete root;
                return temp;
            }
            else{
                Node*temp = root->right;
                while(temp->left != nullptr){
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = Delete(root->right,temp->data);
            }
        }
        return root;
    }

    void Delete(int data){
        root = Delete(root,data);
    }
};
int main(){
    Tree t;
    t.insert(10);
    t.insert(5);
    t.insert(15);
    t.insert(3);
    t.insert(7);
    t.insert(2);
    t.insert(12);
    t.insert(18);
    t.inorder();
    cout<<endl;
    t.preorder();
    cout<<endl;
    t.postorder();
    cout<<endl;
    cout<<t.search(7)<<endl;
    cout<<t.search(8)<<endl;
    t.Delete(5);
    t.inorder();
    cout<<endl;
    t.Delete(10);
    t.inorder();
    cout<<endl;
    t.Delete(3);
    t.inorder();
    return 0;
}