#include<iostream>
#include<queue>

#define MAX 100000

bool visited[MAX + 1] = { false };
int dist[MAX + 1] = { 0 };

using namespace std;

int main() {
	queue<int> q;
	int n, k;

	cin >> n >> k;

	visited[n] = true;
	q.push(n);

	while (!q.empty()) {
		int currnt = q.front();
		q.pop();
		

		
		if (currnt-1>=0 && !visited[currnt - 1]) {
			q.push(currnt - 1);
			visited[currnt - 1] = true;
			dist[currnt - 1] = dist[currnt] + 1;
		}
		if (currnt+1<=MAX && !visited[currnt + 1]) {
			q.push(currnt + 1);
			visited[currnt + 1] = true;
			dist[currnt + 1] = dist[currnt] + 1;
		}
		if (currnt*2<=MAX && !visited[currnt * 2]) {
			q.push(currnt * 2);
			visited[currnt * 2] = true;
			dist[currnt * 2] = dist[currnt] + 1;
		}

	}

	cout << dist[k]<<'\n';

	return 0;
}