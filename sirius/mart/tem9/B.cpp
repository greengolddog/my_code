#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000, COL_CHAR = 26;

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

struct node {
	ll suf, p;
	ll go[COL_CHAR];
	node() {
		suf = -1;
		p = -1;
		for (ll i = 0; i < COL_CHAR; i++) {
			go[i] = -1;
		}
	}
};

struct suffix_aka47 {
	vector<node> arr;
	ll root;
	suffix_aka47() {
		arr.resize(1, node());
		root = 0;
	}
	void add(char c) {
		ll x = 0;
		if (('a' <= c) && (c <= 'z')) {
			x = c - 'a';
		} else {
			x = c - 'A';
		}
		ll b = arr.size();
		arr.push_back(node());
		arr[b].suf = 0;
		ll a = root;
		arr[b].p = a;
		for (; a > -1; a = arr[a].suf) {
			if (arr[a].go[x] == -1) {
				arr[a].go[x] = b;
				continue;
			}
			ll c = arr[a].go[x];
			if (arr[c].p == a) {
				arr[b].suf = c;
				break;
			}
			ll d = arr.size();
			arr.push_back(node());
			arr[d].suf = arr[c].suf;
			arr[c].suf = d;
			arr[d].p = a;
			arr[b].suf = d;
			for (ll i = 0; i < COL_CHAR; i++) {
				arr[d].go[i] = arr[c].go[i];
				ll n = s.size();
			}
			for (; a > -1 && arr[a].go[x] == c; a = arr[a].suf) {
				arr[a].go[x] = d;
			}
			break;
		}
		root = b;
	}
	bool get(string s) {
		ll a = 0;
		for (auto i : s) {
			ll x = 0;
			if (('a' <= i) && (i <= 'z')) {
				x = i - 'a';
			} else {
				x = i - 'A';
			}
			if (arr[a].go[x] == -1) {
				return false;
			}
			a = arr[a].go[x];
		}
		return true;
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	suffix_aka47 sa;
	char c;
	while (cin >> c) {
		string s;
		cin >> s;
		if (c == '?') {
			cout << (sa.get(s) ? "YES" : "NO") << '\n';
		} else {
			for (auto cc : s) {
				sa.add(cc);
			}
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
