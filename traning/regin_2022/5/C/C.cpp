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

mt19937 rnd(time(0));

string solve(ll n, ll k, string s) {
	ll col_e = 30;
	vector<ll> col(col_e, 0);
	for (auto i : s) {
		col[i - 'a']++;
	}
	vector<pair<ll, ll>> all;
	for (ll i = 0; i < col_e; i++) {
		all.push_back(make_pair(-col[i], i));
	}
	sort(all.begin(), all.end());
	vector<ll> q;
	for (auto[_, i] : all) {
		q.push_back(i);
	}
	for (ll i = 0; i < col_e; i++) {
		if (n % (i + 1) == 0) {
			ll c = n / (i + 1);
			ll need = 0;
			for (ll j = 0; j <= i; j++) {
				need += max(0ll, c - col[q[j]]);
			}
			if (need <= k) {
				vector<ll> get(col_e, 0), need(col_e, 0);
				for (ll j = 0; j <= i; j++) {
					get[q[j]] = max(0ll, c - col[q[j]]);
				}
				for (ll j = 0; j <= i; j++) {
					need[q[j]] = c;
				}
				for (ll j = 0; j < n; j++) {
					if (col[s[j] - 'a'] > need[s[j] - 'a']) {
						ll now = 0;
						for (; now < col_e; now++) {
							if (get[now] > 0) {
								break;
							}
						}
						get[now]--;
						col[s[j] - 'a']--;
						s[j] = now + 'a';
					}
				}
				return s;
			}
		}
	}
	ll aa = INF;
	string sa = s;
	assign_min(k, n);
	vector<vector<ll>> arr(col_e);
	for (ll i = 0; i < n; i++) {
		arr[s[i] - 'a'].push_back(i);
	}
	vector<ll> col_add(col_e, 0);
	for (ll i = col_e; i > 0; i--) {
		if (i != col_e) {
			if (col[q[i]] == 0) {
				continue;
			}
			col[q[i]] = 0;
			k += col_add[q[i]];
			for (auto i : arr[q[i]]) {
				k--;
				ll mi = INF, nmi = 0;
				for (ll i = 0; i < col_e; i++) {
					if (col[i] != 0 && assign_min(mi, col[i])) {
						nmi = i;
					}
				}
				col_add[nmi]++;
				arr[nmi].push_back(i);
				col[nmi]++;
				s[arr[nmi].back()] = nmi + 'a';
			}
			if (k < 0) {
				break;
			}
			arr[q[i]].clear();
		}
		ll kn = k;
		auto narr = arr;
		auto ncol = col;
		string sn = s;
		while (true) {
			ll ma = 0, nma = 0;
			for (ll i = 0; i < col_e; i++) {
				if (assign_max(ma, ncol[i])) {
					nma = i;
				}
			}
			ll mi = INF, nmi = 0;
			for (ll i = 0; i < col_e; i++) {
				if (ncol[i] != 0 && assign_min(mi, ncol[i])) {
					nmi = i;
				}
			}
			kn--;
			if (assign_min(aa, ma - mi)) {
				sa = sn;
			}
			if (kn < 0) {
				break;
			}
			if (ma - mi < 2) {
				break;
			}
			narr[nmi].push_back(narr[nma].back());
			narr[nma].pop_back();
			sn[narr[nmi].back()] = nmi + 'a';
			ncol[nmi]++;
			ncol[nma]--;
		}
	}
	return sa;
}

string smart(ll n, ll k, string s) {
	ll a = INF;
	ll col_e = 30;
	string sa = s;
	for (ll i = 0; i < n; i++) {
		string ns = s;
		for (ll j = 'a'; j < 'z'; j++) {
			ns[i] = j;
			vector<ll> col(col_e, 0);
			for (auto i : ns) {
				col[i - 'a']++;
			}
			ll ma = 0, nma = 0;
			for (ll i = 0; i < col_e; i++) {
				if (assign_max(ma, col[i])) {
					nma = i;
				}
			}
			ll mi = INF, nmi = 0;
			for (ll i = 0; i < col_e; i++) {
				if (col[i] != 0 && assign_min(mi, col[i])) {
					nmi = i;
				}
			}
			if (assign_min(a, ma - mi)) {
				sa = ns;
			}
		}
	}
	return sa;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	bool b = true;
	if (b) {
		ll n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		cout << solve(n, k, s);
	} else {
		while (true) {
			ll n = rnd() % 10 + 1, k = 1;
			string s;
		}
	}
}
/*
⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣵⣿⣿⣿⠿⡟⣛⣧⣿⣯⣿⣝⡻⢿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⠋⠁⣴⣶⣿⣿⣿⣿⣿⣿⣿⣦⣍⢿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⢷⠄⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢼⣿⣿⣿⣿
⢹⣿⣿⢻⠎⠔⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⣿⣿⣿⣿
⢸⣿⣿⠇⡶⠄⣿⣿⠿⠟⡛⠛⠻⣿⡿⠿⠿⣿⣗⢣⣿⣿⣿⣿
⠐⣿⣿⡿⣷⣾⣿⣿⣿⣾⣶⣶⣶⣿⣁⣔⣤⣀⣼⢲⣿⣿⣿⣿
⠄⣿⣿⣿⣿⣾⣟⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⢟⣾⣿⣿⣿⣿
⠄⣟⣿⣿⣿⡷⣿⣿⣿⣿⣿⣮⣽⠛⢻⣽⣿⡇⣾⣿⣿⣿⣿⣿
⠄⢻⣿⣿⣿⡷⠻⢻⡻⣯⣝⢿⣟⣛⣛⣛⠝⢻⣿⣿⣿⣿⣿⣿
⠄⠸⣿⣿⡟⣹⣦⠄⠋⠻⢿⣶⣶⣶⡾⠃⡂⢾⣿⣿⣿⣿⣿⣿
⠄⠄⠟⠋⠄⢻⣿⣧⣲⡀⡀⠄⠉⠱⣠⣾⡇⠄⠉⠛⢿⣿⣿⣿
⠄⠄⠄⠄⠄⠈⣿⣿⣿⣷⣿⣿⢾⣾⣿⣿⣇⠄⠄⠄⠄⠄⠉⠉
⠄⠄⠄⠄⠄⠄⠸⣿⣿⠟⠃⠄⠄⢈⣻⣿⣿⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⢿⣿⣾⣷⡄⠄⢾⣿⣿⣿⡄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠸⣿⣿⣿⠃⠄⠈⢿⣿⣿⠄⠄⠄⠄⠄⠄⠄
*/
