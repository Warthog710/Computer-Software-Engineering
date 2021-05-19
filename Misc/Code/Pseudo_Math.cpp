//Program written by Quinn Roemer 11/23/2019

//This code performs common mathmatical operations using only assignments, increment/decrement, and comparisons.

//KNOWN ISSUES:
//Overflow is not properly detected and dealt with. The input ranges have been modified to prevent overflow.

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int add(int x, int y)
{
    //Increment X, Y times.
    for (int count = 0; count < y; count++)
    {
        x++;
    }

    return x;
}

int recursiveAdd(int x, int y)
{
    if (y <= 0)
    {
        return x;
    }
    else
    {
        x++;
        y--;
        recursiveAdd(x, y);
    }    
}

int sub (int x, int y)
{
    //Decrement X, Y times.
    for (int count = 0; count < y; count++)
    {
        x--;
    }

    return x;
}

int recursiveSub(int x, int y)
{
    if (y <= 0)
    {
        return x;
    }
    else
    {
        x--;
        y--;
        recursiveSub(x, y);
    }    
}

int mult (int x, int y)
{
    //Set a temp value
    int temp = 0;

    //For Y times, increment temp, X times.
    for (int count = 0; count < y; count++)
    {
        for (int index = 0; index < x; index++)
        {
            temp++;
        }
    }

    //Return the value in temp.
    return temp;
}

int recursiveMult(int x, int y, int orig)
{
    if (y <= 1)
    {
        return x;
    }
    else
    {
        x = recursiveAdd(orig, x);
        y--;
        recursiveMult(x, y, orig);
    }

}

int divide(int x, int y)
{
    int count = 0;

    //Any number goes into 0, 0 times. Thus, return 0.
    if (x == 0)
    {
        return 0;
    }

    //Catch divide by zero error.
    if (y == 0)
    {
        return -1;
    }


    while(x > 0)
    {
        //Decrement X, Y times.
        for (int index = 0; index < y; index++)
        {
            x--;
        }

        //If the value in X is greater than 0. Increment the counter.
        if (x >= 0)
        {
            count++;
        }
    }
    
    //Return the count.
    return count;
}

int recursiveDiv(int x, int y, int count)
{
    if (y == 0)
    {
        return -1;
    }

    if (x < y)
    {
        return count;
    }
    else
    {
        x = recursiveSub(x, y);
        count++;
        recursiveDiv(x, y, count);
    }
    
    
}

int mod(int x, int y)
{
    int count = 0;

    //When x is less than y, x should be returned.
    if (x < y)
    {
        return x;
    }

    while(x > 0)
    {
        //Decrement X, Y times.
        for (int index = 0; index < y; index++)
        {
            x--;
        }

        //If the remaining value in X is less than Y. Return X.
        if (x < y)
        {
            return x;
        }
    }

    //Else, if the loop terminates, the mod must be zero.
    return 0;
}



int factorial(int factor)
{
    //Set the temp value to factor. This will hold the original value.
    int temp = factor;
    //Decrement factor by one. This is because the first term is calculated by N * (N - 1).
    factor--;

    //If the factorial is 0. Return 1.
    if (temp == 0)
    {
        return 1;
    }

    //Multiply the value in factor, by the temp value, until count is greater than 0.
    for (int count = factor; count > 0; count--)
    {
        temp = mult(temp, factor);
        factor--;        
    }

    return temp;
}

int exp(int x, int expo)
{
    //Save orignal value and set a temp variable.
    int orig = x;
    int temp = 0;

    //If the exponent is 0. Return 1.
    if (expo == 0)
    {
        return 1;
    }

    //If the exponent is 1. Return x.
    if (expo == 1)
    {
        return x;
    }

    //Multiply X times the orignal value expo - 1 times.
    for (int count = 0; count < expo - 1; count++)
    {
        temp = mult(x, orig);

        x = temp;      

    }

    //Return the calculated value.
    return temp;
}

int main()
{
    srand(time(NULL));
    int x, y;

    //PLEASE NOTE!!!
    //The modulus operation done here is only for testing purposes.
    //It does not break the rules by which this program runs.
    //The implemented modolus does work for this operation, but it is slow... as intended...

    x = rand() % 1000;
    y = rand() % 1000;
    cout << x << " + " << y << " = " << add(x, y) << endl;

    x = rand() % 1000;
    y = rand() % 1000;
    cout << x << " - " << y << " = " << sub(x, y) << endl;

    x = rand() % 1000;
    y = rand() % 1000;
    cout << x << " * " << y << " = " << mult(x, y) << endl;

    x = rand() % 1000;
    y = rand() % 1000;
    cout << x << " / " << y << " = " << divide(x, y) << endl;

    x = rand() % 1000;
    y = rand() % 1000;
    cout << x << " % " << y << " = " << mod(x, y) << endl;

    x = rand() % 10;
    y = rand() % 10;
    cout << x << "^" << y << " = " << exp(x, y) << endl;

    x = rand() % 11;
    cout << x <<"! = " << factorial(x) << endl;

    cout << "rAdd = " << recursiveAdd(5, 5) << endl;
    cout << "rSub = " << recursiveSub(5, 5) << endl;
    cout << "rMult = " << recursiveMult(23, 39, 23) << endl;
    cout << "rDiv = " << recursiveDiv(12, 5, 0) << endl;
}