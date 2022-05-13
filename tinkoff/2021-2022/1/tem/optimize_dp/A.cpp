#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

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

using namespace std;

struct line {
	ll k, c;
	double start = -1e6, end = 1e6;
	line(ll k, ll c): k(k), c(c) {}
	double get(double x) {
		return x * k + c;
	}
	double operator*(line l) {
		return (l.c - c) / (k - l.k);
	}
	bool down(line& l) {
		if (get(l.start) < l.get(l.start)) {
			return true;
		} else {
			double x = *this * l;
			l.end = x;
			start = x;
			return false;
		}
	}
};

struct CHT {
	vector<line> all;
	ll now = 0;
	CHT(ll k, ll c) {
		all.resize(1, line(k, c));
	}
	void add(ll k, ll c) {
		line l(k, c);
		while (l.down(all.back())) {
			all.pop_back();
		}
		all.push_back(l);
		assign_min(now, (ll)all.size() - 1);
	}
	ll get(ll x) {
		while (x > all[now].end) {
			now++;
		}
		return all[now].get(x);
	}
};

bool comp(pair<ll, ll> p1, pair<ll, ll> p2) {
	if (p1.first < p2.first) {
		return true;
	} else {
		if (p1.first == p2.first) {
			return p1.second > p2.second;
		} else {
			return false;
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<pair<ll, ll>> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());
	vector<pair<ll, ll>> a;
	for (auto[aa, b] : arr) {
		while (!a.empty() && a.back().second <= b) {
			a.pop_back();
		}
		a.push_back(make_pair(aa, b));
	}
	n = a.size();
	vector<ll> dp(n, 0);
	CHT c(a[0].second, 0);
	dp[0] = a[0].first * a[0].second;
	for (ll i = 1; i < n; i++) {
		dp[i] = min(dp[i - 1] + a[i].first * a[i].second, c.get(a[i].first));
		c.add(a[i].second, dp[i - 1]);
	}
	cout << dp.back();
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
