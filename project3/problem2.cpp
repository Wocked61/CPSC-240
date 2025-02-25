#include <iostream>
#include <iomanip>
using namespace std;
short score, total, counter, avg, rem;
void promptScore()
{
cout << "Input score (-1 to exit): ";
cin >> score;
}
int main()
{
total = 0;
score = 0;
counter = 0;
__asm {
mov ax, total;
Prompt:
call promptScore;
cmp score, -1;
je CalculateAvg;
jne UseScore;
UseScore:
mov ax, score;
add total, ax;
inc counter;
jmp Prompt;
CalculateAvg:
mov ax, total;
cwd;
idiv counter;
mov avg, ax;
mov rem, dx;
}
cout << "Your average is: " << avg << "\nWith remainder: " << rem << endl;
return 0;
}
