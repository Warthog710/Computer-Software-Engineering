#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace std;

#define MAX 32767
#define MAXby10 3276 // i.e. integer divide 32767 / 10 = 3276 . . .


int a2i1();


int main(void)
{
    
   int test = a2i1();

   /*int test = INT32_MIN; //Max 32bit negative value.
   cout << "Test: " << test << endl;
   test = -test; //Negate
   cout << "Test: " << test << endl;*/

   


}


int a2i1( void )
{ // a2i
int number = 0;
int neg = 0;
char c = '1';
if ( c == '-' ) 
{
   neg = 1;
   c = getchar();
}
else if ( c == '+' ) 
{
   c = getchar(); // keep neg = 0
} //end if
while ( isdigit( c ) ) 
{
    if ( number > MAXby10 ) 
    { 
        printf( "Overflow 1. max = %d\n", MAX );
    }
    else if ( number == MAXby10 ) 
    { 
        if ( c == '9' ) 
        {
            printf( "Overflow 2. max = %d\n", MAX );
        }
        else if ( c == '8' ) 
        {
            if ( neg ) 
            { 
                number = -32768;
            }
            else
            { 
                printf( "Overflow 3. max = %d\n", MAX );
            } //end if 
        }
        else
        {
            number = number * 10 + ( c - '0' ); 
        } //end if
    }
    else
    {
        number = number * 10 + ( c - '0' );
    } //end if

    c = getchar();
} //end while
 return neg ? -number : number;
 
 } //end a2i