#include <iostream>
#include <string>

using namespace std;

int main() {
    int arr[] = {10, 6,5,4,3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            comparisons++;
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }

    cout << "SORTED LIST: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "TOTAL COMPARISIONS: " << comparisons << endl;

    return 0;
}