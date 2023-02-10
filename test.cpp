#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int main()
{
	int a[] = {7, 5, 4, 6, 8, 9};  //数组长度是6
	sort(a, a + 6, cmp);   //自定义比较函数
	for (int i = 0; i < 6; i ++)
		cout << a[i] << ' ';
	return 0;
}
