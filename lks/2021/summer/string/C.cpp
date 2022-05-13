#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000, col_char = 26;

struct node {
	bool f = false;
	ll col = 0;
	map<char, node*> arr;
	node() {}
	void end() {
		f = true;
		col++;
	}
	void add(char c) {
		if (arr.find(c) == arr.end()) {
			arr[c] = new node();
		}
		col++;
	}
	node *go(char c) {
		if (arr.find(c) == arr.end()) {
			return nullptr;
		}
		return arr[c];
	}
};

ll get_size(node *t) {
	if (t == nullptr) {
		return 0;
	}
	return t->col;
}

struct bor {
	node *root = nullptr;
	bor() {
		root = new node();
	}
	void add(string s) {
		auto now = root;
		for (auto i : s) {
			now->add(i);
			now = now->go(i);
		}
		now->end();
	}
	string get(ll x) {
		string ans;
		auto now = root;
		while (!(x == 1 && now->f)) {
			if (now->f) {
				x--;
			}
			for (ll i = 'a'; i <= 'z'; i++) {
				if (x <= get_size(now->go(i))) {
					ans.push_back((char)i);
					now = now->go(i);
					break;
				} else {
					x -= get_size(now->go(i));
				}
			}
		}
		return ans;
	}
};

int main() {
	freopen("kthstr.in", "r", stdin);
	freopen("kthstr.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	bor b;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[0] - '0' >= 0 && s[0] - '0' <= 9) {
			cout << b.get(stoi(s)) << '\n';
		} else {
			b.add(s);
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
