// 1. Design a class Line that implements a line, which is represented by the
//  formula ax + by + c = 0. Your class should store a, b and c as double
//  member variables. Create suitable constructor for the class which takes
//  values from the user. Write a member function intersect (l) that returns
//  the point at which this line intersects line l. If the two lines are parallel,
//  then your function should print lines are Parallel. Write a C + + program
//  that creates a number of 4 Line objects and tests each pair for intersection.
//  Your program should print an appropriate error message for parallel lines.

#include <iostream>
    using namespace std;

class line
{
public:
    double a, b, c;
    line()
    {

        cout << "Enter Value of a : " << endl;
        cin >> a;
        cout << "Enter Value of b : " << endl;
        cin >> b;
        cout << "Enter Value of c : " << endl;
        cin >> c;
    }
    line(line l1,line l2){
        cout<<"---------------------------------------------------------"<<endl;
    }
    void intersect(line l1, line l2)
    {
        double x, y, x3, y3;

        x = l2.a / l1.a;
        int x1, y1, x2, y2;
        x1 = l2.a / l1.a;
        y = l2.b / l1.b;
        y1 = l2.b / l1.b;

        x3 = l1.a / l2.a;
        y3 = l1.b / l2.b;
        x2 = l1.a / l2.a;
        y2 = l1.b / l2.b;

        if (x1 == x && y1 == y || x2 == x3 && y2 == y3)
            cout << "Lines Are in Parallel With Each Other Because Multiple of x and y are multiple of other lines multiple : " << endl;
        else
        {
            x = (((l1.b * l2.c) - (l2.b * l1.c)) / ((l1.a * l2.b) - (l2.a * l1.b)));
            y = (((l1.c * l2.a) - (l2.c * l1.a)) / ((l1.a * l2.b) - (l2.a * l1.b)));

            cout << "Intersect at (" << x << ","
                 << y
                 << ")" << endl;
        }
    }
};

int main()
{
    cout << "Equation ax+by+c=0 : " << endl;
    cout << "Enter For Line 1 : " << endl;
    line l1;
    cout << "Enter For Line 2 : " << endl;
    line l2;
    cout << "Enter For Line 2 : " << endl;
    line l3;
    cout << "Enter For Line 4 : " << endl;
    line l4;

    line l5(l1,l2);
    cout<<"l1 & l2"<<endl;
    l5.intersect(l1, l2);
    cout<<"l1 & l3"<<endl;
    l5.intersect(l1, l3);
    cout<<"l1 & l4"<<endl;
    l5.intersect(l1, l4);
    cout<<"l2 & l3"<<endl;
    l5.intersect(l2, l3);
    cout<<"l2 & l4"<<endl;
    l5.intersect(l2, l4);
    cout<<"l3 & l4"<<endl;
    l5.intersect(l3, l4);
    


    return 0;
}
