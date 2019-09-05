#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int map[26][26] = { 0 };
bool visited[26][26] = { false };
int danji_num[25 * 25] = { 0 };

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char tmp;
			cin >> tmp;
			map[i][j] = tmp - '0';
		}
	}

	int danji = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && map[i][j]) { //new danji
				danji++;
				queue<pair<int, int>> q;

				q.push(make_pair(i, j));
				visited[i][j] = true;
				danji_num[danji]++;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];

						if (0 <= nx && nx <= n && 0 <= ny && ny <= n && !visited[ny][nx] && map[ny][nx]) {
							q.push(make_pair(ny, nx));
							visited[ny][nx] = true;
							danji_num[danji]++;
						}
					}
				}
			}
		}
	}
	cout << danji << '\n';
	
	sort(danji_num + 1, danji_num + danji+1);

	for (int i = 1; i <= danji; i++)
		cout << danji_num[i] << '\n';

	return 0;
}