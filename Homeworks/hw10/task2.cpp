/*#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1001;

int cinema[N][N];
int visited[N][N];
int movieTime[N][N];
int n;
int m;
int result = 0;

bool check(int X, int Y) {
    return (X > 0 && Y > 0 && X <= n && Y <= m);
}

void bfs(int x, int y) {
    queue<pair<int, int>>q;
    visited[x][y] = 1;
    q.push({ x,y });
    while (!q.empty()) {
        int X = q.front().first;
        int Y = q.front().second;
        q.pop();

        if (check(X - 1, Y)) {
            if (visited[X - 1][Y] == 0) {
                q.push({ X - 1, Y });
                visited[X - 1][Y] = 1;
                movieTime[X - 1][Y] = movieTime[X][Y] + 1;
            }
            else if (visited[X - 1][Y] == -1) {
                q.push({ X - 1, Y });
                visited[X - 1][Y] = 2;
                movieTime[X - 1][Y] = movieTime[X][Y] + 1;
            }
        }

        if (check(X + 1, Y)) {
            if (visited[X + 1][Y] == 0) {
                q.push({ X + 1, Y });
                visited[X + 1][Y] = 1;
                movieTime[X + 1][Y] = movieTime[X][Y] + 1;
            }
            else if (visited[X + 1][Y] == -1) {
                q.push({ X + 1, Y });
                visited[X + 1][Y] = 2;
                movieTime[X + 1][Y] = movieTime[X][Y] + 1;
            }
        }

        if (check(X, Y - 1)) {
            if (visited[X][Y - 1] == 0) {
                q.push({ X ,Y - 1 });
                visited[X][Y - 1] = 1;
                movieTime[X][Y - 1] = movieTime[X][Y] + 1;
            }
            else if (visited[X][Y - 1] == -1) {
                q.push({ X ,Y - 1 });
                visited[X][Y - 1] = 2;
                movieTime[X][Y - 1] = movieTime[X][Y] + 1;
            }
        }

        if (check(X, Y + 1)) {
            if (visited[X][Y + 1] == 0) {
                q.push({ X ,Y + 1 });
                visited[X][Y + 1] = 1;
                movieTime[X][Y + 1] = movieTime[X][Y] + 1;
            }
            else if (visited[X][Y + 1] == -1) {
                q.push({ X ,Y + 1 });
                visited[X][Y + 1] = 2;
                movieTime[X][Y + 1] = movieTime[X][Y] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int guests = n * m;

    int T, K;
    cin >> T >> K;
    int first_x, first_y;
    int second_x, second_y;
    cin >> first_x >> first_y;
    bfs(first_x, first_y);
    int sick = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (movieTime[i][j] <= T && movieTime[i][j] != 0) {
                sick++;
                visited[i][j] = -1;
            }
            else {
                visited[i][j] = 0;
            }
            movieTime[i][j] = 0;
        }
    }

    if (K == 2) {
        cin >> second_x >> second_y;
        sick++;
        bfs(second_x, second_y);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (movieTime[i][j] <= T && movieTime[i][j] != 0 && visited[i][j] != 2) {
                if (i == first_x && j == first_y) {};
                sick++;
            }
        }
    }

    int result = guests - sick;
    cout << result;


    return 0;
}*/