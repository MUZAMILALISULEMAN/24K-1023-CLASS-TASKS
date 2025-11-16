    #include <iostream>
#include <string>
using namespace std;

class athlete {
    string playerName;
    int finishTime;
public:
    athlete(int t = 0, string n = "") : finishTime(t), playerName(n) {}
    int getFinishTime() const { return finishTime; }
    string getPlayerName() const { return playerName; }
};

void combine(athlete list[], int start, int middle, int end) {
    int leftSize = middle - start + 1;
        int rightSize = end - middle;
    athlete leftArr[leftSize], rightArr[rightSize];
        for (int i = 0; i < leftSize; i++)
            leftArr[i] = list[start + i];
    for (int j = 0; j < rightSize; j++)
        rightArr[j] = list[middle + 1 + j];
            int i = 0, j = 0, k = start;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i].getFinishTime() <= rightArr[j].getFinishTime()) {
                list[k] = leftArr[i];
            i++;
        } else {
            list[k] = rightArr[j];
                j++;
        }
            k++;
    }
        while (i < leftSize) {
            list[k] = leftArr[i];
        i++;
            k++;
    }
    while (j < rightSize) {
        list[k] = rightArr[j];
            j++;
        k++;
    }
}

void sortMerge(athlete list[], int start, int end) {
        if (start < end) {
            int middle = start + (end - start) / 2;
        sortMerge(list, start, middle);
            sortMerge(list, middle + 1, end);
        combine(list, start, middle, end);
    }
}

int main() {
    const int SIZE = 10;
        athlete players[SIZE];
    for (int i = 0; i < SIZE; i++) {
        string playerName;
            int finishTime;
        cout << "ENTER NAME AND FINISH TIME OF ATHLETE " << i + 1 << ": ";
            cin >> playerName >> finishTime;
        players[i] = athlete(finishTime, playerName);
    }
        sortMerge(players, 0, SIZE - 1);
    cout << "\nATHLETES SORTED BY FINISH TIME:\n";
        for (int i = 0; i < SIZE; i++)
            cout << players[i].getPlayerName() << " " << players[i].getFinishTime() << endl;
    return 0;
}