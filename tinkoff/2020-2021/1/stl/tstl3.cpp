#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, c, nv, tp, vp, s;
    pair<long long, long long> c1, c2;
    cin >> n;
    tp = 1;
    vp = 0;
    map<pair<long long, long long>, long long> m;
    for (long long i = 0; i < n; i++) {
        cin >> c;
	nv = max(tp, 1000 - c);
	m[{nv, i+1}] = c;
    }
    c = 0;
    while (true) {
	s = 0;
	for (auto i : m) {
	    if (s == 0) {
		s = 1;
	    } else {
		if (i.first.first == (*m.begin()).first.first) {
		    cout << i.first.first;
		    c = 1;
		} else {
		    if (abs((*m.begin()).first.second - tp) > (*m.begin()).first.first - vp) {
			cout << (*m.begin()).first.first;
			c = 1;
		    } else {
			tp = (*m.begin()).first.second;
			vp = (*m.begin()).first.first;
			nv = max(tp, 1000 - m[{(*m.begin()).first.first, (*m.begin()).first.second}] - 1) + (*m.begin()).first.first;
			m[{nv, (*m.begin()).first.second}] = m[{(*m.begin()).first.first, (*m.begin()).first.second}] + 1;
			m.erase(m.begin());
		    }
		}
		break;
	    }
	}
	if (c == 1) {
	    break;
	}
	cout << vp << ' ' << tp << endl;
    }
}