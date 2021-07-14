#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	multiset<ll> s;
	ll mex = 1;
	for (ll i = 0; i < n; i++) {
		ll now;
		cin >> now;
		s.insert(now);
	}
	while (!s.empty()) {
		ll now = *s.begin();
		s.erase(s.begin());
		if (now >= mex) {
			mex++;
		}
	}
	cout << mex;
}
