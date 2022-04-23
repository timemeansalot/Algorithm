#include "headfile.h"
class Solution
{
public:
    int reverse(int x)
    {
        queue<int> q;
        int sign = x >= 0 ? 1 : -1;
        int res = 0;
        bool valid = false;

        // x *= sign;
        while (x)
        {
            q.push(x % 10);
            x /= 10;
        }

        while (q.size())
        {
            if (~valid)
                if (q.front())
                    valid = true;

            if (valid == false)
            {
                q.pop();
            }
            else
            {
                if (res >= INT32_MAX / 10)
                {
                    if (res > INT32_MAX / 10)
                        return 0;
                    else if (res == INT32_MAX / 10 && q.front()>7)
                        return 0;
                }
                if(res<=INT32_MIN/10)
                {
                    if(res<INT32_MIN/10)
                    return 0;
                    else if(res==INT32_MIN/10&&q.front()<-4)
                    return 0;
                }
                res = res * 10 + q.front();
                q.pop();
            }
        }
        // res *= sign;
        return res;
    }
};

int main()
{

    cout << int(0x7fffffff) << " " << int(0x7fffffff) - 5 << endl;
    cout << int(0x80000001) << " " << int(0x80000001) + 5 << endl;
    int out = 0, in = -321;
    cout << INT32_MAX << "  " << INT32_MIN << endl;
    cout << INT32_MAX / 10 << " " << INT32_MIN / 10 << endl;
    Solution sol;
    cout << sol.reverse(in) << endl;
}

//-214748364
//-2147483648
