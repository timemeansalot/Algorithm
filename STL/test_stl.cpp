#include <vector>
#include <iostream>
using namespace std;

/**
 * @brief show all items in a vector, test iteraotr of vecotr
 * 
 * @tparam T type of elements in vector
 * @param v vecotr to be shown
 */
template <typename T>
void show_vector(vector<T> const &v) // pass by reference, const means can not change value of v
{
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << endl;
    }
}

template<typename T>
void vecotr_capacity(vector<T> const &v)
{
    cout<<"capacity: "<<v.capacity()<<endl;
    cout<<"size: "<<v.size()<<endl;
    cout<<"max_size: "<<v.max_size()<<endl;
    if(v.empty())
        cout<<"empty"<<endl;
    else
        cout<<"not empty"<<endl;
}
template<typename T>
void vecotr_access_data(vector<T> const &v)
{
    cout<<"first item: "<<v.front()<<endl;
    cout<<"last item: "<<v.back()<<endl;
    cout<<"first item: "<<v[0]<<endl;
    cout<<"first item: "<<v.at(0)<<endl;
    // get a pointer to the first data
    const T *p=v.data();
    cout<<"first data: "<<*p<<endl;
}

int main()
{
    cout << "test vector" << endl;
    vector<int> v;
    for (int i = 0; i < 6; i++)
        v.push_back(i);
//    show_vector(v);
//    vecotr_capacity(v);
    vecotr_access_data(v);
    return 0;
}