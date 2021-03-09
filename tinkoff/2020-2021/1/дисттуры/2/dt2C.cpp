#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, m, inp, ko;
    cin >> n >> m;
    multiset<pair<long long, long long>> k, s, o;
    for (long long i = 1; i <= n; i++) {
	cin >> inp;
	k.insert({inp, i});
    }
    for (long long i = 1; i <= m; i++) {
	cin >> inp;
	s.insert({inp, i});
    }
    ko = 0;
    auto pk = k.begin();
    auto ps = s.end();
    for (long long i = 1; i <= min(n, m); i++) {
	ps--;
	if ((*pk).first < (*ps).first) {
	    ko += 1;
	    o.insert({(*pk).second, (*ps).second});
	} else {
	    break;
	}
	pk++;
    }
    cout << ko << "\n";
    for (auto i : o) {
	cout << i.first << ' ' << i.second << "\n";
    }
}