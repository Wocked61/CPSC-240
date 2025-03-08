#include <iostream>
#include <iomanip>
using namespace std;
float a, b, c, x1, x2, disc;
float neg_one = -1, four = 4, two = 2;
void getInput()
{
    cout << "To see the two real roots of aX^2 + bX + c = 0\nEnter the a, b, and c values: ";
    cin >> a >> b >> c;
}
void displayResults()
{
    cout << "\tX1 = " << x1 << "\tX2 = " << x2 << endl;
}
int main()
{
    __asm
    {
        call getInput;
        solveDiscriminant:
        fld b;
        fld b;
        fmul; // b^2
        fld four;
        fld a;
        fmul;
        fld c;
        fmul;
        fsubp st(1), st(0); // b^2 - 4ac
        fsqrt;
        fstp disc;
        solveX1:
        fld b;
        fld neg_one;
        fmul;
        fld disc;
        fadd;
        fld a;
        fld two;
        fmul; // 2a
        fdiv;
        fstp x1;
        solveX2:
        fld b;
        fld neg_one;
        fmul;
        fld disc;
        fsub;
        fld a;
        fld two;
        fmul;
        fdiv;
        fstp x2;
        call displayResults;
    }
    return 0;
}