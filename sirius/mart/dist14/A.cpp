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

struct min_stack {
	stack<ll> s, mins;
	ll sz = 0;
	min_stack() {
		mins.push(INF);
		sz = 0;
	}
	void push(ll x) {
		s.push(x);
		mins.push(min(mins.top(), x));
		sz++;
	}
	ll pop() {
		ll x = s.top();
		s.pop();
		mins.pop();
		sz--;
		return x;
	}
	ll get_min() {
		return mins.top();
	}
	ll top() {
		return s.top();
	}
	ll size() {
		return sz;
	}
	bool empty() {
		return size() == 0;
	}
};

struct min_queue {
	min_stack s1, s2;
	min_queue() {}
	void push(ll x) {
		s1.push(x);
	}
	ll pop() {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.pop());
			}
		}
		return s2.pop();
	}
	ll get_min() {
		return min(s1.get_min(), s2.get_min());
	}
	ll size() {
		return s1.size() + s2.size();
	}
	bool empty() {
		return size() == 0;
	}
};

struct pref_sum {
	vector<vector<ll>> arr;
	pref_sum(vector<vector<ll>> a) {
		arr.resize(a.size() + 1, vector<ll>(a[0].size() + 1, 0));
		for (ll i = 0; i < a.size(); i++) {
			for (ll j = 0; j < a[0].size(); j++) {
				arr[i + 1][j + 1] = arr[i][j + 1] + arr[i + 1][j] - arr[i][j] + a[i][j];
			}
		}
	}
	ll get(ll x1, ll y1, ll x2, ll y2) {
		return arr[x2 + 1][y2 + 1] - arr[x2 + 1][y1] - arr[x1][y2 + 1] + arr[x1][y1];
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m, a, b, c, d;
	cin >> n >> m >> a >> b >> c >> d;
	swap(n, m);
	swap(a, b);
	swap(c, d);
	vector<vector<ll>> arr(n, vector<ll>(m, 0));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	pref_sum ps(arr);
	vector<vector<ll>> sumab(n - a + 1, vector<ll>(m - b + 1, 0));
	for (ll i = 0; i <= n - a; i++) {
		for (ll j = 0; j <= m - b; j++) {
			sumab[i][j] = ps.get(i, j, i + a - 1, j + b - 1);
		}
	}
	vector<vector<ll>> sumcd(n - c + 1, vector<ll>(m - d + 1, 0));
	for (ll i = 0; i <= n - c; i++) {
		for (ll j = 0; j <= m - d; j++) {
			sumcd[i][j] = ps.get(i, j, i + c - 1, j + d - 1);
		}
	}
	ll colbd = b - d - 1;
	vector<vector<ll>> ms(n - c + 1, vector<ll>(m - d - colbd + 2, 0));
	for (ll i = 0; i <= n - c; i++) {
		min_queue mq;
		for (ll j = 0; j < colbd; j++) {
			mq.push(sumcd[i][j]);
		}
		for (ll j = colbd; j <= m - d; j++) {
			ms[i][j - colbd] = mq.get_min();
			mq.pop();
			mq.push(sumcd[i][j]);
		}
		ms[i].back() = mq.get_min();
	}
	ll colac = a - c - 1;
	vector<vector<ll>> mm(n - c - colac + 2, vector<ll>(m - d - colbd + 2, 0));
	for (ll i = 0; i <= m - d - colbd + 1; i++) {
		min_queue mq;
		for (ll j = 0; j < colac; j++) {
			mq.push(ms[j][i]);
		}
		for (ll j = colac; j <= n - c; j++) {
			mm[j - colac][i] = mq.get_min();
			mq.pop();
			mq.push(ms[j][i]);
		}
		mm.back()[i] = mq.get_min();
	}
	ll maxs = 0, x1, x2, y1, y2;
	for (ll i = 0; i <= n - a; i++) {
		for (ll j = 0; j <= m - b; j++) {
			if (assign_max(maxs, sumab[i][j] - mm[i + 1][j + 1])) {
				x1 = i;
				y1 = j;
			}
		}
	}
	ll mms = 0;
	for (ll i = x1 + 1; i <= x1 + colac; i++) {
		for (ll j = y1 + 1; j <= y1 + colbd; j++) {
			if (assign_max(mms, sumab[x1][y1] - sumcd[i][j])) {
				x2 = i;
				y2 = j;
			}
		}
	}
	cout << y1 + 1 << ' ' << x1 + 1 << '\n' << y2 + 1 << ' ' << x2 + 1 << '\n';
}
