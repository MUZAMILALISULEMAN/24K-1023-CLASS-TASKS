#include <iostream>
using namespace std;

class hashTable {
private:
    int arr[100];
    int size;

public:
    hashTable() { size = 0; }

    void add(int x) {
        int i = size - 1;
        while (i >= 0 && arr[i] > x) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = x;
        size++;
    }

    void removeValue(int x) {
        int index = -1;
        for (int i = 0; i < size; i++)
            if (arr[i] == x) index = i;

        if (index == -1) return;

        for (int i = index; i < size - 1; i++)
            arr[i] = arr[i + 1];

        size--;
    }

    void search(int x) {
        for (int i = 0; i < size; i++)
            if (arr[i] == x) {
                cout << x << " found\n";
                return;
            }
        cout << x << " not found\n";
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    hashTable h;

    h.add(1);
    h.add(3);
    h.add(4);
    h.add(5);
    h.add(7);

    h.display();

    cout << "Remove 3\n";
    h.removeValue(3);

    h.display();

    h.search(5);
    h.search(6);

    return 0;
}