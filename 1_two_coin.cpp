#include<iostream>
#include<utility>

using namespace std;

char board[20][20];

int cnt = -1;

int n, m;

void moveCoins(pair<int,int >p1,pair<int,int>p2,int move,int bye_coin) {
	/* Ending condition */
	if (move > 10)
		return;
	else if (bye_coin > 1)
		return;
	else if (bye_coin == 1) {
		if (cnt == -1) 
			cnt = move;
		else if (move < cnt)
			cnt = move;

		return;
	}

	/* Continuing condition */
	//up
	pair<int, int>newP1, newP2;

	int bye = 0;

	if (p1.first>0 && board[p1.first-1][p1.second] == '.') {	//normal
		newP1 = make_pair(p1.first-1, p1.second);
	}
	else if (p1.first == 0) {									//cliff
		newP1 = p1;
		bye += 1;
	}
	else //cannot move
		newP1 = p1;

	if (p2.first>0 && board[p2.first - 1][p2.second] == '.') {	//normal
		newP2 = make_pair(p2.first - 1, p2.second);
	}
	else if (p2.first == 0) {									//cliff
		newP2 = p2;
		bye += 1;
	}
	else //cannot move
		newP2 = p2;

	moveCoins(newP1, newP2, move + 1, bye_coin + bye);

	//down
	bye = 0;

	if (p1.first<n-1 && board[p1.first + 1][p1.second] == '.') {	//normal
		newP1 = make_pair(p1.first + 1, p1.second);
	}
	else if (p1.first == n-1) {									//cliff
		newP1 = p1;
		bye += 1;
	}
	else //cannot move
		newP1 = p1;

	if (p2.first<n-1 && board[p2.first + 1][p2.second] == '.') {	//normal
		newP2 = make_pair(p2.first + 1, p2.second);
	}
	else if (p2.first == n-1) {									//cliff
		newP2 = p2;
		bye += 1;
	}
	else //cannot move
		newP2 = p2;

	moveCoins(newP1, newP2, move + 1, bye_coin + bye);

	//left
	bye = 0;

	if (p1.second>0 && board[p1.first][p1.second-1] == '.') {	//normal
		newP1 = make_pair(p1.first, p1.second-1);
	}
	else if (p1.second == 0) {									//cliff
		newP1 = p1;
		bye += 1;
	}
	else //cannot move
		newP1 = p1;

	if (p2.second>0 && board[p2.first][p2.second-1] == '.') {	//normal
		newP2 = make_pair(p2.first, p2.second-1);
	}
	else if (p2.second == 0) {									//cliff
		newP2 = p2;
		bye += 1;
	}
	else //cannot move
		newP2 = p2;

	moveCoins(newP1, newP2, move + 1, bye_coin + bye);

	//right
	bye = 0;

	if (p1.second<m-1 && board[p1.first][p1.second + 1] == '.') {	//normal
		newP1 = make_pair(p1.first, p1.second + 1);
	}
	else if (p1.second == m-1) {									//cliff
		newP1 = p1;
		bye += 1;
	}
	else //cannot move
		newP1 = p1;

	if (p2.second<m-1 && board[p2.first][p2.second + 1] == '.') {	//normal
		newP2 = make_pair(p2.first, p2.second + 1);
	}
	else if (p2.second == m-1) {									//cliff
		newP2 = p2;
		bye += 1;
	}
	else //cannot move
		newP2 = p2;

	moveCoins(newP1, newP2, move + 1, bye_coin + bye);

}

int main() {
	int count = 0;
	pair<int, int>p1, p2;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				if (count == 0)
					p1 = make_pair(i, j);
				else if (count == 1)
					p2 = make_pair(i, j);
				count += 1;
				board[i][j] = '.';
			}
		}
	}

	moveCoins(p1, p2, 0, 0);


	cout << cnt <<'\n';

	return 0;
}