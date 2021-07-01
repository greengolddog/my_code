#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	ll l = 0, r = n/2+1;
	while (r - l > 1) {
		ll mid = (l+r)/2;
		cout << "? " << mid*2 << endl;
		ll c1, c2;
		cin >> c1;
		cout << "? " << mid*2-1 << endl;
		cin >> c2;
		if (c1 == c2) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << "? " << r*2-1 << endl;
	ll ans;
	cin >> ans;
	cout << "! " << ans << endl;
}
