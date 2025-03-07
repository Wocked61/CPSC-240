#include <iostream>
#include <iomanip>
using namespace std;
int hexValue, total, i, tempValue;
void promptUser()
{
    cout << "Input a 4-digit hex value to test validity: ";
    cin >> hex >> hexValue;
}
void printValid()
{
    cout << endl
         << hex << uppercase << hexValue << " ";
    cout << "is a valid ID for the family" << endl;
}
void printInvalid()
{
    cout << endl
         << hex << uppercase << hexValue << " ";
    cout << "is NOT a valid ID for the family" << endl;
}
void printTest()
{
    cout << i << "\t" << dec << total << "\t" << hex << hexValue << "\t" << tempValue << endl;
}
int main()
{
    total = 0; // Initialize total before use
    __asm
    {
        call promptUser; // Get user input
        mov ebx, hexValue; // Copy PIN value into ebx
        mov i, 0; // Initialize i
        mov total, 0; // Initialize total
        Total:
        cmp i, 4;
        je TestValidity;
        mov eax, ebx;
        and eax, 0xF; // Extract last hex digit
        add total, eax; // Add to total
        shr ebx, 4; // Shift right to process the next digit
        inc i;
        // call printTest;
        jmp Total;
        TestValidity:
        mov eax, total;
        and eax, 1;
        jnz Odd;
        jmp Valid;
        Odd:
        call printInvalid;
        jmp Done;
        Valid:
        call printValid;
        Done:
    }
    return 0;
}