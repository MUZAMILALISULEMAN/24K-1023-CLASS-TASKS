#include <iostream>
using namespace std;

struct element {
    int value;
    element* next;
    element* prev;
    element(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class doublyList {
public:
    element* start;
    doublyList() : start(nullptr) {}
  
    void insert(int val) {
        element* newElem = new element(val);
            if (start == nullptr) {
                start = newElem;
            return;
        }
            element* walker = start;
        while (walker->next) {
            walker = walker->next;
        }
        walker->next = newElem;
            newElem->prev = walker;
    }
  
    void display() {
            element* walker = start;
        while (walker) {
            cout << walker->value << " ";
                walker = walker->next;
        }
        cout << endl;
    }
  
    void exchange(element* firstElem, element* secondElem) {
        int temp = firstElem->value;
            firstElem->value = secondElem->value;
        secondElem->value = temp;
    }
    element* divide(element* left, element* right) {
        int pivotVal = right->value;
            element* marker = left->prev;
        for (element* current = left; current != right; current = current->next) {
            if (current->value <= pivotVal) {
                marker = (marker == nullptr) ? left : marker->next;
                    exchange(marker, current);
            }
        }
            marker = (marker == nullptr) ? left : marker->next;
        exchange(marker, right);
            return marker;
    }
  
    void sortQuick(element* left, element* right) {
        if (left && right && left != right && left != right->next) {
                element* pivotNode = divide(left, right);
            sortQuick(left, pivotNode->prev);
                sortQuick(pivotNode->next, right);
        }
    }
    void sortQuick() {
        sortQuick(start, getLast());
    }
    element* getLast() {
        element* walker = start;
            while (walker && walker->next) {
                walker = walker->next;
        }
            return walker;
    }
};

int main() {
    doublyList numbers;
        numbers.insert(10);
    numbers.insert(7);
        numbers.insert(8);
    numbers.insert(9);
        numbers.insert(1);
    numbers.insert(5);
        numbers.insert(3);
    cout << "ORIGINAL LIST: ";
        numbers.display();
    numbers.sortQuick();
        cout << "SORTED LIST USING QUICKSORT: ";
    numbers.display();
        return 0;
}