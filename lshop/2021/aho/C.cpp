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
	pair<ll, ll> stc = {1000000000000000, 0};
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
	void be(ll x) {
		stc.first = min(stc.first, x);
		stc.second = max(stc.second, x);
	}
	pair<ll, ll> get() {
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

void dfs(node *t, vector<pair<ll, pair<ll, ll>>>& ans) {
	t->used = true;
	for (auto i : t->from) {
		if (!i->used) {
			dfs(i, ans);
			t->stc.first = min(i->stc.first, t->stc.first);
			t->stc.second = max(i->stc.second, t->stc.second);
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
	vector<pair<ll, pair<ll, ll>>> col(string s) {
		node *now = root;
		for (ll i = 0; i < s.size(); i++) {
			now = now->go(s[i]);
			now->be(i+1);
		}
		for (auto i : all) {
			i->reverse_link();
		}
		vector<pair<ll, pair<ll, ll>>> ans;
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
	vector<string> all;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		t.add(s);
		all.push_back(s);
	}
	string s;
	cin >> s;
	vector<pair<ll, pair<ll, ll>>> ans = t.col(s);
	sort(ans.begin(), ans.end());
	for (auto[i, x] : ans) {
		if (x.second == 0) {
			cout << -1 << ' ' << -1 << '\n';
			continue;
		}
		cout << x.first-all[i].size() << ' ' << x.second-all[i].size() << '\n';
	}
}
