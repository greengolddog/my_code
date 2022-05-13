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

struct node {
	map<char, node*> go;
	node *link = nullptr, *p = nullptr;
	bool term = false, used = false;
	ll col = 0, dp = 0, new_dp = 0;
	vector<ll> nums;
	char up = '$';
	node(node *p = nullptr, char up = '$'): p(p), up(up) {
	}
	node *add_go(char c) {
		if (go.find(c) == go.end()) {
			go[c] = new node(this, c);
		}
		return go[c];
	}
	node *get_link() {
		if (link == nullptr) {
			link = p->get_link()->get_go(up);
		}
		return link;
	}
	node *get_go(char c) {
		if (go.find(c) == go.end()) {
			go[c] = get_link()->get_go(c);
		}
		return go[c];
	}
	void make_term(ll i) {
		term = true;
		nums.push_back(i);
	}
	bool is_term() {
		return term;
	}
	void be_in() {
		col++;
	}
	ll& get_col() {
		return col;
	}
	bool is_used() {
		return used;
	}
	void be_used() {
		used = true;
	}
	void be_unused() {
		used = false;
	}
};

struct trie {
	node *root;
	ll col = 0;
	vector<ll> ans;
	trie() {
		node *trash = new node();
		trash->p = trash;
		trash->link = trash;
		root = new node(trash);
		for (char i = 'a'; i <= 'z'; i++) {
			trash->go[i] = root;
		}
		root->link = trash;
	}
	void add(string s) {
		node *now = root;
		for (auto i : s) {
			now = now->add_go(i);
		}
		now->make_term(col);
		ans.push_back(0);
		col++;
	}
	ll end(ll n) {
		root->dp = 1;
		vector<node*> arr;
		queue<node*> q;
		q.push(root);
		root->be_used();
		while (!q.empty()) {
			node *now = q.front();
			q.pop();
			if (now->get_link()->is_term()) {
				now->make_term(0);
			}
			if (!now->is_term()) {
				arr.push_back(now);
			}
			for (auto[_, i] : now->go) {
				if (!i->is_used()) {
					i->be_used();
					if (now->is_term()) {
						i->make_term(0);
					}
					q.push(i);
				}
			}
		}
		for (auto i : arr) {
			i->be_unused();
		}
		for (ll i = 0; i < n; i++) {
			for (auto j : arr) {
				j->new_dp = 0;
			}
			for (auto j : arr) {
				for (char k = 'a'; k <= 'z'; k++) {
					if (!j->get_go(k)->is_term()) {
						j->get_go(k)->new_dp += j->dp;
						j->get_go(k)->new_dp = j->get_go(k)->new_dp % 10'000;
					}
				}
			}
			for (auto j : arr) {
				j->dp = j->new_dp;
			}
		}
		ll ans = 0;
		for (auto i : arr) {
			ans += i->dp;
		}
		return ans % 10'000;
	}
};

int main() {
	freopen("strings.in", "r", stdin);
	freopen("strings.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, c;
	cin >> n >> c;
	trie t;
	for (ll i = 0; i < c; i++) {
		string s;
		cin >> s;
		t.add(s);
	}
	ll ans = 1;
	for (ll i = 0; i < n; i++) {
		ans *= 26;
		ans = ans % 10'000;
	}
	cout << (ans - t.end(n) + 10'000) % 10'000;
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
