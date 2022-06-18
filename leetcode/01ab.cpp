#include <iostream>
#include <string>

using namespace std;

// variables
int T = 0; // amount of all test cases
int test_case = 0;
int ab_value = 1, ba_value = 2;
string s = "";
int min_value = 0;
int left_index = 0, right_index = 0;

void modify_string()
{
    int left_index = 0, right_index = 0;
    int s_length = s.length();
    char left_char = 'C', right_char = 'C'; // left char and right char of ??? sebset
    char replace_char = 'A';                // replace ? with this char

    // find all subset of ???? in s: ?????= s[left_index, right_index)
    while (right_index < s_length)
    {
        // find first ? in subset
        while (s[right_index] != '?' && right_index <= s_length)
        {
            right_index++;
        }
        left_index = right_index;

        // find last ? in setset
        while (s[right_index] == '?' && right_index <= s_length)
        {
            right_index++;
        }

        // output current subset ??? for test
        // for (int i = left_index; i < right_index; i++)
        //     cout << s[i];
        // cout << endl;

        // modify the subset accoring to its left value and right value
        if (ab_value >= 0 && ba_value >= 0)
        {
            // decide left_char, right_char and replace_char
            if (left_index == 0)
                left_char = 'C';
            else
                left_char = s[left_index - 1];
            if (right_index == s_length)
                right_char = 'C';
            else
                right_char = s[right_index];

            if (left_char == 'A' && right_char == 'B')
                replace_char = 'A';
            else if (left_char == 'B' && right_char == 'A')
                replace_char = 'B';
            else if (left_char == 'A' || right_char == 'A')
                replace_char = 'A';
            else
                replace_char = 'B';
            // cout replace char for test
            // cout << "left_index: " << left_index << ", right_index: " << right_index << ", replace char: " << replace_char << endl;

            // change subset ??? into replace char
            for (int i = left_index; i < right_index; i++)
                s[i] = replace_char;
        }
    }

    // cout s after modify
    // cout << "s after: " << s << endl;
}

/**
 * @brief calculate value of s accordingto AB and BA in s.
 *
 */
void calculate_string_value()
{
    // init min_value to 0
    min_value = 0;

    // calculate min_value for current s
    for (int i = 1; i <= s.length(); i++)
    {
        if (s[i - 1] == 'A' && s[i] == 'B')
        {
            min_value += ab_value;
        }
        else if (s[i - 1] == 'B' && s[i] == 'A')
        {
            min_value += ba_value;
        }
    }
}
int main()
{

    // while (1)
    // {
    //     cin >> s;
    //     modify_string();

    //     min_value = 0; // init min_value
    //     calculate_string_value();
    //     cout << "min_value= " << min_value << endl;
    // }

    cin >> T;
    while (test_case < T)
    {
        test_case++;

        // test if input data correctly
        cin >> ab_value >> ba_value >> s;
        // cout << "input data: " << ab_value << " " << ba_value << " " << s << endl;

        // replace ? in string s
        modify_string();

        // calculate miminum value of string s after modify
        calculate_string_value();

        // output result
        cout << "Case #" << test_case << ": " << min_value << endl;
    }

    return 0;
}