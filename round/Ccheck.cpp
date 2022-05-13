#include "testlib.h"
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

pair<ll, vector<ll>> read(InStream& stream, ll n, ll t, bool b) {
	ll now_ans = stream.readLong(0, INF, "answer");
	vector<ll> ans(n);
	vector<pair<ll, ll>> all;
	for (ll i = 0; i < n; i++) {
		ans[i] = stream.readLong(0, INF, "%i number");
		all.push_back(make_pair(ans[i], i));
	}
	sort(all.begin(), all.end());
	set<ll> s;
	s.insert(-1);
	s.insert(n);
	ll na = 0;
	for (auto[num, i] : all) {
		auto it = s.lower_bound(i);
		ll x = *it;
		it--;
		ll y = *it;
		s.insert(i);
		na += num * (i - y) * (x - i);
	}
	if (na != now_ans && b) {
		stream.quitf(_wa, "you answer on test %d isn't equivalent to answer in your example, you answer: %d, example answer: %d", t, now_ans, na);
	}
	if (na != now_ans && !b) {
		stream.quitf(_wa, "jury answer on test %d isn't equivalent to answer in jury example, jury answer: %d, example answer: %d", t, now_ans, na);
	}
	return make_pair(na, ans);
}

int main(int argc, char* argv[]) {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	registerTestlibCmd(argc, argv);
	ll t = inf.readInt();
	for (ll i = 0; i < t; i++) {
		ll n = inf.readInt();
		auto[bp, ap] = read(ouf, n, i, true);
		auto[bj, aj] = read(ans, n, i, false);
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			arr[i] = inf.readInt();
		}
		sort(arr.begin(), arr.end());
		sort(ap.begin(), ap.end());
		sort(aj.begin(), aj.end());
		if (arr != ap) {
			quitf(_wa, "you array on test %d doesn't equivalent to array in input", i);
		}
		if (arr != aj) {
			quitf(_fail, "jury array on test %d doesn't equivalent to array in input", i);
		}
		if (bp > bj) {
			quitf(_wa, "jury answer on test %d is better, you answer: %d, jury answer: %d", i, bp, bj);
		}
		if (bp < bj) {
			quitf(_fail, "you answer on test %d is better, you answer: %d, jury answer: %d", i, bp, bj);
		}
	}
	quitf(_ok, "OK");
}
