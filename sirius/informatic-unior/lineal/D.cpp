#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll sum = 0, u = 0;
	pair<ll, pair<ll, ll>> ans = {-1000000000000000, {0, 0}};
	for (ll i = 0; i < n; i++) {
		sum += arr[i];
		ans = max(ans, {sum, {-i, u}});
		if (sum <= 0) {
			sum = 0;
			u = i+1;
		}
	}
	cout << ans.second.second+1 << '\n' << -ans.second.first+1;
}
