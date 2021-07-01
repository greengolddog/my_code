#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll a = 0;
	vector<ll> arr(m+1, 0);
	for (ll i = 0; i < n; i++) {
		for (ll i = 0; i < m; i++) {
			ll in;
			cin >> in;
			if (in == 1) {
				arr[i] = 0;
			} else {
				arr[i]++;
			}
		}
		arr[m] = -1;
		stack<pair<ll, ll>> s;
		s.push({-2, -1});
		ll ans = 0;
		for (ll i = 0; i < arr.size(); i++) {
			while (s.top().first >= arr[i]) {
				ll now = s.top().first;
				s.pop();
				ans = max(ans, now*(i-s.top().second-1));
			}
			s.push({arr[i], i});
		}
		a = max(a, ans);
	}
	cout << a;
}
