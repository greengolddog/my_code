#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 9'000'000'000'000'000'000, COLC = 10;

template<typename T>
T assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
T assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, a, b;
	cin >> n >> a >> b;
	if (n / 3 == 0) {
		cout << a / n;
		return 0;
	}
	if (n % 3 == 1) {
		if (b / (n / 3) >= a) {
			cout << a;
			return 0;
		}
	}
	if (n % 3 == 2) {
		if (b / (n / 3) >= a / 2) {
			cout << a / 2;
			return 0;
		}
	}
	cout << (a + b * 3) / n;
}
