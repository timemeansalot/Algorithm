#include "iostream"
#include "display.h"

using namespace std;

/**
 * @brief Perform select sort based on change items
 *
 * @tparam T template typename
 * @param a array which needed to be sort
 * @param length length of array
 * @return int return 1 if finish sort
 */
template <typename T>
int select_sort(T a[], const int length)
{
    int index = 0;
    T temp=0;
    for (int i = 0; i < length; i++)
    {
        index = i;
        for (int j = i; j < length; j++)
        {
            if (a[j] < a[index])
                index = j;
        }
        temp=a[i];
        a[i]=a[index];
        a[index]=temp;
    }
    return 1;
}
int main()
{
    const int length=5;
    int a[length]={33,2,13,24,7};
    display_array(a,length);
    select_sort(a,length);
    display_array(a,length);

    return 0;
}