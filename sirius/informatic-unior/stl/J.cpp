#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n;
	unordered_set<ll> s1, s2;
	vector<ll> a1, a2;
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		s1.insert(a);
		a1.push_back(a);
	}
	cin >> m;
	for (ll i = 0; i < m; i++) {
		ll a;
		cin >> a;
		s2.insert(a);
		a2.push_back(a);
	}
	vector<ll> ans;
	for (auto i : a1) {
		if (s2.find(i) == s2.end()) {
			ans.push_back(i);
		}
	}
	for (auto i : a2) {
		if (s1.find(i) == s1.end()) {
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end())-ans.begin());
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i << '\n';
	}
}
