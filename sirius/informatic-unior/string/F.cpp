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
	ll mod = 1000000009, p = 57;
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
			hash[i] = add(mul(hash[i-1], p, mod), (s[i-1]-'a'+1), mod);
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

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, start = 0;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	HashString s11(s1), s12(s1, 61, 1000000007), s21(s2), s22(s2, 61, 1000000007);
	ll l = 0, r = n+1;
	while (r - l > 1) {
		ll mid = (l+r)/2;
		bool f = false;
		set<pair<ll, ll>> s;
		for (ll i = 0; i <= n-mid; i++) {
			s.insert({s11.get(i, i+mid), s12.get(i, i+mid)});
		}
		for (ll i = 0; i <= n-mid; i++) {
			if (s.find({s21.get(i, i+mid), s22.get(i, i+mid)}) != s.end()) {
				f = true;
				start = i;
			}
		}
		if (f) {
			l = mid;
		} else {
			r = mid;
		}
	}
	for (ll i = start; i < start+l; i++) {
		cout << s2[i];
	}
}
