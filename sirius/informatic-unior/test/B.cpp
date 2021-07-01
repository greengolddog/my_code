#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	deque<string> d;
	for (ll i = 0; i < n; i++) {
		string s, c;
		cin >> s >> c;
		if (c == "top") {
			d.push_front(s);
		} else {
			d.push_back(s);
		}
	}
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		ll x;
		cin >> x;
		cout << d[x-1] << '\n';
	}
}
