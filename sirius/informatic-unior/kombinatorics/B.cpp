#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void gen(ll n, ll k, vector<ll>& arr, ll p, ll last) {
	if (p == k) {
		for (auto i : arr) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	for (ll i = k-p; i < last; i++) {
		arr[p] = i;
		gen(n, k, arr, p+1, i);
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(k, 0);
	gen(n, k, arr, 0, n+1);
}
