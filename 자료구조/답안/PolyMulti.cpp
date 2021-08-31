#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using bi = long long;
class haeng {
private:
	bi coe;  bi exo;
public:
	bi GetEXO() { return exo; }
	bi GetCOE() { return coe; }
	void Init(bi coe, bi exo) { this->coe = coe; this->exo = exo; }
	void coe_plus(bi num) { coe += num; }
	void Show_haeng() { cout << coe << " " << exo << endl; }
};
haeng* Makehaeng() {
	bi coe, exo;
	cin >> coe >> exo;
	haeng* temp = new haeng;
	temp->Init(coe, exo);
	return temp;
}
void Show_func(vector<haeng>& func) {
	auto iter = func.begin();
	while (iter != func.end()) { iter++->Show_haeng(); }
}
void Overlap_check(vector<haeng>& func) {
	auto iter = func.begin();
	while (iter != func.end() && (iter + 1) != func.end()) {
		if (iter->GetEXO() == (iter + 1)->GetEXO()) {
			(iter + 1)->coe_plus(iter->GetCOE());
			iter = func.erase(iter);
		}
		else iter++;
	}
}
void Clean_Zero(vector<haeng>& func) {
	auto iter = func.begin();
	while (iter != func.end()) {
		if (iter->GetCOE() == 0) { iter = func.erase(iter); }
		else  iter++;
	}
}
bool exo_set(haeng& h1, haeng& h2) { return h1.GetEXO() > h2.GetEXO(); }
void set(vector<haeng>& function) {
	sort(function.begin(), function.end(), exo_set);
	Overlap_check(function);
	Clean_Zero(function);
}
void Plus_vector(vector<haeng>& fun) {
	bi num; cin >> num;
	for (int i = 0; i < num; i++) {
		haeng* temp = Makehaeng();
		fun.push_back(*temp);
	}
}
haeng multi(vector<haeng>::iterator& iter1, vector<haeng>::iterator& iter2) {
	haeng temp;
	temp.Init((iter1->GetCOE() * iter2->GetCOE()), (iter1->GetEXO() + iter2->GetEXO()));
	return temp;
}
void multi_fun(vector<haeng>& fun1, vector<haeng>& fun2, vector<haeng>& ALL) {
	auto iter1 = fun1.begin();
	auto iter2 = fun2.begin();
	while (iter1 != fun1.end()) {
		while (iter2 != fun2.end()) {
			haeng temp = multi(iter1, iter2);
			ALL.push_back(temp);
			iter2++;
		}
		iter1++; iter2 = fun2.begin();
	}
}
void Answer(vector<haeng>* array, vector<haeng>& fun, bi num) {
	set(array[0]);
	for (int i = 0; i < num - 1; i++) {
		multi_fun(array[i], array[i + 1], fun);
		set(fun); array[i + 1] = fun; fun.clear();
	}
	if (array[num - 1].size() == 0) { cout << "1" << endl << "0 0" << endl; }
	else { cout << array[num - 1].size() << endl; Show_func(array[num - 1]); }
}
int main() {
	bi num, i; cin >> num;
	if (num == 0) { cout << "0" << endl << "0 0"; return 0; }
	vector<haeng> fun;
	vector<haeng>* array = new vector<haeng>[num];
	for (i = 0; i < num; i++) { Plus_vector(fun);  array[i] = fun;  fun.clear(); }
	Answer(array, fun, num);
	return 0;
}