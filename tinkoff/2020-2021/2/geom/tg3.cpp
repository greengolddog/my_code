#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;

struct point {
	db x;
	db y;
	point(db x = 0.0, db y = 0.0): x(x), y(y) {}
	friend istream& operator>> (istream& inp, point& p);
	point operator- (point p) {
		return point(x - p.x, y - p.y);
	}
};

istream& operator>> (istream& inp, point& p) {
	inp >> p.x >> p.y;
	return inp;
}

struct vct {
	point p;
	vct(point p2 = point(0, 0), point start = point(0, 0)) {
		p = p2 - start;
	}
	db operator^ (vct v) {
		return p.x*v.p.y - p.y*v.p.x;
	}
	db operator* (vct v) {
		return p.x*v.p.x + p.y*v.p.y;
	}
	db operator% (vct v) {
		return atan2((*this)^v, (*this)*v);
	}
	friend istream& operator>> (istream& inp, vct& v);
};

istream& operator>> (istream& inp, vct& v) {
	inp >> v.p;
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
	point o, p1, p2, p3;
	cin >> p1 >> o  >> p2 >> p3;
	vct v1(p1, o), v2(p2, o), v3(p3, o);
	db a1 = v1^v2, a2 = v1^v3, a3 = v3^v2;
	// cout << a1 << ' ' << a2 << ' ' << a3 << endl;
	// cout << v1.p.x << ' ' << v1.p.y << endl << v2.p.x << ' ' << v2.p.y << endl << v3.p.x << ' ' << v3.p.y << endl;
	if ((a1 <= 0 && a2 <= 0 && a3 <= 0) || (a1 >= 0 && a2 >= 0 && a3 >= 0)) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}
