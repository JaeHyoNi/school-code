#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cal(int* array, int num, int sum, vector<int>& ans, vector<int*>& A_ans, int sol_num, int haeng);

void Answer(int* array, int sum, int solution_num, int haeng) {
	vector<int*> Answer_contain;
	vector<int> temp_ans;
	cal(array, 0, sum, temp_ans, Answer_contain, solution_num, haeng);
	if (Answer_contain.size() == 0 || Answer_contain.size() < solution_num) {cout << "NONE"; exit(0);}
	int* arr = Answer_contain[solution_num - 1];
	for (int i = 0; i < haeng; i++) { cout << arr[i] << " "; }
}

void set_answer(vector<int>& ans, vector<int*>& A_ans, int num, int sol_num, int haeng) {
	int* arr = new int[num + 1];
	int i = 0;
	for (auto w : ans) { arr[i++] = w; }
	A_ans.push_back(arr);
	if (A_ans.size() == sol_num) { for (int i = 0; i < haeng; i++) { cout << arr[i] << " "; } exit(0); }
	for(int i=0;i<haeng;i++) { cout<<arr[i]<<" ";}
	cout <<endl;
	ans.pop_back();
}

int cal(int* array, int num, int sum, vector<int>& ans, vector<int*>& A_ans, int sol_num, int haeng) {
	int limit = sum / array[num], i = 1;
	int val;
	if (num + 1 == haeng) {
		if (sum % array[num] == 0) {
			ans.push_back(sum / array[num]);
			set_answer(ans, A_ans, num, sol_num, haeng);
			return 1;}
		else return 0;}
	while (i < limit + 1) {
		val = sum - array[num] * i;
		ans.push_back(i);
		if (val == 0) {ans.pop_back();break;}
		else {cal(array, num + 1, val, ans, A_ans, sol_num, haeng);  i++; ans.pop_back();}}
	return 0;
}

int main(void) {
	int  solution_num, i, haeng, sum;
	cin >> haeng >> solution_num;
	int* array = new int[haeng];
	for (i = 0; i < haeng; i++) { cin >> array[i]; }  cin >> sum;
	Answer(array, sum, solution_num, haeng);
	return 0;
}
