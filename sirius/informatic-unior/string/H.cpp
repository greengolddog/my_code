#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll mul(ll a, ll b, ll m) {
	return a*b%m;
}

ll mul(ll a, ll b) {
	return a*b;
}

ll add(ll a, ll b, ll m) {
	if (a+b >= m) return a+b-m;
	if (a+b < 0) return a+b+m;
	return a+b;
}

ll add(ll a, ll b) {
	return a+b;
}

ll sub(ll a, ll b, ll m) {
	if (a-b >= m) return a-b-m;
	if (a-b < 0) return a-b+m;
	return a-b;
}

ll sub(ll a, ll b) {
	return a-b;
}

struct HashString {
	string s;
	ll mod = 1000000009, p = 151;
	vector<ll> hash, power;
	HashString() {}
	HashString(string& s): s(s) {
		calc();
	}
	HashString(string& s, ll p, ll mod): s(s), p(p), mod(mod) {
		calc();
	}
	HashString(istream& input) {
		input >> s;
		calc();
	}
	HashString(istream& input, ll p, ll mod): p(p), mod(mod) {
		input >> s;
		calc();
	}
	void calc() {
		hash.resize(s.size()+1, 0);
		power.resize(s.size()+1, 1);
		for (ll i = 1; i <= s.size(); i++) {
			power[i] = mul(power[i-1], p, mod);
			hash[i] = add(mul(hash[i-1], p, mod), ((int)s[i-1]), mod);
		}
	}
	ll get(ll l, ll r) {
		return sub(hash[r], mul(hash[l], power[r-l], mod), mod);
	}
	ll all() {
		return hash[s.size()];
	}
	ll size() {
		return s.size();
	}
	bool match(ll l1, ll r1, ll l2, ll r2) {
		return get(l1, r1) == get(l2, r2);
	}
	char operator[] (ll x) {
		return s[x];
	}
};

struct String {
	HashString s1, s2;
	String(istream& input) {
		string s;
		input >> s;
		s1 = HashString(s);
		reverse(s.begin(), s.end());
		s2 = HashString(s);
	}
	ll size() {
		return s1.size();
	}
	char operator[] (ll x) {
		return s1[x];
	}
	ll get(ll l, ll r) {
		return s1.get(l, r);
	}
	ll get_reverse(ll l, ll r) {
		return s2.get(size()-r, size()-l);
	}
	bool polindrom(ll l, ll r) {
		if ((r - l) % 2 == 0) {
			return get(l, (l+r)/2) == get_reverse((l+r)/2+1, r+1);
		} else {
			return get(l, (l+r)/2+1) == get_reverse((l+r)/2+1, r+1);
		}
	}
};

HashString s;

bool cmp(ll a, ll b) {
	ll l1 = a, r1 = s.size(), l2 = b, r2 = s.size();
	ll l = 0, r = min(r1-l1, r2-l2)+1;
	while (r - l > 1) {
		ll mid = (l + r)/2;
		if (s.get(l1, l1+mid) == s.get(l2, l2+mid)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	if ((l1 + l == r1) && (l2 + l == r2)) {
		return true;
	} else {
		if (l1 + l == r1) {
			return true;
		} else {
			if (l2 + l == r2) {
				return false;
			} else {
				return ((s[l1+l] > s[l2+l]) ? false : true);
			}
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	s = HashString(cin);
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		arr[i] = i;
	}
	stable_sort(arr.begin(), arr.end(), cmp);
	for (auto i : arr) {
		cout << i + 1 << ' ';
	}
}
