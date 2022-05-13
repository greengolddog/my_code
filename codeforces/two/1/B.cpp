#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> arr(n, 0), rra(m, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (ll i = 0; i < m; i++) {
		cin >> rra[i];
	}
	ll u = 0;
	for (auto i : rra) {
		while ((u < n) && (arr[u] < i)) {
			u++;
		}
		cout << u << ' ';
	}
}
