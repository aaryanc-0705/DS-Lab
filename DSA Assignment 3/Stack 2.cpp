#include <iostream>
#include <string>
using namespace std;
#define MAX 100

class stack{
    public:
    char arr[MAX];
    int top;

    stack(){
        top = -1;
    }

    void push(char c){
        ++top;
        arr[top] = c;
    }

    char pop (){
       return arr[top--];
    }
};

int main(){
    stack s;
    string str = "DataStructures";
    int n = str.length();
    
    for(int i=0; i<n; i++){
        s.push(str[i]);
    }  

    for(int i = s.top; i>=0; i--){
        cout << s.pop();
    }
}