#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	int n, l, r, q,b;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> q;
	for (int i = 0; i < q;i++) {
		cin >> l >> r;
		b = 0;
		for (int j = l-1; j < r; j++) {
			if (arr[j] != 1) {
				b = 1;
				break;
			}
		}
		if (b == 0) {
			cout << 2 << endl;
		} else {
			cout << 1 << endl;
		}
	}
}