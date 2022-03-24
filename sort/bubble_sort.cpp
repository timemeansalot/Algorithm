#include <iostream>
#include "display.h"

using namespace std;

/**
 * @brief Do bubble sort
 *
 * @param a Array to be sorted
 * @param length length of array which will be sorted
 * @return int return 1 when finish sorting
 */
int bubble_sourt(int a[], const int length)
{
    bool sorted = 1;
    int temp = 0;
    for (int j = length - 1; j > 0; j--)
    {
        for (int i = 0; i < j ; i++)
        {
            if (a[i] > a[i + 1])
            {
                sorted = 0;
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
        if (sorted == 1)
            break;
    }
    return 1;
}

int main()
{
    int a[5]={3,2,4,7,1};
    display_array(a,5);
    bubble_sourt(a,5);
    display_array(a,5);

    return 0;
}