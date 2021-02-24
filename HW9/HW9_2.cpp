#include <iostream>
#include <vector>
using namespace std;
void helper(vector<vector<char>>& grid, int x, int y, int& cnt, int& res)
{
	if (x < 0 || x >= grid.size()) return;
	if (y < 0 || y >= grid[0].size()) return;
	if (grid[x][y] != 49) return;
	grid[x][y] = -1;
	cnt++;
	res = max(res, cnt);
	vector<vector<int>> dirs{ { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };
	for (auto dir : dirs)
		helper(grid, x + dir[0], y + dir[1], cnt, res);
}
int maxAreaOfIsland(vector<vector<char>>& grid)
{
	if (grid.empty() || grid[0].empty()) return 0;
	int m = grid.size(), n = grid[0].size(), res = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] != 49)continue;
			int cnt = 0;
			helper(grid, i, j, cnt, res);
		}
	}
	return res;
}
int main()
{
	int w, l, i, j;
	char input;
	cin >> w >> l;
	vector<vector<char>> matrix(w, vector<char>(l));
	for (i = 0; i < w; i++)
	{
		for (j = 0; j < l; j++)
		{
			cin >> input;
			matrix[i][j] = input;
		}
	}
	cout << maxAreaOfIsland(matrix) << endl;
	return 0;
}
