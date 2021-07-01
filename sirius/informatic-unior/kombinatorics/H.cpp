#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll gen(ll n, ll k, vector<ll>& arr, vector<ll>& fact, vector<ll>& used, ll p) {
	if (p == k) {
		return 0;
	}
	ll now = 0;
	for (ll i = 1; i < arr[p]; i++) {
		if (!used[i]) {
			now += (fact[n-p-1]/fact[n-k]);
		}
	}
	used[arr[p]] = 1;
	return gen(n, k, arr, fact, used, p+1)+now;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(k, 0), fact(n+1, 0), used(n+1, 0);
	for (ll i = 0; i < k; i++) {
		cin >> arr[i];
	}
	fact[0] = 1;
	for (ll i = 1; i <= n; i++) {
		fact[i] = fact[i-1]*i;
	}
	cout << gen(n, k, arr, fact, used, 0)+1;
}
