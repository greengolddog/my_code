#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void gen(ll n, vector<ll>& arr, ll last) {
	if (n == 0) {
		for (auto i : arr) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	for (ll i = min(n, last); i > 0; i--) {
		arr.push_back(i);
		gen(n - i, arr, i);
		arr.pop_back();
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr;
	gen(n, arr, n);
}
