#include <iostream>
#include <cmath>
using namespace std;

double area(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double perimeter(double a, double b, double c)
{
    return a + b + c;
}

string triangleType(double a, double b, double c)
{
    double x = a;
    double y = b;
    double z = c;

    if (x > y)
        swap(x, y);
    if (y > z)
        swap(y, z);
    if (x > y)
        swap(x, y);

    if (x + y <= z)
        return "Others (Invalid Triangle)";

    double left = (x * x) + (y * y);
    double right = z * z;

    if (left > right)
        return "Acute Triangle";
    else if (left < right)
        return "Obtuse Triangle";
    else
        return "Others (Right Triangle)";
}

int main()
{
    double side1, side2, side3;

    cout << "Enter side 1: ";
    cin >> side1;

    cout << "Enter side 2: ";
    cin >> side2;

    cout << "Enter side 3: ";
    cin >> side3;

    if (side1 + side2 > side3 &&
        side1 + side3 > side2 &&
        side2 + side3 > side1)
    {
        cout << "\nArea = " << area(side1, side2, side3) << endl;
        cout << "Perimeter = " << perimeter(side1, side2, side3) << endl;
        cout << "Triangle Type = " << triangleType(side1, side2, side3) << endl;
    }
    else
    {
        cout << "\nThe given sides do not form a triangle." << endl;
    }

    return 0;
}