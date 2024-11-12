#include <bits/stdc++.h>

using namespace std;


int binarySearch(const vector<int>& arr, int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item) {
            return mid + 1;  
        } else if (arr[mid] < item) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;  
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];

        int pos = binarySearch(arr, key, 0, i - 1);

        for (int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertionSort(arr);

    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    
}
