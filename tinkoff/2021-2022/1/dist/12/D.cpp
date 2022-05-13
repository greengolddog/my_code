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

mt19937 rnd(time(0) + 2);

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll k, n, t;
	cin >> n >> k >> t;
	k--;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll l = 0, r = 1'000'000'000;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		bool b = false;
		for (ll i = 0; i < 2; i++) {
			if (i == 0) {
				for (ll x = 0; x < n; x++) {
					double now = 0;
					stack<ll> next, previous;
					for (ll i = 0; i < k; i++) {
						previous.push(i);
					}
					for (ll i = n - 1; i > k; i--) {
						next.push(i);
					}
					bool bb = true;
					previous.push(k);
					bool bbb = true;
					ll nx = x;
					while (!previous.empty() && !next.empty() && nx > 0) {
						if (bbb) {
							ll n1 = previous.top();
							previous.pop();
							ll n2 = next.top();
							if ((arr[n2] - arr[n1]) > mid * (t + now) * 2) {
								bb = false;
								break;
							}
							//now = ((double)arr[n2] - arr[n1]) / mid / 2;
							now += t;
						} else {
							ll n1 = previous.top();
							ll n2 = next.top();
							next.pop();
							if ((arr[n2] - arr[n1]) > mid * (t + now) * 2) {
								bb = false;
								break;
							}
							//now = ((double)arr[n2] - arr[n1]) / mid / 2;
							now += t;
						}
						nx--;
						bbb = !bbb;
					}
					if (!previous.empty() && !next.empty()) {
						if (bbb) {
							if (previous.size() == 1) {
								continue;
							}
							ll n1 = previous.top();
							previous.pop();
							ll n2 = next.top();
							ll n3 = previous.top();
							if ((arr[n2] - arr[n1] + arr[n1] - arr[n3]) > mid * (t + now) * 2) {
								bb = false;
							}
							now += t;
						} else {
							if (next.size() == 1) {
								continue;
							}
							ll n1 = previous.top();
							ll n2 = next.top();
							next.pop();
							ll n3 = next.top();
							if ((arr[n2] - arr[n1] + arr[n3] - arr[n2]) > mid * (t + now) * 2) {
								bb = false;
							}
							now += t;
						}
					}
					for (ll i = 1; i < previous.size(); i++) {
						if ((arr[i] - arr[i - 1]) > mid * t * 2) {
							bb = false;
							break;
						}
					}
					for (ll i = n - next.size() + 1; i < n; i++) {
						if ((arr[i] - arr[i - 1]) > mid * t * 2) {
							bb = false;
							break;
						}
					}
					b = b || bb;
				}
			} else {
				for (ll x = 0; x < n; x++) {
					double now = 0;
					stack<ll> next, previous;
					for (ll i = 0; i < k; i++) {
						previous.push(i);
					}
					for (ll i = n - 1; i > k; i--) {
						next.push(i);
					}
					bool bb = true;
					next.push(k);
					bool bbb = true;
					ll nx = x;
					while (!previous.empty() && !next.empty() && nx > 0) {
						if (bbb) {
							ll n1 = previous.top();
							previous.pop();
							ll n2 = next.top();
							if ((arr[n2] - arr[n1]) > mid * (t + now) * 2) {
								bb = false;
								break;
							}
							now += t;
							//now = ((double)arr[n2] - arr[n1]) / mid / 2;
						} else {
							ll n1 = previous.top();
							ll n2 = next.top();
							next.pop();
							if ((arr[n2] - arr[n1]) > mid * (t + now) * 2) {
								bb = false;
								break;
							}
							now += t;
							//now = ((double)arr[n2] - arr[n1]) / mid / 2;
						}
						nx--;
						bbb = !bbb;
					}
					if (!previous.empty() && !next.empty()) {
						if (bbb) {
							if (previous.size() == 1) {
								continue;
							}
							ll n1 = previous.top();
							previous.pop();
							ll n2 = next.top();
							ll n3 = previous.top();
							if ((arr[n2] - arr[n1] + arr[n1] - arr[n3]) > mid * (t + now) * 2) {
								bb = false;
							}
							now = ((double)arr[n2] - arr[n1]) / mid / 2;
						} else {
							if (next.size() == 1) {
								continue;
							}
							ll n1 = previous.top();
							ll n2 = next.top();
							next.pop();
							ll n3 = next.top();
							if ((arr[n2] - arr[n1] + arr[n3] - arr[n2]) > mid * (t + now) * 2) {
								bb = false;
							}
							now = ((double)arr[n2] - arr[n1]) / mid / 2;
						}
					}
					for (ll i = 1; i < previous.size(); i++) {
						if ((arr[i] - arr[i - 1]) > mid * t * 2) {
							bb = false;
							break;
						}
					}
					for (ll i = n - next.size() + 1; i < n; i++) {
						if ((arr[i] - arr[i - 1]) > mid * t * 2) {
							bb = false;
							break;
						}
					}
					b = b || bb;
				}
			}
		}
		if (b) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r;
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
