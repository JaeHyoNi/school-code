#include <iostream>
#include <vector>

using namespace std;
class Phone {
private:
	int score; int price; int num;
public:
	Phone(int score, int price,int num) :score(score), price(price),num(num) {};
	Phone():score(0),price(0),num(0) {};
	void Init_ph(int score, int price, int num) { this->score = score; this->price = price; this->num = num; }
	int GetS() { return score; }
	int GetP() { return price; }
	int GetR() { return num; }
	void Show() { cout << score << " " << price << endl; }
	bool comp( Phone oper) {
		if (score > oper.GetS() && price <= oper.GetP()) return 1;
		else return 0;
	}
};
void Recommend(int Num_of_phone) {
	Phone* arr = new Phone[Num_of_phone];
	vector<Phone>::iterator iter;
	vector<Phone> reco;
	Phone temp, standard, next_standard;
	int i,pri=0,sco=0,max_sco=0,min_pri=999999;
	for (i = 0; i < Num_of_phone; i++) {
		cin >> sco >> pri;
		temp.Init_ph(sco, pri,i+1);
		reco.push_back(temp);
		if (sco > max_sco) { max_sco = sco; standard = temp; }
		if (pri < min_pri) { min_pri = pri; }
	}
	pri = 0;
	int next = min_pri;
	while (pri != min_pri) {
		next = min_pri - 1;
		for(iter=reco.begin(); iter!=reco.end();) {
			if (standard.comp(*iter)) {iter = reco.erase(iter); continue; }
			if ( (*iter).GetP()<standard.GetP() && (*iter).GetP() > next ) { next = (*iter).GetP(); next_standard = *iter;}
			iter++;
		}
		standard = next_standard;
		pri = standard.GetP();
	}
	for (iter = reco.begin(); iter != reco.end();) {
		if (standard.comp(*iter)) {iter = reco.erase(iter); }
		else iter++;
	}
	for (auto w : reco) cout << w.GetR() << endl;
}

int main(void) {
	int Num_of_phone=0, i, max, min;
	cin >> Num_of_phone;
	Recommend(Num_of_phone);

}
