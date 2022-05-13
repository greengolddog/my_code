#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000, mod = 1'000'000'009;

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
	ll col = 0;
	vector<ll> dp, new_dp;
	ll nums = 0;
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
		nums |= 1 << i;
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
	ll end(ll n, ll c) {
		vector<node*> arr;
		queue<node*> q;
		q.push(root);
		root->be_used();
		while (!q.empty()) {
			node *now = q.front();
			now->dp.resize(1 << col, 0);
			q.pop();
			now->nums |= now->get_link()->nums;
			arr.push_back(now);
			for (auto[_, i] : now->go) {
				if (!i->is_used()) {
					i->be_used();
					i->nums |= now->nums;
					q.push(i);
				}
			}
		}
		root->dp[0] = 1;
		for (ll i = 0; i < n; i++) {
			for (auto l : arr) {
				l->new_dp.clear();
				l->new_dp.resize(1 << col, 0);
			}
			for (ll j = 'a'; j <= 'z'; j++) {
				for (ll k = 0; k < (1 << col); k++) {
					for (auto l : arr) {
						l->get_go(j)->new_dp[k | l->get_go(j)->nums] += l->dp[k];
						l->get_go(j)->new_dp[k | l->get_go(j)->nums] %= mod;
					}
				}
			}
			for (auto l : arr) {
				l->dp = l->new_dp;
			}
		}
		ll ans = 0;
		for (ll i = 0; i < (1 << col); i++) {
			ll x = 0;
			for (ll j = 0; j < col; j++) {
				x += (i >> j) & 1;
			}
			if (x == c) {
				for (auto j : arr) {
					ans += j->dp[i];
					ans %= mod;
				}
			}
		}
		return ans;
	}
};

int main() {
	freopen("cofnsubstrings.in", "r", stdin);
	freopen("cofnsubstrings.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	trie t;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		t.add(s);
	}
	ll c, l;
	cin >> c >> l;
	cout << t.end(l, c);
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
