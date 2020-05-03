#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int t;

int main() {

    scanf("%d", &t);
    switch(t) {
        case 1: {
            printf("I love Luogu!");
            break;
        }
        case 2: {
            printf("6 4");
            break;
        }
        case 3: {
            printf("3\n12\n2");
            break;
        }
        case 4: {
            printf("166.667");
            break;
        }
        case 5: {
            printf("15");
            break;
        }
        case 6: {
            cout << sqrt(6 * 6 + 9 * 9);
            break;
        }
        case 7: {
            printf("110\n90\n0");
            break;
        }
        case 8: {
            cout << 3.141593 * 10 << endl;
            cout << 3.141593 * 25 << endl;
            cout << 4 * 3.141593 * 125 / 3.0;
            break;
        }
        case 9: {
            printf("22");
            break;
        }
        case 10: {
            printf("9");
            break;
        }
        case 11: {
            cout << 100 / 3.0;
            break;
        }
        case 12: {
            printf("13\nR");
            break;
        }
        case 13: {
            double v1 = 4 * 3.141593 * 64 / 3.0;
			double v2 = 4 * 3.141593 * 1000 / 3.0;
            cout << (int)pow(v1 + v2, 1 / 3.0);
            break;
        }
        case 14: {
            printf("50");
            break;
        }
    }
    return 0;
}
