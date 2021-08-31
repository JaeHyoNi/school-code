#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define TRUE 1
#define FALSE 0

class customer {
private:
	int cus_ID;
	int chair;
public:
	customer(int num, int chair) :cus_ID(num), chair(chair) {}
	customer() :cus_ID(0), chair(0) {}
	void Init(int num, int chair) { cus_ID = num; this->chair = chair; }
	int GetChair() { return chair; }
	int GetID() { return cus_ID; }
	void Show() { cout << cus_ID << " " << chair << endl; }
};

int Max_Distance(int* Array, int size) {    
	int max = 0, i, num = 0;
	for (i = 0; i < size; i++) if (Array[i] >= max) { max = Array[i]; num = i; }
	return num;
}

int nextnum(vector<customer>& corona, int num_of_chair) {   
	int  size = corona.size(), i = 0, j, num = 0, maxN;
	int* Distance = new int[size];			
	auto iter = corona.begin();
	auto riter = corona.rbegin();
	Distance[i] = num_of_chair - iter->GetChair() + riter->GetChair();
	for (j = 0; j < size - 1; j++) { Distance[++i] = iter->GetChair() - (iter + 1)->GetChair(); iter += 1; } 
	iter = corona.begin();
	maxN = Max_Distance(Distance, size);		
	num = ((iter + maxN)->GetChair() + Distance[maxN] / 2);
	delete[] Distance;
	if (num == num_of_chair) {
		if (riter->GetChair() != 1) return 1;	
		return num_of_chair;
	}
	else  return num % num_of_chair;	
}

bool overlap_check(vector<customer>& corona, int ID, int num_of_chair) {  
	auto iter = corona.begin();
	while (iter != corona.end()) {
		if (iter->GetID() == ID) { corona.erase(iter); return TRUE; }
		iter++;
	}
	if (corona.size() == num_of_chair)	return TRUE;
	return FALSE;
}

bool chair_cmp(customer& l1, customer& l2) { return l1.GetChair() > l2.GetChair(); }  

void Customer_sit(vector<customer>& cafe, int next_num, vector<customer>& customer_list, int num_of_chair) {
	int ID;	cin >> ID;
	customer* temp = new customer(ID, next_num);
	if (overlap_check(cafe, ID, num_of_chair)) return;   
	cafe.push_back(*temp);                                
	customer_list.push_back(*temp);                       
	sort(cafe.begin(), cafe.end(), chair_cmp);          
}

int main() {
	vector<customer> cafe;              
	vector<customer> customer_list;   
	int num_of_chair, peo, i, j = 0, next_num = 1;
	cin >> num_of_chair >> peo;
	for (i = 0; i < peo; i++) {
		Customer_sit(cafe, next_num, customer_list, num_of_chair);      
		next_num = nextnum(cafe, num_of_chair);                     
	}
	for (auto iter : customer_list) iter.Show();
	return 0;
}
