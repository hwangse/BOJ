#include <iostream>
using namespace std;

bool check[10] = { false };
int arr[10] = { 0 };

void findP(int n, int m, int count,int start) {
	if (count == m) {
		//print array
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	for (int i = start; i <= n; i++) {
		if (check[i]) continue;
		check[i] = true;
		arr[count] = i;
		findP(n, m, count + 1,i+1);
		check[i] = false;
	}
}

int main() {
	int n, m;

	cin >> n >> m;

	findP(n, m, 0,1);

	return 0;
}