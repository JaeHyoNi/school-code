#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

typedef struct HCC {
	int st;
	int fi;
	int pri;
}hcc;
HCC arr[1001];
bool compare(HCC& h1, HCC& h2) {
	if (h1.st < h2.st) return true;
	else if (h1.st == h2.st) {if (h1.fi < h2.fi) {return true;}
		                      else return false;}
	else return false;
}
int max_price=0, max_day=0,glo_N;
void update(int pri, int day) {
	if (pri > max_price) { max_price = pri; max_day = day; }
	else if (pri == max_price) { if (max_day > day) max_day = day; }
}

void find(int i, int price, int day) { 
	stack<int> temp;
	int t = i++;
	while (!(arr[t].fi < arr[i].st)) {
		temp.push(i);
		i++;
		if (i>= glo_N) {update(price + arr[t].pri-10, day + arr[t].fi - arr[t].st + 1); return;}
	}
	find(i, price + arr[t].pri-10, day + arr[t].fi - arr[t].st + 1);
	while (!temp.empty()) {
		find(temp.top(),  price, day );
		temp.pop();
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
	find( 0, 0, 0);
	out << max_price+10 << " " << max_day;
	in.close();
	out.close();
}
