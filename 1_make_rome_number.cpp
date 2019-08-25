#include<iostream>

using namespace std;

int totalCount = 0;
bool check[50 * 20 + 1] = { false };
int arr[5] = { 0,1,5,10,50 };

void countNum(int n, int selected,int currntNum,int total) {
	if (selected == n) {
		if (check[total] == false)
			check[total]=true;
		return;
	}
	if (currntNum > 4) return;
	//select currntNum
	countNum(n, selected + 1, currntNum, total + arr[currntNum]);
	//deselect currntNum
	countNum(n, selected, currntNum + 1,total);
}

int main() {
	int n;

	cin >> n;

	countNum(n, 0, 1, 0);

	for (int i = 1; i < 50 * 20 + 1; i++) {
		if (check[i])
			totalCount += 1;
	}

	cout << totalCount << '\n';

	return 0;
}