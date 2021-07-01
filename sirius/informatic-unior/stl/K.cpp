#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k, p;
	cin >> n >> k >> p;
	vector<ll> com(p, 0);
	vector<ll> last(n, 1);
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 0; i < p; i++) {
		cin >> com[i];
		com[i]--;
		arr[com[i]].push_back(i);
	}
	vector<ll> m(n, -1000);
	for (ll i = 0; i < n; i++) {
		arr[i].push_back(n+1);
	}
	set<pair<ll, ll>> s;
	ll ans = 0;
	for (auto i : com) {
		if (m[i] == -1000) {
			if (s.size() == k) {
				ans++;
				m[(*s.rbegin()).second] = -1000;
				s.erase(*s.rbegin());
				s.insert({arr[i][last[i]], i});
				m[i] = arr[i][last[i]];
				last[i]++;
			} else {
				ans++;
				s.insert({arr[i][last[i]], i});
				m[i] = arr[i][last[i]];
				last[i]++;
			}
		} else {
			s.erase({m[i], i});
			s.insert({arr[i][last[i]], i});
			m[i] = arr[i][last[i]];
			last[i]++;
		}
	}
	cout << ans;
}
