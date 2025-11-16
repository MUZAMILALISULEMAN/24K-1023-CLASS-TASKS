#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void countingSort(int dataArray[], int arraySize, int placeValue) {
    int tempArray[arraySize];
    int countFreq[10] = {0};
    for (int i = 0; i < arraySize; i++)
        countFreq[(dataArray[i] / placeValue) % 10]++;
    for (int i = 1; i < 10; i++)
        countFreq[i] += countFreq[i - 1];
    for (int i = arraySize - 1; i >= 0; i--) {
        int digitVal = (dataArray[i] / placeValue) % 10;
        tempArray[countFreq[digitVal] - 1] = dataArray[i];
        countFreq[digitVal]--;
    }
    for (int i = 0; i < arraySize; i++)
        dataArray[i] = tempArray[i];
}

void radixSort(int dataArray[], int arraySize) {
    int maxValue = dataArray[0];
    for (int i = 1; i < arraySize; i++)
        if (dataArray[i] > maxValue)
            maxValue = dataArray[i];
    for (int placeValue = 1; maxValue / placeValue > 0; placeValue *= 10)
        countingSort(dataArray, arraySize, placeValue);
}

int main() {
    srand(time(0));
    int studentMarks[50];
    for (int i = 0; i < 50; i++)
        studentMarks[i] = rand() % 101;
    
    cout << "ORIGINAL MARKS:\n";
    for (int i = 0; i < 50; i++)
        cout << studentMarks[i] << " ";
    cout <<endl<<endl;

    radixSort(studentMarks, 50);

    cout << "MARKS WITH RANKS (HIGHEST = RANK 1):\n";
    int rankPosition = 1;
        for (int i = 49; i >= 0; i--)
            cout << "RANK " << rankPosition++ << ": " << studentMarks[i] << endl;

    return 0;
}