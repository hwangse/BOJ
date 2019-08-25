#include<iostream>

using namespace std;

typedef struct {
	int t;
	int p;
}DayInfo;

DayInfo dayInfo[16];
int maxProfit = -1;

void calcProfit(int today, int profit, int n) {
	if (today==n+1) {
		if (profit > maxProfit)
			maxProfit = profit;
		return;
	}
	if (today > n) return;
	//������ ���õ� ���
	calcProfit(today + dayInfo[today].t, profit + dayInfo[today].p, n);
	//������ ���õ��� ���� ���
	calcProfit(today + 1, profit, n);
}

int main() {
	int day;

	cin >> day;

	for (int i = 1; i <= day; i++)
		cin >> dayInfo[i].t >> dayInfo[i].p;

	calcProfit(1, 0, day);
	
	cout << maxProfit;

	return 0;
}