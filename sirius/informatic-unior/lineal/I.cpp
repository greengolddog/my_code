#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	vector<ll> col(k, 0);
	ll e = 0, cn = k;
	pair<ll, pair<ll, ll>> ans = {1000000000000, {0, 0}};
	for (ll i = 0; i <= arr.size(); i++) {
		if (i != 0) {
			col[arr[i-1]]--;
			if (col[arr[i-1]] == 0) {
				cn++;
			}
		}
		while (e < arr.size() && cn != 0) {
			if (col[arr[e]] == 0) {
				cn--;
			}
			col[arr[e]]++;
			e++;
		}
		if (cn != 0) {
			break;
		}
		ans = min(ans, make_pair(e-i, make_pair(i, e-1)));
	}
	cout << ans.second.first+1 << ' ' << ans.second.second+1;
}
