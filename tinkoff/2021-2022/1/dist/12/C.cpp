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
	ll n;
	cin >> n;
	vector<pair<long double, long double>> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	auto sa = arr;
	vector<tuple<ll, ll, ll>> q;
	bool can = false;
	ll cnt = 0, cnt2 = 0;
	bool bbb = true;
	for (ll a = 0; a < n; a++) {
		for (ll b = 0; b < n; b++) {
			for (ll c = 0; c < n; c++) {
				long double pb = arr[a].first - arr[b].first, pa = -(arr[a].second - arr[b].second);
				long double pc = -(arr[a].first * pa + arr[a].second * pb);
				if (arr[c].first * pa + arr[c].second * pb + pc != 0) {
					bbb = false;
					break;
				}
			}
			if (!bbb) {
				break;
			}
		}
		if (!bbb) {
			break;
		}
	}
	if (bbb) {
		cout << -1;
		return 0;
	}
	for (ll i = 0; i <= 2500; i++) {
		bool bb = true;
		for (auto[a, c] : arr) {
			bb = bb && (a >= 0) && (c >= 0);
			if (abs(a) > 1'000'000'000 || abs(c) > 1'000'000'000) {
				return 1;
			}
		}
		if (bb) {
			can = true;
			break;
		}
		if (n < 3) {
			break;
		}
		ll a = rnd() % n, b = rnd() % n, c = rnd() % n;
		long double pb = arr[a].first - arr[b].first, pa = -(arr[a].second - arr[b].second);
		long double pc = -(arr[a].first * pa + arr[a].second * pb);
		long double x = (arr[a].first + arr[b].first) / 2, y = (arr[a].second + arr[b].second) / 2;
		long double nx = arr[c].first - (arr[c].first - x) * 2;
		long double ny = arr[c].second - (arr[c].second - y) * 2;
		ll col = 0;
		bb = false;
		while (a == b || a == c || b == c || arr[c].first * pa + arr[c].second * pb + pc == 0 || abs(nx) > 1'000 || abs(ny) > 1'000) {
			a = rnd() % n;
			b = rnd() % (n - 1);
			if (b >= a) {
				b++;
			}
			c = rnd() % (n - 2);
			if (c >= min(a, b)) {
				c++;
			}
			if (c >= max(a, b)) {
				c++;
			}
			pb = arr[a].first - arr[b].first;
		       	pa = -(arr[a].second - arr[b].second);
			pc = -(arr[a].first * pa + arr[a].second * pb);
			x = (arr[a].first + arr[b].first) / 2;
			y = (arr[a].second + arr[b].second) / 2;
			nx = arr[c].first - (arr[c].first - x) * 2;
			ny = arr[c].second - (arr[c].second - y) * 2;
			col++;
			if (col > n * n) {
				bb = true;
				break;
			}
		}
		if (bb) {
			i = -1;
			arr = sa;
			cnt++;
			q.clear();
			continue;
		}
		q.push_back({a, b, c});
		arr[c].first = nx;
		arr[c].second = ny;
		if (i == 2500) {
			i = -1;
			arr = sa;
			cnt2++;
			q.clear();
			//if (false && cnt2 > 10'000'000'000 / n) {
			//	break;
			//}
			continue;
		}
	}
	cout << q.size() << '\n';
	for (auto[a, b, c] : q) {
		cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << '\n';
	}
	//for (auto[a, b] : arr) {
	//	cout << setprecision(20) << a << ' ' << setprecision(20) << b << '\n';
	//}
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
