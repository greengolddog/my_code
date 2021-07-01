#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, col;
	cin >> n;
	col = n/2;
	vector<char> arr(n, ' ');
	for (ll i = 0; i < n-1; i++) {
		cout << "? " << i+1 << ' ' << i+2 << endl;
		string a;
		cin >> a;
		if (a == "Yes") {
			arr[i] = '(';
			arr[i+1] = ')';
			col--;
		}
	}
	for (ll i = 0; i < n; i++) {
		if (arr[i] == ' ') {
			if (col == 0) {
				arr[i] = ')';
			} else {
				arr[i] = '(';
				col--;
			}
		}
	}
	cout << "! ";
	for (auto i : arr) {
		cout << i;
	}
}
