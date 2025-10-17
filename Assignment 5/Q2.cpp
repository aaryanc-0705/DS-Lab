#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

class List{
    public:

    Node* head;
    List(){head = nullptr;}
    
    void insert_beg(int x){
        if(!head){
            Node* newNode = new Node(x);
            head = newNode;
        }
        else{
            Node* newNode = new Node(x);
            newNode->next = head;
            head = newNode;
        }
    }

    void insert_end(int x){
        Node* newNode = new Node(x);

        if(!head){head = newNode;}
        else{
            Node* curr = head;
            while(curr->next){
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void display(){
        if(!head){cout << "Empty list." << endl;}
        else{
            Node* curr = head;
            while(curr){
                cout << curr->data << "\t";
                curr = curr->next;
            }
            cout << endl;
        }
    }

    void rem_key(int x){
        if(!head){cout << "Empty list." << endl;}
        else{
            int count = 0;
            Node* temp = head;
            Node* pre;

            while(temp->next){

                if(temp->next->data == x && temp != head){
                    count++;
                    Node* rem = temp->next;
                    temp->next = temp->next->next;
                    delete rem;
                }
                else if(head->data == x){
                    count++;
                    Node* rem = temp;
                    head = temp->next;                    
                    temp = temp->next;
                    delete rem;
                }
                else{
                    temp = temp->next;
                }              
            }

            if(count!=0){cout << "Element appeared " << count << " times." << endl;}
            else{cout << "No instances of the element in this list." << endl;}
            
        }

    }
};

int main(){
    List l1;

    l1.insert_beg(1);
    l1.insert_end(1);
    l1.insert_end(2);
    l1.insert_end(3);
    l1.insert_end(1);
    l1.insert_end(2);
    l1.insert_end(1);

    l1.display();

    l1.rem_key(1);

    l1.display();

    return 0;
}