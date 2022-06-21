#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
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

void solve() {
	ll n, coly = 0;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	set<char> nb;
	deque<char> d;
	for (char i = 'A'; i <= 'Z'; i++) {
		nb.insert(i);
	}
	vector<char> ans(n, '.');
	for (ll i = 0; i < n; i++) {
		nb.erase(s1[i]);
		if (s2[i] == 'G') {
			ans[i] = s1[i];
		} else {
			d.push_back(s1[i]);
		}
		coly += s2[i] == 'Y';
	}
	if (d.size() == 1 && coly == 1) {
		cout << "No" << '\n';
		return;
	}
	d.push_back(d.front());
	d.pop_front();
	for (ll i = 0; i < n; i++) {
		if (s2[i] == 'Y') {
			ans[i] = d.front();
			d.pop_front();
		}
		if (s2[i] == 'W') {
			d.pop_front();
			if (nb.empty()) {
				cout << "No" << '\n';
				return;
			}
			ans[i] = *nb.begin();
			nb.erase(nb.begin());
		}
	}
	cout << "Yes\n";
	for (auto i : ans) {
		cout << i;
	}
	cout << '\n';
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
