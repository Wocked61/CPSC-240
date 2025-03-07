#include <iostream>
using namespace std;
int a[5] = {9, 3, 22, 8, 1};
int length = 5;
int loop_end = length - 1;
void printArr(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << " " << arr[i];
    }
}
int main()
{
    cout << "Original Array a[]:\t";
    printArr(a, length);
    __asm
    {
        mov ecx, 0; // ecx is i
        outer_loop:
        cmp ecx, loop_end;
        jge done;
        mov edx, 0; // edx is j
        inc ecx;
        inner_loop:
        cmp edx, loop_end;
        jge outer_loop;
        // if comparison
        lea esi, [a];
        mov eax, [esi + edx * 4];
        mov ebx, [esi + edx * 4 + 4];
        cmp eax, ebx;
        jle back_to_inner_loop;
        mov[esi + edx * 4], ebx;
        mov[esi + edx * 4 + 4], eax;
        back_to_inner_loop:
        inc edx;
        jmp inner_loop;
        done:
    }
    cout << "\nSorted Array a[]:\t";
    printArr(a, length);
    return 0;
}