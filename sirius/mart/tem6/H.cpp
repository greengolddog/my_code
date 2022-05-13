#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
#define double long long

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

double PI = acos(-1), eps = 1e-6;

struct point {
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}
	point operator- (point p) {
		return point(x - p.x, y - p.y);
	}
	point operator+ (point p) {
		return point(x + p.x, y + p.y);
	}
	bool operator< (point p) {
		return (p.x == x ? y < p.y : x < p.x);
	}
	bool operator> (point p) {
		return (p.x == x ? y > p.y : x > p.x);
	}
	bool operator<= (point p) {
		return (p.x == x ? y >= p.y : x >= p.x);
	}
	bool operator>= (point p) {
		return (p.x == x ? y >= p.y : x >= p.x);
	}
	bool operator!= (point p) {
		return p.x != x || p.y != y;
	}
	bool operator== (point p) {
		return p.x == x && p.y == y;
	}
};

istream& operator>> (istream& in, point& p) {
	in >> p.x >> p.y;
	return in;
}

ostream& operator<< (ostream& out, point& p) {
	out << p.x << ' ' << p.y;
	return out;
}

struct vct {
	point p;
	vct(point a = point(), point b = point()) {
		p = a - b;
	}
	double operator* (vct v) {
		return p.x * v.p.x + p.y * v.p.y;
	}
	double operator% (vct v) {
		return p.x * v.p.y - p.y * v.p.x;
	}
	double operator~ () {
		return p.x * p.x + p.y * p.y;
	}
	bool operator< (vct v) {
		return (*this % v == 0 ? ~*this < ~v : *this % v < 0);
	}
	bool operator<= (vct v) {
		return *this % v <= 0;
	}
	bool is_in(vct v1, vct v2) {
		return (v1 <= *this) && (*this <= v2);
	}
	point operator+ (point pp) {
		return point(pp.x + p.x, pp.y + p.y);
	}
};

struct line {
	double a, b, c;
	line(double a = 0, double b = 0, double c = 0): a(a), b(b), c(c) {}
	vct norm() {
		return vct(point(a, b));
	}
	vct to_vct() {
		return vct(point(b, -a));
	}
	db dist(point p) {
		return (p.x * a + p.y * b + c) / sqrt(a * a + b * b);
	}
};

struct segment {
	point p1, p2;
	segment(point p1, point p2): p1(p1), p2(p2) {}
	line to_line() {
		line l;
		vct v(p1, p2);
		l.a = v.p.y;
		l.b = -v.p.x;
		l.c = -(p1.x * l.a + p1.y * l.b);
		return l;
	}
	db dist(point p) {
		if (vct(p1, p2) * vct(p, p2) >= 0 && vct(p2, p1) * vct(p, p1) >= 0) {
			return to_line().dist(p);
		}
		return sqrt(min(~vct(p, p1), ~vct(p, p2)));
	}
};

struct polygon {
	vector<point> arr;
	polygon(vector<point> a = vector<point>(0)) {
		arr = a;
	}
	ll area() {
		ll j = arr.size() - 1;
		ll ans = 0;
		for (ll i = 0; i < arr.size(); i++) {
			ans += vct(arr[j]) % vct(arr[i]);
			j = i;
		}
		return ans;
	}
	ll size() {
		return arr.size();
	}
	point operator[] (ll x) {
		return arr[x];
	}
	point back() {
		return arr.back();
	}
};

istream& operator>> (istream& in, polygon& p) {
	ll n;
	in >> n;
	p.arr.resize(n);
	for (auto& i : p.arr) {
		in >> i;
	}
	sort(p.arr.begin(), p.arr.end());
	p.arr.resize(unique(p.arr.begin(), p.arr.end()) - p.arr.begin());
	reverse(p.arr.begin(), p.arr.end());
	return in;
}

ostream& operator<< (ostream& out, polygon& p) {
	out << p.arr.size() << '\n';
	for (auto& i : p.arr) {
		out << i << '\n';
	}
	ll x = abs(p.area());
	if (x % 2 == 0) {
		cout << x / 2;
	} else {
		cout << x / 2 << '.' << 5;
	}
	return out;
}

