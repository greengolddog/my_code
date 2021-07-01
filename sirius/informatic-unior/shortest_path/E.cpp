#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<bool>> arr(n, vector<bool>(n, false));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			ll m;
			cin >> m;
			arr[i][j] = m;
		}
	}
	for (ll k = 0; k < n; k++) {
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				arr[i][j] = arr[i][j] | (arr[i][k] && arr[k][j]);
			}
		}
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}
