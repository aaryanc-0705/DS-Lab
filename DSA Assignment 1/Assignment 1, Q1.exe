#include <iostream>
using namespace std;
int main(){
    int arr[50], x, n;


    while(1){
        cout<<"\n1. CREATE"<<endl;
        cout<<"2. DISPLAY"<<endl;
        cout<<"3. INSERT"<<endl;
        cout<<"4. DELETE"<<endl;
        cout<<"5. LINEAR SEARCH"<<endl;
        cout<<"6. EXIT"<<endl;

        cin>>x;

        switch(x){
            case 1: {       //Create
                cout<<"Enter number of elements: " << endl;
                cin>>n;
                cout<<"Enter elements: " << endl;
                for(int i=0; i<n; i++){
                    cin>>arr[i];
                }
                break;
            }

            case 2: {       //Display
                cout<<"The created array is: ";
                for(int i=0; i<n; i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
                break;
            }

            case 3: {       //Insert
                int a, pos;
                cout<<"Enter the element you want to insert: ";
                cin>>a;
                cout<<"Enter the position: ";
                cin>>pos;
                for(int i=n; i>=pos-1; i--){
                        arr[i]= arr[i-1];
                }
                arr[pos-1] = a;
                n++;
                break;
            }

            case 4: {       //Delete
                cout<<"Enter the number you want to delete: ";
                int b;
                cin>>b;
                int ind;
                for(int i=0; i<n; i++) {
                    if(arr[i]==b) {
                        int ind = i;
                    }
                }
                for(int i = ind; i<n; i++){
                    arr[i] = arr[i+1];
                }
                n--;
                break;
            }

            case 5: {       //Linear Search
                int num;
                cout<<"Enter the number you want to search: ";
                cin>>num;
                int index = -1;
                for(int i=0; i<n; i++){
                    if (arr[i]==num){
                        index = i;
                        break;
                    }
                }
                if(index == -1){cout<<"Element not found.";}

                else {
                    if(index==0) {cout<<"Element found at 1st position";}
                    else if(index==1) {cout<<"Element found at 2nd position";}
                    else if(index==2) {cout<<"Element found at 3rd position";}
                    else{cout << "Element found at "<< index+1 <<"th position";}
                }
                break;
            }

            case 6: {       //Exit
                return 0;
            }
        }
    }
    return 0;
}
