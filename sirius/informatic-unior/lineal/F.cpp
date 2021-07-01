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
	reverse(arr.begin(), arr.end());
	stack<pair<ll, ll>> s;
	s.push({-1, -1});
	stack<ll> ans;
	for (ll i = 0; i < n; i++) {
		while (s.top().first >= arr[i]) {
			s.pop();
		}
		ans.push(s.top().second);
		s.push({arr[i], n-i-1});
	}
	while (!ans.empty()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
}
