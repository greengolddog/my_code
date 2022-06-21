#include <bits/stdc++.h>
#include "treasure.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007, col = 4, s = 22361;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

template<typename T>
T square(T a) {
	return a * a;
}

template<>
struct std::hash<pair<ll, ll>> {
	ll operator() (pair<ll, ll> p) {
		return ((__int128)p.first * MOD + p.second) % INF64;
	}
};

vector<int> encode(vector<int> a, vector<int> b) {
	vector<ll> ans(a.size(), 0);
	for (ll i = 0; i < a.size(); i++) {
		ans[i] += a[i] + (ll)b[i] * 500'000'000;
	}
	vector<int> na;
	for (ll i = 0; i < a.size(); i++) {
		for (ll j = 0; j < col; j++) {
			na.push_back(ans[i] % s);
			ans[i] /= s;
		}
	}
	for (ll i = 0; i < na.size(); i++) {
		na[i] = na[i] * na.size() + i;
	}
	return na;
}

vector<int> decode(vector<int> a) {
	vector<pair<ll, ll>> aa;
	for (auto& i : a) {
		aa.push_back(make_pair(i % a.size(), i / a.size()));
	}
	sort(aa.begin(), aa.end());
	vector<ll> aaa(aa.size() / col);
	for (ll i = 0; i < aa.size() / col; i++) {
		for (ll j = col - 1; j >= 0; j--) {
			aaa[i] *= s;
			aaa[i] += aa[i * col + j].second;
		}
	}
	vector<int> ans;
	for (auto i : aaa) {
		ans.push_back(i % 500'000'000);
		ans.push_back(i / 500'000'000);
	}
	return ans;
}
