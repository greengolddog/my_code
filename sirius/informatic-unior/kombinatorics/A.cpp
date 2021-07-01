#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void gen(ll n, ll k, vector<ll>& arr, ll p) {
	if (p == n) {
		for (auto i : arr) {
			if (i < 10) {
				cout << i;
			} else {
				cout << (char)('a'+(i-10));
			}
		}
		cout << '\n';
		return;
	}
	for (ll i = k-1; i >= 0; i--) {
		arr[p] = i;
		gen(n, k, arr, p+1);
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
