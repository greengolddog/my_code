#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

struct block {
	vector<ll> arr;
	ll size;
	ll min_el = 10000000000000;
	block(vector<ll> arr = vector<ll>(0, 0)): arr(arr) {
		size = arr.size();
		for (ll i = 0; i < size; i++) {
			min_el = min(min_el, arr[i]);
		}
	}
	ll operator[] (ll num) {
		return arr[num];
	}
	ll operator[] (pair<ll, ll> gr) {
		if ((gr.first == 0) and (gr.second == size)){
			return min_el;
		} else {
			ll min_now = 10000000000000;
			for (ll i = gr.first; i < gr.second; i++) {
				min_now = min(min_now, arr[i]);
			}
			return min_now;
		}
	}
	void operator+= (ll num) {
		arr.push_back(num);
		min_el = min(min_el, num);
	}
	void operator+= (pair<ll, ll> num) {
		arr.insert(arr.begin()+num.second, num.first);
		min_el = min(min_el, num.first);
	}
};

struct sqrt_min {
	vector<block> blocks;
	ll k = 400;
	ll stc = 0;
	sqrt_min(vector<ll> arr = vector<ll>(0, 0)) {
		blocks = vector<block>(arr.size()/k+1, block());
		for (ll i = 0; i < arr.size(); i++) {
			blocks[i/k] += arr[i];
		}
	}
	ll operator[] (pair<ll, ll> lr) {
		ll nac = 0, ans = 100000000000, l = lr.first, r = lr.second;
		for (ll i = 0; i < blocks.size(); i++) {
			if ((nac <= r) && (nac+blocks[i].size > l)) {
				ans = min(ans, blocks[i][{max(nac, l), min(nac+blocks[i].size, r)}]);
			}
			nac += blocks[i].size;
		}
		return ans;
	}
	void per() {
		vector<ll> arr(0, 0);
		for (ll i = 0; i < blocks.size(); i++) {
			for (ll j = 0; j < blocks[i].size; j++) {
				arr.push_back(blocks[i][j]);
			}
		}
		blocks = vector<block>(arr.size()/k+1, block());
		for (ll i = 0; i < arr.size(); i++) {
			blocks[i/k] += arr[i];
		}
		stc = 0;
	}
	void operator+= (pair<ll, ll> num) {
		stc++;
		ll nac = 0,  mes = num.first, ch = num.second;
		for (ll i = 0; i < blocks.size(); i++) {
			if ((nac <= mes) && (nac+blocks[i].size > mes)) {
				blocks[i] += {ch, mes-nac};
			}
			nac += blocks[i].size;
		}
		if (stc == k) {
			per();
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sqrt_min s;
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		char zap;
		ll c1, c2;
		cin >> zap >> c1 >> c2;
		if (zap == '+') {
			s += {c1, c2};
		} else {
			cout << s[{c1, c2}] << endl;
		}
	}
}
