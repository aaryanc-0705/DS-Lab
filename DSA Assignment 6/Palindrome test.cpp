#include <iostream>
using namespace std;

class Node{
public:
    string data;
    Node *next;
    Node *prev;
    Node(string x){
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL
{
public:
    Node *head;
    DLL(){head = nullptr;}

    void insert_beg(string x){
        Node *newNode = new Node(x);

        if (!head){
            head = newNode;
        }

        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_end(string x){
        Node* newNode = new Node(x);

        if(!head){head = newNode;}
        else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }

            newNode->prev = temp;
            temp->next = newNode;

        }

    }

    void insert_after(string ref, string x){
        Node* newNode = new Node(x);
        Node* curr = head;

        while(curr!=nullptr && curr->data != ref){
            curr = curr->next;
        }

        if(!curr){cout << "Element not found in list."<<endl;}
        else{
            newNode->prev = curr;
            newNode->next = curr->next;
            if(curr->next){curr->next->prev = newNode;};            
            curr->next = newNode;
        };
        
    }

    void display(){
        if(!head){
            cout << "Empty list" << endl;
        }
        else{
            Node* temp = head;

            while(temp != nullptr){
                cout << temp->data << "\t";
                temp = temp->next;
            }

            cout << endl;
        }
    }

    void search(string x){
        Node* temp = head;
        int counter = 1;
        if(!temp){cout << "Empty list." << endl;}
        else{
            while(temp && temp->data != x){
                temp = temp->next;
                counter++;
            }

            if(temp){cout << "Given element is at node " << counter << endl;}
            else{cout << "Data not found in list." << endl;}
        }

    }

    void del(string x){
        if(!head){cout << "Empty list." << endl;}
        else{
            if(head->data == x){
                if(!head->next){
                    Node* curr = head;
                    head = nullptr;
                    delete curr;
                }
                else{
                    Node* curr = head;
                    head = head->next;
                    delete curr;
                }
            }
            else{
                Node* temp = head;
                
                while(temp && temp->data != x){
                    temp = temp->next;
                }

                if(!temp){cout << "Element not found in the list." << endl;}
                else{
                    if(temp->next){
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                        delete temp;
                    }
                    else{temp->prev->next = nullptr; delete temp;}
                }
            }
        }

    }

    void size(){
        if(!head){cout << "Empty list; size = 0." << endl;}
        else{
            Node* temp = head;
            int count = 1;

            while(temp->next){
                temp = temp->next;
                count++;
            }
            
            cout << "Size of the list is " << count << endl;
        }

    }

    void palindrome(){
        Node* backwards = head;
        while(backwards->next){
            backwards = backwards->next;
        }

        Node* forward = head;
        Node* for_pre = forward;
        Node* back_pre = backwards;

            bool p = false;
            
            while(for_pre->next != back_pre->prev && for_pre->next != back_pre){
                if(forward->data == backwards->data){

                    for_pre = forward;
                    back_pre = backwards;
                    forward = forward->next;
                    backwards = backwards->prev;
                    p = true;

                    
                }
                else{
                    p = false;
                    break;
                }
            }

            if(p){cout << "Given list is a palindrome." << endl;}
            else{cout << "Not a palindrome." << endl;}
    }

};

int main(){
    DLL d;
    
    d.insert_beg("r");
    d.insert_end("a");
    d.insert_end("c");
    d.insert_end("e");
    d.insert_end("c");
    d.insert_end("a");
    d.insert_end("r");

    d.display();

    d.palindrome();
}
