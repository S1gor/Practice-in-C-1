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
		printf("Введите диапозон = ");
		scanf_s("%d%d", &f, &g);
		srand(time(0));
		for (int i = 0; i < N; i++)
			mas[i] = Random(f, g);
		printMas(mas, N);
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
		printf("Введите k1 и k2 (k2>k1)\n");
		scanf_s("%d%d", &k1, &k2);
	} while (k2 < k1);
	int e = E(mas, k1, k2);

	//е)среднее арифмитическое всех элементов массива
	float f = F(mas, N);

	//ж)среднее арифметическое элементов массива с s1 по s2(s2>s1)
	int s1, s2;
	do {
		printf("Введите s1 и s2 (s2>s1)\n");
		scanf_s("%d%d", &s1, &s2);
	} while (s1 > s2);
	float g = G(mas, s1, s2);

	printf("Сумма всех элементов массива = %d\nПроизведение всех элементво массива = %d\nCумма квадратов всех элементов массива = %d\nCумма шести первых элементов массива = %d\nСумма элементов массива с k1 по k2 = %d\nСреднее арифмитическое всех элементов массива = %.1f\nСреднее арифметическое элементов массива с s1 по s2 = %.1f\n", a, b, c, d, e, f, g);
}