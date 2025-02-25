#include <iostream>
#include <iomanip>
using namespace std;
short a, b, c, d, e, f, temp;
short yT, xT, den, x, y;
void printMessage()
{
cout << "This program solves the system" << endl;
cout << "\taX + bY = c\n\tdX + eY = f" << endl;
}
void promptUser()
{
cout << "Enter the values a, b, c: ";
cin >> a >> b >> c;
cout << "Enter the values d, e, f: ";
cin >> d >> e >> f;
}
int main()
{
__asm
{
call printMessage;
call promptUser;
//Y numerator
mov ax, c;
imul d;
mov temp, ax;
mov ax, a;
imul f;
sub ax, temp;
mov yT, ax;
//X numerator
mov ax, b;
imul f;
mov temp, ax;
mov ax, c;
imul e;
sub ax, temp;
mov xT, ax;
//Denominator
mov ax, b;
imul d;
mov temp, ax;
mov ax, a;
imul e;
sub ax, temp;
mov den, ax;
//Solve Y
mov ax, yT;
cwd;
idiv den;
mov y, ax;
//Solve X
mov ax, xT;
cwd;
idiv den;
mov x, ax;
}
cout << "\tX = " << x << "\n\tY = " << y << endl;
return 0;
}