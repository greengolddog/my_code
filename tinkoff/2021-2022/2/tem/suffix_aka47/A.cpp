#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007, COLC = 20;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
T square(T a) {
	return a * a;
}

template<>
struct std::hash<pair<ll, ll>> {
	ll operator() (pair<ll, ll> p) {
		return ((__int128)p.first * MOD + p.second) % INF64;
	}
};

struct node {
	ll go[COLC];
	ll p, suf;
	node() {
		suf = -1;
		p = -1;
		for (ll i = 0; i < COLC; i++) {
			go[i] = -1;
		}
	}
};

struct suffix_aka47 {
	vector<node> arr;
	vector<bool> t;
	ll root;
	suffix_aka47() {
		root = 0;
		arr.resize(1, node());
	}
	suffix_aka47(string s) {
		root = 0;
		arr.resize(1, node());
		for (auto i : s) {
			add(i);
		}
		t.resize(arr.size(), false);
		ll a = root;
		for (; a > 0; a = arr[a].suf) {
			t[a] = true;
		}
	}
	void add(char c) {
		ll x = c - 'a';
		ll a = root;
		root = arr.size();
		arr.push_back(node());
		arr[root].suf = 0;
		arr[root].p = a;
		for (; a >= 0; a = arr[a].suf) {
			if (arr[a].go[x] == -1) {
				arr[a].go[x] = root;
				continue;
			}
			if (arr[arr[a].go[x]].p == a) {
				arr[root].suf = arr[a].go[x];
				break;
			}
			ll b = arr.size();
			arr.push_back(node());
			arr[b].p = a;
			arr[b].suf = arr[arr[a].go[x]].suf;
			arr[arr[a].go[x]].suf = b;
			arr[root].suf = b;
			for (ll i = 0; i < COLC; i++) {
				arr[b].go[i] = arr[arr[a].go[x]].go[i];
			}
			ll c = arr[a].go[x];
			for (; a >= 0 && arr[a].go[x] == c; a = arr[a].suf) {
				arr[a].go[x] = b;
			}
			break;
		}
	}
};

void solve() {
	string s;
	cin >> s;
	suffix_aka47 sa(s);
	cout << sa.arr.size() << '\n';
	for (auto i : sa.arr) {
		for (auto j : i.go) {
			cout << j + 1 << ' ';
		}
		cout << '\n';
	}
	for (auto i : sa.t) {
		cout << (i ? 0 : 1) << ' ';
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
