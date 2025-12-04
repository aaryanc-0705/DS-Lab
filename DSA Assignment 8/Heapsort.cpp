#include <iostream>
#include <vector>
using namespace std;

class Max_Heap{
    vector<int> heap;
    int heap_size;
    int length;

    public:

    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}

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

    void Ascending(){
        int length = heap_size;
        for(int i = length-1; i>0; i--){
            int temp = heap[i];
            heap[i] = heap[0];
            heap[0] = temp;
            heap_size--;
            Max_heapify(0);
        }
        heap_size = length;
    }

    void disp(){
        for(int x : heap){cout << x << " ";}
        cout << endl;
    }
};

class Min_Heap{
    vector<int> heap;
    int heap_size;
    int length;

    public:

    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}

    Min_Heap(vector<int> arr){
        heap_size = arr.size();
        heap = arr;
        for(int i = (heap_size-2)/2; i>=0; i--){
            Min_heapify(i);
        }
    }

    void Min_heapify(int i){
        int smallest;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if(l < heap_size && heap[l] < heap[i]){
            smallest = l;
        }
        else{smallest = i;}

        if(r < heap_size && heap[r] < heap[smallest]){smallest = r;}
        
        if(smallest != i){
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            Min_heapify(smallest);
        }        
    }

    void Descending(){
        int length = heap_size;
        for(int i = length-1; i>0; i--){
            int temp = heap[i];
            heap[i] = heap[0];
            heap[0] = temp;
            heap_size--;
            Min_heapify(0);
        }
        heap_size = length;
    }

    void disp(){
        for(int x : heap){cout << x << " ";}
        cout << endl;
    }  
};

int main(){
    vector<int> x = {9, 4, 13, 11, 12, 20, 1};
    Max_Heap h(x);
    h.Ascending();
    h.disp();

    Min_Heap h1(x);
    h1.Descending();
    h1.disp();
}
