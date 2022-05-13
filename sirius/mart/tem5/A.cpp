#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize(3)
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
typedef int_fast32_t ll;

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

mt19937 rnd(1647078870);

ll count(vector<vector<ll>>& arr) {
	ll ans = 0;
	for (ll i = 0; i < arr.size() - 1; i++) {
		for (ll j = 0; j < arr[0].size() - 1; j++) {
			for (ll k = i + 1; k < arr.size(); k++) {
				for (ll l = j + 1; l < arr[0].size(); l++) {
					ans += (arr[i][j] == arr[k][l]) && (arr[i][j] == arr[i][l]) && (arr[i][j] == arr[k][j]);
				}
			}
		}
	}
	return ans;
}

ll count(vector<vector<ll>>& arr, ll k, ll l) {
	ll ans = 0;
	for (ll i = 0; i < arr.size(); i++) {
		for (ll j = 0; j < arr[0].size(); j++) {
			if (i == k || j == l) {
				continue;
			}
			ans += (arr[i][j] == arr[k][l]) && (arr[i][j] == arr[i][l]) && (arr[i][j] == arr[k][j]);
		}
	}
	return ans;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	//cout << time(0) << '\n';
	ll n, m, c;
	cin >> n >> m >> c;
	if (c == 3) {
		vector<vector<ll>> arr(n, vector<ll>(m, 1));
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				arr[i][j] = rnd() % 3;
			}
		}
		ll cnt = count(arr);
		vector<vector<ll>> to(3, vector<ll>(2, 0));
		to[0][0] = 1;
		to[0][1] = 2;
		to[1][0] = 0;
		to[1][1] = 2;
		to[2][0] = 0;
		to[2][1] = 1;
		ll N = 1'000'000'000;
		for (ll i = 0; i < N; i++) {
			ll x = rnd() % n, y = rnd() % m;
			ll c = to[arr[x][y]][rnd() % 2];
			//ll c = rnd() % 3;
			ll oc = arr[x][y];
			ll ooc = count(arr, x, y);
			arr[x][y] = c;
			ll new_cnt = cnt - ooc + count(arr, x, y);
			if (new_cnt >= cnt) {
				double d = (rnd() % 1'000'000'000);
			       	d /= 1'000'000'000;
				if (d < exp(-(double)i / N * 2.28)) {
					arr[x][y] = oc;
				} else {
					cnt = new_cnt;
				}
			} else {
				cnt = new_cnt;
			}
			if (cnt == 0) {
				break;
			}
		}
		//cout << cnt << '\n';
		for (auto i : arr) {
			for (auto j : i) {
				cout << j + 1 << ' ';
			}
			cout << '\n';
		}
	} else {
		vector<vector<ll>> arr(n, vector<ll>(m, 1));
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				arr[i][j] = rnd() % 2;
			}
		}
		ll cnt = count(arr);
		ll N = 1000000;
		ll i = 0;
		while (cnt != 0) {
			i++;
			if (i > N) {
				N *= 10;
			}
			ll x = rnd() % n, y = rnd() % m, c = rnd() % 2;
			ll oc = arr[x][y];
			arr[x][y] = c;
			ll new_cnt = count(arr);
			if (new_cnt >= cnt) {
				double d = (rnd() % 1'000'000'000);
			       	d /= 1'000'000'000;
				if (d < exp(-(double)i / N)) {
					arr[x][y] = oc;
				} else {
					cnt = new_cnt;
				}
			} else {
				cnt = new_cnt;
			}
		}
		for (auto i : arr) {
			for (auto j : i) {
				cout << j + 1 << ' ';
			}
			cout << '\n';
		}
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
