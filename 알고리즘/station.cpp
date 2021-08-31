#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef vector<double> point;
double sta = 0.0001;
double dis(point p1, point p2) {
	return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2) + pow(p1[2] - p2[2], 2));
}

pair<double,point> find(point p0,point p1, point p2) {
	double to0,to1 = dis(p0, p1), to2 = dis(p0, p2);
	point temp = { (p1[0] + p2[0]) / 2,(p1[1] + p2[1]) / 2,(p1[2] + p2[2]) / 2 };
	to0 = dis(p0, temp);
	if (abs(to0 - to1)<sta) {
		if (to0 > to1) return make_pair(to1, p1);
		else return make_pair(to0, temp);
	}
	if (abs(to0 - to2)<sta) {
		if (to0 > to2) return make_pair(to2, p2);
		else return make_pair(to0, temp);
	}
	else if (to1 > to2) {return find(p0, temp, p2);}
	else                 return find(p0, temp, p1);
}

double distance(point p0, point p1, point p2, point p3) {
	point compare = p1;
	pair<double,point> temp;
	double d1, d2;
	while (1) {
		temp = find(compare, p2, p3);
		d1 = temp.first; compare = temp.second;
		temp = find(compare, p0, p1);
		d2 = temp.first; compare = temp.second;
		if (abs(d1 - d2) < sta) {
			return min(d1, d2);
		}
	}
}

int main() {
	ifstream in("station.inp");
	ofstream out("station.out");
	double x, y, z, xx, yy, zz,a, b, c, aa, bb, cc;
	in >> x>> y>> z >> xx >> yy>> zz >> a >> b >> c >> aa >> bb >> cc;
	point p1 = { x,y,z }, p2 = { xx,yy,zz }, p3 = { a,b,c }, p4 = { aa,bb,cc };
	double ans = distance(p1, p2, p3, p4);
	if (ans - (int)ans < 0.0001) { out << (int)ans; }
	else                           out << ceil(ans);
	in.close();
	out.close();
}

