#include <iostream>
#include <iomanip>
using namespace std;

int allShirts, medShirts, shrtShirts, redShirts;

int i;

int cube[3][3][2] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };

void all_shirts() {
	cout << "The total number of all shirts is " << allShirts << endl;
}

void med_shirts() {
	cout << "The total number of all shirts is " << medShirts << endl;
}

void shrt_shirts() {
	cout << "The total number of all shirts is " << shrtShirts << endl;
}

void red_shirts() {
	cout << "The total number of all shirts is " << redShirts << endl;
}

int main() {

	_asm {
		mov ebx, 0;
		mov i, 0;
		lea esi, [cube];

	loop1:
		cmp i, 18;
		Je done1;
		add ebx, [esi];
		inc i;
		add esi, 4;
		jmp loop1;

	done1:
		mov allShirts, ebx;

		mov ebx, 12;
		mov i, 0;
		lea esi, [cube];

	loop2:
		cmp i, 3;
		Je done2;
		add ebx,[esi];
		add esi, 4;
		add ebx, [esi];
		add esi, 20;
		inc i;
		jmp loop2;

	done2:
		mov medShirts, ebx;


		mov ebx, 0;
		mov i, 0;
		lea esi, [cube];
	loop3:
		cmp i, 9;
		Je done3;
		add ebx, [esi];
		inc i;
		add esi, 8;
		jmp loop3;

	done3:
		mov shrtShirts, ebx;

		mov ebx, 0;
		mov i, 0;
		lea esi, [cube];

	loop4:
		cmp i, 6;
		Je done4;
		add ebx, [esi];
		inc i;
		add esi, 4;
		jmp loop4;

	done4:
		mov redShirts, ebx;

		call all_shirts;
		call med_shirts;
		call shrt_shirts;
		call red_shirts;
	}
}
