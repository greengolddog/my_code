#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

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
	vector<ll> rra = arr;
	reverse(rra.begin(), rra.end());
	ll sum1 = 0, sum2 = 0, n1 = 0, n2 = 0;
	while (n1 < n && sum1 <= 0) {
		sum1 += arr[n1];
		n1++;
	}
	while (n2 < n && sum2 <= 0) {
		sum2 += rra[n2];
		n2++;
	}
	if (n2+n1 < n) {
		cout << n1 << ' ' << n-n1-n2 << ' ' << n2;
		return 0;
	}
	sum1 = 0;
	lsum1 = 0;
	u2 = 1;
	sum2 = arr[0];
	for (ll i = 0; i < n; i++) {
		sum1 += arr[i];
		sum2 -= arr[i];
		if (sum1 > 0) {
			if (sum1 < lsum1) {
				while (su
	cout << 0;
}
