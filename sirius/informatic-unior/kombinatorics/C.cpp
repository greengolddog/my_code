#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void gen(ll n, ll k, vector<ll>& arr, ll p) {
	if (p == n) {
		for (auto i : arr) {
			cout << i;
		}
		cout << '\n';
		return;
	}
	if (n-p > k) {
		arr[p] = 0;
		gen(n, k, arr, p+1);
	}
	if (k > 0) {
		arr[p] = 1;
		gen(n, k-1, arr, p+1);
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n, 0);
	gen(n, k, arr, 0);
}
