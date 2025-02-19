#include <iostream>
#include <iomanip>
using namespace std;
int main3()
{
short fahr, cel;
cout << "Enter temp in Fahrenheit: ";
cin >> fahr;
_asm {
mov ax, fahr;
sub ax, 32;
imul ax, 5;
cwd;
mov cx, 9;
idiv cx;
mov cel, ax;
}
cout << fahr << " F is " << cel << " C" << endl;
return 0;
}