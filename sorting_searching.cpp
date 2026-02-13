#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[5] = {5, 2, 9, 1, 7};

    bubbleSort(arr, 5);

    cout << "Sorted Array:\n";
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    int pos = binarySearch(arr, 5, 7);
    cout << "\nElement found at index: " << pos;

    return 0;
}