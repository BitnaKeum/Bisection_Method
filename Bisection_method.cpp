#include <stdio.h>
#include <math.h>

double f(double x) { return x * x * x + 4 * x * x - 10; } // 주어진 함수
int min(int a, int b); // 두 값 중 더 작은 값을 반환하는 함수

int main()
{
	double an = 1.0;
	double bn = 2.0;
	double TOL = 0.0005;
	int n = min(20, ceil(log((bn - an) / TOL) / log(2.0)));

	printf(" n      an           bn           pn           f(pn)\n");

	for (int i = 1; i <= n; i++)	// n번 반복
	{
		double pn = (an + bn) / 2.0;	// pn은 an와 bn의 중간 값

		printf("%2d %.10f %.10f %.10f ", i, an, bn, pn);
		if (f(pn) > 0)	printf(" ");	// 칸 맞춤
		printf("%.10f\n", f(pn));

		if (f(an)*f(pn) < 0)	// 해는 pn의 왼쪽에 위치 (해 < pn)
			bn = pn;
		else            // 해는 pn의 오른쪽에 위치 (해 > pn)
			an = pn;
	}
}

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}
