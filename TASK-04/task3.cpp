#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "ENTER SIZE: ";
    cin >> n;
    int arr[n];
    cout << "ENTER ELEMENTS: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "ARRAY: ";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "SHELL SORTED ARRAY: ";
    printArray(arr, n);

    return 0;
}