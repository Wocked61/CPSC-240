#include <iostream>
#include <iomanip>
using namespace std;
float a, b, c, h, len, width, tArea, tPeri, rArea, rPeri;
float half = 0.5;
void inpt()
{
    cout << "Enter the values of a,b,c and h for the triangle : ";
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> h;
    cout << endl;
}
void LnW()
{
    cout << "Enter the length and the width of the rectangle: ";
    cin >> len;
    cin >> width;
    cout << endl;
}
void output()
{
    cout << "Triangle" << endl;
    cout << " Area.........................................." << fixed << showpoint << setprecision(2) << tArea << endl;
    cout << " Perimeter................................" << tPeri << endl;
    cout << "Rectangle" << endl;
    cout << " Area.........................................." << rArea << endl;
    cout << " Perimeter................................" << rPeri << endl;
}
int main()
{
    __asm {
        call inpt;
        call LnW;
        fld h; //[h]
        fld c; //[b,h]
        fmul; // b * h
        fld half; //[0.5,bh]
        fmul; //
        fstp tArea;
        fld a;
        fld b;
        fld c;
        fadd;
        fadd;
        fstp tPeri;
        fld len;
        fld width;
        fmul;
        fstp rArea;
        fld len;
        fld len;
        fadd;
        fld width;
        fld width;
        fadd;
        fadd;
        fstp rPeri;
        call output;
    }
    return 0;
}