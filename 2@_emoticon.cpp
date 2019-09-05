#include<iostream>
#include<queue>

using namespace std;

#define MAX 2000

bool visited[MAX + 1] = { false };
int currntClipBoard[MAX + 1] = { 0 };
int minT[MAX + 1] = { 0 };

int main() {
	int s;

	cin >> s;

	queue<int> q;
	q.push(1);
	visited[1] = true;
	minT[1] = 1; //copy 1 to clipboard
	currntClipBoard[1] = 1; //currntly 1 in clipboard

	while (!q.empty()) {
		int now = q.front();
		q.pop();
	
		if (now - 1 >= 2 && !visited[now - 1]) {
			q.push(now - 1);
			visited[now - 1] = true;
			minT[now - 1] = minT[now] + 1;
			currntClipBoard[now - 1] = currntClipBoard[now];
		}
		/////////////////////////////////////////////////////

		if (now + currntClipBoard[now] <= MAX && !visited[now + currntClipBoard[now]]) {
			q.push(now + currntClipBoard[now]);
			visited[now + currntClipBoard[now]] = true;
			minT[now + currntClipBoard[now]] = minT[now] + 1;
			currntClipBoard[now + currntClipBoard[now]] = currntClipBoard[now];
		}
		if (now != currntClipBoard[now] && now * 2 <= MAX && !visited[now * 2]) {
			q.push(now * 2);
			visited[now * 2]=true;
			minT[now * 2] = minT[now] + 2;
			currntClipBoard[now * 2] = now;
		}
	}
	cout << minT[s] << '\n';



	return 0;
}