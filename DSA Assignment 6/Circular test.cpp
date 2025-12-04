#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int num)
    {
        data = num;
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

    void insert_beg(int num){
        Node *newNode = new Node(num);
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

    void insert_end(int num){
        Node* newNode = new Node(num);

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

    void insert_after(int ref, int num){
        Node* newNode = new Node(num);
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
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << temp->data << "\t";
            temp = temp->next;
            cout << temp->data << endl;
        }
    }

    void del(int val){
        if(!head){cout << "Empty list." << endl;}
        else{

            if(head->data == val){
                if(head->next == head){Node* temp = head; delete temp; head = nullptr;}
                else{
                    Node* temp = head;
                    head->prev->next = head->next;
                    head->next->prev = head->prev;
                    head = head->next;
                    delete temp;
                }
            }

            else{
                Node* curr = head;

                while(curr->next != head && curr->data != val){
                    curr = curr->next;
                }

                if(curr->next == head && curr->data != val){cout << "Data not found in list." << endl;}
                else{
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                }
            }
        }

    }

    void search(int val){
        if(!head){cout << "Empty list." << endl;}
        else{
            Node* curr = head;
            int count = 1;
            while(curr->next != head && curr->data != val){
                curr = curr->next;
                count++;
            }
            if(curr->next == head && curr->data != val){cout << "Data not present in list." << endl;}
            else{cout << "Data found at node number-" << count << endl;}
        }

    }

    void size(){
        if(!head){cout << "Empty list (size = 0)." << endl;}

        else{
            Node* curr = head;
            int count = 1;
            while(curr->next != head){
                curr = curr->next;
                count++;
            }

            cout << "Size of this list is " << count << endl;
        }
    }
};

bool circular(CLL* x){
    if(!x->head){throw runtime_error("Empty list.");}
    else{
        Node* curr = x->head;
        while(curr->next != x->head && curr->next){
            curr = curr->next;
        }

        if(curr->next == x->head){return true;}
        else{return false;}
    }
};


int main(){
    CLL c1;

    c1.insert_beg(1);
    c1.insert_end(3);
    //c1.insert_end(3);
    c1.insert_end(2);
    c1.insert_end(1);

    c1.display();
    
    cout << circular(&c1) << endl;

    return 0;
}