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

mt19937 rnd(time(0));

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll x = 1;
	cout << 'U' << endl;
	char c;
	cin >> c;
	if (c != 'N') {
		return 0;
	}
	cout << 'R' << endl;
	cin >> c;
	if (c != 'N') {
		return 0;
	}
	while (true) {
		cout << 'L' << endl;
		char c;
		cin >> c;
		if (c != 'N') {
			return 0;
		}
		for (ll j = 0; j < x; j++) {
			cout << 'U' << endl;
			char c;
			cin >> c;
			if (c != 'N') {
				return 0;
			}
		}
		for (ll j = 0; j < x; j++) {
			cout << 'R' << endl;
			char c;
			cin >> c;
			if (c != 'N') {
				return 0;
			}
		}
		cout << 'U' << endl;
		cin >> c;
		if (c != 'N') {
			return 0;
		}
		x++;
		for (ll j = 0; j < x; j++) {
			cout << 'L' << endl;
			char c;
			cin >> c;
			if (c != 'N') {
				return 0;
			}
		}
		for (ll j = 0; j < x; j++) {
			cout << 'D' << endl;
			char c;
			cin >> c;
			if (c != 'N') {
				return 0;
			}
		}
		x++;
	}
	while (false) {
		for (ll i = 0; i < 300; i++) {
			cout << 'D' << endl;
			char c;
			cin >> c;
			if (c != 'N') {
				return 0;
			}
		}
		cout << 'L' << endl;
		char c;
		cin >> c;
		if (c != 'N') {
			return 0;
		}
	}
}
