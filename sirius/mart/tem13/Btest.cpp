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

void decode() {
	string s;
	cin >> s;
	ll log = 17;
	string ans;
	ll x = s.size(), last = 0, now = 1;
	while (x > 0) {
		if ((now >> last) == 1) {
			ans.push_back('0');
		} else {
			ans.push_back(
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
}
