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

ll lcm(ll a, ll b) {
	return a*b/gcd(a, b);
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
	string s;
	cin >> s;
	ll oc = (s.size() == 1 ? ((s[0]-'0')%4) : (((s[s.size()-1]-'0')+(s[s.size()-2]-'0')*10)%4));
	if (oc == 0) {
		cout << 4;
	}
	if (oc == 1) {
		cout << 0;
	}
	if (oc == 2) {
		cout << 0;
	}
	if (oc == 3) {
		cout << 0;
	}
}
