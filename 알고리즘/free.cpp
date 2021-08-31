#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct HCC { int st; int fi; int pri; }hcc;
typedef struct te { int price; int day; int num; }te;
HCC order[101];
te schedule[2000];
bool compare(HCC& h1, HCC& h2) {
	if (h1.fi < h2.fi) return true;
	else if (h1.fi == h2.fi) {
		if (h1.st < h2.st) { return true; }
		else return false;
	}
	else return false;
}

int main() {
	ifstream in("free.inp");
	ofstream out("free.out");
	int num, i,max_p=0,max_d=9999;
	in >> num;
	for (i = 0; i < num; i++) {
		in >> order[i].st >> order[i].fi >> order[i].pri;
		if (order[i].pri > max_p) {
			max_p = order[i].pri;
			max_d = order[i].fi - order[i].st + 1;
		}
		else if (order[i].pri == max_p) {
			max_d = min(order[i].fi - order[i].st + 1, max_d);
		}
	}
	sort(order, order + num, compare);
	int j = 1, t1, t2;
	num = order[num - 1].fi + 1;
	schedule[order[0].fi] = { order[0].pri,order[0].fi - order[0].st + 1 ,1 };

	for (i = order[0].fi; i < num; i++) {
		if (schedule[i].price < schedule[i - 1].price) {
			if (schedule[i - 1].price <= 10) {
				schedule[i - 1] = { 0,0,0 };
			}
			schedule[i] = schedule[i - 1];
		}
		if (i == order[j].fi) {
			while (i == order[j].fi) {
				t1 = schedule[i].price;
				t2 = schedule[order[j].st - 1].price + order[j].pri;
				if (schedule[order[j].st - 1].num != 0)
					t2 -= 10;
				if (t2 > t1) {
					schedule[i].price = t2;
					schedule[i].day = schedule[order[j].st - 1].day + order[j].fi - order[j].st + 1;
					schedule[i].num++;
				}
				else if (t1 == t2) {
					if (schedule[i].day > schedule[order[j].st - 1].day + order[j].fi - order[j].st + 1) {
						schedule[i].day = schedule[order[j].st - 1].day + order[j].fi - order[j].st + 1;
						schedule[i].num++;
					}
				}
				j++;
			}
		}
	}
	if (max_p > schedule[i - 1].price) { out << max_p << " " << max_d; }
	else if (max_p == 10 && 10 == schedule[i - 1].price) { out << "10 " << max_d; }
	else if (max_p == schedule[i - 1].price) { out << max_p << " " << min(max_d, schedule[i - 1].day); }
	else { out << schedule[i - 1].price << " " << schedule[i - 1].day; }
	in.close();
	out.close();
}
