#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void gen(ll n, ll k, vector<ll>& arr, vector<ll>& fact, vector<ll>& used, ll p,) {
	if (p == n) {
		for (auto i : arr) {
			cout << i;
		}
		return;
	}
	for (ll i = 1; i <= n; i++) {
		if (!used[i]) {
			ll col = fact[n-p-1];
			if (col < k) {
				k -= col;
			} else {
				used[i] = 1;
				arr[p] = i;
				gen(n, k, arr, fact, used, p+1);
				return;
			}
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n, 0), fact(1, 1), used(n+1, 0);

}
