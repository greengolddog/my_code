#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;

const ll INF = 1'000'000'000'000'000;
const db nan2 = 0.0/0.0;
const db pi = acos(-1);
const ll rc = 1'000'000'000;
const ll precision = 30;

db rou(db num) {
	return round(num * rc) / rc;
}

db to_rad(db deg) {
	return pi / 180 * deg;
}

db from_rad(db deg) {
	return 180 / pi * deg;
}

db sign(db i) {
    return i/abs(i);
}

struct point {
	db x;
	db y;
	point(db x = 0.0, db y = 0.0): x(x), y(y) {}
	point(pair<db, db> a) {
		x = a.first;
		y = a.second;
	}
	friend istream& operator>> (istream& inp, point& p);
	point operator- (point p) {
		return point(x - p.x, y - p.y);
	}
	bool operator== (point p) {
		return ((rou(x) == rou(p.x)) && (rou(y) == rou(p.y)));
	}
	bool operator<= (point p) {
		return ((x <= p.x) && (y <= p.y));
	}
	bool operator< (point p) {
		return ((x < p.x) && (y < p.y));
	}
	pair<db, db> to_pair() {
		return {rou(x), rou(y)};
	}
	friend ostream& operator<< (ostream& out, point p);
	point to(db n) {
		return *this / ~(*this) * n;
	}
	point operator* (db d) {
		return point(x * d, y * d);
	}
	point operator+ (point p) {
		return point(p.x + x, p.y + y);
	}
	point operator/ (db d) {
		return point(x/d, y/d);
	}
	db operator~ () {
		return sqrt(x * x + y * y);
	}
	db dist(point p) {
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}
	point operator^ (point p) {
		return point((x + p.x) / 2, (y + p.y) / 2);
	}
};

ostream& operator<< (ostream& out, point p) {
	out << setprecision(precision) << p.x << ' ' << setprecision(precision) << p.y;
	return out;
}

istream& operator>> (istream& inp, point& p) {
	inp >> p.x >> p.y;
	return inp;
}

struct vct {
	point p;
	vct(point p2 = point(), point start = point()) {
		p = p2 - start;
	}
	vct rev() {
		return vct(point(-p.x, -p.y));
	}
	db operator~ () {
		return ~p;
	}
	db operator^ (vct v) {
		return p.x * v.p.y - p.y * v.p.x;
	}
	db operator^ (vct v) const {
		return p.x * v.p.y - p.y * v.p.x;
	}
	vct operator+ (db f) {
		return vct(point(p.x * rou(cos(f)) - p.y * rou(sin(f)), p.x * rou(sin(f)) + p.y * rou(cos(f))));
	}
	db operator* (vct v) {
		return p.x * v.p.x + p.y * v.p.y;
	}
	db operator* (vct v) const {
		return p.x * v.p.x + p.y * v.p.y;
	}
	db operator% (vct v) {
		return atan2((*this) ^ v, (*this) * v);
	}
	db operator% (vct v) const {
		return atan2((*this) ^ v, (*this) * v);
	}
	vct operator/ (db d) {
		return vct(p / d);
	}
	vct operator* (db d) {
		return vct(p * d);
	}
	point to_point() {
		return p;
	}
	vct to(db d) {
		return vct(p.to(d));
	}
	vct mid(vct v) {
		return vct(p ^ v.p);
	}
	friend istream& operator>> (istream& inp, vct& v);
};

istream& operator>> (istream& inp, vct& v) {
	inp >> v.p;
	return inp;
}

struct segment {
	point a;
	point b;
	segment(point a = point(), point b = point()): a(a), b(b) {}
	segment(vct v, point start = point()) {
		a = start;
		b = v.p + start;
	}
	bool point_in(point p) {
		return ((p < point(max(a.x, b.x), max(a.y, b.y))) && (point(min(a.x, b.x), min(a.y, b.y)) < p));
	}
	db len() {
		return ~point(a.x - b.x, a.y - b.y);
	}
	vct to_vct() {
		return vct(b, a);
	}
	friend istream& operator>> (istream& inp, segment& s);
	point mid() {
		return a ^ b;
	}
};

istream& operator>> (istream& inp, segment& s) {
	inp >> s.a >> s.b;
	return inp;
}

