#include <iostream>

int Vvod()
{
	int a;
	do
	{
		printf("�������:\n0 - ��������� ������ �������\n1 - ��������� ������ �������� �� ��������� ���������\n2 - ��������� ������ �� txt\n");
		scanf_s("%d", &a);
	} while (a > 2 || a < 0);
	return a;
}

void scanMas(int mas[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("mas[%d] = ", i);
		scanf_s("%d", &mas[i]);
	}
}

void printMas(int mas[], int size)
{
	for (int i = 0; i < size; i++)
		printf("mas[%d] = %d\n", i, mas[i]);
}

int Random(int a, int b)
{
	return rand() % (b - a + 1) + a;
}

void readFile(const char* filename, int mas[], int size)
{
	FILE* f;
	if (fopen_s(&f, filename, "r") != 0)
	{
		printf("��������� ������� ����!!!");
		exit(1);
	}
	for (int i = 0; i < size; i++)
		fscanf_s(f, "%d", &mas[i]);
	fclose(f);
}

int A(int mas[], int size)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		counter += mas[i];
	}
	return counter;
}
int B(int mas[], int size)
{
	int counter = 1;
	for (int i = 0; i < size; i++)
		counter *= mas[i];
	return counter;
}
int C(int mas[], int size)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
		counter += mas[i] * mas[i];
	return counter;
}
int D(int mas[])
{
	int counter = 0;
	for (int i = 0; i < 6; i++)
		counter += mas[i];
	return counter;
}
int E(int mas[], int size1, int size2)
{
	int counter = 0;
	for (size1 - 1; size1 - 1 <= size2 - 1; size1++)
		counter += mas[size1 - 1];
	return counter;
}
float F(int mas[], int size)
{
	float counter = 0;
	float s = 0;
	for (int i = 0; i < size; i++)
	{
		s += mas[i];
		counter++;
	}
	float f = s / counter;
	return f;
}
float G(int mas[], int size1, int size2)
{
	float counter = 0;
	float s = 0;
	for (size1 - 1; size1 - 1 <= size2 - 1; size1++)
	{
		s += mas[size1 - 1];
		counter++;
	}
	float g = s / counter;
	return g;
}

int main()
{
	system("chcp 1251");

	int choise = Vvod();
	const int N = 7;
	int mas[N];

	if (choise == 0)
		scanMas(mas, N);
	if (choise == 1)
	{
		int f, g;
		printf("������� �������� = ");
		scanf_s("%d%d", &f, &g);
		srand(time(0));
		for (int i = 0; i < N; i++)
			mas[i] = Random(f, g);
		printMas(mas, N);
	}
	if (choise == 2)
		readFile("1.txt", mas, N);

	//�) ����� ���� ��������� �������
	int a = A(mas, N);

	//�)������������ ���� ��������� �������
	int b = B(mas, N);

	//�)����� ��������� ���� ��������� �������
	int c = C(mas, N);

	//�)����� ����� ������ ��������� �������
	int d = D(mas);

	//�)����� ��������� ������� � k1 �� k2(k2>k1)
	int k1, k2;
	do {
		printf("������� k1 � k2 (k2>k1)\n");
		scanf_s("%d%d", &k1, &k2);
	} while (k2 < k1);
	int e = E(mas, k1, k2);

	//�)������� �������������� ���� ��������� �������
	float f = F(mas, N);

	//�)������� �������������� ��������� ������� � s1 �� s2(s2>s1)
	int s1, s2;
	do {
		printf("������� s1 � s2 (s2>s1)\n");
		scanf_s("%d%d", &s1, &s2);
	} while (s1 > s2);
	float g = G(mas, s1, s2);

	printf("����� ���� ��������� ������� = %d\n������������ ���� ��������� ������� = %d\nC���� ��������� ���� ��������� ������� = %d\nC���� ����� ������ ��������� ������� = %d\n����� ��������� ������� � k1 �� k2 = %d\n������� �������������� ���� ��������� ������� = %.1f\n������� �������������� ��������� ������� � s1 �� s2 = %.1f\n", a, b, c, d, e, f, g);
}