#include <iostream>
using namespace std;
class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y) :x(x), y(y) {}
    Point() :x(0), y(0) {}
    int GetX() { return x; }
    int GetY() { return y; }
    void init() { cin >> x >> y; }
    void show() const { cout<<" "<< x <<"  "<< y <<endl; }
    bool go(Point to) {
        if (x == to.GetX() && y == to.GetY())
            return 1;
        if (x - to.GetX() == 0) {
            if (y - to.GetY() < 0) {y ++;return 0;}
            else {y --;return 0;}}
        if (x - to.GetX() < 0) {x ++;return 0;}
        else{x --;return 0;}
        }
};
void loc(Point start, Point* v, int num, int t) {
    int i = 1;
    while (t > 0) {
            if (start.go(v[i])) {i++;if (i == num)i = 0;continue;}
        t--;}
    start.show();
}
int main()
{
    int n, i, t[5];  cin >> n;
    Point arr[50];
    for (i = 0; i < n; i++) {arr[i].init();}
    for(auto &w:t){cin>>w;}
    for (i = 0; i < 5; i++) {loc(arr[0], arr, n, t[i]);}
    return 0;
}
