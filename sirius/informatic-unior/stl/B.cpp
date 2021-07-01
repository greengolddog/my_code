#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll a;
	while (cin >> a) {
		string s;
		getline(cin, s);
		ll now = 0, ans = a;
		for (auto i : s) {
			if (i == ' ') {
				ans += now;
				now = 0;
			} else {
				now = now*10+(i-'0');
			}
		}
		ans += now;
		cout << ans << endl;
	}
}
