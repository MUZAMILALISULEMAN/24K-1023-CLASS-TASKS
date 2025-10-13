#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void shellSort(int arr[], int n) {
    //generating the gap for shell 
    for (int gap = n / 2; gap > 0; gap /= 2) {
          for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }

        cout << "AFTER GAP " << gap << ": ";
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {0,1, 3, 6, 2, 9, 10};
    int n = 7;

    cout << "ARRAY: ";
    printArray(arr, n);
    shellSort(arr, n);

    cout << "SORTED ARRAY: ";
    printArray(arr, n);

    return 0;
}