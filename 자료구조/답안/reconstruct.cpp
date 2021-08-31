#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
typedef map<char, pair<char, char>> b_t; 
void preorder(b_t m, char node) {
	cout << node  ; 
	if (m[node].first != '.') { preorder(m,m[node].first);}
	if (m[node].second != '.') { preorder(m,m[node].second);}
}
void postorder(b_t m,char node) {
	if (m[node].first != '.') {postorder(m,m[node].first);}
	if (m[node].second != '.') { postorder(m,m[node].second);}
	cout << node  ;
}

void to_Post(b_t& tree,string str1, string str2,char pre) {
	string in_l, in_r,p_l,p_r;
	int sd_n = str1.find(pre);
	if (str1.length() == 1) { tree[pre] = make_pair('.', '.'); return; }
	in_l = str1.substr(0, sd_n);
	in_r = str1.substr(sd_n + 1, str1.length());
	p_l = str2.substr(1, in_l.length());
	p_r = str2.substr(in_l.length() + 1, str1.length());
	if (sd_n == 0) {tree[pre] = make_pair('.', p_r.front());to_Post(tree, in_r, p_r, p_r.front());return;}
	if (sd_n == str1.length()-1) {tree[pre] = make_pair(p_l.front(), '.');to_Post(tree, in_l, p_l, p_l.front());return;}
	else {tree[pre] = make_pair(p_l.front(), p_r.front());to_Post(tree, in_l, p_l, p_l.front());to_Post(tree, in_r, p_r, p_r.front());}
}
void to_Pre(b_t& tree, string str1, string str2, char pre) {
	string in_l, in_r, p_l, p_r;
	int sd_n = str1.find(pre);
	if (str1.length() == 1) { tree[pre] = make_pair('.', '.'); return;}
	in_l = str1.substr(0, sd_n);
	in_r = str1.substr(sd_n + 1, str1.length());
	p_l = str2.substr(0, in_l.length());
	p_r = str2.substr(in_l.length(), str1.length()-sd_n-1);
	if (sd_n == 0) {tree[pre] = make_pair('.', p_r.back());to_Pre(tree, in_r, p_r, p_r.back());return;}
	if (sd_n == str1.length() - 1) {tree[pre] = make_pair(p_l.back(), '.');to_Pre(tree, in_l, p_l, p_l.back());return;}
	else {tree[pre] = make_pair(p_l.back(), p_r.back());to_Pre(tree, in_l, p_l, p_l.back());to_Pre(tree, in_r, p_r, p_r.back());}
}
/*
void Switch_fun(b_t& tree, string str1, string str2, char pre, int num) {
	string in_l, in_r, p_l, p_r;
	int sd_n = str1.find(pre);
	if (str1.length() == 1) { tree[pre] = make_pair('.', '.'); return; }
	in_l = str1.substr(0, sd_n);
	in_r = str1.substr(sd_n + 1, str1.length());
	if (num == 0){
		p_l = str2.substr(1, in_l.length());
		p_r = str2.substr(in_l.length() + 1, str1.length());
		if (sd_n == 0) { tree[pre] = make_pair('.', p_r.front()); Switch_fun(tree, in_r, p_r, p_r.front()); return; }
		if (sd_n == str1.length() - 1) { tree[pre] = make_pair(p_l.front(), '.'); Switch_fun(tree, in_l, p_l, p_l.front()); return; }
		else { tree[pre] = make_pair(p_l.front(), p_r.front()); Switch_fun(tree, in_l, p_l, p_l.front()); Switch_fun(tree, in_r, p_r, p_r.front()); }
	}
	else {
		p_l = str2.substr(0, in_l.length());
		p_r = str2.substr(in_l.length(), str1.length() - sd_n - 1);
		if (sd_n == 0) { tree[pre] = make_pair('.', p_r.back()); Switch_fun(tree, in_r, p_r, p_r.back()); return; }
		if (sd_n == str1.length() - 1) { tree[pre] = make_pair(p_l.back(), '.'); Switch_fun(tree, in_l, p_l, p_l.back()); return; }
		else { tree[pre] = make_pair(p_l.back(), p_r.back()); t(tree, in_l, p_l, p_l.back()); Switch_fun(tree, in_r, p_r, p_r.back()); }
	}
}
*/
int main()
{
	b_t tree;
	string type, type2, string1, string2;
	cin >> type >> string1;
	cin >> type2 >> string2;
	if (type2 == "Preorder") { to_Post(tree, string1, string2, string2.front()); cout << "Posorder "; postorder(tree, string2.front()); }
	else { to_Pre(tree, string1, string2, string2.back()); cout << "Preorder "; preorder(tree, string2.back()); }
}