#include <iostream>
#include <iomanip>
using namespace std;
short custNum, sandTotal, sandNum, drinkNum, sandSize, billTotal, drinkTotal;
short sodaP = 2, waterP = 1, tenP = 3, twelveP = 5;
char drinkType;
void readMenu()
{
 cout << "Question 1" << endl;
 cout << "Convenience Store " << endl;
 cout << "Drinks " << endl;
 cout << "Soda(S) $2 Water(W) $1 " << endl;
 cout << "Sandwiches " << endl;
 cout << "Enter number of customers: ";
 cin >> custNum;
}
void takeOrder()
{
 cout << " How Many Drinks ?";
 cin >> drinkNum;
 cout << " What kind of drink ?";
 cin >> drinkType;
 cout << "How many sandwiches? ";
 cin >> sandNum;
 cout << " What size of sandwich(10 or 12)?";
 cin >> sandSize;
}
void displayTotal()
{
 cout << "Your total is = " << billTotal << endl;
}
int main() {
 _asm {
 call readMenu;
 mov al, drinkType;
 L1:
 call takeOrder;
 cmp drinkType, 'W';
 je Water;
 testW:
 cmp al, 'w'
 jne Soda;
 Water:
 mov ax, drinkNum;
 imul waterP;
 mov drinkTotal, ax;
 jmp sandwich;
 Soda:
 mov ax, drinkNum;
 imul sodaP;
 mov drinkTotal, ax;
 sandwich:
 cmp sandSize, 10;
 jne Twelve;
 Ten:
 mov ax, sandNum;
 imul tenP;
 mov sandTotal, ax;
 jmp Total;
 Twelve:
 mov ax, sandNum;
 imul twelveP;
 mov sandTotal, ax;
 Total:
 mov ax, drinkTotal;
 add ax, sandTotal;
 mov billTotal, ax;
 call displayTotal;
 cmp custNum, 0;
 dec custNum;
 jnz L1;
 }
 return 0;
}
