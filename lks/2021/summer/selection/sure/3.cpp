#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, x;
	cin >> n >> x;
	ll ans = 0;
	vector<ll> mins(n, -1), arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		mins[i] = arr[i];
		ans += arr[i];
	}
	for (ll j = 1; j < n; j++) {
		ll new_ans = 0;
		for (ll i = 0; i < j; i++) {
			new_ans += mins[i];
		}
		for (ll i = j; i < n; i++) {
			mins[i] = min(mins[i], arr[i-j]);
			new_ans += mins[i];
		}
		new_ans += x*j;
		ans = min(ans, new_ans);
	}
	cout << ans;
}
