#include <iostream>
using namespace std;

class hashTable {
private:
static const int SIZE = 100;
int arr[SIZE];
bool occupied[SIZE];


int hash(int key) {
    return key % SIZE;
}


public:
hashTable() {
for (int i = 0; i < SIZE; i++) {
arr[i] = 0;
occupied[i] = false;
}
}


void add(int key) {
    int idx = hash(key);
    int start = idx;
    while (occupied[idx]) {
        idx = (idx + 1) % SIZE;
        if (idx == start) return;
    }
    arr[idx] = key;
    occupied[idx] = true;
}

void removeValue(int key) {
    int idx = hash(key);
    int start = idx;
    while (occupied[idx]) {
        if (arr[idx] == key) {
            occupied[idx] = false;
            return;
        }
        idx = (idx + 1) % SIZE;
        if (idx == start) return;
    }
}

void search(int key) {
    int idx = hash(key);
    int start = idx;
    while (occupied[idx]) {
        if (arr[idx] == key) {
            cout << key << " found\n";
            return;
        }
        idx = (idx + 1) % SIZE;
        if (idx == start) break;
    }
    cout << key << " not found\n";
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (occupied[i]) cout << arr[i] << " ";
    }
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
