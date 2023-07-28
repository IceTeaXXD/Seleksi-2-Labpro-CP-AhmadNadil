#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, x, y, p, q;
    cin >> n >> x >> y >> p >> q;
    x--;y--;p--;q--;
    int xmove[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int ymove[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    vector<vector<int>> board(n, vector<int>(n, 0));
    queue<pair<int, int>> qu;
    qu.push(make_pair(x, y));
    board[x][y] = 1;

    while (!qu.empty()) {
        pair<int, int> pos = qu.front();
        qu.pop();

        if (pos.first == p && pos.second == q) {
            cout << board[pos.first][pos.second] - 1 << endl;
            return 0;
        }

        for (int i = 0; i < 8; i++) {
            int nextX = pos.first + xmove[i];
            int nextY = pos.second + ymove[i];

            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
                if (board[nextX][nextY] == 0){
                    board[nextX][nextY] = board[pos.first][pos.second] + 1;
                    qu.push(make_pair(nextX, nextY));
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}