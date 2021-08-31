#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int n = 0;
int decide(string temp, int num) {
	auto iter1 = temp.begin();
	auto iter2 = temp.begin(); iter2 += (num - 1);
	for (int i = 0; i < num / 2; i++) { if (*iter1 != *iter2) { n = i; return 0; }iter1++; iter2--; }
	return 1;
}
int main() {
	ifstream in("palin.inp");
	ofstream out("palin.out");
	int num, tem;
	string temp, temp1, temp2;
	in >> num;
	for (int i = 0; i < num; i++) {
		in >> temp;
		tem = temp.size();
		if (decide(temp, tem)) out << "1" << "\n";
		else {
			tem = tem - 2 * n - 1;
			temp1 = temp.substr(n, tem);
			temp2 = temp.substr(n + 1, tem);
			if (decide(temp1, tem))  out << "2" << "\n";
			else if (decide(temp2, tem))  out << "2" << "\n";
			else  out << "3" << "\n";
		}
	}
	in.close();
	out.close();
}
