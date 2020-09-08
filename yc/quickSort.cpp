#include <iostream>

using namespace std;

class quickSort {

private:
    int arrayLength = 0;
    int *array;

    int partition(int p, int r) {
        // i: always point to the end of array's left partition
        int i = p - 1;
        int x = array[r];

        for (int j = p; j < r; j++) {
            if (array[j] <= x) {
                i++;
                exchange(i, j);
            }
        }

        exchange(i + 1, r);
        return i + 1;
    }

    void exchange(int i, int j) {
        if (i == j)
            return;
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    void recursiveSort(int p, int r) {
        if (p < r) {
            int q = partition(p, r);
            recursiveSort(p, q - 1);
            recursiveSort(q + 1, r);
        }
    }

    void sort(void) {
        recursiveSort(0, arrayLength - 1);
    }

public:
    quickSort(int len, int *a) {
        arrayLength = len;
        array = a;
        sort();
    }

    void printArray() {
        for (int i = 0; i < arrayLength; ++i)
            cout << array[i] << endl;
    }
};

int main() {
    int len = 10;
    int a[10] = {134,341,5,1,15,53,135,135,15,133};

    quickSort q = quickSort(len, a);
    q.printArray();
}
