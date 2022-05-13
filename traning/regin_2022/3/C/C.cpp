#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;

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

const db nan2 = 0.0/0.0;
const db pi = acos(-1), eps = 1e-3;

db rou(db num) {
	return round(num*1'000)/1'000;
}

db to_rad(db deg) {
	return pi/180*deg;
}

db from_rad(db deg) {
	return 180/pi*deg;
}

db sign(db i) {
    return i/abs(i);
}

struct point {
	db x;
	db y;
	point(db x = 0.0, db y = 0.0): x(x), y(y) {}
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
	friend ostream& operator<< (ostream& out, point p);
	point to(db n) {
		return *this / ~(*this) * n;
	}
	point operator* (db d) {
		return point(x*d, y*d);
	}
	point operator+ (point p) {
		return point(p.x + x, p.y + y);
	}
	point operator/ (db d) {
		return point(x/d, y/d);
	}
	db operator~ () {
		return sqrt(x*x+y*y);
	}
	db dist(point p) {
		return sqrt((x - p.x)*(x - p.x)+(y - p.y)*(y - p.y));
	}
	point operator^ (point p) {
		return point((x+p.x)/2, (y+p.y)/2);
	}
};

ostream& operator<< (ostream& out, point p) {
	out << setprecision(20) << p.x << ' ' << setprecision(20) << p.y;
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
		return p.x*v.p.y - p.y*v.p.x;
	}
	db operator^ (vct v) const {
		return p.x*v.p.y - p.y*v.p.x;
	}
	vct operator+ (db f) {
		return vct(point(p.x*rou(cos(f))-p.y*rou(sin(f)), p.x*rou(sin(f))+p.y*rou(cos(f))));
	}
	db operator* (vct v) {
		return p.x*v.p.x + p.y*v.p.y;
	}
	db operator* (vct v) const {
		return p.x*v.p.x + p.y*v.p.y;
	}
	db operator% (vct v) {
		return atan2((*this)^v, (*this)*v);
	}
	db operator% (vct v) const {
		return atan2((*this)^v, (*this)*v);
	}
	vct operator/ (db d) {
		return vct(p/d);
	}
	vct operator* (db d) {
		return vct(p*d);
	}
	point to_point() {
		return p;
	}
	vct to(db d) {
		return vct(p.to(d));
	}
	vct mid(vct v) {
		return vct(p^v.p);
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
		return (((p <= a) && (b <= p)) || ((p <= b) && (a <= p)));
	}
	db len() {
		return ~point(a.x-b.x, a.y-b.y);
	}
	vct to_vct() {
		return vct(b, a);
	}
	friend istream& operator>> (istream& inp, segment& s);
	point mid() {
		return a^b;
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
		return (a*d) - (b*c);
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
		return ((a/l.a == b/l.b) || ((a == 0) && (l.a == 0)) || ((b == 0) && (l.b == 0)))
		&& ((b/l.b == c/l.c) || ((c == 0) && (c == l.c)) || ((b == 0) && (l.b == 0)))
		&& ((a/l.a == c/l.c) || ((c == 0) && (c == l.c)) || ((a == 0) && (l.a == 0)));
	}
	bool par(line l) {
		return ((a/l.a == b/l.b) || ((a == 0) && (l.a == 0)) || ((b == 0) && (l.b == 0)));
	}
	vct norm() {
		return vct(point(a, b)).to(1);
	}
	vct to_vct() {
		return vct(point(-b, a)).to(1);
	}
	point project(point p) {
		if (point_in(p+norm().to(dist(p)).to_point())) {
			return p+norm().to(dist(p)).to_point();
		}
		return p+norm().rev().to(dist(p)).to_point();
	}
	db dist(point p) {
		return (a*p.x + b*p.y + c) / sqrt(a*a+b*b);
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
		return point(dex(l)/de(l), dey(l)/de(l));
	}
	bool point_in(point p) {
		return p.x*a+p.y*b+c == 0;
	}
	friend istream& operator>> (istream& inp, line& l);
};

istream& operator>> (istream& inp, line& l) {
	inp >> l.a >> l.b >> l.c;
	return inp;
}

struct angle {
	vct a;
	vct b;
	point o;
	angle(point a = point(), point o = point(), point b = point()): a(vct(a, o)), b(vct(b, o)), o(o) {}
	angle(vct a = vct(), vct b = vct(), point o = point()): a(a), b(b), o(o) {}
	db operator~ () {
		return abs(a%b);
	}
	db operator~ () const {
		return abs(a%b);
	}
	db operator! () {
		return ~(*this)/pi*180;
	}
	bool in(point p) {
		vct v(p, o);
		db a2 = ~(*this), b2 = a^v, c2 = v^b;
		return (a2 <= 0 && b2 <= 0 && c2 <= 0) || (a2 >= 0 && b2 >= 0 && c2 >= 0);
	}
	bool operator> (angle an) {
		return ~(*this) > ~an;
	}
	bool operator< (angle an) {
		return ~(*this) < ~an;
	}
	bool operator> (const angle an) const {
		return ~(*this) > ~an;
	}
	bool operator< (const angle an) const {
		return ~(*this) < ~an;
	}
	vct vct_mid() {
		return vct(a.mid(b/((~b)/(~a))));
	}
	line mid() {
		return line(segment(vct_mid(), o));
	}
};

