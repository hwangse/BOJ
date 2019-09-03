#include<iostream>
#include<utility>

using namespace std;

pair <int, int>stk[100];

int stkMax = 0;

int main() {
	int h, w;

	cin >> h >> w;

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> stk[i].first >> stk[i].second;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int tmpMax = -1;
				int r1, r2, c1, c2;
				//sticker1 : r1, c1 & sticker2 : r2, c2
				if (k == 0) {
					r1 = stk[i].first; c1 = stk[i].second;
					r2 = stk[j].first; c2 = stk[j].second;
				}
				else if (k == 1) {
					r1 = stk[i].first; c1 = stk[i].second;
					r2 = stk[j].second; c2 = stk[j].first;
				}
				else if (k == 2) {
					r1 = stk[i].second; c1 = stk[i].first;
					r2 = stk[j].first; c2 = stk[j].second;
				}
				else {
					r1 = stk[i].second; c1 = stk[i].first;
					r2 = stk[j].second; c2 = stk[j].first;
				}

				if (!(r1 <= w && c1 <= h)) //oversize sticker1
					continue;
				else {
					tmpMax = r1 * c1;

					if ((r2<=(w-r1) && c2<=h) || (c2<=(h-c1)&&r2<=w)) {
						tmpMax += r2 * c2;
						if (tmpMax > stkMax)
							stkMax = tmpMax;
					}
					else
						continue;
				}
			}
		}
	}
	cout << stkMax << '\n';

	return 0;
}