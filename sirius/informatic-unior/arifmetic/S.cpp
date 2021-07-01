#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

__int128 power(__int128 a, __int128 p, __int128 m = (ll)1e18) {
	if (p == 0) {
		return 1;
	}
	if (p % 2 == 0) {
		__int128 ans = power(a, p/2, m);
		return ans*ans%m;
	} else {
		return power(a, p-1, m)*a%m;
	}
}

ll gcd(ll a, ll b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	return gcd(min(a, b), max(a, b)%min(a, b));
}

ll gcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll d = gcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return d;
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

ll sub(ll a, ll b, ll m) {
	if (a-b < 0) return a-b+m;
	return a-b;
}

ll sum(ll a, ll b, ll m) {
	if (a+b >= m) return a+b-m;
	return a+b;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	ll x, y;
	ll d = gcd(a, b, x, y);
	if (c % d != 0) {
		cout << -1;
	} else {
		cout << 0 << '\n';
		x *= c/d;
		y *= c/d;
		ll p = 100000000;
		ll lx = ceil((-p-x)*d*1.0/b), rx = (p-x)*d/b, ly = ceil((-p-y)*d*-1.0/b), ry = (p-x)*d/b;
		cout << x+max(lx, ly)*b/d << ' ' << y+max(lx, ly)*a/d;
	}
}
