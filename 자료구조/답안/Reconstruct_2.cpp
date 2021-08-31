#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
typedef map<char, pair<char, char>> b_t;
void show(b_t m, char n,bool i) {
	if (i) { cout << n; }
	if (m[n].first!='.') { show(m,m[n].first);}
	if (m[n].second!='.') { show(m,m[n].second);}
	if (!i) { cout << n; }
}
void Switch(b_t& tree, string str1, string str2, char pre, int n) {
	string in_l,in_r,p_l,p_r;
	int sd_n = str1.find(pre);
	if (str1.length()==1) {tree[pre] = make_pair('.','.');return;}
	in_l = str1.substr(0, sd_n);
	in_r = str1.substr(sd_n + 1, str1.length());
	p_l = str2.substr(n, in_l.length());
	if (n == 1){
		p_r = str2.substr(in_l.length() + 1, str1.length());
		if (sd_n == 0) {tree[pre] = make_pair('.', p_r.front());Switch(tree, in_r, p_r, p_r.front(), 1);return;}
		if (sd_n == str1.length() - 1) {tree[pre] = make_pair(p_l.front(), '.');Switch(tree, in_l, p_l, p_l.front(), 1);return; }
		else {tree[pre] = make_pair(p_l.front(), p_r.front());Switch(tree, in_l, p_l, p_l.front(), 1);Switch(tree, in_r, p_r, p_r.front(), 1);}}
	else {
		p_r = str2.substr(in_l.length(), str1.length() - sd_n - 1);
		if (sd_n == 0) { tree[pre] = make_pair('.', p_r.back()); Switch(tree, in_r, p_r, p_r.back(),0); return; }
		if (sd_n == str1.length() - 1) { tree[pre] = make_pair(p_l.back(), '.'); Switch(tree, in_l, p_l, p_l.back(),0); return; }
		else { tree[pre] = make_pair(p_l.back(), p_r.back()); Switch(tree, in_l, p_l, p_l.back(),0); Switch(tree, in_r, p_r, p_r.back(),0); }}
}
int main()
{
	b_t tree;
	string type, type2, str1, str2;
	cin >> type >> str1;
	cin >> type2 >> str2;
	if (type2=="Inorder") {swap(type, type2);swap(str1, str2);}
	if (type2 == "Preorder") {Switch(tree, str1, str2, str2.front(),1);cout<<"Postorder "; post(tree, str2.front(),0); }
	else { Switch(tree, str1, str2, str2.back(),0);cout<<"Preorder "; pre(tree, str2.back(),1); }
}
