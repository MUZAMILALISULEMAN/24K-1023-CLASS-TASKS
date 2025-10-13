#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n) {
    return (x < n && y < n && arr[x][y] == 1);
}

bool warehousePath(int **arr, int x, int y, int n, int **solArr) {
    if (x == n - 1 && y == n - 1) {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n)) {
        solArr[x][y] = 1;
        if (warehousePath(arr, x + 1, y, n, solArr))
            return true;
        if (warehousePath(arr, x, y + 1, n, solArr))
            return true;
        solArr[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    int n = 4;
    int maze[4][4] = {
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };

    int **arr = new int*[n];
    int **solArr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = maze[i][j];
            solArr[i][j] = 0;
        }
    }

    if (warehousePath(arr, 0, 0, n, solArr)) {
        cout << "PATH FOUND:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << solArr[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "NO PATH FOUND.\n";
    }

    return 0;
}
