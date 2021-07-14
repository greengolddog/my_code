#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string s;
	cin >> s;
	for (ll i = 1; i < s.size(); i++) {
		if (s[i-1] == s[i]) {
			cout << i << ' ' << i+1;
			return 0;
		}
	}
	for (ll i = 2; i < s.size(); i++) {
		if (s[i-2] == s[i]) {
			cout << i-1 << ' ' << i+1;
			return 0;
		}
	}
	cout << -1 << ' ' << -1;
}
