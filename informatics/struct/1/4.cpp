#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct que {
	vector<ll> arr, rra;
	que(vector<ll> arr = vector<ll>(0, 0)): arr(arr) {}
	void push(ll n = 0) {
		arr.push_back(n);
	}
	ll pop() {
		if (size() == 0) {
			return -10000000000;
		}
		if (rra.size() == 0) {
			for (ll i = arr.size() - 1; i >= 0; i--) {
				rra.push_back(arr[i]);
			}
			arr.resize(0, 0);
		}
		ll ans = rra[rra.size()-1];
		rra.pop_back();
		return ans;
	}
	ll front() {
		if (size() == 0) {
			return -10000000000;
		}
		if (rra.size() == 0) {
			return arr[0];
		}
		return rra[rra.size() - 1];
	}
	ll size() {
		return arr.size()+rra.size();
	}
	void clear() {
		arr.resize(0, 0);
		rra.resize(0, 0);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	que s;
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
		if (com == "front") {
			ll ans = s.front();
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
