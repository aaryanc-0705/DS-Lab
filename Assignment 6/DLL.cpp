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

class DLL
{
public:
    Node *head;
    DLL()
    {
        head = nullptr;
    }

    void insert_beg(int num){
        Node *newNode = new Node(num);

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

    void insert_end(int num){
        Node* newNode = new Node(num);

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

    void insert_after(int ref, int num){
        Node* newNode = new Node(num);
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
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }

    void search(int num){
        Node* temp = head;
        int counter = 1;
        if(!temp){cout << "Empty list." << endl;}
        else{
            while(temp && temp->data != num){
                temp = temp->next;
                counter++;
            }

            if(temp){cout << "Given element is at node " << counter << endl;}
            else{cout << "Data not found in list." << endl;}
        }

    }

    void del(int num){
        if(!head){cout << "Empty list." << endl;}
        else{
            if(head->data == num){
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
                
                while(temp && temp->data != num){
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
};

int main(){
    DLL d;
    
    d.insert_beg(1);
    d.insert_end(2);
    d.insert_end(3);
    d.insert_end(2);
    d.insert_end(1);

    d.display();

    d.search(3);
    
    d.size();
}
