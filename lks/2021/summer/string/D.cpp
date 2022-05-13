#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

struct node {
	node *zero = nullptr, *one = nullptr;
	ll cz = 0, co = 0;
	node() {}
	void add(ll x) {
		if (x) {
			co++;
		} else {
			cz++;
		}
	}
	node *get(ll x) {
		if (x) {
			if (one == nullptr) {
				one = new node();
			}
			return one;
		} else {
			if (zero == nullptr) {
				zero = new node();
			}
			return zero;
		}
	}
	void del(ll x) {
		if (x) {
			co--;
			if (!co) {
				one = nullptr;
			}
		} else {
			cz--;
			if (!cz) {
				zero = nullptr;
			}
		}
	}
	bool be(ll x) {
		if (x) {
			return one != nullptr;
		} else {
			return zero != nullptr;
		}
	}
};

struct bor {
	node *root = nullptr;
	bor() {
		root = new node();
	}
	void add(ll x) {
		vector<ll> arr;
		for (ll i = 0; i < 32; i++) {
			arr.push_back(x % 2);
			x = x / 2;
		}
		reverse(arr.begin(), arr.end());
		auto now = root;
		for (auto i : arr) {
			now->add(i);
			now = now->get(i);
		}
	}
	void del(ll x) {
		vector<ll> arr;
		for (ll i = 0; i < 32; i++) {
			arr.push_back(x % 2);
			x = x / 2;
		}
		reverse(arr.begin(), arr.end());
		auto now = root;
		for (auto i : arr) {
			now->del(i);
			if (!now->be(i)) {
				break;
			}
			now = now->get(i);
		}
	}
	ll get(ll x) {
		ll ox = x;
		vector<ll> arr;
		for (ll i = 0; i < 32; i++) {
			arr.push_back(x % 2);
			x = x / 2;
		}
		reverse(arr.begin(), arr.end());
		auto now = root;
		vector<ll> ans;
		for (auto i : arr) {
			if (!now->be(0) || (now->be(1) && i == 0)) {
				ans.push_back(1);
				now = now->get(1);
			} else {
				ans.push_back(0);
				now = now->get(0);
			}
		}
		ll a = 0;
		for (auto i : ans) {
			a *= 2;
			a += i;
		}
		return ox ^ a;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll q;
	cin >> q;
	bor b;
	b.add(0);
	for (ll i = 0; i < q; i++) {
		char c;
		cin >> c;
		if (c == '+') {
			ll x;
			cin >> x;
			b.add(x);
		}
		if (c == '-') {
			ll x;
			cin >> x;
			b.del(x);
		}
		if (c == '?') {
			ll x;
			cin >> x;
			cout << b.get(x) << '\n';
		}
	}
}

/*
⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣵⣿⣿⣿⠿⡟⣛⣧⣿⣯⣿⣝⡻⢿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⠋⠁⣴⣶⣿⣿⣿⣿⣿⣿⣿⣦⣍⢿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⢷⠄⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢼⣿⣿⣿⣿
⢹⣿⣿⢻⠎⠔⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⣿⣿⣿⣿
⢸⣿⣿⠇⡶⠄⣿⣿⠿⠟⡛⠛⠻⣿⡿⠿⠿⣿⣗⢣⣿⣿⣿⣿
⠐⣿⣿⡿⣷⣾⣿⣿⣿⣾⣶⣶⣶⣿⣁⣔⣤⣀⣼⢲⣿⣿⣿⣿
⠄⣿⣿⣿⣿⣾⣟⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⢟⣾⣿⣿⣿⣿
⠄⣟⣿⣿⣿⡷⣿⣿⣿⣿⣿⣮⣽⠛⢻⣽⣿⡇⣾⣿⣿⣿⣿⣿
⠄⢻⣿⣿⣿⡷⠻⢻⡻⣯⣝⢿⣟⣛⣛⣛⠝⢻⣿⣿⣿⣿⣿⣿
⠄⠸⣿⣿⡟⣹⣦⠄⠋⠻⢿⣶⣶⣶⡾⠃⡂⢾⣿⣿⣿⣿⣿⣿
⠄⠄⠟⠋⠄⢻⣿⣧⣲⡀⡀⠄⠉⠱⣠⣾⡇⠄⠉⠛⢿⣿⣿⣿
⠄⠄⠄⠄⠄⠈⣿⣿⣿⣷⣿⣿⢾⣾⣿⣿⣇⠄⠄⠄⠄⠄⠉⠉
⠄⠄⠄⠄⠄⠄⠸⣿⣿⠟⠃⠄⠄⢈⣻⣿⣿⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⢿⣿⣾⣷⡄⠄⢾⣿⣿⣿⡄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠸⣿⣿⣿⠃⠄⠈⢿⣿⣿⠄⠄⠄⠄⠄⠄⠄
*/
