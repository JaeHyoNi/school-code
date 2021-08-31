#include <iostream>
using namespace std;
class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y) :x(x), y(y) {}
    Point() :x(0), y(0) {}
    int GetX() const { return x; }
    int GetY() const { return y; }
    void init() { cin >> x >> y; }
    void show() const { cout << x << " " << y; }
    int go(Point com) {
        if (x == com.GetX() && y == com.GetY()) return 1;
        if (x - com.GetX() == 0) {
            if (y - com.GetY() < 0) {this->y += 1; return 0;}
            else {this->y -= 1;return 0;}}
        if (x - com.GetX() < 0) {this->x += 1;return 0;}
        else {this->x -= 1;return 0;}
    }
};
int interval(Point p1, Point p2) {
    if ((abs(p1.GetX() - p2.GetX())) + (abs(p1.GetY() - p2.GetY())) == 1) {return 1;}
    return 0;
}
void gof(Point& start, Point* vertex, int& i, int num) {
    if (start.go(vertex[i])) {
        if (++i == num) {i = 0;}
        start.go(vertex[i]);
    }
}
void gob(Point& start, Point* vertex, int& i, int num) {
    if (start.go(vertex[i])) {
        if (--i < 0) {i = num - 1;}
        start.go(vertex[i]);
    }
}
bool mi(int i, int j, int num) {
    if (abs(i - j) < 2 || abs(i - j) == num - 1)
        return 1;
    return 0;
}
void shallmove(Point start, Point start2, int& i, int& j, int num, int& move, int& time) {
    if (start.GetX() == start2.GetX() && start.GetY() == start2.GetY() || interval(start, start2)){
        move = (move + 1) % 2;
        if (--i < 0) {
            i = num - 1;
        }
        if (++j == num) {
            j = 0;
        }
        if (interval(start, start2)) {
            time--;
        }
    }
}
void where(Point start, Point start2, Point* vertex, int num, int time, int wh1, int wh2) {
    int i = wh1;
    int j = wh2;
    int move = 1;
    int t=1;
    int bo = 0;
    while (time > 0) {
        if (move) {
            bo = mi(i, j, num);
            gof(start, vertex, i, num);
            gob(start2, vertex, j, num);
            if (bo) {
                shallmove(start, start2, i, j, num, move, time);
            }
            bo = 1;
        }
        else {
            bo = mi(i, j, num);
            gob(start, vertex, i, num);
            gof(start2, vertex, j, num);
            if (bo) {
                shallmove(start2, start, j, i, num, move, time);
            }
            bo = 1;
        }
        time--;
    }
    start.show();
    cout << endl;
    start2.show();
}
int main()
{
    int num, time, i;
    cin >> num;
    Point arr[50];
    for (i = 0; i < num; i++) {
        arr[i].init();
    }
    Point start = arr[0];
    Point start2 = arr[num / 2-1];
    cin >> time;
    where(start, start2, arr, num, time, 1, num/2-2);
    return 0;
}

