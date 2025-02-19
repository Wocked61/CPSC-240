#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
//Enter a 3 digit int number : 358
//The total of digits in 358 is 16
short input = 0;
short first, second,third;
short divisor = 10;
cout << "Enter a 3 digit int number : ";
cin >> input;
_asm {
mov ax, input;
mov dx, 0;
idiv divisor;
mov first, dx;
mov dx, 0;
idiv divisor;
mov second, dx;
mov dx, 0;
idiv divisor;
mov third, dx;
}
cout << "The total of digits in " << input << " is " << (first + second + third);
return 0;
}