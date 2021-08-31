#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Customer {
private:
	int ID;
	int number;
	int dis;
public:
	Customer() :ID(0), number(0), dis(0) {}
	Customer(int ID, int number, int dis) :ID(ID), number(number), dis(dis) {}
	void adj() { dis = dis/2; }
	void adj1() {dis = dis / 2 + 1; }
	void GiveDis(int num) { dis = dis + num; }
	int GetID()		{ return ID; }
	int Getnum()	{ return number; }
	int Getdis()	{ return dis; }
	void Show() { cout << ID << " " << number << endl; }
	void SHOW() {
		cout << "[" << ID << " ," << number << " ," << dis << "] ";
	}
};

bool chair_cmp(Customer& l1, Customer& l2) {
	return l1.Getnum() > l2.Getnum();
}

void Delete(vector<Customer> &cafe, int Cus_ID) {
	sort(cafe.begin(), cafe.end(), chair_cmp);
	vector<Customer>::iterator iter = cafe.begin();
	while (iter->GetID() != Cus_ID)  iter++;
	if      (iter == cafe.end() - 1)  cafe.begin()->GiveDis(iter->Getdis());
	else    (iter + 1)->GiveDis(iter->Getdis());
	cafe.erase(iter);
}

int find_Max_and_Overlap(vector<Customer>& cafe,int Cus_ID) {		
	vector<Customer>::iterator iter = cafe.begin();
	vector<Customer>::iterator ID   = cafe.begin();
	int Max_Distance = 0;
	int num=0,ID_Num=0;
	while (iter != cafe.end()) {
		if (iter->GetID() == Cus_ID)       {Delete(cafe, iter->GetID());   return -1;}
		if (iter->Getdis() > Max_Distance) {ID = iter;ID_Num = num;Max_Distance = iter->Getdis();}
		else if (iter->Getdis() == Max_Distance) {
			if (iter->Getnum() < ID->Getnum()) {
				ID = iter;ID_Num = num;}
			}
		iter++;  num++;
	}
	return ID_Num;
}

Customer* Make_Customer(vector<Customer>& cafe, int Next_num, int num_of_chair, int Pre_ID,int ID) {
	vector<Customer>::iterator Pre = cafe.begin()+Pre_ID;
	int Next_dis;
	if (Next_num == num_of_chair) {
		sort(cafe.begin(), cafe.end(), chair_cmp);
		Pre_ID = find_Max_and_Overlap(cafe, ID);
		Pre = cafe.begin() + Pre_ID;
		if ((cafe.end() - 1)->Getnum() != 1) {
			Next_dis = Pre->Getdis() / 2;
			Customer* temp = new Customer(ID, 1, Next_dis);
			Pre->adj1();
			return temp;
		}
		else {
			if (Pre->Getdis() % 2 == 0)	Next_dis = Pre->Getdis() / 2;
			else                        Next_dis = Pre->Getdis() / 2 + 1;
			Customer* temp = new Customer(ID,Next_num,Next_dis);
			Pre->adj();
			return temp;
		}
	}
	else {
		if (Pre->Getdis() % 2 == 0)	Next_dis = Pre->Getdis() / 2;
		else                        Next_dis = Pre->Getdis() / 2 + 1;
		Customer* temp = new Customer(ID, Next_num%num_of_chair, Next_dis);
		Pre->adj();
		return temp;
	}
}

void Customer_sit(vector<Customer>& cafe,vector<Customer>& cafe_list, int num_of_chair) {
	int ID;	cin >> ID;
	if (cafe.size() == 0) {
		Customer* temp = new Customer(ID, 1, num_of_chair);
		cafe.push_back(*temp);
		cafe_list.push_back(*temp);
		return;
	}
	int Next_num, Next_dis;
	int Pre_ID = find_Max_and_Overlap(cafe,ID);
	if (Pre_ID == -1) {return;}
	if (cafe.size() == num_of_chair) { return; }
	vector<Customer>::iterator Pre = cafe.begin() + Pre_ID;
	Next_num = Pre->Getnum() + Pre->Getdis() / 2;
	Customer* temp = Make_Customer(cafe, Next_num, num_of_chair, Pre_ID, ID);
	cafe.push_back(*temp);
	cafe_list.push_back(*temp);
	for (auto iter : cafe) iter.SHOW();
}

int main() {
	vector<Customer> cafe;
	vector<Customer> cafe_list;
	int num_of_chair, peo, i, j = 0, next_num = 1;
	cin >> num_of_chair >> peo;
	for (i = 0; i < peo; i++) {
		Customer_sit(cafe,cafe_list, num_of_chair);
	}
	for (auto iter : cafe_list) iter.Show();
	return 0;
}