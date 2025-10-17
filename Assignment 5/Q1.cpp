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

    void insert_after(int ref, int x){
        if(!head){cout << "Empty list." << endl;}
        else{
            Node* curr = head;
            while(curr->next && curr->data != ref){
                curr = curr->next;
            }

            if(!curr->next && curr->data != ref){cout << "Data not found in the list." << endl;}
            else{
                Node* newNode = new Node(x);
                newNode->next = curr->next;
                curr->next = newNode;
            }

        }
    }

    void insert_before(int ref, int x){
        if(!head){cout << "Empty list." << endl;}
        else{
            if(head->data == ref){
                Node* newNode = new Node(x);
                newNode->next = head;
                head = newNode;
            }
            else{
                Node* curr = head;
                Node* pre;
                while(curr->next && curr->data != ref){
                    pre = curr;
                    curr = curr->next;
                }

                if(!curr->next && curr->data != ref){cout << "Data not found in the list." << endl;}
                else{
                    Node* newNode = new Node(x);
                    newNode->next = curr;
                    pre->next = newNode;
                }
            }

        } 
    }

    void del_beg(){
        if(!head){cout << "Empty list; nothing to delete." << endl;}
        else{
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void del_end(){
        if(!head){cout << "Empty list; nothing to delete." << endl;}
        else if(head->next){
            Node* curr = head;
            Node* pre;

            while(curr->next){
                pre = curr;
                curr = curr->next;
            }
            pre->next = nullptr;
            delete curr;
        }
        else{
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void del_element(int x){
        if(!head){cout << "Empty list." << endl;}
        else if(head->data == x){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else{
            Node* curr = head;
            Node* pre;
            while(curr->next && curr->data != x){
                pre = curr;
                curr = curr->next;
            }

            if(!curr->next && curr->data != x){cout << "Element not found in the list." << endl;}
            else{
                pre->next = curr->next;
                delete curr;
            }
        }
    }

    void search(int x){
        if(!head){cout << "Empty list, nowhere to search." << endl;}
        else if(head->data == x){cout << "Element found at head (1st node)." << endl;}
        else{
            int count = 1;
            Node* curr = head;
            while(curr->next && curr->data != x){
                curr = curr->next;
                count++;
            }
            if(!curr->next && curr->data != x){cout << "Element not found in the list." << endl;}
            else{
                cout << "Element found at node number - " << count << endl;
            }
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

};


int main(){
    List l1;

    l1.insert_beg(1);
    l1.insert_after(1,2);
    l1.insert_after(2,3);
    l1.insert_beg(0);
    l1.insert_end(5);
    l1.insert_before(5,4);
    l1.insert_before(0, -1);
    
    l1.del_element(-1);

    l1.display();
    l1.search(0);

    return 0;
}