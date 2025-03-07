#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;
short SprinklersOn = 0;
short defective = 0;
unsigned short AX = 0x6A2F;
void displayOn()
{
    cout << SprinklersOn << " sprinklers are ON" << endl;
}
void defectiveSpklr()
{
    cout << "Defective sprinklers: ";
    for (int i = 15; i >= 0; i--)
    {
        if (!(AX & (1 << i)))
        {
            cout << (i + 1) << " ";
        }
    }
    cout << endl;
}
int main()
{
    cout << "AX=" << bitset<16>(AX) << endl;
    __asm {
    mov ax, 0x6A2F;
    mov bx, 0;
    mov cx, 0;
    mov si, 16;
    checkBits:
    test ax, 1;
    jz defectiveBit;
    inc bx;
    jmp nextBit;
    defectiveBit:
    mov di, si;
    shl di, 1;
    or cx, di;
    nextBit:
    shr ax, 1;
    dec si;
    jnz checkBits;
    mov SprinklersOn, bx;
    mov defective, cx;
    call displayOn;
    call defectiveSpklr;
    }
    return 0;
}