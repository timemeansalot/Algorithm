#include "headfile.h"

int main()
{
    int T, X, Y;
    int stage = 1;
    string s;
    cin >> T;
    while (stage <= T)
    {
        // input each line
        cin>>X>>Y>>s;
        cout<<"Case #"<<stage<<": "<<X<<" "<<Y<<" "<<s<<endl;


         
        stage++;
    }

    return 0;
}