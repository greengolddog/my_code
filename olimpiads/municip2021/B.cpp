#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 9'000'000'000'000'000'000, COLC = 10;

template<typename T>
T assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
T assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a, b;
	cin >> a >> b;
	ll l = 0, r = 3'000'000'000;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (mid * a < mid * b + (mid - 1) * mid / 2) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r;
}
