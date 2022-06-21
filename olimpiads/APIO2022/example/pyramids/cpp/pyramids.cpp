#include <bits/stdc++.h>
#include "pyramids.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
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

vector<ll> prefa, prefb;

void init(vector<int> a, vector<int> b) {
	prefa.resize(1, 0);
	for (auto i : a) {
		prefa.push_back(prefa.back() + i);
	}
	prefb.resize(1, 0);
	for (auto i : b) {
		prefb.push_back(prefb.back() + i);
	}
}

bool can_convert(int l, int r, int x, int y) {
	return (prefa[r + 1] - prefa[l]) == (prefb[y + 1] - prefb[x]);
}
