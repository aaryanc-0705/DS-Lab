#include <iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Tree{
    public:
    Node* root;

    Tree(){root = nullptr;}

    void insert(int x){
        Node* newNode = new Node(x);

        if(!root){
            root = newNode;
        }
        else{
            Node* temp = root;

            while(temp){
                if(x<temp->data && temp->left){temp = temp->left;}
                else if(x>temp->data && temp->right){temp = temp->right;}
                else if(x == temp->data){cout << "Element already present in the tree." << endl;}
                else{break;}
            }
            
            if(x < temp->data){temp->left = newNode;}
            else if(x > temp->data){temp->right = newNode;}
        }

    }

    void in_inorder(Node* x){
            if(x){
                in_inorder(x->left);
                cout << x->data << "\t";
                in_inorder(x->right);
            }
        }
    
    void inorder(){
        in_inorder(root);
    }

    void in_preorder(Node* x){
        if(x){
            cout << x->data << "\t";
            in_preorder(x->left);
            in_preorder(x->right);
        }
        
    }

    void preorder(){
        in_preorder(root);
    }

    void in_postorder(Node* x){
        if(x){
            in_postorder(x->left);
            in_postorder(x->right);
            cout << x->data << "\t";
        }
    }

    void postorder(){
        in_postorder(root);
    }
    
    Node* search(Node* curr, int k){

        while(curr && curr->data != k){
            if(k < curr->data){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        
        return curr;
    }

};

int main(){
    Tree t;

    t.insert(8);
    t.insert(3);
    t.insert(1);
    t.insert(10);
    t.insert(6);
    t.insert(14);
    t.insert(4);
    t.insert(7);
    t.insert(13);    

    t.inorder();

    cout << endl;

    Node* x = t.search(t.root, 7);
    cout << x->data << endl;

    return 0;
}