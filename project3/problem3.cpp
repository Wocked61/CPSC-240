#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
int upper, lower;
char c;
void input() {
 cout << "Enter a sentence: ";
}
void readchar() {
 c = cin.get();
}
void displayOut() {
 cout << "Number of upper case = " << upper << endl;
 cout << "Number of lower case = " << lower << endl;
}
int main() {
 _asm {
 calculate:
 call input;
 whileLoop:
 call readchar
 cmp c, '\n';
 Je exitLoop;
 cmp c, 64;
 Jle whileLoop;
 cmp c, 90;
 Jle upperCount;
 cmp c, 123;
 Jge whileLoop;
 cmp c, 97;
 Jge lowerCount;
 Jmp exitLoop;
 upperCount:
 inc upper;
 Jmp whileLoop;
 lowerCount:
 inc lower;
 Jmp whileLoop;
 exitLoop:
 call displayOut;
 }
 return 0;
}