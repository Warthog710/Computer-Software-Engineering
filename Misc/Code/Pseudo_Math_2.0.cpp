//Program written by Quinn Roemer 11/23/2019

//This code performs common mathmatical operations using only assignments, increment/decrement,
//comparisons, and function calls.

//KNOWN ISSUES:
//Overflow is not properly detected and dealt with. The input ranges have been modified to prevent overflow.

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int recursiveAdd(int x, int y)
{
    //If y equals 0, return x.
    if (y == 0)
    {
        return x;
    }
    else
    {
        //If y is less than zero, decrement x and increment y.
        if (y < 0)
        {
            x--;
            y++;
        }
        //Else y must be greater than zero, increment x, decrement y.
        else
        {
            x++;
            y--;
        }

        //Recursive call.
        recursiveAdd(x, y);        
    }    
}

int recursiveSub(int x, int y)
{
    //If y equals zero, return x.
    if (y == 0)
    {
        return x;
    }
    else
    {
        //If y is less than zero, increment x and y.
        if (y < 0)
        {
            x++;
            y++;
        }
        //Else y must be greater than zero. Decrement x and y.
        else
        {
            x--;
            y--;
        }

        //Recursive call.
        recursiveSub(x, y);        
    }    
}

/*Another Implemenation
int recursiveSub(int x, int y)
{
    return recursiveAdd(x, -y);
}*/

//Function mostly provided by Professor Mayer.
int recursiveMult(int x, int y)
{
    //If y is 0, x times y must equal 0.
    if (y == 0)
    {
        return 0;
    }
    //If y is 1, x times y must equal x.
    if (y == 1)
    {
        return x;
    }
    //If y is less than zero...
    else if (y < 0)
    {
        //Negate the return value and y.
        return -recursiveMult(x, -y);
    }
    else
    {
        //Decrement the y value.
        y--;

        //return the addition of x and the return of mult.
        return recursiveAdd(x, recursiveMult(x, y));
    }   
}

//Main function to execute.
int main()
{
    //Generating random numbers.
    srand(time(NULL));
    int x, y;

   //Testing add 
    x = rand() % 100;
    y = rand() % 100;
    cout << x << " + " << y << " = " << recursiveAdd(x, y) << endl;

    //Testing sub
    x = rand() % 100;
    y = rand() % 100;
    cout << x << " - " << y << " = " << recursiveSub(x, y) << endl;
    
    //Testing multiplication
    x = rand() % 100;
    y = rand() % 100;
    cout << x << " * " << y << " = " << recursiveMult(x, y) << endl;
}