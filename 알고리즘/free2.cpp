#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct HCC {int st;int fi;int pri;}hcc;
typedef struct con {int pre_f;int f;int pre_p;int p;int pre_d;int d;}con;
HCC arr[1001];
vector<con> arrr;
bool compare(HCC& h1, HCC& h2) {
	if (h1.st < h2.st) return true;
	else if (h1.st == h2.st) {if (h1.fi < h2.fi) {return true;}
		                      else return false;}
	else return false;
}
bool compare2(con& a, con& b) {
	if (a.f < b.f) return true;
	else if (a.f == b.f) {
		if (a.pre_f < b.pre_f) { return true; }
		else return false;}
	else return false;
}
stack<HCC> temp_s;
int glo_N;
void sett(int i,int j) {
	arrr[j] = {arrr[j].f,arr[i].fi,arrr[j].p,arrr[j].p+arr[i].pri-10,arrr[j].d,arrr[j].d+arr[i].fi-arr[i].st+1};
}
con ad_v(int i, int j) {
	con temp;
	temp = arrr[j];
	temp.f = arr[i].fi;
	temp.p = arrr[j].pre_p + arr[i].pri;
	temp.d = arrr[j].pre_d + arr[i].fi - arr[i].st + 1;
	return temp;
}
void find() {
	int i = 0,vsize=0,j=0,t_vsize=0;
	vector<con>::iterator iter,iter2;
	con tt;
	while (!(arr[0].fi < arr[i].st)) {arrr.push_back({ 0,arr[i].fi,0,arr[i].pri,0,arr[i].fi - arr[i].st + 1 });i++; vsize++;}
	t_vsize = vsize;
	while (i < glo_N) {
		for (j = 0; j < vsize; j++) {
			if (arrr[j].f < arr[i].st) { sett(i, j); }
			else if (arr[i].st<arrr[j].f && arr[i].st > arrr[j].pre_f && arrr[j].pre_f != 0) {
				arrr.push_back(ad_v(i, j));
				t_vsize++;
			}
		}
		vsize = t_vsize;
		i++;
		sort(arrr.begin(), arrr.end(),compare2);

		iter = arrr.begin();
		while (iter + 1 != arrr.end()) {
			if ((*iter).f >= (*(iter + 1)).f && (*iter).pre_f <= (*(iter + 1)).pre_f && (*iter).p >= (*(iter + 1)).p) {
				arrr.erase(iter + 1);
			}
			else { iter++; }
		}
	}
}
int main() {
	ifstream in("free.inp");
	ofstream out("free.out");
	int num,i;
	in >> num;
	glo_N = num;
	for (i = 0; i < num; i++) {in >> arr[i].st >> arr[i].fi >> arr[i].pri;}
	sort(arr, arr + num,compare);
	find();
	int max_p=0, max_d;
	for (con& x : arrr) {
		if (max_p < x.p) { max_p = x.p; max_d = x.d; }
		else if (max_p == x.p) if (max_d > x.d) {max_d = x.d; }
	}
	out << max_p << " " << max_d;
	in.close();
	out.close();
}
