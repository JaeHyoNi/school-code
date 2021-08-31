#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define TRUE 1
#define FALSE 0

class set {
private:
	int n1; int n2; int n3;
public:
	void Init(int n1, int n2, int n3) { this->n1 = n1; this->n2 = n2; this->n3 = n3; }
	void show()						  { cout << n1<< " " << n2<< " " << n3<< endl; }
};

class cust {
private:
	int cus_ID;
	int chair;
public:
	cust(int num, int chair )	  :cus_ID(num), chair(chair) {}
	cust()						  :cus_ID(0),chair(0)		 {}
	void Init(int num, int chair) { cus_ID = num; this->chair = chair; }
	int GetChair()				  { return chair;  }
	int GetID()					  { return cus_ID; }
	void Show()					  { cout << cus_ID << " " << chair << endl; }
};

int min(int* Array,int size) {
	int min=0,i,num=0;
	for (i = 0; i < size; i++) if(Array[i] >= min) {min = Array[i]; num = i;}
	return num;
}

int nextnum(vector<cust>& corona, int num_of_chair) {
	int  size   = corona.size(), i = 0, j = 0, num = 0;
	int* minNum = new int[size];
	auto iter   = corona.begin();
	minNum[i]   = num_of_chair + 1 - iter->GetChair();
	for (j = 0; j < size - 1; j++) { minNum[++i] = iter->GetChair() - (iter + 1)->GetChair(); iter += 1; }
	iter        = corona.begin();
	int minN    = min(minNum,size);
	num         = ((iter+minN)->GetChair() +  minNum[minN]/ 2);
	delete [] minNum;
	return num;
}

void MakeSet(vector<cust>& corona, set* Set, int num) {
	auto iter = corona.begin();
	auto riter = iter + corona.size() - 1;
	auto target = iter;
	while (target != corona.end()) { if (target->GetID() == num) break; target += 1; }
	if (corona.size() == 1)		Set->Init(target->GetID(), target->GetID(), target->GetID());
	else if (target == iter)	Set->Init(target->GetID(), (target + 1)->GetID(), riter->GetID());
	else if (target == riter)	Set->Init(target->GetID(), iter->GetID(), (target - 1)->GetID());
	else						Set->Init(target->GetID(), (target + 1)->GetID(), (target - 1)->GetID());
}

bool overlap_check(vector<cust>& corona, int j) {
	auto iter = corona.begin();
	while (iter != corona.end()) {
		if (iter->GetID() == j) {
			corona.erase(iter);
			return TRUE;
		}
		iter++;
	}
	return FALSE;
}

bool chair_cmp(cust& l1, cust& l2) { return l1.GetChair() > l2.GetChair(); }

int main() {
	vector<cust> corona;
	int num_of_chair, peo, i, num, next_num=1,j=0;
	cin >> num_of_chair >> peo;
	set*  Set = new set[peo];
	for (i = 0; i < peo; i++) {
		cin >> num;
		cust *temp = new cust(num, next_num);
		if (overlap_check(corona, num))	continue;
		corona.push_back(*temp);
		sort(corona.begin(),corona.end(),chair_cmp);
	    next_num = nextnum(corona,num_of_chair);
	}
	for (i = 0; i < j ; i++) {
		Set[i].show();
	}
	return 0;
}