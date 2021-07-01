#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll INF = 1000000000000000;
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> arr(n, vector<ll>(n, INF));
	for (ll i = 0; i < n; i++) {
		arr[i][i] = 0;
	}
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		arr[a][b] = min(arr[a][b], c);
	}
	for (ll i = 0; i < n; i++) {
		for (ll a = 0; a < n; a++) {
			for (ll b = 0; b < n; b++) {
				arr[a][b] = min(arr[a][b], arr[a][i]+arr[i][b]);
			}
		}
	}
	for (ll s = 0; s < n; s++) {
		for (ll f = 0; f < n; f++) {
			cout << ((arr[s][f] > INF/10) ? 30000 : arr[s][f]) << ' ';
		}
		cout << '\n';
	}
}
