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

mt19937 rnd(0);

vector<ll> to, rev;

void encode() {
	ll x;
	cin >> x;
	if (x == 0) {
		for (ll i = 0; i < 50; i++) {
			cout << 0;
		}
	}
	ll last = 0;
	while (x > 0) {
		ll c = to[x % 10];
		for (ll i = 0; i < c; i++) {
			cout << last;
		}
		last++;
		x /= 10;
	}
}

void decode() {
	string s;
	if (!(cin >> s)) {
		cout << 0;
		return;
	}
	sort(s.begin(), s.end());
	ll ans = 0;
	bool b = false;
	for (ll i = 9; i >= 0; i--) {
		ans *= 10;
		ll c = 0;
		while (!s.empty() && s.back() - '0' == i) {
			c++;
			s.pop_back();
			b = true;
		}
		if (c == 50) {
			cout << 0;
			return;
		}
		if (c == 0 && !b) {
			continue;
		}
		c = rev[c];
		ans += c;
	}
	cout << ans;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string s;
	cin >> s;
	to.resize(10, 0);
	for (ll i = 0; i < 10; i++) {
		to[i] = i;
	}
	shuffle(to.begin(), to.end(), rnd);
	//reverse(to.begin(), to.end());
	rev.resize(10, 0);
	for (ll i = 0; i < 10; i++) {
		rev[to[i]] = i;
	}
	if (s == "Alice") {
		encode();
	} else {
		decode();
	}
}
