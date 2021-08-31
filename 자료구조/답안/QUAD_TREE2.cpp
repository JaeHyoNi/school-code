#include <bits/stdc++.h>
using namespace std;

void draw_QTS(string str, int block, bool** img, int x, int y) {
	string temp[4] = { "","","",""};
	int i = 0,j,num=0;
	if (str.size() == 1) {for (i = x; i < x+block; i++) {for (j = y; j < y+block; j++) {img[i][j] = str[0] - '0';}}return;}
	string::iterator it = str.begin();
	str.erase(0, 1); str.pop_back();
	while (it != str.end()) {
		if (*it == '(') {
			temp[i].push_back('('); it++;
			while (1) {
				if (*it == '(') { num++; }
				if (*it == ')') { num--; }
				temp[i].push_back(*it++);
				if (*it == ')' && num == 0) break;
			}
			temp[i++].push_back(*it++);
			continue;
		}
		else {temp[i++].push_back(*it++);}
	}
	draw_QTS(temp[0], block / 2, img,x,y+block/2);
	draw_QTS(temp[1], block / 2, img,x,y);
	draw_QTS(temp[2], block / 2, img,x+block/2,y);
	draw_QTS(temp[3], block / 2, img,x+block/2,y+block/2);
}

void Qts_to_Img(int k) {
	int full = (int)pow(2, k), i, j, g;
	bool** img = new bool* [full];
	for (i = 0; i < full; ++i) { img[i] = new bool[full]; memset(img[i], 0, sizeof(bool) * full); } //img¹è¿­ ¸¸µê
	string temp; cin >> temp;
	draw_QTS(temp, full, img, 0, 0);
	for (i = 0; i < full; i++) {for (j = 0; j < full; j++) {cout << img[i][j];}cout << endl;}
}

void print_img(int x, int y, int block,bool** img) {
	if (block == 1) { cout << img[x][y]; return; }
	bool all_one=true,all_zero=true;
	for (int i = x; i < x + block; i++) {
		for (int j = y; j < y + block; j++) {
			if (img[i][j] == 0) all_one = false;
			if (img[i][j] == 1) all_zero = false;
		}
	}
	if (all_one) { cout << 1; return; }
	if (all_zero) { cout << 0; return; }
	cout << "(";
	print_img(x, y + block / 2, block / 2,img);
	print_img(x, y, block / 2, img);
	print_img(x + block / 2, y, block / 2, img);
	print_img(x + block / 2, y + block / 2 , block / 2, img);
	cout << ")";
}

void Img_to_Qts(int k) {
	int full = (int)pow(2, k), i, j, g;
	bool** img = new bool* [full];
	for (i = 0; i < full; ++i) { img[i] = new bool[full]; memset(img[i], 0, sizeof(bool) * full); }
	string temp;
	for (i = 0; i < full; i++) { cin >> temp; for (j = 0; j < full; j++) { img[i][j] = temp[j] - '0'; } }
	print_img(0, 0, full,img);
}

int main(){
	int num;
	string tree_type;
	cin >> num >> tree_type;
	if (tree_type == "QTS") {Qts_to_Img(num);}
	else					{Img_to_Qts(num);}
	return 0;
}