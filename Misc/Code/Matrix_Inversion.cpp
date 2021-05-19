#include <iostream>
#include <string.h>

using namespace std;

#define N 5
void invert(int m[N][N]) {
    int temp[N][N];
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            temp[row][col] = m[col][row];
        }
    }
    m = temp;
}

int ascii_to_int() {
     int result = 0;
     char c = getchar();
     while (c != '\n') {
        if (isdigit(c))
            result = result * 10 + (c - '0');
        c = getchar();
     } return result;
}


int main()
{
    int temp = ascii_to_int();
    cout << "Temp: " << temp << endl;

    


}