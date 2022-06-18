#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct coin
{
    int value;
    int account;
} s[30];
int compare_function(const void *x, const void *y)
{
    struct coin *x1 = (coin *)x;
    struct coin *x2 = (coin *)y;
    return x1->value - x2->value;
}
int main()
{
    int i, N, C, coin_types = 0, ans = 0;
    cin >> N >> C;
    for (i = 0; i < N; i++)
    {
        int value, account;
        cin >> value >> account;
        if (value >= C) // if coin value > C, just add account to ans
            ans += account;
        else
        {
            s[coin_types].value = value, s[coin_types].account = account;
            coin_types++;
        }
    }
    qsort(s, coin_types, sizeof(s[0]), compare_function);

    // for (int i = 0; i < coin_types; i++)
    // {
    //     printf("value: %d, amount: %d\n", s[i].value, s[i].account);
    // }

    for (i = coin_types - 1; i >= 0; i--)
    {
        int times = C / s[i].value;
        int need = C - s[i].value * times;
        int bucks = s[i].account / times;
        int remain = s[i].account - bucks * times;
        if (need != 0)
        {
            for (int k = 0; k < i; k++)
            {
                if (s[k].value < need)
                    continue;

                if (s[k].account >= bucks)
                {
                    s[k].account -= bucks;
                    s[i].account -= bucks * times;
                    ans += bucks;
                    bucks = 0;
                    break;
                }
                else
                {
                    bucks -= s[k].account;
                    ans += s[k].account;
                    s[k].account = 0;
                }
            }

            ans += (bucks / (times + 1));
        }
        else
        {
            ans += bucks;
            s[i].account -= times * bucks;
        }

        if (remain != 0)
        {
            // output
            // for(int k=0;k<coin_types;k++)
            // {
            //     printf("value: %d, account: %d\n",s[k].value,s[k].account);
            // }
            if (i == 0)
                break;

            int goal = C - remain * s[i].value;
            while (goal)
            {
                for (int k = i - 1; k >= 0; k--)
                {
                    while (goal >= s[k].value && s[k].account)
                    {
                        goal -= s[k].value;
                        s[k].account--;
                    }
                }
            }
            if (goal == 0)
                ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
