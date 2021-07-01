#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void gen(ll n, vector<ll>& arr, vector<ll>& used, ll p) {
	if (p == n) {
		for (auto i : arr) {
			cout << i;
		}
		cout << '\n';
		return;
	}
	for (ll i = 1; i <= n; i++) {
		if (!used[i]) {
			used[i] = 1;
			arr[p] = i;
			gen(n, arr, used, p+1);
			used[i] = 0;
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n, 0), used(n+1, 0);
	gen(n, arr, used, 0);
}
