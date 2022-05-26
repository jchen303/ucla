#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Enter a strictly positive integer: " << endl;
    unsigned int x; cin >> x;
    
    if (x == 0)
    {
        cout << "This number is not STRICTLY positive" << endl;
        return 0;
    }
    
    cout << "The binary representation of " << x << " is given by ";
  
    int exp = 0;
    
    while (x >= pow(2, exp + 1)) // checks to see if the number is still greater
    {               // than or equal to the next power of 2 (if it can still fit
        for (int temp = x; temp > 0; --temp) // the pwr inside the number)
        {
            if ((temp % (static_cast<int>(pow(2, exp + 1))) == 0))
            { // checks all numbers of input to see if a power of 2 fits in it
                ++exp;  // need to cast bc mod won't work w/o it
                break;
            }
        }
    }

    while (exp > -1)
    {
        if (x / static_cast<int>(pow(2, exp)) == 1)
        {
            cout << "1"; // if it has a 2^that power, print 1
            x -= pow(2, exp); // and deduct that number from x
        }
        else
        {
            cout << "0";
        }
        
        --exp;
    }

    cout << endl;
    
    return 0;
}
