#include <iostream>
#include <bitset>
using namespace std;
short floorNum = 0;
void printFloor()
{
    cout << " " << floorNum;
}
int main()
{
    unsigned short AX = 0b1001000100001100;
    cout << "AX = " << bitset<16>(AX) << endl;
    cout << "Elevator will stop at floors no.";
    __asm {
    mov cx, 16;
    mov dx, AX;
    check_floors:
    mov bx, dx;
    and bx, 1;
    jz skip;
    mov floorNum, cx;
    call printFloor;
    skip:
    shr dx, 1;
    dec cx;
    jnz check_floors;
    }
    return 0;
}