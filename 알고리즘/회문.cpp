#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

string temp1, temp2;
int n=0;

int decide(string temp) {
	auto iter1 = temp.begin();
	auto iter2 = temp.begin(); iter2 += (temp.size()-1);
	for (int i = 0; i < temp.size() / 2; i++) {
		if (*iter1 != *iter2) {	n = i;return 0; }
		iter1++; iter2--;
	}
	return 1;
}

int main() {
	int num;
	string temp;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		temp1 = temp2 = temp;
		if (decide(temp)) ans.push_back(1);
		else {
			temp1.erase(n, 1);
			temp2.erase(temp2.size() - n, 1);
			if (decide(temp1))		ans.push_back(2);
			else if (decide(temp2)) ans.push_back(2);
			else					ans.push_back(3);
		}
	}
	for (auto x : ans) {cout << x << endl;}
}
