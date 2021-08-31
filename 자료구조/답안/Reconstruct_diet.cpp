#include <bits/stdc++.h>
using namespace std;
void ans(string s1, string s2, char p, int n) {
	int s = s1.find(p), l = s1.size();
	if (l == 1) { cout << p; return; }
	string il = s1.substr(0, s), ir = s1.substr(s + 1, l), pl, pr;
	pl = s2.substr(n, s);
	if (n == 1) {
		pr = s2.substr(s + 1, l);
		if (s == 0) { ans(ir, pr, pr[0], 1); }
		else if (s == l - 1) { ans(il, pl, pl[0], 1); }
		else { ans(il, pl, pl[0], 1); ans(ir, pr, pr[0], 1); }
		cout << p;
	}
	else {
		pr = s2.substr(s, l - s - 1); cout << p;
		if (s == 0) { ans(ir, pr, pr.back(), 0); }
		else if (s == l - 1) { ans(il, pl, pl.back(), 0); }
		else { ans(il, pl, pl.back(), 0); ans(ir, pr, pr.back(), 0); }
	}
}
int main()
{
	string t, t2, s1, s2;
	cin >> t >> s1 >> t2 >> s2;
	if (t2 == "Inorder") { swap(t, t2); swap(s1, s2); }
	if (t2 == "Preorder") { cout << "Posorder "; ans(s1, s2, s2[0], 1); }
	else { cout << "Preorder "; ans(s1, s2, s2.back(), 0); }
}