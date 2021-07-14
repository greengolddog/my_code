#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll to_ll(char c) {
	return c-'a';
}

char to_char(ll x) {
	return (char)('a'+x);
}

struct node {
	map<char, node*> next;
	vector<node*> from;
	node *link = nullptr;
	node *p = nullptr;
	char pch;
	bool f = false, used = false;
	ll stc = 0;
	vector<ll> number;
	node(node *p, char pch): p(p), pch(pch) {}
	node* add(char c) {
		if (next.find(c) == next.end() || next[c]->p != this) {
			next[c] = new node(this, c);
		}
		return next[c];
	}
	node* go(char c) {
		if (next.find(c) == next.end()) {
			if (p == nullptr) {
				next[c] = this;
			} else {
				next[c] = get_link()->go(c);
			}
		}
		return next[c];
	}
	node* get_link() {
		if (link == nullptr) {
			if (p == nullptr) {
				link = this;
			} else {
				if (p->p == nullptr) {
					link = p;
				} else {
					link = p->get_link()->go(pch);
				}
			}
		}
		return link;
	}
	void reverse_link() {
		get_link()->from.push_back(this);
	}
	void be() {
		stc++;
	}
	ll get() {
		return stc;
	}
	void be_t(ll x) {
		f = true;
		number.push_back(x);
	}
	bool is_t() {
		return f;
	}
};

void dfs(node *t, vector<pair<ll, ll>>& ans) {
	t->used = true;
	for (auto i : t->from) {
		if (!i->used) {
			dfs(i, ans);
			t->stc += i->stc;
		}
	}
	if (t->f) {
		for (auto i : t->number) {
			ans.push_back({i, t->stc});
		}
	}
}

struct trie {
	node *root;
	vector<node*> all;
	ll stc = 0;
	trie() {
		root = new node(nullptr, '-');
		all.push_back(root);
	}
	void add(string s) {
		node *now = root;
		for (auto i : s) {
			now = now->add(i);
			all.push_back(now);
		}
		now->be_t(stc);
		stc++;
	}
	vector<pair<ll, ll>> col(string s) {
		node *now = root;
		for (auto i : s) {
			now = now->go(i);
			now->be();
		}
		for (auto i : all) {
			i->reverse_link();
		}
		vector<pair<ll, ll>> ans;
		dfs(root, ans);
		return ans;
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	trie t;
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		t.add(s);
	}
	string s;
	cin >> s;
	vector<pair<ll, ll>> ans = t.col(s);
	sort(ans.begin(), ans.end());
	for (auto[_, x] : ans) {
		cout << x << '\n';
	}
}
