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

int main() {
	//aboba7
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll h, w, c;
	cin >> h >> w >> c;
	map<pair<ll, char>, ll> m;
	vector<string> all;
	for (ll i = 0; i < h * w; i++) {
		ll x;
		char c;
		cin >> x >> c;
		all.push_back(to_string(x) + c);
		m[make_pair(x, c)]++;
	}
	char p1 = 'a', p2, p3, p4;
	ll wa = 1, ha = 1, p = 1;
	vector<ll> ch(c), cw(c);
	for (ll hh = 2; hh <= h; hh++) {
		for (ll ww = 2; ww < w; ww++) {
			ll lw = ww - 2, lh = hh - 2;
			if (lw * 2 + lh * 2 + 4 <= p) {
				continue;
			}
			for (ll i = 'a'; i < 'a' + c; i++) {
				if (m[make_pair(0, i)] > 0) {
					for (ll j = 'a'; j < 'a' + c; j++) {
						if (m[make_pair(1, j)] > 0) {
							for (ll k = 'a'; k < 'a' + c; k++) {
								if (m[make_pair(2, k)] > 0) {
									for (ll l = 'a'; l < 'a' + c; l++) {
										if (m[make_pair(3, l)] > 0) {
											vector<ll> can(c, (lw + 1) / 2 * 2), nh(c), nw(c);
											if (i != j && (lw % 2 == 1)) {
												can[i - 'a']--;
												can[j - 'a']--;
											}
											if (i == j) {
												can[i - 'a']--;
											}
											if (k != l && (lw % 2 == 1)) {
												can[k - 'a']--;
												can[l - 'a']--;
											}
											if (k == l) {
												can[k - 'a']--;
											}
											ll nc = lw * 2;
											ll nco = 0;
											while (nc > 0 && (nco != nc)) {
												nco = nc;
												for (ll o = 'a'; o < 'a' + c; o++) {
													if (nh[o - 'a'] < can[o - 'a'] && nh[o - 'a'] <  m[make_pair(4, o)] && nc > 0) {
														nh[o - 'a']++;
														nc--;
													}
												}
											}
											if (nc > 0) {
												continue;
											}
											can.clear();
											can.resize(c, (lh + 1) / 2 * 2);
											if (i != l && (lh % 2 == 1)) {
												can[i - 'a']--;
												can[l - 'a']--;
											}
											if (i == l) {
												can[i - 'a']--;
											}
											if (k != j && (lh % 2 == 1)) {
												can[k - 'a']--;
												can[j - 'a']--;
											}
											if (k == j) {
												can[k - 'a']--;
											}
											nc = lw * 2;
											nco = 0;
											while (nc > 0 && (nco != nc)) {
												nco = nc;
												for (ll o = 'a'; o < 'a' + c; o++) {
													if (nw[o - 'a'] < can[o - 'a'] && nw[o - 'a'] <  m[make_pair(5, o)] && nc > 0) {
														nw[o - 'a']++;
														nc--;
													}
												}
											}
											if (nc == 0) {
												wa = ww;
												ha = hh;
												p = lw * 2 + lh * 2 + 4;
												ch = nh;
												cw = nw;
												p1 = i;
												p2 = j;
												p3 = k;
												p4 = l;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (p == 1) {
		shuffle(all.begin(), all.end(), rnd);
		for (ll i = 0; i < h; i++) {
			for (ll j = 0; j < w; j++) {
				cout << all[i * w + j] << ' ';
			}
			cout << endl;
		}
		return 0;
	}
	m[make_pair(0, p1)]--;
	m[make_pair(1, p2)]--;
	m[make_pair(2, p3)]--;
	m[make_pair(3, p4)]--;
	cout << "0" << p1 << ' ';
	char prev = p1;
	for (ll i = 1; i < wa - 1; i++) {
		char ans;
		ll col = 0;
		vector<ll> a;
		for (ll j = 'a'; j < 'a' + c; j++) {
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
