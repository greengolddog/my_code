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
	bool term = false, used = false, used2 = false;
	ll col = 0;
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
	vector<node*> all_go() {
		vector<node*> ans;
		ans.push_back(get_go('0'));
		ans.push_back(get_go('1'));
		return ans;
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
	void be_used2() {
		used2 = true;
	}
	bool is_used2() {
		return used2;
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
		for (char i = '0'; i <= '1'; i++) {
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
	bool end() {
		vector<node*> arr;
		queue<node*> q;
		q.push(root);
		root->be_used();
		while (!q.empty()) {
			node *now = q.front();
			q.pop();
			arr.push_back(now);
			if (now->get_link()->is_term()) {
				now->make_term(0);
			}
			for (auto[_, i] : now->go) {
				if (!i->is_used()) {
					i->be_used();
					q.push(i);
				}
			}
		}
		for (auto i : arr) {
			i->be_unused();
		}
		return dfs(root);
	}
	bool dfs(node *x) {
		x->be_used();
		x->be_used2();
		for (auto i : x->all_go()) {
			if (i->is_used2() || i->is_term()) {
				if (i->is_used()) {
					return true;
				}
			} else {
				if (dfs(i)) {
					return true;
				}
			}
		}
		x->be_unused();
		return false;
	}
};

int main() {
	freopen("virus.in", "r", stdin);
	freopen("virus.out", "w", stdout);
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
	cout << (t.end() ? "TAK" : "NIE");
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
