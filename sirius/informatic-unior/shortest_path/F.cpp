#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll INF = 1000000000000000;
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(n, INF));
	for (ll i = 0; i < n; i++) {
		arr[i][i] = 0;
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			ll m;
			cin >> m;
			if (m != 100000) {
				arr[i][j] = min(arr[i][j], m);
			}
		}
	}
	for (ll i = 0; i < n; i++) {
		for (ll a = 0; a < n; a++) {
			for (ll b = 0; b < n; b++) {
				arr[a][b] = min(arr[a][b], arr[a][i]+arr[i][b]);
				if ((a == b) && (arr[a][b] < 0)) {
					cout << "YES";
					return 0;
				}
			}
		}
	}
	cout << "NO";
}
