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
	ll a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	ll a1 = 0, a2 = 0;
	ll nk = k;
	if (a >= k) {
		cout << k;
		return 0;
	}
	if (b >= k) {
		cout << a + k;
		return 0;
	}
	ll pa = d, pc = b, pb = a, pd = c;
	if (c > a) {
		a1 -= pa;
	}
	if (a > c) {
		nk -= a;
		a1 = a;
		swap(a, c);
		swap(pa, pc);
	}
	if (a == c) {
		a1 = INF;
	} else {
		ll ns = c - a;
		ll cs = c + a + pa + pc;
		a1 += (nk + ns - 1) / ns * cs - ((nk + ns - 1) / ns * ns - nk);
	}
	nk = k;
	if (b > d) {
		nk -= b;
		a2 = pb + b;
		swap(b, d);
		swap(pb, pd);
	}
	if (b == d) {
		a2 = INF;
	} else {
		ll ns = d - b;
		ll cs = d + b + pb + pd;
		a2 += (nk + ns - 1) / ns * cs - ((nk + ns - 1) / ns * ns - nk);
	}
	cout << min(a1, a2);
}
