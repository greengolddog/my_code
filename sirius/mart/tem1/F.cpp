#include <bits/stdc++.h>
typedef long long ll;
typedef __float128 db;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;

const db nan2 = 0.0/0.0;
const db pi = acos(-1);
const ll rc = 1'000'000'000'000'000'000;
const ll precision = 100;

db abs(db x) {
	return (x < 0 ? -1 : x);


db rou(db num) {
	return round((ldb)(num * rc)) / rc;
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
	bool operator!= (point p) {
		return !(*this == p);
	}
	bool operator<= (point p) {
		return ((x <= p.x) && (y <= p.y));
	}
	bool operator< (const point p) const {
		return ((x <= p.x) && (y <= p.y));
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
		return sqrt((ldb)(x * x + y * y));
	}
	db dist(point p) {
		return sqrt((ldb)((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)));
	}
	point operator^ (point p) {
		return point((x + p.x) / 2, (y + p.y) / 2);
	}
};

ostream& operator<< (ostream& out, point p) {
	out << setprecision(precision) << (ldb)p.x << ' ' << setprecision(precision) << (ldb)p.y;
	return out;
}

istream& operator>> (istream& inp, point& p) {
	ldb x1, x2;
	cin >> x1 >> x2;
	p.x = x1;
	p.y = x2;
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
		return vct(point(p.x * rou(cos((ldb)f)) - p.y * rou(sin((ldb)f)), p.x * rou(sin((ldb)f)) + p.y * rou(cos((ldb)f))));
	}
	db operator* (vct v) {
		return p.x * v.p.x + p.y * v.p.y;
	}
	db operator* (vct v) const {
		return p.x * v.p.x + p.y * v.p.y;
	}
	db operator% (vct v) {
		return atan2((ldb)((*this) ^ v), (ldb)((*this) * v));
	}
	db operator% (vct v) const {
		return atan2((ldb)((*this) ^ v), (ldb)((*this) * v));
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
		return (a * p.x + b * p.y + c) / sqrt((ldb)(a * a + b * b));
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

struct angle {
	vct a;
	vct b;
	point o;
	angle(point a = point(), point o = point(), point b = point()): a(vct(a, o)), b(vct(b, o)), o(o) {}
	angle(vct a = vct(), vct b = vct(), point o = point()): a(a), b(b), o(o) {}
	db operator~ () {
		return abs(a % b);
	}
	db operator~ () const {
		return abs(a % b);
	}
	db operator! () {
		return ~(*this) / pi * 180;
	}
	bool in(point p) {
		vct v(p, o);
		db a2 = ~(*this), b2 = a ^ v, c2 = v ^ b;
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
		return vct(a.mid(b / ((~b) / (~a))));
	}
	line mid() {
		return line(segment(vct_mid(), o));
	}
};

struct triangle {
	point a;
	point b;
	point c;
	triangle(point a = point(), point b = point(), point c = point()): a(a), b(b), c(c) {}
	db square() {
		vct v1(b, a), v2(c, a);
		return (v1 ^ v2) / 2;
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
	bool point_in(point p) {
		return get_angle(0).in(p) && get_angle(1).in(p) && get_angle(2).in(p);
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

struct polygon {
    	vector<point> points;
    	ll len;
    	bool convex = false;
    	polygon(vector<point> p = vector<point>(0, point()), bool b = false) {
		if (!b) {
        		points = p;
        		len = points.size();
        		convex = is_convex();
		} else {
			set<pair<db, db>> se;
			point minp = p[0];
			for (auto i : p) {
				se.insert(i.to_pair());
				minp = point(min(minp.to_pair(), i.to_pair()));
			}
			p.clear();
			for (auto i : se) {
				p.push_back(point(i));
			}
			points.push_back(minp);
			vector<pair<pair<db, db>, point>> arr;
			for (auto i : p) {
				if (i != minp) {
					arr.push_back({{(vct(point(-1, 0)) ^ vct(i, minp)) / ~vct(i, minp), -(~vct(i, minp))}, i});
				}
			}
			sort(arr.begin(), arr.end());
			reverse(arr.begin(), arr.end());
			for (auto[_, i] : arr) {
				while (points.size() > 1 && (vct(points[points.size() - 2], points.back()) ^ vct(i, points.back())) >= 0) {
					points.pop_back();
				}
				points.push_back(i);
			}
			len = points.size();
			convex = true;
		}
    	}
    	bool is_convex() {
        	if (len > 2) {
            		db sign_fir = sign(triangle(points[len - 1], points[len - 2], points[0]).square());
	    		ll j = len - 1;
            		for (ll i = 1; i < len; i++) {
                       		if (sign(triangle(points[i - 1], points[j], points[i]).square()) != sign_fir) {
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
	    	if (!convex) {
        		db a = 0;
        		ll j = len - 1;
        		for (ll i = 0; i < len; i++) {
            			a += vct(points[j], p)%vct(points[i], p);
            			j = i;
        		}
        		return (rou(a) != 0);
		} else {
			if (!angle(points[1], points[0], points[len - 1]).in(p)) {
				return false;
			}
			ll l = 1, r = len - 1;
			while (r - l > 1) {
				ll mid = (r + l) / 2;
				if (angle(points[1], points[0], points[mid]).in(p)) {
					r = mid;
				} else {
					l = mid;
				}
			}
			if (triangle(points[0], points[r], points[r - 1]).point_in(p)) {
				return true;
			}
			return false;
		}
	}
	friend ostream& operator<< (ostream& out, polygon& p);
    	friend istream& operator>> (istream& inp, polygon& p);
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	map<pair<db, db>, ll> m;
	vector<point> p(n);
	for (ll i = 0; i < n; i++) {
		cin >> p[i];
		m[p[i].to_pair()] = i + 1;
	}
	polygon poly(p, true);
	//cout << poly.points.size() << '\n';
	for (auto i : poly.points) {
		//cout << m[i.to_pair()] << ' ';
	}
	ldb per = 0;
	ll j = poly.points.size() - 1;
    cout << poly.points.size() << '\n';
    for (auto i : poly.points) {
        cout << i << '\n';
    }
	for (ll i = 0; i < poly.points.size(); i++) {
		per += abs(~vct(poly.points[j], poly.points[i]));
		j = i;
	}
	//cout << '\n';
	cout << setprecision(precision) << (ldb)poly.area() << '\n';
}