struct circle {
	point s;
	db r;
	circle(point s = point(), db r = 0.0): s(s), r(r) {}
	pair<point, point> tan(point p) {
		if (rou(s.dist(p)) < r) {
			return {point(nan2, nan2), point(nan2, nan2)};
		}
		return {(vct(s, p) + atan2(r, rou(sqrt(s.dist(p)*s.dist(p)-r*r)))).to_point().to(sqrt(s.dist(p)*s.dist(p)-r*r)) + p,
			(vct(s, p) + (-atan2(r, rou(sqrt(s.dist(p)*s.dist(p)-r*r))))).to_point().to(sqrt(s.dist(p)*s.dist(p)-r*r)) + p};
	}
	bool operator== (circle c) {
		return (s == c.s) && (r == c.r);
	}
	bool point_in(point p) {
		return rou(s.dist(p)) <= rou(r);
	}
	bool point_on(point p) {
		return rou(s.dist(p)) == rou(r);
	}
	pair<ll, pair<pair<point, pair<db, db>>, pair<point, point>>> operator*(circle c) {
		pair<ll, pair<pair<point, pair<db, db>>,  pair<point, point>>> ans = {2, {{point(), {0, 0}}, {point(), point()}}};
		db x = rou((r*r - c.r*c.r + s.dist(c.s)*s.dist(c.s))/(2*s.dist(c.s)));
		ans.second.first.second.first = x;
		ans.second.first.second.second = rou(sqrt(r*r - x*x));
		vct v = vct(c.s, s);
		point p = v.to_point().to(x) + s;
		ans.second.first.first = p;
		ans.second.second.first = (vct(c.s, s)+atan2(ans.second.first.second.second, x)).to_point().to(r)+s;
		ans.second.second.second = (vct(c.s, s)+(-atan2(ans.second.first.second.second, x))).to_point().to(r)+s;
		if (ans.second.second.first == ans.second.second.second) {
			ans.first = 1;
		}
		if (rou(s.dist(c.s)) == rou(r+c.r)) {
			ans.first = 1;
		}
		if (rou(s.dist(c.s)) == rou(abs(r-c.r))) {
			ans.first = 1;
		}
		if ((*this) == c) {
			ans.first = 3;
		}
		if (rou(r+c.r) < rou(s.dist(c.s))) {
			ans.first = 0;
		}
		if (rou(r+s.dist(c.s)) < rou(c.r)) {
			ans.first = 0;
		}
		if ((s == c.s) && (rou(r) != rou(c.r))) {
			ans.first = 0;
		}
		if (rou(c.r+s.dist(c.s)) < rou(r)) {
			ans.first = 0;
		}
		return ans;
	}
	pair<point, point> operator*(line l) {
		if (rou(l.dist(s)) > r) {
			return {point(nan2, nan2), point(nan2, nan2)};
		}
		return {l.project(s) + l.to_vct().to(sqrt(r*r-l.dist(s)*l.dist(s))).to_point(),
			l.project(s) - l.to_vct().to(sqrt(r*r-l.dist(s)*l.dist(s))).to_point()};
	}
	friend istream& operator>> (istream& inp, circle& c);
};

istream& operator>> (istream& inp, circle& c) {
	inp >> c.s >> c.r;
	return inp;
}

struct triangle {
	point a;
	point b;
	point c;
	triangle(point a = point(), point b = point(), point c = point()): a(a), b(b), c(c) {}
	db square() {
		vct v1(b, a), v2(c, a);
		return (v1^v2)/2;
	}
	angle get_angle(ll i) {
		if (i == 0) {
			return angle(c, a, b);
		}
		if (i == 1) {
			return angle(a, b, c);
		}
		return angle(b, c, a);
	}
	angle min_angle() {
		return min(get_angle(0), min(get_angle(1), get_angle(2)));
	}
	angle max_angle() {
		return max(get_angle(0), max(get_angle(1), get_angle(2)));
	}
	segment get_seg(ll i) {
		if (i == 0) {
			return segment(a, b);
		}
		if (i == 1) {
			return segment(b, c);
		}
		return segment(c, a);
	}
	friend istream& operator>> (istream& inp, triangle& t);
};

istream& operator>> (istream& inp, triangle& t) {
	inp >> t.a >> t.b >> t.c;
	return inp;
}

