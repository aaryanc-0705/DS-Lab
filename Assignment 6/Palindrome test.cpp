#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string data;
    Node *next;
    Node *prev;
    Node(string x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class CLL{
public:
    Node *head;
    CLL()
    {
        head = nullptr;
    }

    void insert_beg(string x){
        Node *newNode = new Node(x);
        if (!head){
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        else
        {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_end(string x){
        Node* newNode = new Node(x);

        if (!head){
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        else{
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;

        }

    }

    void insert_after(string ref, string x){
        Node* newNode = new Node(x);
        Node* curr = head;

        while(curr->next != head && curr->data != ref){
            curr = curr->next;
        }

        if(curr->next == head && curr->data != ref){cout << "Element not found in list." << endl;}
        else{
            newNode->prev = curr;
            newNode->next = curr->next;
            curr->next = curr->next->prev = newNode;          
            curr->next = newNode;
        };
        
    }

    void display(){
        Node* temp = head;

        if(!head){
            cout << "Empty list" << endl;
        }
        else{
            while(temp->next != head){
                cout << temp->data << endl;
                temp = temp->next;
            }
            cout << temp->data << endl;
            temp = temp->next;
            cout << temp->data << endl;
        }
    }


    void palindrome(){
        if(!head){cout << "Empty list." << endl;}
        else{
            Node* forward = head;
            Node* backward = head->prev;
            bool p = false;
            
            while((forward->next != backward && forward->next != backward->prev) && forward->data == backward->data){
                forward = forward->next;
                backward = backward->prev;
                p = true;
            }

            if(p){cout << "Given list is a palindrome." << endl;}
            else{cout << "Not a palindrome." << endl;}
        }
    }
};


int main(){
    CLL d;

    d.insert_beg("r");
    d.insert_end("a");
    d.insert_end("c");
    d.insert_end("e");
    d.insert_end("c");
    d.insert_end("a");
    d.insert_end("r");

    d.palindrome();

}