#include<iostream>

using namespace std;

/**
 * @brief display all elements in array
 * 
 * @tparam T Data type
 * @param a array to be displayed
 * @param length array length
 */
template <typename T>
void display_array(T a[],const int length)
{
    cout<<"array data is : ";
    for(int i=0;i<length;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}