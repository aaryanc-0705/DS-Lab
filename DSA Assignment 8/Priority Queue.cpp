#include <iostream>
#include <vector>
using namespace std;

class Max_Heap {
    vector<int> heap;
    int heap_size;
    int length;

public:
    Max_Heap(vector<int> arr) {
        heap_size = arr.size();
        length = arr.size();
        heap = arr;
        for(int i = (heap_size-2)/2; i >= 0; i--) {
            Max_heapify(i);
        }
    }

    Max_Heap(int x) {
        heap.resize(1);
        heap[0] = x;
        heap_size = 1;
        length = 1;
    }

    int parent(int i) {
        return (i-1)/2;
    }

    void Max_heapify(int i) {
        int largest;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if(l < heap_size && heap[l] > heap[i]) {
            largest = l;
        } else {
            largest = i;
        }

        if(r < heap_size && heap[r] > heap[largest]) {
            largest = r;
        }
        
        if(largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            Max_heapify(largest);
        }        
    }

    void disp() {
        for(int x : heap) {
            cout << x << " ";
        }
        cout << endl;
    }

    // Priority Queue Operations
    void insert(int key) {
        heap.resize(++length);
        heap_size = length;
        int i = heap_size - 1;
        heap[i] = key;
        
        // Bubble up
        while(i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int extractMax() {
        if(heap_size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        
        int max = heap[0];
        heap[0] = heap[heap_size - 1];
        heap_size--;
        length--;
        heap.resize(length);
        
        if(heap_size > 0) {
            Max_heapify(0);
        }
        return max;
    }

    int getMax() {
        if(heap_size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    bool isEmpty() {
        return heap_size == 0;
    }

    void increaseKey(int i, int key) {
        if(i >= heap_size || key < heap[i]) {
            cout << "Invalid index or key!" << endl;
            return;
        }
        heap[i] = key;
        while(i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
};

int main() {
    // Priority Queue using Max Heap
    vector<int> arr = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    Max_Heap pq(arr);
    
    cout << "Initial Heap: ";
    pq.disp();  // 16 14 10 8 7 9 3 2 4 1
    
    cout << "\nMax element: " << pq.getMax() << endl;
    
    pq.insert(20);
    cout << "After insert 20: ";
    pq.disp();  // 20 16 10 14 7 9 3 2 4 1 8
    
    cout << "\nExtract Max: " << pq.extractMax() << endl;
    cout << "After extract: ";
    pq.disp();  // 16 14 10 8 7 9 3 2 4 1
    
    pq.increaseKey(1, 25);
    cout << "After increaseKey(1,25): ";
    pq.disp();  // 25 16 10 14 7 9 3 2 4 1 8
    
    return 0;
}