struct polygon {
    vector<point> points;
    ll len;
    bool convex = 0;
    polygon(vector<point> p = vector<point>(0, point())) {
        points = p;
        len = points.size();
        convex = is_convex();
    }
    bool is_convex() {
        if (len > 2) {
            db sign_fir = sign(triangle(points[len - 1], points[len - 2], points[0]).square());
	    ll j = len - 1;
            for (ll i = 1; i < len; i++) {
                // cout << i << ' ' << sign(vct(points[i-1], points[0])^vct(points[i], points[0])) << ' ' << sign_fir << endl;
                if (sign(triangle(points[i-1], points[j], points[i]).square()) != sign_fir) {
                    return false;
                }
		j = i - 1;
            }
        }
        return true;
    }
    db area() {
        db a  = 0;
        ll j = len - 1;
        for (ll i = 0; i < len; i++) {
            a += triangle(point(), points[j], points[i]).square();
            j = i;
        }
        return abs(a);
    }
    bool point_in(point p) {
        db a = 0;
        ll j = len - 1;
        for (ll i = 0; i < len; i++) {
            a += vct(points[j], p)%vct(points[i], p);
            j = i;
        }
        return (rou(a) != 0);
    }
    friend istream& operator>> (istream& inp, polygon& p);
};

istream& operator>> (istream& inp, polygon& p) {
    inp >> p.len;
    p.points.resize(p.len, point());
    for (ll i = 0; i < p.len; i++) {
        inp >> p.points[i];
    }
    p.convex = p.is_convex();
    return inp;
}

istream& operator>> (istream& inp, pair<polygon, point>& p) {
    inp >> p.first.len >> p.second;
    p.first.points.resize(p.first.len, point());
    for (ll i = 0; i < p.first.len; i++) {
        inp >> p.first.points[i];
    }
    p.first.convex = p.first.is_convex();
    return inp;
}

void solve() {
	deque<point> p(3);
	point p1, p2, p3;
	cin >> p1 >> p2 >> p3 >> p[0] >> p[1] >> p[2];
	deque<ll> arr;
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(2);
	do {
		bool b = true;
		for (ll i = 0; i < 3; i++) {
			if ((p2.dist(line(segment(p[arr[0]], p2)) * line(segment(p[arr[2]], p3))) <= p2.dist(p[arr[0]])) && (p3.dist(line(segment(p[arr[0]], p2)) * line(segment(p[arr[2]], p3))) <= p3.dist(p[arr[2]]))) {
				if ((p2.dist(line(segment(p[arr[0]], p2)) * line(segment(p[arr[2]], p3))) - p2.dist(line(segment(p[arr[0]], p2)) * line(segment(p[arr[1]], p3))) <= eps) && (p3.dist(line(segment(p[arr[0]], p2)) * line(segment(p[arr[2]], p3))) - p3.dist(line(segment(p[arr[2]], p3)) * line(segment(p[arr[1]], p2))) <= eps)) {
				} else {
					b = false;
				}
			} else {
				if (!(p2.dist(line(segment(p[arr[0]], p2)) * line(segment(p[arr[2]], p3))) > p2.dist(p[arr[0]]))) {
					if ((p2.dist(line(segment(p[arr[0]], p2)) * line(segment(p[arr[2]], p1))) <= p2.dist(line(segment(p[arr[0]], p2)) * line(segment(p[arr[1]], p3)))) && (p3.dist(line(segment(p[arr[0]], p2)) * line(segment(p[arr[2]], p3))) - p3.dist(line(segment(p[arr[2]], p3)) * line(segment(p[arr[1]], p2))) <= eps)) {
					} else {
						b = false;
					}
				} else {
					if ((p3.dist(line(segment(p[arr[0]], p1)) * line(segment(p[arr[2]], p3))) <= p3.dist(line(segment(p[arr[2]], p3)) * line(segment(p[arr[1]], p2)))) && (p2.dist(line(segment(p[arr[0]], p2)) * line(segment(p[arr[2]], p3))) - p2.dist(line(segment(p[arr[0]], p2)) * line(segment(p[arr[1]], p3))) <= eps)) {
					} else {
						b = false;
					}
				}
			}
			point op1 = p1, op2 = p2, op3 = p3;
			p2 = op1;
			p3 = op2;
			p1 = op3;
			arr.push_front(arr.back());
			arr.pop_back();
		}
		if (b) {
			if (arr[0] == 0) {
				cout << 1 << ' ';
			}
			if (arr[1] == 0) {
				cout << 2 << ' ';
			}
			if (arr[2] == 0) {
				cout << 3 << ' ';
			}
			if (arr[0] == 1) {
				cout << 1 << ' ';
			}
			if (arr[1] == 1) {
				cout << 2 << ' ';
			}
			if (arr[2] == 1) {
				cout << 3 << ' ';
			}
			if (arr[0] == 2) {
				cout << 1 << ' ';
			}
			if (arr[1] == 2) {
				cout << 2 << ' ';
			}
			if (arr[2] == 2) {
				cout << 3 << ' ';
			}
			cout << '\n';
			return;
		}
	} while (next_permutation(arr.begin(), arr.end()));
	cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
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
