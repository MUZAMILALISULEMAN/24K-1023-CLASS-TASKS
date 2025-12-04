
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
   string data;
   Node *next;
   Node(string val) : data(val), next(nullptr) {}
};

class hashTable
{
private:
   vector<Node *> table;
   int buckets;

   int hashFunction(const string &key)
   {
      int sum = 0;
      for (char c : key)
         sum += int(c);
      return sum % buckets;
   }

public:
   hashTable(int size) : buckets(size)
   {
      table.resize(buckets, nullptr);
   }

   void add(const string &key)
   {
      int index = hashFunction(key);
      Node *newNode = new Node(key);
      newNode->next = table[index];
      table[index] = newNode;
   }

   bool search(const string &key)
   {
      int index = hashFunction(key);
      Node *temp = table[index];
      while (temp != nullptr)
      {
         if (temp->data == key)
            return true;
         temp = temp->next;
      }
      return false;
   }

   void show()
   {
      cout << "Hash Table:\n";
      for (int i = 0; i < buckets; i++)
      {
         cout << "Bucket " << i << ": ";
         Node *temp = table[i];
         if (!temp)
         {
            cout << "NULL\n";
            continue;
         }
         while (temp != nullptr)
         {
            cout << temp->data << " -> ";
            temp = temp->next;
         }
         cout << "NULL\n";
      }
   }
};

int main()
{
   hashTable ht(10);

   ht.add("apple");
   ht.add("mango");
   ht.add("apple");
   ht.add("grapes");
   ht.add("peach");
   ht.add("banana");

   ht.show();

   cout << "\nSearching 'apple': "
        << (ht.search("apple") ? "Found" : "Not Found") << endl;

   cout << "searching 'muzamil': "
        << (ht.search("muzamil") ? "Found" : "Not Found") << endl;

   return 0;
}
