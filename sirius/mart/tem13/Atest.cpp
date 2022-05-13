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

ll ask(ll x) {
	cout << x << endl;
	ll c;
	cin >> c;
	return c;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	ll l = 0, r = n + 1;
	while (true) {
		ll mid = (l + r) / 2;
		ll x = ask(mid);
		if (x == -1) {
			r = mid;
		}
		if (x == 1) {
			l = mid;
		}
		if (x == 0) {
			return 0;
		}
	}
}
