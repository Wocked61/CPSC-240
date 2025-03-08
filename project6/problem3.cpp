#include <iostream>
#include <iomanip>
using namespace std;
float drinks, sandwhiches, drinksPrice, sandsPrice, totalBill;
char drinkType;
int sandSize;
const float soda = 2.25, water = 1.75, tenInch = 3.45, twelveInch = 5.25;
void getInput()
{
    cout << "How many drinks? ";
    cin >> drinks;
    cout << "What kind of drink (S = soda, W = water)? ";
    cin >> drinkType;
    cout << "How many Sandwhiches? ";
    cin >> sandwhiches;
    cout << "What size of sandwhich (10/12 inches)? ";
    cin >> sandSize;
}
void printBill()
{
    cout << "Your total bill = $" << totalBill << endl;
}
int main()
{
    __asm
    {
call getInput;
fld drinks;
cmp drinkType, 'S';
jne Water;
Soda:
fld soda;
jmp TestSand;
Water:
fld water;
TestSand:
fmul;
fstp drinksPrice;
fld sandwhiches;
cmp sandSize, 12;
je FootLong;
jne TenInch;
FootLong:
fld twelveInch;
jmp Done;
TenInch:
fld tenInch;
Done:
fmul;
fstp sandsPrice;
fld sandsPrice;
fld drinksPrice;
fadd;
fstp totalBill;
call printBill;
    }
    return 0;
}