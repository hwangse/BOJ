#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int map[1001][1001][2] = { 0 };
int cost[1001][1001][2] = { -1 };
bool visited[1001][1001][2] = { false };

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char tmp;
			cin >> tmp;
			map[i][j][0] = tmp - '0';
			map[i][j][1] = tmp - '0';
		}
	}
	queue<tuple<int, int, int>>q;

	q.push(make_tuple(1, 1, 0));
	visited[1][1][0] = true;
	cost[1][1][0] = 1;
	visited[1][1][1] = true;
	cost[1][1][1] = 1;

	while (!q.empty()) {
		int y = get<0>(q.front());
		int x = get<1>(q.front());
		int wall_flag = get<2>(q.front());
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (1 <= nx && nx <= m && 1 <= ny && ny <= n && !visited[ny][nx][wall_flag]) {
				if (!map[ny][nx][wall_flag]) { 
						q.push(make_tuple(ny, nx, wall_flag));
						visited[ny][nx][wall_flag]=true;
						cost[ny][nx][wall_flag] = cost[y][x][wall_flag] + 1;
				}

				if(map[ny][nx][wall_flag] && !wall_flag && !visited[ny][nx][1]){ //break the wall
					q.push(make_tuple(ny, nx, 1));
					visited[ny][nx][1]=true;
					cost[ny][nx][1] = cost[y][x][0] + 1;
				}
			}
		}
	}
	int minCost;

	if (!cost[n][m][0] && !cost[n][m][1])
		minCost = -1;
	else if (cost[n][m][0] && cost[n][m][1])
		minCost = cost[n][m][0] < cost[n][m][1] ? cost[n][m][0] : cost[n][m][1];
	else
		minCost = cost[n][m][0] == 0 ? cost[n][m][1] : cost[n][m][0];

	cout << minCost << '\n';

	return 0;
}