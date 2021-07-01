#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> nn(n, 0), mm(m, 0);
	for (ll i = 0; i < n; i++) {
		cin >> nn[i];
	}
	for (ll i = 0; i < m; i++) {
		cin >> mm[i];
	}
	vector<ll> ans;
	ll u1 = 0, u2 = 0;
	while ((u1 < n) && (u2 < m)) {
		if (nn[u1] <= mm[u2]) {
			ans.push_back(nn[u1]);
			u1++;
		} else {
			ans.push_back(mm[u2]);
			u2++;
		}
	}
	for (ll i = u1; i < n; i++) {
		ans.push_back(nn[i]);
	}
	for (ll i = u2; i < m; i++) {
		ans.push_back(mm[i]);
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
}
