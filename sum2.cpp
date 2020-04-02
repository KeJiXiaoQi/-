#include<iostream>
using namespace std;

#define NUM 100

int MaxSum(int n, int *array)
{
	int maxsum = 0, nowmax = 0;
	for (int i = 1; i <= n; i++)
	{
		if (nowmax > 0) nowmax += array[i];
		else nowmax = array[i];
		if (nowmax > maxsum) maxsum = nowmax;
	}
	return maxsum;
}

int main()
{
	int array[NUM] = { 0 };
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> array[i];
	cout << MaxSum(n, array) << endl;
	return 0;
}