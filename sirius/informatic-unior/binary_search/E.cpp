#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll iii = 0; iii < t; iii++) {
		ll n, m;
		cin >> n >> m;
		if (n*(n+1)/2 < m) {
			cout << "Crewmates" << '\n';
			cout << n << '\n';
		} else {
			cout << "Impostors" << '\n';
			ll l = 0, r = n;
			while (r - l > 1) {
				ll mid = (l+r)/2;
				if (mid*(n+n-mid+1)/2 >= m) {
					r = mid;
				} else {
					l = mid;
				}
			}
			cout << r << '\n';
		}
	}
}
