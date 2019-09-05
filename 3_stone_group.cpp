#include<iostream>
#include<queue>
#include<utility>

using namespace std;

bool visited[1501][1501] = { false };

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void sort3(int *a, int *b, int *c) {
	if (*a > *b) 
		swap(a, b);
	if (*a > *c)
		swap(a, c);
	if (*b > *c)
		swap(b, c);
}

int main() {
	int a, b, c;
	int total=0;
	int res = 0;

	cin >> a >> b >> c;

	total = a + b + c;

	if (total % 3 == 0) {
		sort3(&a, &b, &c);
		queue<pair<int, int>>q;
		q.push(make_pair(a, b));
		visited[a][b] = true;

		while (!q.empty()) {
			int a = q.front().first, b = q.front().second;
			q.pop();
			int c = total - a - b;

			if (a == b && b == c) {
				res = 1; break;
			}

			for (int k = 0; k < 3; k++) {
				int x, y;
				int nx, ny, nz;
				if (k == 0) {
					x = a; y = b;
				}
				else if (k == 1) {
					x = b; y = c;
				}
				else {
					x = a; y = c;
				}

				if (x != y) {
					nx = x + x; ny = y - x; nz = total - nx - ny;
					sort3(&nx, &ny, &nz);
					if (!visited[nx][ny]) {
						q.push(make_pair(nx, ny));
						visited[nx][ny] = true;
					}
				}
			}
		}
	}
	cout << res << '\n';

	return 0;
}