#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	set<ll> num;
	for (ll i = 1; i <= n; i++) {
		num.insert(i);
	}
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (num.lower_bound(x) == num.end()) {
			cout << *num.begin() << ' ';
			num.erase(num.begin());
		} else {
			cout << *num.lower_bound(x) << ' ';
			num.erase(num.lower_bound(x));
		}
	}
}
