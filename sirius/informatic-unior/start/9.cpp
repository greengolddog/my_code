#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct block {
	vector<ll> arr;
	block(ll k = 400) {


int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, q;
	cin >> n >> q;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		arr[i] = i;
	}
	for (ll i = 0; i < q; i++) {
		ll z;
		cin >> z;
		if (z == 2) {
			ll zz;
			cin >> zz;
			cout << arr[zz-1]+1 << '\n';
		} else {
			ll p, d;
			cin >> p >> d;
}
