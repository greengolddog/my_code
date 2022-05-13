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
	cout << '?' << ' ' << x << endl;
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
	ll l = 1, r = n;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (ask(mid) == 0) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << '!' << ' ' << l << endl;
}
