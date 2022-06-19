#include <iostream>
#include <string>

using namespace std;

const int max_length = 1001;
const int max_value = 0x3fffffff;
// variables
int T = 0; // amount of all test cases
int test_case = 0;
int ab_value = 1, ba_value = 2;
string s = "";
int s_length = 0;
int min_value = 0;
int dp[max_length][2];
int main()
{

    cin >> T;
    while (test_case < T)
    {
        test_case++;

        // reset dp array to 0
        for (int i = 0; i < max_length; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 0;
        }

        // test if input data correctly
        cin >> ab_value >> ba_value >> s;
        s_length = s.length();
        // cout << "input data: " << ab_value << " " << ba_value << " " << s << endl;

        // init dp
        if (s[0] == '?')
        {
            dp[0][0] = 0;
            dp[0][1] = 0;
        }
        else if (s[0] == 'A')
        {
            dp[0][0] = 0;
            dp[0][1] = max_value;
        }
        else if (s[0] == 'B')
        {
            dp[0][0] = max_value;
            dp[0][1] = 0;
        }

        // calculate dp
        for (int i = 1; i < s_length; i++)
        {
            if (s[i] == '?')
            {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + ba_value);
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + ab_value);
            }
            else if (s[i] == 'A')
            {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + ba_value);
                dp[i][1] = max_value;
            }
            else if (s[i] == 'B')
            {
                dp[i][0] = max_value;
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + ab_value);
            }
        }


        for(int i=0;i<s_length;i++)
        {
            cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }
        // output result
        cout << "Case #" << test_case << ": " << min(dp[s_length-1][0],dp[s_length-1][1]) << endl;
    }

    return 0;
}