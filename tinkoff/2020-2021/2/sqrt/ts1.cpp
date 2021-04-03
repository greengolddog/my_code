#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

struct sqrt_min {
	vector<ll> arr;
	vector<ll> blocks;
	ll block;
	sqrt_min(vector<ll> arr = vector<ll>(0, 0)): arr(arr) {
		block = 300;
		blocks = vector<ll>(ceil(arr.size()/block) + 1, 10000000000000);
		for (ll i = 0; i < arr.size(); i++) {
			blocks[i/block] = min(blocks[i/block], arr[i]);
		}
	}
	ll min_in_line(ll l, ll r) {
		ll ans = 100000000000, dob = ceil(1.0*l/block)*block;
		for (ll i = l; i < min(r, dob); i++) {
			ans = min(ans, arr[i]);
		}
		for (ll i = ceil(1.0*l/block); i < r/block; i++) {
			ans = min(ans, blocks[i]);
		}
		for (ll i = max(l, r/block*block); i < r; i++) {
			ans = min(ans, arr[i]);
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll raz;
	cin >> raz;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sqrt_min s(arr);
	for (ll i = 0; i <= n-raz; i++) {
		cout << s.min_in_line(i, i+raz) << ' ';
	}
}
