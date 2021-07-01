#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, l;
	cin >> n >> l;
	vector<tuple<ll, ll, ll, ll>> arr(1, make_tuple(0, 0, 0, 0));
	for (ll i = 0; i < n; i++) {
		ll x, d, t, p;
		cin >> x >> d >> t >> p;
		arr[i].push_back(tie(x, d, t, p));
	}
	arr.push_back(make_tuple(l, 0, 0, 0));
	sort(arr.begin(), arr.end());
	vector<ll> dp1(n+2, 0), dp2(n+2, 0), pr(n+2, 0);
	pr[0] = 0;
	dp1[0] = 0;
	dp2[0] = 0;
	for (ll i = 1; i <= n+1; i++) {
	}
}
