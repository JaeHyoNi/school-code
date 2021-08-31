#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> mytoken = { "front", "back", "cut", "double" , "flip" , "report" };

int get_type(string w) {
	for (int i = 0; i < mytoken.size(); i++) {
		if (w == mytoken[i]) return(i);
	}
	return(-1);
}
void str_cut(string& str, int n1, int n2) {
	str.erase(str.begin() + n1 - 1, str.begin() + n2);
}
void str_front(string& str, int n1, int n2) {
	str.insert(0, str.substr(n1 - 1, n2 - n1 + 1));
	str_cut(str, n2 + 1, n2 + n2 - n1 + 1);
}
void str_back(string& str, int n1, int n2) {
	str.append(str.substr(n1 - 1, n2 - n1 + 1));
	str_cut(str, n1, n2);
}
void str_double(string& str, int n1, int n2) {
	str.insert(str.begin() + n2, str.begin() + n1 - 1, str.begin() + n2);
}
void str_flip(string& str, int n1, int n2) {
	reverse(str.begin() + n1 - 1, str.begin() + n2);
}

bool set_num(int& num1, int& num2, int len) {
	if (num1 > len) return 1;
	if (num1<len && num2>len) { num2 = len; return 0; }
	else
		return 0;
}
int main(void) {
	string myword, temp;
	temp = ("");
	int num, num1, num2, mytype;
	ifstream in("sapiens.txt");
	string in_line;
	getline(in, in_line);
	string DNA;
	while (getline(in, in_line)) {
		DNA.append(in_line);
	}
	in.close();
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> myword >> num1 >> num2;
		mytype = get_type(myword);
		if (set_num(num1, num2, DNA.length())) {
			if (mytype == 5) {temp.append("NONE\n");}
			mytype = -1;
		}
		switch (mytype) {
		case 0:
			str_front(DNA, num1, num2);
			break;
		case 1:
			str_back(DNA, num1, num2);
			break;
		case 2:
			str_cut(DNA, num1, num2);
			break;
		case 3:
			str_double(DNA, num1, num2);
			break;
		case 4:
			str_flip(DNA, num1, num2);
			break;
		case 5:
			temp.append(DNA.substr(num1 - 1, num2 - num1 + 1));
			temp.append("\n");
			break;
		case -1:
			break;
		}
	}
	temp.pop_back();
	cout << temp;	
	return 0;
}

