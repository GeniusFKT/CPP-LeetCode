#include <iostream>

using namespace std;

class maxHeap {

private:
    int heapLength = 0;
    int *heap;

    int parent(int i) {
        if (i == 0) {
            return -1;
        }
        else {
            return int((i - 1) / 2);
        }
    }

    int left(int i) {
        int tmp = 2 * i + 1;
        if (tmp >= heapLength) {
            return -1;
        }
        return tmp;
    }

    int right(int i) {
        int tmp = 2 * i + 2;
        if (tmp >= heapLength) {
            return -1;
        }
        return tmp;
    }

    void buildMaxHeap(void) {
        if (heapLength == 1)
            return;

        for (int i = int(heapLength - 2) / 2; i >= 0; --i)
            maxHeapify(i);
    }

    void maxHeapify(int i) {
        int largest;
        if (left(i) != -1 && heap[left(i)] > heap[i]) {
            largest = left(i);
        }
        else {
            largest = i;
        }

        if (right(i) != -1 && heap[right(i)] > heap[largest]) {
            largest = right(i);
        }

        if (largest != i) {
            int tmp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = tmp;
            maxHeapify(largest);
        }
    }


public:
    maxHeap(int len, int *h) {
        heapLength = len;
        heap = h;
        buildMaxHeap();        
    }

    void heapSort(void) {
        int realLength = heapLength;

        for (int i = 0; i < realLength - 1; ++i) {
            int tmp = heap[0];
            heap[0] = heap[heapLength-1];
            heap[heapLength-1] = tmp;

            heapLength -= 1;
            maxHeapify(0);
        }

        heapLength = realLength;
    }

    void printHeap(void) {
        for (int i = 0; i < heapLength; ++i)
            cout << heap[i] << endl;
    }
};

int main() {
    int len = 10;
    int a[10] = {3,4,74,13,53,3,13,24,434,12};
    
    maxHeap h = maxHeap(len, a);
    h.printHeap();
    h.heapSort();
    h.printHeap();
}
