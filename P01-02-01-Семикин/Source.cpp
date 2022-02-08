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
int E(int mas[], int size1, int size2)					//���������
{
	int counter = 0;
	for (size1; size1 < size2; size1++)
		counter += mas[size1];
	return counter;
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
		printf("������� k1 � k2 (k1>k2)\n");
		scanf_s("%d%d", &k1, &k2);
	} while (k2 > k1);
	int e = E(mas, k2, k1);




	printf("����� ���� ��������� ������� = %d\n������������ ���� ��������� ������� = %d\nC���� ��������� ���� ��������� ������� = %d\nC���� ����� ������ ��������� ������� = %d\n����� ��������� ������� � k1 �� k2 = %d", a, b, c, d, e);
}