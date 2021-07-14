#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	pair<tuple<vector<pair<vector<__int128>, tuple<ll, long long, signed int, unsigned short>>>, long double, vector<tuple<ll>>, pair<ll, pair<ll, pair<pair<signed, ll>, pair<ll, ll>>>>>, pair<ll, tuple<ll, pair<ll, ll>>>> musor;
	ll k, n;
	cin >> k >> n;
	ll a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> b1 >> b2 >> b3 >> b4 >> b5 >> b6;
	ll l = 0, r = 1000000000;
	for (ll i = 0; i < 40; i++) {
		ll mid1 = l+(r-l)/3, mid2 = l+(r-l)/3*2;
		if ((n*mid1-(max(mid1*2-a1, 0ll)+max(mid1*2-b1, 0ll)+max(mid1*2-a2, 0ll)+max(mid1*2-b2, 0ll)+max(mid1*2-a3, 0ll)+max(mid1*2-b3, 0ll)+max(mid1-a4, 0ll)+max(mid1-b4, 0ll)+max(mid1-a5, 0ll)+max(mid1-b5, 0ll)+max(mid1*8-a6, 0ll)+max(mid1*8-b6, 0ll))*k) >= (n*mid2-(max(mid2*2-a1, 0ll)+max(mid2*2-b1, 0ll)+max(mid2*2-a2, 0ll)+max(mid2*2-b2, 0ll)+max(mid2*2-a3, 0ll)+max(mid2*2-b3, 0ll)+max(mid2-a4, 0ll)+max(mid2-b4, 0ll)+max(mid2-a5, 0ll)+max(mid2-b5, 0ll)+max(mid2*8-a6, 0ll)+max(mid2*8-b6, 0ll))*k)) {
			r = mid2;
		} else {
			l = mid1;
		}
	}
	ll ans = 0ll;
	for (ll mid1 = l; mid1 <= r; mid1++) {
		ans = max(ans, (n*mid1-(max(mid1*2-a1, 0ll)+max(mid1*2-b1, 0ll)+max(mid1*2-a2, 0ll)+max(mid1*2-b2, 0ll)+max(mid1*2-a3, 0ll)+max(mid1*2-b3, 0ll)+max(mid1-a4, 0ll)+max(mid1-b4, 0ll)+max(mid1-a5, 0ll)+max(mid1-b5, 0ll)+max(mid1*8-a6, 0ll)+max(mid1*8-b6, 0ll))*k));
	}
	cout << ans;
}
