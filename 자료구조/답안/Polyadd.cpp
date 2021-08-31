#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class haeng {
private:
	int coe;
	int exo;
public:
	int GetEXO() { return exo; }
	int GetCOE() { return coe; }
	void Init(int coe, int exo) { this->coe = coe; this->exo = exo; }
	void coe_plus(int num) { coe += num; }
	void Show_haeng() { cout << coe << " " << exo<<endl; }
};

haeng* Makehae() {
	int coe, exo;
	cin >> coe >> exo;
	haeng* temp = new haeng;
	temp->Init(coe, exo);
	return temp;
}

void Show_func(vector<haeng>& func) {
	vector<haeng>::iterator iter = func.begin();
	while (iter != func.end()) {
		iter++->Show_haeng();
	}
}

void Overlap_check(vector<haeng>& func) {
	vector<haeng>::iterator iter = func.begin();
	while (iter != func.end() && (iter+1)!= func.end()) {
		if (iter->GetEXO() == (iter + 1)->GetEXO()) {
			(iter + 1)->coe_plus(iter->GetCOE());
			iter = func.erase(iter);}
		else iter++;}
}

void Clean_Zero(vector<haeng>& func) {
	vector<haeng>::iterator iter = func.begin();
	while (iter != func.end()) {
		if (iter->GetCOE() == 0) {iter = func.erase(iter);}
		else  iter++;
	}
}

bool exo_set(haeng& h1, haeng& h2) { return h1.GetEXO() > h2.GetEXO(); }

void Answer(vector<haeng>& function) {
	sort(function.begin(), function.end(), exo_set);
	Overlap_check(function);
	Clean_Zero(function);
	if (function.size() == 0) { cout <<"1"<<endl<< "0 0"; }
	else { cout << function.size() << endl; Show_func(function); }
}

void Plus_vector(vector<haeng>& fun) {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		haeng* temp = Makehae();
		fun.push_back(*temp);
	}
}

int main() {
	int num, i;
	cin >> num;
	vector<haeng> function;
	for (int i = 0; i < num; i++) {
		Plus_vector(function);
	}
	Answer(function);
	return 0;
}
