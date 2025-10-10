#include <iostream>
using namespace std;


class  Stack{
    int max, top;
    int arr[];

    public:
    Stack(){max = 100; top=-1;};
    Stack(int n){max = n; top=-1;};

    void push(int num){
        if(top<max-1){
            top++;
            arr[top] = num;
        }else{
            cout << "Stack full -- element couldn't be pushed." << endl;
        }
    }
    int pop(){
        if(top>=0){
            int x = arr[top];
            top--;
            return x;
        }else{
            cout << "Stack empty..." << endl;
            return 0;
        };
    }
    bool isEmpty(){
        return top<0;
    };
    bool isFull(){
        return top>=max-1;
    }
    void display(){
        if(top >= 0){
            cout << "Stack is:" << endl;
            for(int i = top; i>=0; i--){
                cout << arr[i] << endl;
            }
            cout << endl;
        }
        else{
            cout << "Stack empty." << endl;
        }
    }
    void peek(){
        if(top>=0){cout << arr[top] << endl;}
        else{cout << "Stack empty." << endl;}
    }
};

int main(){
    Stack s1(5);
    s1.push(22);
    s1.peek();
    s1.push(33);
    s1.push(44);
    s1.push(55);
    s1.push(66);
    s1.display();
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    
    return 0;
}