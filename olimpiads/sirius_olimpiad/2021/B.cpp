#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll s, t, m, n;
	cin >> s >> t >> m >> n;
	vector<ll> start(t, 0), finish(t, 0);
	for (ll i = 0; i < t; i++) {
		cin >> start[i];
	}
	for (ll i = 0; i < t; i++) {
		cin >> finish[i];
	}
	vector<ll> c(m, 0), d(n, 0);
	for (ll i = 0; i < m; i++) {
		cin >> c[i];
	}
	for (ll i = 0; i < n; i++) {
		cin >> d[i];
	}
	for (ll i = 0; i < t; i++) {
		ll last = 0;
		for (ll j = 0; j < n; j++) {
			while ((last != m) && (c[last]+finish[i] <= d[j]+s-finish[i])) {
				last++;
			}
			if (last == m) {
				break;
			}
			if (c[last]+start[i] < d[j]+s-start[i]) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}
