#include <iostream>
#include <string>
using namespace std;

class item
{
    string title;
    double cost;
    string details;
    bool inStock;
public:
    item(string t, double c, string det, bool s) : title(t), cost(c), details(det), inStock(s) {}
    double getCost() const { return cost; }
    string getTitle() const { return title; }
    string getDetails() const { return details; }
    bool isInStock() const { return inStock; }
};

void exchange(item &x, item &y)
{
        item temp = x;
    x = y;
        y = temp;
}

int divide(item list[], int start, int end)
{
    double pivotCost = list[end].getCost();
        int i = start - 1;
            for (int j = start; j < end; j++)
    {
        if (list[j].getCost() < pivotCost)
        {
                i++;
            exchange(list[i], list[j]);
        }
    }
        exchange(list[i + 1], list[end]);
    return i + 1;
}

void sortQuick(item list[], int start, int end)
{
        if (start < end)
    {
            int pivotIndex = divide(list, start, end);
        sortQuick(list, start, pivotIndex - 1);
            sortQuick(list, pivotIndex + 1, end);
    }
}

void showItems(item list[], int count)
{
        for (int i = 0; i < count; i++)
    {
        cout << "ITEM TITLE: " << list[i].getTitle() << endl;
            cout << "COST: $" << list[i].getCost() << endl;
        cout << "DETAILS: " << list[i].getDetails() << endl;
            cout << "STOCK: " << (list[i].isInStock() ? "AVAILABLE" : "UNAVAILABLE") << endl;
        cout << endl;
    }
}

int main()
{
    item inventory[3] = {
        item("Lays", 1000, "xys", true),
            item("Cakes", 540, "etry", true),
        item("Biscuits", 3400, "uytuy", false)};
        sortQuick(inventory, 0, 2);
    cout << "SORTED ITEM LIST BY COST:" << endl;
        showItems(inventory, 3);
}