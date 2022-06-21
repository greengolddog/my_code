#include <bits/stdc++.h>

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

struct edge {
        ll a, b, c, f;
        edge *i;
        edge(ll a, ll b, ll c, ll f, edge *i): a(a), b(b), c(c), f(f), i(i) {}
        void add(ll x) {
                f -= x;
                i->f += x;
        }
};

template<typename T>
struct midqueue {
        deque<T> q1, q2;
        midqueue() {}
        void push(T x) {
                q2.push_back(x);
                if (q2.size() > q1.size()) {
                        q1.push_back(q2.front());
                        q2.pop_front();
                }
        }
        T pop() {
                T x = q1.front();
                q1.pop_front();
                if (q2.size() > q1.size()) {
                        q1.push_back(q2.front());
                        q2.pop_front();
                }
                return x;
        }
        void push_mid(T x) {
                q2.push_front(x);
                if (q2.size() > q1.size()) {
                        q1.push_back(q2.front());
                        q2.pop_front();
                }
        }
        bool empty() {
                return q1.empty() && q2.empty();
        }
};

bool find_flow(ll n, vector<vector<edge*>>& arr, ll& ans) {
        vector<ll> dist(n, INF64);
        vector<edge*> p(n, nullptr);
        dist[0] = 0;
        vector<bool> be(n, false);
        midqueue<ll> mq;
        mq.push(0);
        while (!mq.empty()) {
                ll x = mq.pop();
                be[x] = false;
                for (auto i : arr[x]) {
                        if (i->f != 0 && assign_min(dist[i->b], dist[i->a] + i->c)) {
                                p[i->b] = i;
                                if (!be[i->b]) {
                                        mq.push_mid(i->b);
                                        be[i->b] = true;
                                }
                        }
                }
        }
        if (p.back() == nullptr) {
                return false;
        }
        ll x = INF64, now = n - 1;
        while (now != 0) {
                assign_min(x, p[now]->f);
                now = p[now]->a;
        }
        ans += x * dist.back();
        now = n - 1;
        while (now != 0) {
                p[now]->add(x);
                now = p[now]->a;
        }
        return true;
}

void solve() {
	ll n;
	cin >> n;
	ll ce1 = 0, ce2 = 0, ce22 = 0;
	vector<ll> p11(n), p12(n), p21(n), p22(n);
	for (ll i = 0; i < n; i++) {
		cin >> p11[i];
		ce1 += p11[i] == 1;
	}
	for (ll i = 0; i < n; i++) {
		cin >> p12[i];
		ce1 += p12[i] == 1;
	}
	for (ll i = 0; i < n; i++) {
		cin >> p21[i];
		ce2 += p21[i] == 1;
	}
	for (ll i = 0; i < n; i++) {
		cin >> p22[i];
		ce2 += p22[i] == 1;
		ce22 += p22[i] == 1;
	}
	if (ce1 != ce2) {
		cout << -1 << '\n';
		return;
	}
	if (ce22 == 0) {
		ll ans = 0;
		vector<ll> f, s;
		for (ll i = 0; i < n; i++) {
			if (p11[i] == 1) {
				f.push_back(i);
			}
		}
		for (ll i = 0; i < n; i++) {
			if (p12[i] == 1) {
				ans++;
				f.push_back(i);
			}
		}
		for (ll i = 0; i < n; i++) {
			if (p21[i] == 1) {
				s.push_back(i);
			}
		}
		sort(f.begin(), f.end());
		sort(s.begin(), s.end());
		while (!f.empty()) {
			ans += abs(f.back() - s.back());
			f.pop_back();
			s.pop_back();
		}
		cout << ans << '\n';
		return;
	}
	vector<pair<ll, ll>> p1, p2;
	for (ll i = 0; i < n; i++) {
		if (p11[i] == 1) {
			p1.push_back(make_pair(0, i));
		}
	}
	for (ll i = 0; i < n; i++) {
		if (p12[i] == 1) {
			p1.push_back(make_pair(1, i));
		}
	}
	for (ll i = 0; i < n; i++) {
		if (p21[i] == 1) {
			p2.push_back(make_pair(0, i));
		}
	}
	for (ll i = 0; i < n; i++) {
		if (p22[i] == 1) {
			p2.push_back(make_pair(1, i));
		}
	}
	n = p1.size();
	ll col = n * 2 + 2;
        vector<vector<edge*>> arr(col);
        for (ll i = 1; i <= n; i++) {
                arr[0].push_back(new edge(0, i, 0, 1, nullptr));
                arr[i].push_back(new edge(i, 0, 0, 0, arr[0].back()));
                arr[0].back()->i = arr[i].back();
        }
        for (ll i = n + 1; i < col - 1; i++) {
                arr.back().push_back(new edge(col - 1, i, 0, 0, nullptr));
                arr[i].push_back(new edge(i, col - 1, 0, 1, arr.back().back()));
                arr.back().back()->i = arr[i].back();
        }
        for (ll i = 1; i <= n; i++) {
                for (ll j = n + 1; j < col - 1; j++) {
                        ll c = abs(p2[i - 1].first - p1[j - n - 1].first) + abs(p2[i - 1].second - p1[j - n - 1].second);
                        arr[i].push_back(new edge(i, j, c, 1, nullptr));
                        arr[j].push_back(new edge(j, i, -c, 0, arr[i].back()));
                        arr[i].back()->i = arr[j].back();
                }
        }
        ll ans = 0;
        while (find_flow(col, arr, ans)) {}
	cout << ans;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
