#include <bits/stdc++.h>
typedef int ll;

const ll INF = 32'000;

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

ll gcd(ll a, ll b) {
	return (min(a, b) == 0 ? max(a, b) : gcd(max(a, b) % min(a, b), min(a, b)));
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

void rec2(vector<ll>& now, vector<ll>& arr, vector<pair<ll, ll>>& s, vector<ll>& need, vector<ll>& t) {
	if (now.size() == arr.size()) {
		vector<ll> p0, p1;
		for (ll i = 0; i < now.size(); i++) {
			p0.push_back(now[i] * 2 % arr[i]);
		}
		for (ll i = 0; i < now.size(); i++) {
			p1.push_back((now[i] * 2 + 1) % arr[i]);
		}
		ll np0 = 0, np1 = 0;
		ll nn = 1;
		for (ll i = now.size() - 1; i >= 0; i--) {
		       	np0 += p0[i] * nn;
			np1 += p1[i] * nn;
			nn *= arr[i];
		}
		s.push_back(make_pair(np0, np1));
		bool b = false;
		ll x = 1;
		for (ll j = 0; j < now.size(); j++) {
			x *= gcd(now[j], arr[j]);
		}
		for (auto i : need) {
			if (x % i == 0) {
				b = true;
				break;
			}
		}
		if (b) {
			t.push_back(s.size() - 1);
		}
		return;
	}
	now.push_back(0);
	for (; now.back() < arr[now.size() - 1]; now.back()++) {
		rec2(now, arr, s, need, t);
	}
	now.pop_back();
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll s;
	cin >> s;
	vector<ll> arr;
	for (ll i = 0; i < s; i++) {
		int x;
		cin >> x;
		//if (x <= 20'000) {
		arr.push_back(x);
		//}
	}
	sort(arr.begin(), arr.end());
	vector<ll> col(20'001, 1);
	vector<ll> need;
	ll x = 1, x3 = 1;
	for (ll i = 0; i < s; i++) {
		bool b = true;
		for (auto j : need) {
			if (arr[i] % j == 0) {
				b = false;
				break;
			}
		}
		if (b) {
			x3 = lcm(x3, arr[i]);
			need.push_back(arr[i]);
			arr[i] /= gcd(x, arr[i]);
			for (ll j = 2; j * j <= arr[i]; j++) {
				while (arr[i] % j == 0) {
					col[j] *= j;
					x *= j;
					arr[i] /= j;
				}
			}
			if (arr[i] > 1) {
				col[arr[i]] *= arr[i];
				x *= arr[i];
			}
		}
	}
	arr.clear();
	ll x2 = 1;
	for (ll i = 2; i <= 20'000; i++) {
		if (col[i] > 1) {
			arr.push_back(col[i]);
			x2 *= col[i];
		}
	}
	if (x > 20'000) {
		return 2;
	}
	if ((x != x2)) {
		return 1;
	}
	col.clear();
	vector<ll> now;
	vector<pair<ll, ll>> ans;
	vector<ll> t;
	rec2(now, arr, ans, need, t);
	cout << x << '\n';
	cout << 1 << ' ';
	cout << t.size() << ' ';
	for (auto i : t) {
		cout << i + 1 << ' ';
	}
	cout << '\n';
	for (auto[a, b] : ans) {
		cout << a + 1 << ' ' << b + 1 << '\n';
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
