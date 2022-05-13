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

ll sub(ll a, ll b, ll m) {
	if (a < b) {
		return a - b + m;
	}
	return a - b;
}

ll sum(ll a, ll b, ll m) {
	if (a + b >= m) {
		return a + b - m;
	}
	return a + b;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<ll> rl(n, 1), rr(n, 1);
	ll c = n - 1;
	while (arr[c] == arr[0] && c != 0) {
		rl[0]++;
		c--;
	}
	for (ll i = 1; i <= c; i++) {
		if (arr[i - 1] == arr[i]) {
			rl[i] = rl[i - 1] + 1;
		}
	}
	c = 0;
	while (arr[c] == arr[n - 1] && c != n - 1) {
		rr[n - 1]++;
		c++;
	}
	for (ll i = n - 2; i >= c; i--) {
		if (arr[i + 1] == arr[i]) {
			rr[i] = rr[i + 1] + 1;
		}
	}
	set<pair<ll, pair<ll, ll>>> s;
	for (ll i = (arr.back() == arr[0] ? rr[0] : 0); i < n; i += rr[i]) {
		if (arr[sum(i, rr[i], n)] > arr[i] && arr[sub(i, 1, n)] > arr[i]) {
			s.insert(make_pair(rr[i], make_pair(i, sum(i, rr[i], n))));
		}
	}
	ll ans = 0;
	while (!s.empty()) {
		auto[c, g] = *s.begin();
		s.erase(s.begin());
		auto[l, r] = g;
		l %= n;
		r %= n;
		ll add = min(k / c, min(arr[sub(l, 1, n)] - arr[l], arr[r % n] - arr[sub(r, 1, n)]));
		ans += add * 2;
		if (k / c == 0) {
			break;
		}
		k -= add * c;
		if (sub(r, 1, n) != l) {
			arr[sub(r, 1, n)] += add;
		}
		arr[l] += add;
		if (arr[l] == arr[sub(l, 1, n)]) {
			rr[sub(l, rl[sub(l, 1, n)], n)] += rr[l];
			rr[sub(l, rl[sub(l, 1, n)], n)] %= n;
			rl[sub(r, 1, n)] += rl[sub(l, 1, n)];
			rl[sub(r, 1, n)] %= n;
			l = sub(l, rl[sub(l, 1, n)], n);
		}
		if (arr[r % n] == arr[sub(r, 1, n)]) {
			rl[sum(sub(r, 1, n), rr[r % n], n)] += rl[sub(r, 1, n)];
			rl[sum(sub(r, 1, n), rr[r % n], n)] %= n;
			rr[l] += rr[r % n];
			rr[l] %= n;
			r = sum(r, rr[r % n], n);
		}
		if (arr[sub(l, 1, n)] > arr[l] && arr[r % n] > arr[sub(r, 1, n)]) {
			s.insert(make_pair(rr[l], make_pair(l, r % n)));
		}
	}
	cout << ans;
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
