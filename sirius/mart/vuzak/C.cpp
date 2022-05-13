#include<bits/stdc++.h>
typedef int ll;

using namespace std;

ll gcd(ll a, ll b) {
	return (min(a, b) == 0 ? max(a, b) : gcd(max(a, b) % min(a, b), min(a, b)));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, x = 10'000'001;
	cin >> n;
	vector<ll> primes;
	vector<ll> nums(x, -1), col(x, -1), max_d(x, -1);
	nums[1] = 1'000'000'000;
	for (ll i = 2; i < x; i++) {
		if (nums[i] == -1) {
			nums[i] = primes.size();
			primes.push_back(i);
			col[i] = 1;
			max_d[i] = nums[i];
		}
		for (ll j = 0; (j <= nums[i]) && (i * primes[j] < x); j++) {
			nums[i * primes[j]] = j;
			col[i * primes[j]] = col[i] + 1;
			max_d[i * primes[j]] = max_d[i];
		}
	}
	for (ll i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		ll gc = gcd(a, b);
		a /= gc;
		b /= gc;
		while (nums[gc] < max(max_d[a], max_d[b])) {
			gc /= primes[nums[gc]];
		}
		cout << gc << '\n';
	}
}
