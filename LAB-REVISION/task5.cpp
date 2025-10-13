#include <iostream>
using namespace std;

const int N = 5;

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1);
}

bool findPath(int maze[N][N], int x, int y, int destX, int destY, int sol[N][N]) {
    if (x == destX && y == destY) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        sol[x][y] = 1;

        if (findPath(maze, x + 1, y, destX, destY, sol)) return true;
        if (findPath(maze, x - 1, y, destX, destY, sol)) return true;
        if (findPath(maze, x, y + 1, destX, destY, sol)) return true;
        if (findPath(maze, x, y - 1, destX, destY, sol)) return true;

        sol[x][y] = 0; // backtrack
        return false;
    }

    return false;
}

int main() {
    int maze[N][N] = {
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };

    int rabbitSol[N][N] = {0};
    int catSol[N][N] = {0};

    if (findPath(maze, 0, 0, 2, 2, rabbitSol)) {
        cout << "RABBIT PATH FROM (0,0) TO (2,2):\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << rabbitSol[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "NO PATH FOUND FOR RABBIT.\n";
    }

    if (findPath(maze, 4, 4, 2, 2, catSol)) {
        cout << "\nCAT PATH FROM (4,4) TO (2,2):\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << catSol[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "NO PATH FOUND FOR CAT.\n";
    }

    cout << "\nINTERSECTION POINTS:\n";
    bool found = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rabbitSol[i][j] == 1 && catSol[i][j] == 1) {
                cout << "(" << i << "," << j << ") ";
                found = true;
            }
        }
    }
    if (!found)
        cout << "NO INTERSECTIONS FOUND.\n";

    return 0;
}
