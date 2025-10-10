#include <iostream>
#include <string>
using namespace std;
#define MAX 100
class Stack{
    char arr[MAX];
    int top;

    public:
    Stack(){top = -1;}

    bool isEmpty(){
        if (top == -1){
            return true;
        } 
        else return false;
    }

    bool isFull(){
        if (top == MAX -1){
            return true;
        } else return false;
    }

    void push( int x){
        if (isFull()){
            cout<<"Stack full (overflow)... element could not be pushed.\n";
        } 
        else {
            top++;
            arr[top]=x;
            
        }
        
    }

    char pop(){
        if (isEmpty()){
            cout<<"Stack is empty (underflow).\n";
        } else {
            char x = arr[top];
            top--;
            return x;
        }
        
    }

    int peek(){
        if(isEmpty()){
            cout<<"empty stack";
        } 
        else{return arr[top];};
    }

    void display(){
        int i;
        for(i=top; i>=0; --i){
            cout<<arr[i];
        }
    }
};

int main(){
    Stack s;
    string str = "{[()]}";

    for(int i= 0; i<str.length(); i++){
        if (str[i] == '{' || str[i] ==  '[' || str[i] ==  '('){
            s.push(str[i]);
        }
         else if (str[i] == '}' || str[i] ==  ']'|| str[i] == ')'){
            if ((str[i] == ')' && s.peek() == '(') ||
                (str[i] == '}' && s.peek() == '{') ||
                (str[i] == ']' && s.peek() == '[')){
                s.pop();
            }else {
                cout<<"not balanced\n";
                return 0;
            }
        }
    } cout <<"balanced";
}