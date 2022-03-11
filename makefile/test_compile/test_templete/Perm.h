#include <iostream>

template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Perm(T list[], int k, int m)
{
    if (k == m-1)
    {
        for (int i = 0; i < m; i++)
            std::cout << list[i];
        std::cout << std::endl;
    }
    else
    {
        for (int i = k; i < m; i++)
        {
            Swap(list[k],list[i]);
            Perm(list,k+1,m);
            Swap(list[k],list[i]);
        }
    }
}