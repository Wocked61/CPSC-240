#include <iostream>
#include <iomanip>
using namespace std;

int a[2][4] = { 12,7,10,11,9,6,10,12 };
void display() {
cout << "this array a " << endl;
for (int i = 0; i < 2; i++) {
for (int j = 0; j < 4; j++) {
cout << setw(4) << a[i][j];
}
cout << endl;
}
}
int main() {
int totalGreen = 0;
int totalLarge = 0;
display();
_asm {
mov ecx, 4;
lea esi, a;
xor eax, eax;
sumGreen:
add eax, [esi];
add esi, 4;
loop sumGreen
mov totalGreen, eax;
lea esi, a
xor eax, eax
mov ecx, 2
mov ebx, 8
sumLarge:
mov edx, [esi + ebx];
add eax, edx
add esi, 16;
loop sumLarge;
mov totalLarge, eax;
}
cout << "Total number of Green shirts = " << totalGreen << endl;
cout << "Total number of Large shirts = " << totalLarge << endl;
}