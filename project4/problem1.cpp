#include <iostream>
#include <iomanip>
using namespace std;
short numOfPrinters, numOfFloppy, sizeOfRam;
// Q1 functions
void displayPrinters()
{
    cout << " The number of printers connected = " << numOfPrinters << endl;
}
void displayFloppy()
{
    cout << " The number of floppy disk drives = " << numOfFloppy << endl;
}
void displayRam()
{
    cout << " The size of the RAM = " << sizeOfRam << "GB RAM" << endl;
}
// Q1
int main()
{
    _asm {
        // Q1a
        mov ax, 1100111010011100b; // ax = state of register
        mov bx, 1100000000000000b; // want to compare the first 2 bits
        and ax, bx;                // ax & bx
        shr ax, 14;                // shift ax 14 to the right
        mov numOfPrinters, ax;     // numOfPrinters = ax
        call displayPrinters;     // display the number of printers
        // Q1b
        mov ax, 1100111010011100b;       // ax = state of register
        mov bx, 0000000011000000b; // want to compare bits 7 and 8
        and ax, bx;
        shr ax, 6;
        mov numOfFloppy, ax;       // numOfFloppy = ax
        add numOfFloppy, 1;        // numOfFloppy = numOfFloppy + 1
        call displayFloppy;       // display the number of floppy disks
        // Q1c
        mov ax, 1100111010011100b;               // ax = state of register
        mov bx, 0000000000001100b;         // want to compare bits 3 and 4
        and ax, bx;                        // ax & bx
        shl ax, 12;                        // shift ax 12 to the left
        shr ax, 14;                        // shift ax 14 to the right
        cmp ax, 0000000000000000b;         // see if all are 0
        Jne testRAM;                      // if not all 0, jump to testRAM
        mov sizeOfRam, 16;                 // else, sizeOfRAM = 16
        Jmp displayR;                     // go to end (displayR)
        testRAM:
        cmp ax, 0000000000000001b; // see if bit 3 was 1 and bit 4 was 0
        Jne test48;                       // if not equal, jump to test48
        mov sizeOfRam, 32;                 // else, sizeOfRAM = 32
        Jmp displayR;                     // go to end (displayR)
        test48:
        cmp ax, 0000000000000010b;  // see if bit 3 was 1 and bit 4 was 1
        Jne elseR;                        // if not equal, go to elseR
        mov sizeOfRam, 48;                 // else, sizeOfRAM = 48
        Jmp displayR;                     // go to end (displayR)
        elseR:
        mov sizeOfRam, 64;           // sizeOfRAM = 64
        displayR:
        call displayRam;         // display the RAM
    }
    return 0;
}