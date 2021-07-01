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
	for (ll i = 0; i < n; i++) {
		ll c;
		cin >> c;
		if (c == 1) {
			cout << *(s.rbegin()) << '\n';
			s.erase(s.find(*(s.rbegin())));
		} else {
			ll a;
			cin >> a;
			s.insert(a);
		}
	}
}
