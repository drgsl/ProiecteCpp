// Simulare Info Bac 2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int I1(int n) {
	return ((n % 2 == 0) && !(n < 0)); // par si pozitiv
}

void I2(int n, int i) {
	int j;
	if (i<n)
	{
		I2(n, i + 1);
		for (j = 1; j <= i; j++)
		{
			cout << j + 2;
		}
	}
}

void I3() {
	int pc = 0;
	int c2 = 0;
	int c3 = 0; 
	int uc = 0;
	for (int i = 1000; i < 9998; i+=2)
	{
		pc = i / 1000;
		c2 = i / 100;
		c3 = i / 10;
		uc = i % 10;

		if ((uc != pc) && (pc % 2 == 0 && c2 % 2 == 0 && c3 % 2 == 0 && uc % 2 == 0))
		{
			cout << i << ' ' << endl;
		}
	}
}

void II1c() {
	int a, b;
	cin >> a >> b;
	int k = 0;
	for (int i = a; i <= b; i++)
	{
		int n = i;
		while (n>0)
		{
			if (n%10%2 == 1)
			{
				k = k + 1;
				cout << i % 10 << ' ';
			}
			n = n / 100;
		}
	}
	cout << k + 1;
}

void II1d() {
	int a, b;
	cin >> a >> b;
	int k = 0;
	int i = a;
	while (i<=b)
	{
		int n = i;
		while (n > 0)
		{
			if (n % 10 % 2 == 1)
			{
				k = k + 1;
				cout << i % 10 << ' ';
			}
			n = n / 100;
		}
		i++;
	}
	cout << k + 1;
}

void II2(float x1, float y1, float x2, float y2) {
	struct punct
	{
		float x, y;
	};

	struct segment
	{
		punct A, B;
	};

	segment seg;

	seg.A.x = x1;
	seg.A.y = y1;

	seg.B.x = x2;
	seg.B.y = y2;

	if (seg.A.x == seg.A.y || seg.B.x == seg.B.y)
	{
		cout << "Este macar un punct pe prima bisectoare ";
	}
	else 
	{
		cout << "Niciun punct nu este pe prima bisectoare ";
	}
}

void II3() {

	int v[5][5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			v[i][j] = (i + j + 3) % 10;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		cout << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << v[i][j] << ' ';
		}
	}

}

int III1(int a, int b) {
	int va[10];
	int vb[10];

	int la = (int)(log10(a) + 1);
	int lb = (int)(log10(b) + 1);

	for (int i = la; i > 0; i--)
	{
		va[i] = a % 10;
		a /= 10;

		vb[i] = b % 10;
		b /= 10;
	}

	bool ok = true;

	for (int k = 1; k <= la; k++)
	{
		int aux = va[la];
		for (int i = la - 1; i >= 1; i--)
			va[i + 1] = va[i];
		va[1] = aux;
		for (int i = 1; i <= la; i++) {
			//cout << va[i] << ' ';
			if (va[i] != vb[i]) {
				ok = false;
				break;
			}
		}
		//cout << endl;
		if (ok)
		{
			cout << k;
			return k;
		}
		else 
		{
			ok = true;
		}
	}
	return -1;
}


void III2() {
	char S[256];
	char c[31];
	char* p;

	cin.getline(S, 256);
	cin.getline(c, 31);

	p = strtok(S, " ");
	while (p)
	{
		for (int i = strlen(c)-1; i >= 0; i--)
		{
			if (c[i] == p[i])
			{
				if (strchr("aeiou", c[i]))
				{
					cout << p << endl;
					break;
				}
				continue;
			}
			break;
		}
		p = strtok(NULL, " ");
	}
}

int III3(int n, int v[]) {

	int ParMax = -1;

	//Bubble Sort
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++) {
			if (v[j] > ParMax && v[j] % 2 == 0)
				ParMax = v[j];
			if (v[j] < v[j + 1])
				swap(v[j], v[j + 1]);

		}

	if (ParMax == -1)
	{
		cout << -1 << endl;
		return -1;
	}

	cout << ParMax << endl;
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ' ';
	}
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

int main()
{
	//I1(-2);
	//I2(4, 1);
	//I3();

	//II1c();
	//II1d();
	//II2(2, 2, 3, 4);
	//II3();

	//III1(120362, 621203);
	//III2();
	int test[] = { 2, 3, 3, 8, 9, 2, 3, 9, 8, 3 };
	III3(10,  test);
}
