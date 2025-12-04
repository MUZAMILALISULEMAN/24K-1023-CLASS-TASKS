#include <iostream>
using namespace std;

class StudentHashTable {
private:
    struct Record {
        int roll;
        string name;
        bool occupied;
        Record() { roll = -1; name = ""; occupied = false; }
    };

    Record table[15];
    int size = 15;

    int hashFunction(int roll) {
        return roll % size;
    }

public:
    void add(int roll, string name) {
        int index = hashFunction(roll);

        for (int attempt = 0; attempt < size; attempt++) {
            int newIndex = (index + attempt * attempt) % size;

            if (!table[newIndex].occupied) {
                table[newIndex].roll = roll;
                table[newIndex].name = name;
                table[newIndex].occupied = true;
                return;
            }
        }

        cout << "Hash table is full. Cannot insert record.\n";
    }

    void find(int roll) {
        int index = hashFunction(roll);

        for (int attempt = 0; attempt < size; attempt++) {
            int newIndex = (index + attempt * attempt) % size;

            if (table[newIndex].occupied && table[newIndex].roll == roll) {
                cout << "Record Found: " << table[newIndex].name << endl;
                return;
            }
        }

        cout << "Record not found\n";
    }
};

int main() {
    StudentHashTable ht;

    ht.add(101, "Rauf");
    ht.add(116, "Muzamil");
    ht.add(131, "Shahmir");
    ht.add(146, "Azmir Waqar");

    ht.find(131);
    ht.find(200);

    return 0;
}