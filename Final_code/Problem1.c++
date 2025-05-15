#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

float pizzaPrice = 3.25f;
float sandwichPrice = 2.10f;
float sodaPrice = 1.25f;
float juicePrice = 1.75f;
float beerPrice = 1.85f;

int main() {
string name;
char foodType, drinkType;
int foodQty, drinkQty;
float foodPrice = 0, drinkPrice = 0, total = 0;
cout << "-------------MENU-------------\n";
cout << "Food\n";
cout << " Pizza (p)....................3.25\n";
cout << " Sandwich(s).................2.10\n";
cout << "Drinks\n";
cout << " Soda(s)......................1.25\n";
cout << " Juice(J).....................1.75\n";
cout << " Beer(b)......................1.85\n";
cout << "What is your name: ";
cin >> name;
cout << "What kind of food in uppercase (P=pizza, S=Sandwich)? ";
cin >> foodType;
cout << "How many? ";
cin >> foodQty;
cout << "What would you like to drink in uppercase (S=soda, J=Juice, B=Beer)? ";
cin >> drinkType;
cout << "How many? ";
cin >> drinkQty;
_asm {
mov al, foodType
cmp al, 'P'
je pizza
cmp al, 'S'
je sandwich
pizza :
fild foodQty
fld dword ptr[pizzaPrice]
fmulp st(1), st(0)
fstp foodPrice
jmp getDrink
sandwich :
fild foodQty
fld dword ptr[sandwichPrice]
fmulp st(1), st(0)
fstp foodPrice
getDrink :
mov al, drinkType
cmp al, 'S'
je soda
cmp al, 'J'
je juice
cmp al, 'B'
je beer
soda :
fild drinkQty
fld dword ptr[sodaPrice]
fmulp st(1), st(0)
fstp drinkPrice
jmp calcTotal
juice :
fild drinkQty
fld dword ptr[juicePrice]
fmulp st(1), st(0)
fstp drinkPrice
jmp calcTotal
beer :
fild drinkQty
fld dword ptr[beerPrice]
fmulp st(1), st(0)
fstp drinkPrice
calcTotal :
fld foodPrice
fadd dword ptr[drinkPrice]
fstp total
}
total *= 1.10f;
cout << fixed << setprecision(2);
cout << name << ", your total bill including 10% tax is $ " << total << endl;
return 0;
}