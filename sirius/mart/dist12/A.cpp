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

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	ll l = 1, r = n + 1;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		cout << '?' << ' ' << 1 << ' ' << mid << ' ' << n << ' ' << n << endl;
		ll x;
		cin >> x;
		if (x > 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	ll bl = l;
	l = 1;
	r = n + 1;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		cout << '?' << ' ' << mid << ' ' << 1 << ' ' << n << ' ' << n << endl;
		ll x;
		cin >> x;
		if (x > 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	ll al = l;
	cout << '?' << ' ' << 1 << ' ' << bl << ' ' << n << ' ' << n << endl;
	ll x;
	cin >> x;
	cout << '?' << ' ' << al << ' ' << 1 << ' ' << n << ' ' << n << endl;
	ll y;
	cin >> y;
	cout << '!' << ' ' << al - x + 1 << ' ' << bl - y + 1 << ' ' << al << ' ' << bl << endl;
}
