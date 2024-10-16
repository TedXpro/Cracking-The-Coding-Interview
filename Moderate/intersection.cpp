#include <iostream>

using namespace std;

class Point{
public:
    double x;
    double y;

    Point(){
        this->x = INT_MAX;
        this->y = INT_MAX;
    }

    Point(double x, double y){
        this->x = x;
        this->y = y;
    }

    bool operator==(const Point& point2){
        return x == point2.x && y == point2.y;
    }

};

class Line{
public:
    double slope;
    double y_intercept;

    Line(){}

    Line(Point start, Point end){
        double dX = end.x - start.x;
        double dY = end.y - start.y;
        this->slope = dY / dX;
        this->y_intercept = start.y - this->slope * start.x;
    }
};

bool isBetween(double start, double mid, double end)
{
    if (start > end)
    {
        return end <= mid && mid <= start;
    }
    return end >= mid && mid >= start;
}

bool isBetween(Point &start, Point &mid, Point &end)
{
    return isBetween(start.x, mid.x, end.x) && isBetween(start.y, mid.y, end.y);
}

Point intersection(Point& start1, Point& end1, Point& start2, Point& end2){
    if(start1.x > end1.x){
        swap(start1, end1);
    }
    if(start2.x > end2.x){
        swap(start2, end2);
    }
    if(start1.x > start2.x){
        swap(start1, start2);
        swap(end1, end2);
    }

    Line line1(start1, end1);
    Line line2(start2, end2);

    if(line1.slope == line2.slope){
        if(line1.y_intercept == line2.y_intercept && isBetween(start1, start2, end1)){
            return start2;
        }
        return Point();
    }

    double x = (line2.y_intercept - line1.y_intercept) / (line1.slope - line2.slope);
    double y = line1.slope * x + line1.y_intercept;
    Point intercept(x, y);

    if(isBetween(start1, intercept, end1) && isBetween(start2, intercept, end2)){
        return intercept;
    }

    return Point();
}


int main(){
    Point start1(1, 1);
    Point end1(2, 2);
    Point start2(1, 3);
    Point end2(2, 4);

    Point answer = intersection(start1, end1, start2, end2);
    if(answer == Point()){
        cout << "There is No Point of intersection between the two lines\n";
    } else {
        cout << "The point of intersection between the two lines is " << "(" << answer.x << "," << answer.y << ")" << endl;
    }
}