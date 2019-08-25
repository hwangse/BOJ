#include<iostream>

using namespace std;

int arr[10];

void recursive(int n, int m,int selected,int currntVal) {
	if (selected == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	if (currntVal > n) return;
	//select currentVal
	arr[selected] = currntVal;
	recursive(n, m, selected + 1, currntVal + 1);
	//deselect currentVal
	arr[selected] = 0;
	recursive(n, m, selected, currntVal + 1);
}

int main() {
	int n, m;

	cin >> n >> m;
	
	recursive(n, m, 0, 1);

	return 0;
}