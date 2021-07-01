#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll get_sum(vector<ll>& pref, ll l, ll r) {
	return pref[r]-pref[l];
}

ll check(vector<ll>& pref, ll s, ll k, ll l, ll r) {
	return min(get_sum(pref, l, s), get_sum(pref, s+k, r));
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<ll> pref(n+1, 0);
	for (ll i = 0; i < n; i++) {
		pref[i+1] = pref[i]+arr[i];
	}
	ll q;
	cin >> q;
	for (ll iii = 0; iii < q; iii++) {
		ll lll, rr, k;
		cin >> lll >> rr >> k;
		ll l = lll, r = rr-k+1;
		for (ll i = 0; i < 40; i++) {
			ll m1 = l+(r-l)/3, m2 = l+(r-l)/3*2;
			if (check(pref, m1, k, lll-1, rr) <= check(pref, m2, k, lll-1, rr)) {
				l = m1;
			} else {
				r = m2;
			}
		}
		ll ans = 0;
		for (ll i = l; i <= r; i++) {
			ans = max(ans, check(pref, i, k, lll-1, rr));
		}
		cout << ans << endl;
	}
}