struct delta {
	db a;
	db b;
	db c;
	db d;
	delta(db a = 0, db b = 0, db c = 0, db d = 0): a(a), b(b), c(c), d(d) {}
	db operator~ () {
		return (a * d) - (b * c);
	}
	db operator/ (delta de) {
		return ~(*this) / ~de;
	}
};

struct line {
	db a;
	db b;
	db c;
	line(db a = 0, db b = 0, db c = 0): a(a), b(b), c(c) {}
	line(segment seg) {
		a = seg.b.y - seg.a.y;
		b = seg.a.x - seg.b.x;
		c = seg.b.x * seg.a.y - seg.a.x * seg.b.y;
	}
	bool operator== (line l) {
		return ((a / l.a == b / l.b) || ((a == 0) && (l.a == 0)) || ((b == 0) && (l.b == 0)))
		&& ((b / l.b == c / l.c) || ((c == 0) && (c == l.c)) || ((b == 0) && (l.b == 0)))
		&& ((a / l.a == c / l.c) || ((c == 0) && (c == l.c)) || ((a == 0) && (l.a == 0)));
	}
	bool par(line l) {
		return ((a / l.a == b / l.b) || ((a == 0) && (l.a == 0)) || ((b == 0) && (l.b == 0)));
	}
	vct norm() {
		return vct(point(a, b)).to(1);
	}
	vct to_vct() {
		return vct(point(-b, a)).to(1);
	}
	point project(point p) {
		if (point_in(p + norm().to(dist(p)).to_point())) {
			return p + norm().to(dist(p)).to_point();
		}
		return p+norm().rev().to(dist(p)).to_point();
	}
	db dist(point p) {
		return (a * p.x + b * p.y + c) / sqrt(a * a + b * b);
	}
	delta de(line l) {
		return delta(a, b, l.a, l.b);
	}
	delta dex(line l) {
		return delta(-c, b, -l.c, l.b);
	}
	delta dey(line l) {
		return delta(a, -c, l.a, -l.c);
	}
	point operator* (line l) {
		return point(dex(l) / de(l), dey(l) / de(l));
	}
	bool point_in(point p) {
		return p.x * a + p.y * b + c == 0;
	}
	friend istream& operator>> (istream& inp, line& l);
};

istream& operator>> (istream& inp, line& l) {
	inp >> l.a >> l.b >> l.c;
	return inp;
}

void topsort(ll v, vector<vector<ll>>& arr, vector<ll>& ans, vector<ll>& used, ll col) {
	used[v] = col;
	for (auto i : arr[v]) {
		if (used[i] == -1) {
			topsort(i, arr, ans, used, col);
		}
	}
	ans.push_back(v);
}

void dfs(ll v, vector<vector<ll>>& arr, vector<ll>& color, ll now, vector<ll>& used) {
	color[v] = now;
	for (auto i : arr[v]) {
		if ((color[i] == -1) && (used[v] == used[i])) {
			dfs(i, arr, color, now, used);
		}
	}
}

ll SCC(ll n, vector<vector<ll>>& arr, vector<ll>& color) {
	vector<ll> tp;
	vector<ll> used(n, -1);
	ll next = 1;
	for (ll i = 0; i < n; i++) {
		if (used[i] == -1) {
			topsort(i, arr, tp, used, next);
			next++;
		}
	}
	reverse(tp.begin(), tp.end());
	vector<vector<ll>> new_arr(n, vector<ll>(0, 0));
	for (ll i = 0; i < n; i++) {
		for (auto v : arr[i]) {
			new_arr[v].push_back(i);
		}
	}
	ll last = 0;
	for (auto i : tp) {
		if (color[i] == -1) {
			dfs(i, new_arr, color, last, used);
			last++;
		}
	}
	return last;
}

