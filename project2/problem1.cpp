#include <iostream>
#include <iomanip>
using namespace std;
int main1()
{
//Q1
int bill, bill2, finalBill;
int drink, sand, drinkP = 2, sandP = 4;
cout << setfill('-') << setw(8) << '-' << "MENU" << setfill('-') << setw(8) << '-' << endl;
cout << "Drinks" << setfill('.') << setw(7) << '.' << drinkP << endl;
cout << "Sandwhiches" << setfill('.') << setw(7) << '.' << sandP << endl;
cout << "How many drinks? ";
cin >> drink;
cout << "How many sandwhiches? ";
cin >> sand;
_asm {
mov eax, drinkP;
imul eax, drink;
mov bill, eax;
mov eax, sandP;
imul eax, sand;
mov bill2, eax;
mov eax, bill;
add eax, bill2;
mov finalBill, eax;
}
cout << "Your total bill today is: " << finalBill << endl;
return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;