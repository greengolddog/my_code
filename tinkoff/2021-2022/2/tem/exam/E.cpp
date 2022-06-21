#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

template<typename T>
T square(T a) {
	return a * a;
}

ll get(char c, ll sum = 0) {
	if (c >= '2' && c <= '9') {
		return sum + c - '0';
	}
	if (c != 'A') {
		return sum + 10;
	}
	if (sum <= 10) {
		return sum + 11;
	} else {
		return sum + 1;
	}
}

void shuffle(multiset<char>& s) {
	for (ll i = 0; i < 4; i++) {
		for (char c = '2'; c <= '9'; c++) {
			s.insert(c);
		}
		s.insert('A');
		s.insert('J');
		s.insert('Q');
		s.insert('K');
		s.insert('0');
	}
}

bool cmp(char c1, char c2) {
	if (c1 == 'A' && c2 == 'A') {
		return false;
	}
	if (c1 == 'A') {
		return true;
	}
	if (c2 == 'A') {
		return false;
	}
	return c1 < c2;
}

ll count(string s) {
	sort(s.begin(), s.end(), cmp);
	reverse(s.begin(), s.end());
	ll ans = 0;
	for (auto i : s) {
		ans = get(i, ans);
	}
	return ans;
}

pair<ll, ll> ns(string s) {
	string s1, s2;
	bool b = false;
	for (auto i : s) {
		if (i == '#') {
			b = true;
			continue;
		}
		if (b) {
			s2.push_back(i);
		} else {
			s1.push_back(i);
		}
	}
	return make_pair(count(s1), count(s2));
}

void solve() {
	ll now = 500'000, need = 4'200'000, colg = 0;
	char c;
	multiset<char> ss;
	for (ll i = 0; i < 6; i++) {
		shuffle(ss);
	}
	while (now > 0 && now < need && colg <= 10'000) {
		string s, s22;
		cin >> s;
		while (s == "shuffle") {
			shuffle(ss);
			cin >> s;
		}
		ll bet = now / 5;
		cout << bet << endl;
		cin >> c;
		ll ds = get(c);
		//ss.erase(ss.find(c));
		cin >> c >> c;
		s22.push_back(c);
		//ss.erase(ss.find(c));
		ll sum = get(c);
		cin >> c;
		s22.push_back(c);
		//ss.erase(ss.find(c));
		sum = ns(s22).first;
		while (true) {
			ll cv = 0;
			for (auto i : ss) {
				s22.push_back(i);
				cv += ns(s22).first <= 21;
				s22.pop_back();
			}
			if (cv >= ss.size() / 2 && sum <= 21) {
				cout << "hit" << endl;
				cin >> s;
				//ss.erase(ss.find(s.back()));
				auto[s1, s2] = ns(s);
				ds = s1;
				sum = s2;
				s22.push_back(s.back());
			} else {
				cout << "break" << endl;
				cin >> s;
				auto[s1, s2] = ns(s);
				ds = s1;
				sum = s2;
				bool b = false;
				for (auto i : s) {
					if (!b) {
						b = true;
						continue;
					}
					if (i == '#') {
						break;
					}
					//ss.erase(ss.find(i));
				}
				if (sum > 21) {
					now -= bet;
					break;
				}
				if (ds > 21) {
					now += bet;
					break;
				}
				if (ds > sum) {
					now -= bet;
				}
				if (sum > ds) {
					now += bet;
				}
				break;
			}
		}
		colg++;
	}
	cout << -1 << endl;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