int main() {
	freopen("snowbound.in", "r", stdin);
	freopen("snowbound.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll col_u = n * 2;
	vector<vector<ll>> arr(col_u, vector<ll>(0, 0));
	vector<point> coor(n);
	for (ll i = 0; i < n; i++) {
		cin >> coor[i];
	}
	map<pair<ll, ll>, ll> all;
	vector<pair<ll, ll>> vs(n), nr(n);
	vector<pair<ll, ll>> ntv(n);
	ll cnt = 0;
	for (ll i = 0; i < n; i++) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		vs[i] = {u, v};
		if (u > i) {
			all[{u, i}] = cnt;
			cnt++;
			ntv[cnt - 1] = {u, i};
		}
		if (v > i) {
			all[{v, i}] = cnt;
			cnt++;
			ntv[cnt - 1] = {v, i};
		}
	}
	for (ll i = 0; i < n; i++) {
		auto[u, v] = vs[i];
		ll n1 = all[{max(u, i), min(u, i)}], n2 = all[{max(v, i), min(v, i)}];
		nr[i].first = n1;
		nr[i].second = n2;
		arr[n1 * 2 + 1].push_back(n2 * 2);
		arr[n2 * 2 + 1].push_back(n1 * 2);
		arr[n1 * 2].push_back(n2 * 2 + 1);
		arr[n2 * 2].push_back(n1 * 2 + 1);
		//cout << n1 * 2 + 1 << ' ' << n2 * 2 << endl;
		//cout << n2 * 2 + 1 << ' ' << n1 * 2 << endl;
		//cout << n1 * 2 << ' ' << n2 * 2 + 1 << endl;
		//cout << n2 * 2 << ' ' << n1 * 2 + 1 << endl;
	}
	//cout << "\n";
	for (auto[p1, n1] : all) {
		for (auto[p2, n2] : all) {
			if (n1 < n2) {
				auto[u1, v1] = p1;
				auto[u2, v2] = p2;
				auto per = line(segment(coor[u1], coor[v1])) * line(segment(coor[u2], coor[v2]));
				if (segment(coor[u1], coor[v1]).point_in(per) && segment(coor[u2], coor[v2]).point_in(per)) {
					arr[n1 * 2].push_back(n2 * 2 + 1);
					arr[n2 * 2].push_back(n1 * 2 + 1);
					//cout << n1 * 2 << ' ' << n2 * 2 + 1 << endl;
					//cout << n2 * 2 << ' ' << n1 * 2 + 1 << endl;
					//cout << n1 << ' ' << n2 << endl;
				}
			}
		}
	}
	vector<ll> color(col_u, -1);
	ll col = SCC(col_u, arr, color);
	for (ll i = 0; i < col_u; i++) {
		for (ll j = 0; j < col_u; j++) {
			if (i != j) {
				if (color[i] == color[j]) {
					if (i / 2 == j / 2) {
						//cout << i << ' ' << j << endl;
						cout << "NO";
						return 0;
					}
				}
			}
		}
	}
	cout << "YES\n";
	vector<vector<ll>> a(col, vector<ll>(0, 0));
	for (ll i = 0; i < col_u; i++) {
		//cout << ' ' << i << ' ' << color[i] << endl;
		a[color[i]].push_back(i);
	}
	vector<ll> ans(n, -1);
	set<pair<ll, ll>> s;
	for (ll i = 0; i < col_u; i++) {
		for (auto j : arr[i]) {
			if (color[i] != color[j]) {
				s.insert({color[i], color[j]});
			}
		}
	}
	arr.clear();
	arr.resize(col, vector<ll>(0, 0));
	for (auto[u, v] : s) {
		//cout << u << ' ' << v << '\n';
		arr[u].push_back(v);
	}
	vector<ll> used(col, -1);
	vector<ll> ts;
	for (ll i = 0; i < col; i++) {
		if (used[i] == -1) {
			topsort(i, arr, ts, used, 0);
		}
	}
	reverse(ts.begin(), ts.end());
	for (auto i : ts) {
		//cout << i << '\n';
		ll now = 1;
		for (auto j : a[i]) {
			if (ans[j / 2] != -1) {
				now = 1 - ans[j / 2];
				break;
			}
		}
		for (auto j : a[i]) {
			//cout << j << ' ';
			if (ans[j / 2] == -1) {
				ans[j / 2] = now;
			} else {
				if (j % 2 == 0) {
					ans[j / 2] = now;
				}
			}
		}
	}
	for (auto i : ans) {
		//cout << i;
	}
	//cout << '\n';
	vector<ll> ans2(n, 0);
	for (ll i = 0; i < n; i++) {
		ans2[i] = (ans[nr[i].first] ? 1 : 2);
	}
	for (auto i : ans2) {
		cout << i << ' ';
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
