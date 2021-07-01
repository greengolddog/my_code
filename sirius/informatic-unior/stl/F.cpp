#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	set<ll> s;
	for (ll i = 1; i <= 300000; i++) {
		s.insert(i);
	}
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		if (a < 0) {
			s.insert(-a);
		} else {
			cout << *s.lower_bound(a) << '\n';
			s.erase(s.lower_bound(a));
		}
	}
}
