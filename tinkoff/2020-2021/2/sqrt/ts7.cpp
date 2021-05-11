#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

struct block {
	vector<ll> arr;
	ll len;
	block(vector<ll> arra = vector<ll>(0, 0)) {
		arr = arra;
		len = arr.size();
	}
	void add(ll a, ll b) {
		arr.insert(arr.begin()+a, b);
		len++;
	}
	void del(ll a) {
		arr.erase(arr.begin()+a);
		len--;
	}
	void add_num(ll a, ll b) {
		arr[a] += b;
	}
	void change(ll a, ll b) {
		arr[a] = b;
	}
	void def(ll a, ll b) {
		arr[a] = arr[a]/b;
	}
	ll operator[](ll a) {
		return arr[a];
	}
};

struct sqrt_min {
	vector<block> arr;
	ll len = 0, k = 350, stc = 0, sum_square = 0, lenl = 0;
	sqrt_min(vector<ll> arra = vector<ll>(1, 0)) {
		lenl = arra.size() - 1;
		vector<ll> bl(0, 0);
		for (ll i = 0; i < arra.size(); i++) {
			sum_square += arra[i]*arra[i];
			bl.push_back(arra[i]);
			if (i % k == k-1) {
				len++;
				arr.push_back(block(bl));
				bl = vector<ll>(0, 0);
			}
		}
		if (bl.size() > 0) {
			len++;
			arr.push_back(block(bl));
		}
	}
	void add(ll a, ll b) {
		lenl++;
		sum_square += b*b;
		for (ll i = 0; i < len; i++) {
			if ((a < arr[i].len) && (a >= 0)) {
				arr[i].add(a, b);
			}
			a -= arr[i].len;
		}
		stc++;
		if (stc == k) {
			per();
			stc = 0;
		}
	}
	ll del(ll a) {
		lenl--;
		for (ll i = 0; i < len; i++) {
			if ((a < arr[i].len) && (a >= 0)) {
				ll ans = arr[i][a];
				sum_square -= arr[i][a]*arr[i][a];
				arr[i].del(a);
				return ans;
			}
			a -= arr[i].len;
		}
	}
	ll operator[] (ll a) {
		for (ll i = 0; i < len; i++) {
			if ((a < arr[i].len) && (a >= 0)) {
				return arr[i][a];
			}
			a -= arr[i].len;
		}
	}
	void change(ll a, ll b) {
		sum_square += b*b;
		for (ll i = 0; i < len; i++) {
			if ((a < arr[i].len) && (a >= 0)) {
				sum_square -= arr[i][a]*arr[i][a];
				arr[i].change(a, b);
				return;
			}
			a -= arr[i].len;
		}
	}
	void add_num(ll a, ll b) {
		for (ll i = 0; i < len; i++) {
			if ((a < arr[i].len) && (a >= 0)) {
				sum_square -= arr[i][a]*arr[i][a];
				arr[i].add_num(a, b);
				sum_square += arr[i][a]*arr[i][a];
				return;
			}
			a -= arr[i].len;
		}
	}
	ll def(ll a, ll b) {
		for (ll i = 0; i < len; i++) {
			if ((a < arr[i].len) && (a >= 0)) {
				ll ans = arr[i][a];
				sum_square -= arr[i][a]*arr[i][a];
				arr[i].def(a, b);
				sum_square += arr[i][a]*arr[i][a];
				return ans;
			}
			a -= arr[i].len;
		}
	}
	void per() {
		vector<ll> arra(0, 0);
		for (ll i = 0; i < len; i++) {
			for (ll j = 0; j < arr[i].len; j++) {
				arra.push_back(arr[i][j]);
			}
		}
		len = 0;
		arr = vector<block>(0, block());
		vector<ll> bl(0, 0);
		for (ll i = 0; i < arra.size(); i++) {
			bl.push_back(arra[i]);
			if (i % k == k-1) {
				len++;
				arr.push_back(block(bl));
				bl = vector<ll>(0, 0);
			}
		}
		if (bl.size() > 0) {
			len++;
			arr.push_back(block(bl));
		}
	}
	ll get_sum() {
		return sum_square;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll m, n, p;
	cin >> n >> p;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	arr.push_back(0);
	cin >> m;
	sqrt_min s(arr);
	cout << s.get_sum() << "\n";
	for (ll i = 0; i < m; i++) {
		ll com;
		cin >> com;
		ll x;
		cin >> x;
		x--;
		if (com == 1) {
			if (x == 0) {
				s.add_num(x + 1, s[x]);
				s.del(x);
			} else if (x == (s.lenl - 1)) {
				s.add_num(x - 1, s[x]);
				s.del(x);
			} else {
				ll p2 = s.del(x);
				s.add_num(x - 1, p2/2);
				s.add_num(x, (p2+1)/2);
			}
		} else {
			ll el = s.def(x, 2);
			s.add(x + 1, (el + 1)/2);
		}
		cout << s.get_sum() << "\n";
	}
}
