#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct deq {
	vector<ll> arr;
	ll begin;
	ll end;
	ll len = 0;
	deq(ll ms = 3, vector<ll> arrr = vector<ll>(0, 0)){
		arr.resize(ms, 0);
		begin = 0;
		end = arrr.size();
		for (ll i = 0; i < arrr.size(); i++) {
			arr[i] = arrr[i];
		}
	}
	void push_back(ll n = 0) {
		len++;
		if (end < arr.size()) {
			arr[end] = n;
			end++;
			return;
		}
		end = 1;
		arr[0] = n;
	}
	void push_front(ll n = 0) {
		len++;
		if (begin > 0) {
			begin--;
			arr[begin] = n;
			return;
		}
		begin = arr.size()-1;
		arr[begin] = n;
	}
	ll pop_back() {
		if (size() == 0) {
			return -10000000000;
		}
		len--;
		ll ans = arr[end - 1];
		if (end == 1) {
			end = arr.size() - 1;
			return ans;
		}
		end--;
		return ans;
	}
	ll pop_front() {
		if (size() == 0) {
			return -10000000000;
		}
		len--;
		ll ans = arr[begin];
		if (begin == arr.size()-1) {
			begin = 0;
			return ans;
		}
		begin++;
		return ans;
	}
	ll front() {
		if (size() == 0) {
			return -10000000000;
		}
		return arr[begin];
	}
	ll back() {
		if (size() == 0) {
			return -10000000000;
		}
		return arr[end - 1];
	}
	ll size() {
		return len;
	}
	void clear() {
		for (ll i = begin; i < end; i++) {
			arr[i] = 0;
		}
		if (begin > end) {
			for (ll i = 0; i < end; i++) {
				arr[i] = 0;
			}
			for (ll i = begin; i < arr.size(); i++) {
				arr[i] = 0;
			}
		}
		begin = 0;
		end = 0;
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	deq s;
	while (true) {
		string com;
		cin >> com;
		if (com == "push_back") {
			ll n;
			cin >> n;
			s.push_back(n);
			cout << "ok" << '\n';
		}
		if (com == "push_front"){
			ll n;
			cin >> n;
			s.push_front(n);
			cout << "ok" << '\n';
		}
		if (com == "pop_back") {
			ll ans = s.pop_back();
			cout << ((ans == -10000000000) ? "error" : to_string(ans)) << '\n';
		}
		if (com == "pop_front") {
			ll ans = s.pop_front();
			cout << ((ans == -10000000000) ? "error" : to_string(ans)) << '\n';
		}
		if (com == "front") {
			ll ans = s.front();
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