struct convex_polygon {
	polygon cp;
	convex_polygon(polygon p = polygon(), bool is_c = false) {
		vector<vct> arr;
		point mp(-1e9, -1e9);
		for (auto& i : p.arr) {
			assign_max(mp, i);
		}
		for (auto& i : p.arr) {
			if (i != mp) {
				arr.push_back(vct(i, mp));
			}
		}
		sort(arr.begin(), arr.end());
		vector<point> ans(1, mp);
		for (auto& i : arr) {
			point pp = i + mp;
			while (ans.size() > 1 && (vct(pp, ans[ans.size() - 2]) <= vct(ans.back(), ans[ans.size() - 2]))) {
				ans.pop_back();
			}
			ans.push_back(pp);
		}
		cp = polygon(ans);
	}
	point operator[] (ll x) {
		return cp[x];
	}
	double area() {
		return cp.area();
	}
	point back() {
		return cp.back();
	}
	ll size() {
		return cp.size();
	}
	bool point_in(point p) {
		ll l = 1, r = cp.size() - 1;
		if (!vct(p, cp[0]).is_in(vct(cp[1], cp[0]), vct(cp.back(), cp[0]))) {
			return false;
		}
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			if (vct(p, cp[0]).is_in(vct(cp[1], cp[0]), vct(cp[mid], cp[0]))) {
				r = mid;
			} else {
				l = mid;
			}
		}
		return vct(p, cp[r]).is_in(vct(cp[0], cp[r]), vct(cp[l], cp[r]));
	}
	bool operator< (const convex_polygon& cp) const {
		return true;
	}
	convex_polygon rev() {
		polygon ans = cp;
		for (auto& i : ans.arr) {
			i.x = -i.x;
			i.y = -i.y;
		}
		return convex_polygon(ans);
	}
	convex_polygon operator+ (convex_polygon scp) {
		vector<vct> fir, sec;
		point p = cp.back();
		for (ll i = 0; i < cp.size(); i++) {
			if (vct(cp[i], p).p.x < 0 || (vct(cp[i], p).p.x == 0 && vct(cp[i], p).p.y < 0)) {
				fir.push_back(vct(cp[i], p));
			} else {
				sec.push_back(vct(cp[i], p));
			}
			p = cp[i];
		}
		p = scp.back();
		for (ll i = 0; i < scp.size(); i++) {
			if (vct(scp[i], p).p.x < 0 || (vct(scp[i], p).p.x == 0 && vct(scp[i], p).p.y < 0)) {
				fir.push_back(vct(scp[i], p));
			} else {
				sec.push_back(vct(scp[i], p));
			}
			p = scp[i];
		}
		sort(fir.begin(), fir.end());
		sort(sec.begin(), sec.end());
		vector<point> ans(1, cp[0] + scp[0]);
		for (auto i : fir) {
			ans.push_back(i + ans.back());
		}
		for (auto i : sec) {
			ans.push_back(i + ans.back());
		}
		//ans.pop_back();
		return convex_polygon(polygon(ans), true);
	}
	db min_dist_to_zero() {
		point p = cp.back();
		db ans = 1e9;
		for (auto i : cp.arr) {
			assign_min(ans, abs(segment(p, i).dist(point())));
			p = i;
		}
		return ans;
	}
	db max_dist_to_zero() {
		db ans = -1e9;
		for (auto i : cp.arr) {
			assign_max(ans, (db)sqrt(~vct(i)));
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, a, b;
	cin >> n >> a >> b;
	a--;
	b--;
	vector<convex_polygon> arr;
	for (ll i = 0; i < n; i++) {
		polygon p;
		cin >> p;
		arr.emplace_back(p);
	}
	vector<vector<db>> dist(n, vector<db>(n, 1e18));
	for (ll i = 0; i < n; i++) {
		dist[i][i] = 0;
		for (ll j = i + 1; j < n; j++) {
			dist[i][j] = (arr[i] + arr[j].rev()).min_dist_to_zero();
			dist[j][i] = dist[i][j];
		}
	}
	for (ll k = 0; k < n; k++) {
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				assign_min(dist[i][j], dist[i][k] + dist[k][j]);
				assign_min(dist[j][i], dist[i][k] + dist[k][j]);
			}
		}
	}
	cout << setprecision(20) << dist[a][b];
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
