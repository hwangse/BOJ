#include<iostream>
#include<queue>
#include<utility>

using namespace std;

int map[101][101] = { 0 };
bool visited[101][101] = { false };
int cost[101][101] = { 0 };

int dy[4] = {-1,1,0,0};
int dx[4] = { 0,0,-1,1 };

int main() {
	int n, m;
	queue<pair<int, int>> q;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char tmp;
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
	}

	q.push(make_pair(1, 1));
	visited[1][1] = true;
	cost[1][1] = 1;

	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		q.pop();

		//code refactoring
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (1 <= ny && ny <= n && 1 <= nx && nx <= m && !visited[ny][nx] && map[ny][nx]) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
				cost[ny][nx] = cost[y][x] + 1;
			}
		}
	}
	cout << cost[n][m] << '\n';

	return 0;
}