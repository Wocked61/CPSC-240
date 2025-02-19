#include <iostream>
#include <iomanip>
using namespace std;
int main2()
{
int a, b, c, h, areaT = 0, perimeterT = 0;
int lengthR, width, areaR = 0, perimeterR = 0;
cout << "Enter the values of a, b, c, and h for the triangle: ";
cin >> a >> b >> c >> h;
cout << "Enter the length and the width of the rectangle: ";
cin >> lengthR >> width;
_asm {
//triangle area
mov eax, h;
imul eax, c;
cdq;
mov ecx, 2;
idiv ecx;
mov areaT, eax;
//triangle perimeter
mov eax, a;
add eax, b;
add eax, c;
mov perimeterT, eax;
//rectangle area
mov eax, lengthR;
imul eax, width;
mov areaR, eax;
//rectangle perimeter
mov eax, width;
add eax, lengthR;
imul eax, 2;
mov perimeterR, eax;
}
cout << "Triangle\n\tArea................" << areaT << "\n\tPerimeter..........." << perimeterT << endl;
cout << "Rectangle\n\tArea................" << areaR << "\n\tPerimeter..........." << perimeterR << endl;
return 0;
}