#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (arr.size() == 0 || k == 0) {
            return vector<int>();
        }
        else if (arr.size() == 1) {
            return arr;
        }

        this->arr = arr;
        this->arrLen = this->arr.size();
        buildHeap();
        for (int i = 0; i < k; ++i) {
            int tmp = this->arr[0];
            this->arr[0] = this->arr[this->arrLen-1];
            this->arr[this->arrLen-1] = tmp;
            this->arrLen -= 1;
            maxHeapify(0);
        }

        return vector<int>(this->arr.end() - k, this->arr.end());
    }

private:
    vector <int> arr;
    int arrLen = 0;
    void buildHeap() {
        for (int i = (arrLen - 2) / 2; i >= 0; i--) {
            maxHeapify(i);
        }
    }

    void maxHeapify(int i) {
        int smallest = i;
        if (left(i) != -1 && arr[left(i)] < arr[i]) {
            smallest = left(i);
        }
        if (right(i) != -1 && arr[right(i)] < arr[smallest]) {
            smallest = right(i);
        }

        if (smallest != i) {
            int tmp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = tmp;
            maxHeapify(smallest);
        }
    }

    int left(int i) {
        int tmp = 2 * i + 1;
        if (tmp >= arrLen) {
            return -1;
        }
        return tmp;
    }

    int right(int i) {
        int tmp = 2 * i + 2;
        if (tmp >= arrLen) {
            return -1;
        }
        return tmp;
    }
};

class SolutionQuickSort {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (arr.size() == 0 || k == 0) {
            return vector<int>();
        }
        else if (arr.size() == 1) {
            return arr;
        }

        this->a = arr;
        smallestKRecursive(0, arr.size() - 1, k);

        return vector<int>(this->a.begin(), this->a.begin() + k);
    }

private:
    vector<int> a;

    void smallestKRecursive(int start, int end, int k) {
        if (end - start + 1 == k) {
            return;
        }

        if (start >= end) {
            return;
        }

        int mid = partition(start, end);

        if (mid - start > k) {
            smallestKRecursive(start, mid - 1, k);
        }
        else if (mid - start == k - 1 || mid - start == k) {
            return;
        }
        else {
            smallestKRecursive(mid + 1, end, k - (mid - start + 1));
        }
    }

    int partition(int start, int end) {
        int r = -1;
        int x = a[end];

        for (int i = start; i < end; ++i) {
            if (a[i] <= x) {
                r++;
                swap(i, r);
            }
        }

        swap(r + 1, end);
        return r + 1;
    }

    void swap(int i, int j) {
        if (i == j)
            return;

        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
};