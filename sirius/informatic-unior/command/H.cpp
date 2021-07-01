#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	vector<vector<ll>> arr(9, vector<ll>(0, 0));
	for (ll i = 1; i < 1111111; i++) {
		ll now = i;
		while (now >= 10) {
			ll nn = 1;
			for (auto i : to_string(now)) {
				if (i != '0') {
					nn *= i-'0';
				}
			}
			now = nn;
		}
		arr[now-1].push_back(i);
	}
	ll q;
	cin >> q;
	for (ll _ = 0; _ < q; _++) {
		ll l, r, k;
		cin >> l >> r >> k;
		cout << ((upper_bound(arr[k-1].begin(), arr[k-1].end(), r)-arr[k-1].begin())-(lower_bound(arr[k-1].begin(), arr[k-1].end(), l)-arr[k-1].begin())) << '\n';
	}
}
