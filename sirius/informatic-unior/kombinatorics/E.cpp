#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void gen(ll n, vector<ll>& arr, ll last) {
	for (ll i = last; i <= n; i++) {
		if (n % i == 0) {
			arr.push_back(i);
			gen(n / i, arr, i);
			arr.pop_back();
		}
	}
	if (n == 1) {
		for (ll i = 0; i < arr.size(); i++) {
			if (i != 0) {
				cout << '*';
			}
			cout << arr[i];
		}
		cout << '\n';
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll> arr;
	gen(n, arr, m);
}
