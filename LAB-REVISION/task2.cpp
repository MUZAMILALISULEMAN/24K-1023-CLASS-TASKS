#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

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

        cout << "ARRAY AFTER GAP = " << gap << ": ";
        printArray(arr, n);
    }
}

int main() {
    int weights[] = {32, 25, 40, 12, 18, 50, 28};
    int n = 7;

    cout << "INITIAL LUGGAGE WEIGHTS: ";
    printArray(weights, n);

    shellSort(weights, n);

    cout << "\nLUGGAGE WEIGHTS SORTED FROM LIGHTEST TO HEAVIEST: ";
    printArray(weights, n);

    cout << "\n--- SORTING ANALYSIS ---\n";
    cout << " SHELL SORT IS FASTER THAN BUBBLE SORT BECAUSE IT AVOIDS MANY UNNECESSARY SWAPS.\n";
    cout << " IT WORKS BY PARTIALLY SORTING ELEMENTS USING LARGE GAPS, THEN REFINING WITH SMALLER GAPS.\n";
    cout << " WHEN THE ARRAY IS ALMOST SORTED TO BEGIN WITH, SHELL SORT RUNS EVEN MORE EFFICIENTLY.\n";
    cout << "   FEWER COMPARISONS AND SHIFTS ARE NEEDED AS MOST ELEMENTS ARE ALREADY NEAR THEIR CORRECT POSITIONS.\n";

    return 0;
}
