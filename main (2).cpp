// محمدصالح صدیقی
// 811901072

#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:

    vector<int> heap;

    void heapUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {

                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {

            swap(heap[index], heap[largest]);
            heapDown(largest);
        }
    }

public:
    void insert(int x) {
        heap.push_back(x);
        heapUp(heap.size() - 1);
    }

    int extractMax() {
        if (!heap.empty()) {
            int max = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            heapDown(0);
            return max;
        } else {
            cout << "heap is empty!";
            return 0;
        }
    }

    int getMax() const {
        if (heap.empty()) {
            throw
            out_of_range("Heap is empty");
        }

        return heap[0];
    }

    bool isEmpty(){
        return heap.empty();
    }
};

int main() {
    MaxHeap maxHeap;

    while (true){
        cout << "Enter number of what you want to do: \n"
                << "1. Add to heap \n"
                << "2. Extract Max \n"
                << "3. Get Max \n"
                << "4. Extract All \n"
                << "5. exit \n";

        char selected;
        cin >> selected;

        int key;
        switch (selected) {
            case '1':
                cout << "Enter the Key: ";
                cin >> key;
                maxHeap.insert(key);
                break;
            case '2':
                cout << "Maximum of heap was " << maxHeap.extractMax() << "\n";
                break;
            case '3':
                cout << "Maximum of heap is " << maxHeap.getMax() << "\n";
                break;
            case '4':
                while (!maxHeap.isEmpty()){
                cout << maxHeap.extractMax() << "\n";
                }
                break;
            case '5':
                exit(0);
        }

    }

    return 0;
}




