#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct element {
	element* next;
	element* pred;
	ll num;
	element(ll num, element& n, element& p): num(num) {
		next = &n;
		pred = &p;
		n.pred = this;
		p.next = this;
	}
	element() {
		num = 0;
		next = this;
		pred = this;
	}
	void del() {
		next->pred = pred;
		pred->next = next;
	}
};

struct q {
	element* start;
	element* mid;
	element* end;
	ll size = 0;
	q() {
		element e;
		start = &e;
		mid = &e;
		end = &e;
	}
	void add(ll num) {
		size++;
		element e(num, *end, *(end->pred));
		if (size == 1) {
			start = &e;
		}
		if (size % 2 == 1) {
			mid = mid->next;
		}
	}
	ll del() {
		ll ans = start->num;
		size--;
		start->del();
		if ((size % 2 == 1) || (size == 0)) {
			mid = mid->next;
		}
		start = start->next;
		return ans;
	}
	void add_cool(ll num) {
		size++;
		element e(num, *(mid->next), *mid);
		if (size == 1) {
			start = &e;
		}
		if (size % 2 == 1) {
			mid = mid->next;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	q que;
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		char com;
		cin >> com;
		if (com == '-') {
			cout << que.del() << endl;
		} else {
			ll num;
			cin >> num;
			if (com == '+') {
				que.add(num);
			} else {
				que.add_cool(num);
			}
		}
	}
}
