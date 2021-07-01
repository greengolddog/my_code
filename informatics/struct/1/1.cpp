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
		ll ans = arr[size() - 1];
		arr.pop_back();
		return ans;
	}
	ll back() {
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
			cout << s.pop() << '\n';
		}
		if (com == "back") {
			cout << s.back() << '\n';
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
