#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct steck {
	vector<ll> arr;
	steck(vector<ll> arr = vector<ll>(0, 0)): arr(arr) {}
	void push(ll n = 0) {
		arr.push_back(n);
	}
	ll pop() {
		if (size() == 0) {
			return -10000000000;
		}
		ll ans = arr[size() - 1];
		arr.pop_back();
		return ans;
	}
	ll back() {
		if (size() == 0) {
			return -10000000000;
		}
		return arr[size() - 1];
	}
	ll size() {
		return arr.size();
	}
	ll operator[] (ll n) {
		return arr[n];
	}
	void clear() {
		arr.resize(0, 0);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	steck s;
	while (true) {
		string com;
		cin >> com;
		if (com == "push") {
			ll n;
			cin >> n;
			s.push(n);
			cout << "ok" << '\n';
		}
		if (com == "pop") {
			ll ans = s.pop();
			cout << ((ans == -10000000000) ? "error" : to_string(ans)) << '\n';
		}
		if (com == "back") {
			ll ans = s.back();
			cout << ((ans == -10000000000) ? "error" : to_string(ans)) << '\n';
		}
		if (com == "size") {
			cout << s.size() << '\n';
		}
		if (com == "clear") {
			s.clear();
			cout << "ok" << '\n';
		}
		if (com == "exit") {
			cout << "bye" << '\n';
			break;
		}
	}
}
