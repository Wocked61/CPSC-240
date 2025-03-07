#include <iostream>
#include <iomanip>
using namespace std;

int allShirts = 0, mediumShirts = 0, blueShirts = 0;
int b = 0,i=0;

int shirts[4][4] = {10,20,30,40,
                    20,10,40,30,
                    5,15,20,25,
                    30,25,20,15};

void displayAll() {
    cout << "The number of all shirts are " << allShirts << endl;
}

void displayMed() {
    cout << "The number of medium shirts are " << mediumShirts << endl;
}

void displayBlue() {
    cout << "The number of blue shirts are " << blueShirts << endl;
}

int main()
{
    
    _asm {
        mov eax, 0;//loop2
        mov dx, 0; //loop2
        lea esi, [shirts];


    loop2:
        cmp dx, 16;
        Je done;
        add eax, [esi];
        inc dx;
        add esi, 4;
        Jmp loop2;



    done:
        mov allShirts, eax;


        mov eax, 0;
        mov dx, 0;
        lea esi, [shirts];
        add esi, 32;


    loop3:
        cmp dx, 4;
        Je done2;
        add eax, [esi];
        inc dx;
        add esi, 4;
        Jmp loop3;


    done2:
        mov blueShirts, eax;

        mov eax, 0;
        mov dx, 0;
        lea esi, [shirts];
        add esi, 4;

    loop4:
        cmp dx, 4;
        Je done3;
        add eax, [esi];
        inc dx;
        add esi, 16;
        Jmp loop4;

    done3:
        mov mediumShirts, eax;

        call displayAll;
        call displayMed;
        call displayBlue;
    }
    return 0;
}
