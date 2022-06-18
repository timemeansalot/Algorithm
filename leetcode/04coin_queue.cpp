#include <cstring>
#include <cstdlib>
#include <stdio.h>
using namespace std;
struct coins
{
	int value;
	int account;
} s[30];
int compare_function(const void *x, const void *y)
{
	struct coins *x1 = (coins *)x;
	struct coins *x2 = (coins *)y;
	return x1->value - x2->value;
}
int main()
{
	int i, N, C, small_coins = 0, sum = 0; // small_coins means the account of coin whose value < C
	scanf("%d %d", &N, &C);
	for (i = 0; i < N; i++)
	{
		int coin_value, coin_account;
		
		// input coin value and account
		scanf("%d %d", &coin_value, &coin_account);
		if (coin_value >= C)
			sum += coin_account;
		else
		{
			s[small_coins].value = coin_value, s[small_coins].account = coin_account;
			small_coins++;
		}
	}
	qsort(s, small_coins, sizeof(s[0]), compare_function);
	while (1)
	{
		int x = C;
		for (i = small_coins - 1; i >= 0; i--)
		{
			if (s[i].account > 0 && x >= s[i].value)
			{
				for (; s[i].account > 0 && x >= s[i].value;)
				{
					x -= s[i].value;
					s[i].account--;
				}
			}
			if (x == 0)
				continue;
		}
		if (x > 0)
		{
			for (i = 0; i < small_coins; i++)
			{
				if (s[i].account > 0 && x <= s[i].value)
				{
					x -= s[i].value;
					s[i].account--;
					break;
				}
			}
		}
		if (x > 0)
			break;
		sum++;
	}
	printf("%d\n", sum);
	return 0;
}
