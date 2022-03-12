/*#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, vector<vector<char>>& adjMat,
    vector<vector<bool>>& visited, int& ans,
    int CurrentVisited, int TotalforVisit) {
    int rows = adjMat.size(), cols = adjMat[0].size();

    visited[i][j] = 1;
	if (adjMat[i][j] == '-') CurrentVisited++;

    if (adjMat[i][j] == 'e') {
        if (CurrentVisited == TotalforVisit) ans++;
        visited[i][j] = 0;
        return;
    }

    if (i >= 1 && !visited[i - 1][j] && adjMat[i - 1][j] != 'x') dfs(i - 1, j, adjMat, visited, ans, CurrentVisited, TotalforVisit);

    if (i < rows - 1 && !visited[i + 1][j] && adjMat[i + 1][j] != 'x') dfs(i + 1, j, adjMat, visited, ans, CurrentVisited, TotalforVisit);

    if (j >= 1 && !visited[i][j - 1] && adjMat[i][j - 1] != 'x') dfs(i, j - 1, adjMat, visited, ans, CurrentVisited, TotalforVisit);

    if (j < cols - 1 && !visited[i][j + 1] && adjMat[i][j + 1] != 'x') dfs(i, j + 1, adjMat, visited, ans, CurrentVisited, TotalforVisit);

    visited[i][j] = 0;
}


int findPaths(vector<vector<char>> adjMat) {
	int TotalforVisit = 0;
	int rows = adjMat.size(), cols = adjMat[0].size();
	int ans = 0;
	vector<vector<bool> > vis(rows, vector<bool>(cols, 0));

	int x, y;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (adjMat[i][j] == '-')TotalforVisit++;
			else if (adjMat[i][j] == 's') {
				x = i, y = j;
			}
		}
	}
	dfs(x, y, adjMat, vis, ans, 0, TotalforVisit);
	return ans;
}

int main() {
	int rows, cols;
	cin >> rows >> cols;

	vector<vector<char>> adjMat(rows,vector<char>(cols));
	char symbol;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> symbol;
			adjMat[i][j] = symbol;
		}
	}
	cout << findPaths(adjMat);
	return 0;
}*/