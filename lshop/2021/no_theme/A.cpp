#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	set<pair<ll, ll>> sr, sp;
	set<ll> s;
	for (ll i = 1; i <= n*4; i++) {
		s.insert(i);
	}
	for (ll i = 1; i <= n*4; i += 2) {
		sr.insert({i, i+1});
	}
	for (ll i = 2; i <= n*4; i += 4) {
		sp.insert({i, i+2});
	}
	for (ll i = 0; i < m; i++) {
		ll now;
		cin >> now;
		s.erase(now);
		if (now % 4 == 1) {
			sr.erase({now, now+1});
		}
		if (now % 4 == 2) {
			sr.erase({now-1, now});
			sp.erase({now, now+2});
		}
		if (now % 4 == 3) {
			sr.erase({now, now+1});
		}
		if (now % 4 == 0) {
			sr.erase({now-1, now});
			sp.erase({now-2, now});
		}
	}
	if (!sr.empty()) {
		cout << sr.begin()->first << ' ' << sr.begin()->second;
		return 0;
	}
	if (!sp.empty()) {
		cout << sp.begin()->first << ' ' << sp.begin()->second;
		return 0;
	}
	cout << *s.begin() << ' ' << *s.rbegin();
}
