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
	for (ll i = 0; i < n; i++) {
		string c;
		cin >> c;
		if (c == "COUNT") {
			cout << s.size() << '\n';
		} else {
			ll a;
			cin >> a;
			if (c == "ADD") {
				s.insert(a);
			} else {
				cout << ((s.find(a) != s.end()) ? "YES" : "NO") << '\n';
			}
		}
	}
}
