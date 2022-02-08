#include <iostream>

int Vvod()
{
	int a;
	do
	{
		printf("Введите:\n0 - заполнить массив вручную\n1 - заполнить массив случайно из заданного диапозона\n2 - заполнить массив из txt\n");
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
		printf("Неудалось открыть файл!!!");
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
int E(int mas[], int size1, int size2)					//ИСПРАВИТЬ
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
		printf("Введите диапозон = ");
		scanf_s("%d%d", &f, &g);
		srand(time(0));
		for (int i = 0; i < N; i++)
			mas[i] = Random(f, g);
	}
	if (choise == 2)
		readFile("1.txt", mas, N);

	//а) сумма всех элементов массива
	int a = A(mas, N);

	//б)произведение всех элементво массива
	int b = B(mas, N);

	//в)сумма квадратов всех элементов массива
	int c = C(mas, N);

	//г)сумма шести первых элементов массива
	int d = D(mas);

	//д)сумма элементов массива с k1 по k2(k2>k1)
	int k1, k2;
	do {
		printf("Введите k1 и k2 (k1>k2)\n");
		scanf_s("%d%d", &k1, &k2);
	} while (k2 > k1);
	int e = E(mas, k2, k1);




	printf("Сумма всех элементов массива = %d\nПроизведение всех элементво массива = %d\nCумма квадратов всех элементов массива = %d\nCумма шести первых элементов массива = %d\nСумма элементов массива с k1 по k2 = %d", a, b, c, d, e);
}