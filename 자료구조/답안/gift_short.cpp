#include <iostream>
#include <vector>
using namespace std;

void calcul(int* price, int num, int sum, vector<int>& ans, int sol_num, int haeng_num) {
	int limit = sum / price[num], i = 1 , val;
	static int num_of_haeng = 0;
	if (num + 1 == haeng_num) {
		if (sum % price[num] == 0) {
			ans.push_back(sum / price[num]);
			if (++num_of_haeng == sol_num) {for (auto w : ans) cout << w << " ";  exit(0);}
			ans.pop_back();
			return ;}
		return ;
	}
	while (i < limit + 1) {
		val = sum - price[num] * i;
		ans.push_back(i);
		if (val == 0) { ans.pop_back(); break; }
		else		  { calcul(price, num + 1, val, ans, sol_num, haeng_num);  i++; ans.pop_back(); }
	}
}

void Answer(int* price, int sum, int solution_num, int haeng_num) {
	vector<int> temp_ans;
	calcul(price, 0, sum, temp_ans, solution_num, haeng_num);
	cout << "NONE";
}

int main(void) {
	int  solution_num, i, haeng_num, sum;
	cin >> haeng_num >> solution_num;
	int* price = new int[haeng_num];
	for (i = 0; i < haeng_num; i++) { cin >> price[i]; }  cin >> sum;
	Answer(price, sum, solution_num, haeng_num);
	return 0;
}