#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll iii = 0; iii < t; iii++) {
		ll n;
		cin >> n;
		vector<float> arr(n, 0.0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		vector<float> sa;
		sa = arr;
		sort(sa.begin(), sa.end());
		ll now = 0;
		stack<float> s;
		for (ll i = 0; i < n; i++) {
			s.push(arr[i]);
			while ((!s.empty()) && (s.top() == sa[now])) {
				s.pop();
				now++;
			}
		}
		if (s.empty()) {
			cout << 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}
