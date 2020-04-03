#include<iostream>
using namespace std;

#define NUM 100

class Cal {
public:
	int MaxSum(int n, int *array);
};

int Cal::MaxSum(int n, int *array)
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
	Cal c;
	int array[NUM] = { 0 };
	int n;
	cout << "请输入数组个数：" << endl;
	cin >> n;
	cout << "请依次输入数组元素：" << endl;
	for (int i = 1; i <= n; i++)
		cin >> array[i];
	cout << "该数组的最大子段和为：" << c.MaxSum(n, array) << endl;
	return 0;
}
