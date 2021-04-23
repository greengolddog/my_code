#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;

const db pi = acos(-1);

struct point {
	db x;
	db y;
	point(db x = 0.0, db y = 0.0): x(x), y(y) {}
	friend istream& operator>> (istream& inp, point& p);
	point operator- (point p) {
		return point(x - p.x, y - p.y);
	}
	bool operator== (point p) {
		return ((x == p.x) && (y == p.y));
	}
	bool operator<= (point p) {
		return ((x <= p.x) && (y <= p.y));
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
	point operator^ (point p) {
		return point((x+p.x)/2, (y+p.y)/2);
	}
	friend ostream& operator<< (ostream& out, point p);
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
	db operator~ () {
		return ~p;
	}
	db operator^ (vct v) {
		return p.x*v.p.y - p.y*v.p.x;
	}
	db operator^ (vct v) const {
		return p.x*v.p.y - p.y*v.p.x;
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
		return  (((p <= a) && (b <= p)) || ((p <= b) && (a <= p)));
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
		return (a/l.a == b/l.b) && ((a/l.a == c/l.c) || ((c == 0) && (c == l.c)));
	}
	bool par(line l) {
		return (a/l.a == b/l.b);
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	point x, y, z;
	cin >> x >> y >> z;
	angle a(y, x, z);
	cout << setprecision(20) <<  a.mid().a << ' ' << setprecision(20) << a.mid().b << ' ' << setprecision(20) << a.mid().c;
}
