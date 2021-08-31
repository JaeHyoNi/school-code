#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class set {
public:
	int a;	int b;	int c;
	void out() { cout << a << " " << b << " " << c << endl; }
};

void gilbon(list<int> &corona,int num,set* s) {
	list<int>::iterator iter = find(corona.begin(), corona.end(), num);
	auto riter = corona.rbegin();
	if (corona.size() == 1) {s->a = s->b = s->c = *iter;return;}
	else if (iter == corona.begin()) {
		auto temp = corona.rbegin();
		s->a = *iter;	s->b = *temp; iter++;	s->c = *iter;
		return;
	}
	else if (*iter == *riter) {
		auto temp = corona.begin();
		s->a = *iter;	iter->2;
		s->b = *iter;
		s->c = *temp;

		return;
	}
	else {
		s->a = *iter;iter--;
		s->b = *iter;iter++;iter++;
		s->c = *iter;
		return;
	}
}
bool setting(list<int>& corona, int num, set* cafe) {
	auto iter = find(corona.begin(), corona.end(), num);
	if (iter != corona.end() && corona.size() != 0) { corona.remove(num);return 1; }
	corona.push_front(num);
	corona.sort();
	return 0;
}
int main(){
	list<int> corona;
	int table, peo,i,num,j=0;
	cin >> table>> peo;
	list<int>::iterator iter;
	set* cafe = new set[peo];
	for (int i = 0; i < peo; i++) {
		cin >> num;
		if(setting(corona,num,cafe))    continue;
		gilbon(corona, num, &cafe[j++]);
	}
	for (int i = 0; i < j; i++) {
		cafe[i].out();
	}
	return 0;
}
