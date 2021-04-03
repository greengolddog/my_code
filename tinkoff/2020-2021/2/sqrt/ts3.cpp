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
		blocks = vector<ll>(ceil(arr.size()/block) + 1, 0);
		for (ll i = 0; i < arr.size(); i++) {
			if (arr[i] == 0) {
				blocks[i/block] += 1;
			}
		}
	}
	ll max_in_line(ll l, ll r) {
		ll ans = 0, dob = ceil(1.0*l/block)*block;
		for (ll i = l; i < min(r, dob); i++) {
			if (arr[i] == 0) {
				ans += 1;
			}
		}
		for (ll i = ceil(1.0*l/block); i < r/block; i++) {
			ans += blocks[i];
		}
		for (ll i = max(min(r, dob), r/block*block); i < r; i++) {
			if (arr[i] == 0) {
				ans += 1;
			}
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
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sqrt_min s(arr);
	ll raz;
	cin >> raz;
	for (ll i = 0; i < raz; i++) {
		ll l, r;
		cin >> l >> r;
		cout << s.max_in_line(l - 1, r) << ' ';
	}
}
