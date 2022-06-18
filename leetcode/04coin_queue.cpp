#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
struct lin
{
	int a;
	int b;
} s[30];
int cmp(const void *x, const void *y)
{
	struct lin *x1 = (lin *)x;
	struct lin *x2 = (lin *)y;
	return x1->a - x2->a;
}
int main()
{
	int i, N, C, lin = 0, sum = 0;
	cin >> N >> C;
	for (i = 0; i < N; i++)
	{
		int l1, l2;
		cin >> l1 >> l2;
		if (l1 >= C)
			sum += l2;
		else
		{
			s[lin].a = l1, s[lin].b = l2;
			lin++;
		}
	}
	qsort(s, lin, sizeof(s[0]), cmp);
	while (1)
	{
		int x = C;
		for (i = lin - 1; i >= 0; i--)
		{
			if (s[i].b > 0 && x >= s[i].a)
			{
				for (; s[i].b > 0 && x >= s[i].a;)
				{
					x -= s[i].a;
					s[i].b--;
				}
			}
			if(x==0)
			continue;
		}
		if (x > 0)
			for (i = 0; i < lin; i++)
			{
				if (s[i].b > 0 && x <= s[i].a)
				{
					x -= s[i].a;
					s[i].b--;
					break;
				}
			}
		if (x > 0)
			break;
		sum++;
	}
	cout << sum;
	return 0;
}
