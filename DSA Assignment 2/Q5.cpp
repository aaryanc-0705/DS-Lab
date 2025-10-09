#include <iostream>
using namespace std;

class Diagonal{
    int n;
    int arr[];

    public:
    Diagonal(int dim){
        n = dim;
        cout << "Enter diagonal elements of array: " << endl;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
    }
    void Display(){
        cout << endl;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i==j){cout<<arr[i];}
                else{cout<<0;};
                cout << "\t"; 
            }
            cout << endl;
        }
    }
};

class TriDiagonal{
    int n; 
    int arr[];
    public:

    TriDiagonal(int dim){
        n = dim;
        int elements = 3*n - 2;
        cout << "Enter tri-diagonal elements of the array: " << endl;
        for(int i = 0; i<elements; i++){
            cin >> arr[i];
        };
    };
    void Display(){
        cout << endl;
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i==j || i-1 == j || i+1==j){cout << arr[count]; count++;}
                else{cout << 0;}
                cout << "\t";
            }
            cout << endl;
        }
    }
};

class LowTri{
    int n;
    int arr[];

    public:
    LowTri(int dim){
        n = dim;
        int elements = n*(n+1)/2;
        cout << "Enter lower triangular elements: " << endl;
        for(int i=0; i<elements; i++){cin >> arr[i];};
    };
    void Display(){
        cout << endl;
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i>=j){cout << arr[count]; count++;}
                else{cout << 0;};
                cout << "\t";
            }
            cout << endl;
        }
    }
};

class UpTri{
    int n;
    int arr[];

    public:
    UpTri(int dim){
        n = dim;
        int elements = n*(n+1)/2;
        cout << "Enter upper triangular elements: " << endl;
        for(int i=0; i<elements; i++){cin >> arr[i];};
    };
    void Display(){
        cout << endl;
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i<=j){cout << arr[count]; count++;}
                else{cout << 0;};
                cout << "\t";
            }
            cout << endl;
        }
    }
};

class Symmetric{
    int n;
    int arr[];

    public:
    Symmetric(int dim){
        n = dim;
        int elements = n*(n+1)/2; 
        cout << "Enter elements of matrix: " << endl;
        for(int i = 0; i<elements; i++){cin >> arr[i];};
    };
    void Display(){
        cout << endl;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int index;
                if(i>=j){
                    index = (i*(i+1)/2) + j;
                }
                else{
                    index = (j*(j+1)/2) + i;
                }

                cout << arr[index] << "\t";
            }
            cout << endl;
        }
    }
};

int main(){
    Diagonal d1(3);
    d1.Display();

    TriDiagonal d2(3);
    d2.Display();

    LowTri d3(3);
    d3.Display();

    UpTri d4(3);
    d4.Display();

    Symmetric d5(3);
    d5.Display();
}

