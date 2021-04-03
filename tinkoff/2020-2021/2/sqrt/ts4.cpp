#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

struct sqrt_min {
	vector<ll> arr;
	vector<pair<ll, ll>> blocks;
	ll block;
	sqrt_min(ll n, ll col) {
		arr = vector<ll>(col, n);
		block = 400;
		blocks = vector<pair<ll, ll>>(ceil(arr.size()/block) + 1, {n, 0});
	}
	ll max_in_line(ll l, ll r) {
		ll ans = 1, dob = ceil(1.0*l/block)*block;
		for (ll i = l; i < min(r, dob); i++) {
			if (arr[i]-blocks[i/block].second < 1) {
				ans = 0;
			}
		}
		for (ll i = ceil(1.0*l/block); i < r/block; i++) {
			if (blocks[i].first < 1) {
				ans = 0;
			}
		}
		for (ll i = max(min(r, dob), r/block*block); i < r; i++) {
			if (arr[i]-blocks[i/block].second < 1) {
				ans = 0;
			}
		}
		if (ans == 1) {
			for (ll i = l; i < min(r, dob); i++) {
				arr[i]--;
				blocks[i/block].first = min(blocks[i/block].first, arr[i] - blocks[i/block].second);
			}
			for (ll i = ceil(1.0*l/block); i < r/block; i++) {
				blocks[i].first--;
				blocks[i].second++;
			}
			for (ll i = max(min(r, dob), r/block*block); i < r; i++) {
				arr[i]--;
				blocks[i/block].first = min(blocks[i/block].first, arr[i] - blocks[i/block].second);
			}
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, col;
	cin >> col >> n;
	sqrt_min s(n, col);
	ll raz;
	cin >> raz;
	for (ll i = 0; i < raz; i++) {
		ll l, r;
		cin >> l >> r;
		cout << s.max_in_line(l, r) << endl;
	}
}
