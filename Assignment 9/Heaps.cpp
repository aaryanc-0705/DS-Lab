#include <iostream>
#include <vector>
using namespace std;

class Max_Heap{
    vector<int> heap;
    int heap_size;
    int length;

    public:

    int parent(int i){
        return (i-1)/2;
    }

    Max_Heap(vector<int> arr){
        heap_size = arr.size();
        heap = arr;
        for(int i = (heap_size-2)/2; i >= 0; i--){
            Max_heapify(i);
        }
    }

    Max_Heap(int x){
        heap[0] = x;
    };

    void Max_heapify(int i){
        int largest;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if(l < heap_size && heap[l] > heap[i]){
            largest = l;
        }
        else{largest = i;}

        if(r < heap_size && heap[r] > heap[largest]){largest = r;}
        
        if(largest != i){
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            Max_heapify(largest);
        }        
    }

    void disp(){
        for(int x : heap){cout << x << " ";}
        cout << endl;
    }
};

int main(){
    vector<int> arr = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    Max_Heap h(arr);
    h.disp();

    return 0;
}