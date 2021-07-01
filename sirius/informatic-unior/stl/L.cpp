#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool is_lower(char c) {
	return ((c >= 'a') && (c <= 'z'));
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	set<string> s, sl;
	for (ll i = 0; i < n; i++) {
		string inp;
		cin >> inp;
		s.insert(inp);
		for (ll i = 0; i < inp.size(); i++) {
			inp[i] = tolower(inp[i]);
		}
		sl.insert(inp);
	}
	string inp;
	ll ans = 0;
	while (cin >> inp) {
		ll cb = 0;
		for (auto i : inp) {
			if (!is_lower(i)) {
				cb++;
			}
		}
		if (cb != 1) {
			ans++;
		} else {
			string linp;
			for (auto i : inp) {
				linp.push_back(tolower(i));
			}
			if ((s.find(inp) == s.end()) && (sl.find(linp) != sl.end())) {
				mns++;
			}
		}
	}
	cout << ans;
}
