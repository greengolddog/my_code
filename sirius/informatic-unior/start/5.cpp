#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> s(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> s[i];
		s[i] -= i;
	}
	sort(s.begin(), s.end());
	ll ch = 0, cc = 0;
	for (ll i = 0; i < m; i++) {
		ll t;
		cin >> t;
		t -= i;
		if (s[0] > t) {
			ch += n;
			continue;
		}
		if (s[n-1] < t) {
			cc += n;
			continue;
		}
		if ((s[0] == t) && (s[n-1] == t)) {
			continue;
		}
		ll l = 0, r = n;
		while (r - l > 1) {
			ll mid = (l+r)/2;
			if (s[mid] > t) {
				r = mid;
			} else {
				l = mid;
			}
		}
		ll l2 = 0, r2 = n;
		while (r2 - l2 > 1) {
			ll mid = (l2+r2)/2;
			if (s[mid] >= t) {
				r2 = mid;
			} else {
				l2 = mid;
			}
		}
		ch += l2+1;
		cc += n - l - 1;
	}
	cout << cc << ' ' << ch;
}
