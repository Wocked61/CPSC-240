#include <iostream>
#include <iomanip>
using namespace std;

unsigned int eaxVal = 0;
unsigned char john, mimi, kia, bill;
const char* winner;

void displayVotes() {
cout << "John " << (int)john << " votes" << endl;
cout << "Mimi " << (int)mimi << " votes" << endl;
cout << "Kia " << (int)kia << " votes" << endl;
cout << "Bill " << (int)bill << " votes" << endl;
cout << "The winner is " << winner << "." << endl;
}
int main() {
const char* nameJ = "John";
const char* nameM = "Mimi";
const char* nameK = "Kia";
const char* nameB = "Bill";
_asm {
mov eax, 11001111100010001111111110011011b
mov ebx, eax
shr ebx, 24
mov john, bl
mov ebx, eax
shr ebx, 16
and bl, 0FFh
mov mimi, bl
mov ebx, eax
shr ebx, 8
and bl, 0FFh
mov kia, bl
mov ebx, eax
and bl, 0FFh
mov bill, bl
mov al, john
mov esi, nameJ
mov bl, mimi
cmp bl, al
jbe notM
mov al, bl
mov esi, nameM
notM :
mov bl, kia
cmp bl, al
jbe notK
mov al, bl
mov esi, nameK
notK :
mov bl, bill
cmp bl, al
jbe notB
mov al, bl
mov esi, nameB
notB :
mov winner, esi
}
displayVotes();
return 0;
}