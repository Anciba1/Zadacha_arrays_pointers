/*Даны два массива: А[n] и B[m]. Необходимо создать
третий массив, в котором нужно собрать:
■■ Элементы обоих массивов;
■■ Общие элементы двух массивов;
■■ Элементы массива A, которые не включаются в B;
■■ Элементы массива B, которые не включаются в A;
■■ Элементы массивов A и B, которые не являются общими для них (то есть объединение результатов двухпредыдущих вариантов).
Обязательно используйте синтаксис указателей для
решения этой задачи.*/

#include <iostream>
#include <time.h>
using namespace std;

void print(int* arr, int size); //Функция вывода массива в консоль
void fill(int* arr, int size); // Функция заполнения массива случайными числами
void fun1(int* arr1, int* arr2, int size1, int size2); // Элементы обоих массивов
void fun2(int* arr1, int* arr2, int size1, int size2); // Вывод общих элементов двух массивов
void fun3(int* arr1, int* arr2, int size1, int size2); // Элементы одного массива, которые не входят в другой массив
void fun4(int* arr1, int* arr2, int size1, int size2); // Элементы массивов А и В, которые не являются общими для них

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	const int s1 = 10; // Размер массива А
	const int s2 = 10; // Размер массива В

	int array1[s1]; // Объявление массива А
	int array2[s2]; // Объявление массива В

	fill(array1, s1); // Заполнение массива А случайными числами
	fill(array2, s2); // Заполнение массива В случайными числами

	cout << "Массив А:\n";
	print(array1, s1);
	cout << "Массив В:\n";
	print(array2, s2);
	cout << "Элементы обоих массивов:\n";
	fun1(array1, array2, s1, s2);
	cout << "Общие элементы двух массивов:\n";
	fun2(array1, array2, s1, s2);
	cout << "Элементы массива А не входящие в массив В:\n";
	fun3(array1, array2, s1, s2);
	cout << "Элементы массива В не входящие в массив А:\n";
	fun3(array2, array1, s2, s1);
	cout << "Элементы массивов А и В, которые не являются общими для них:\n";
	fun4(array1, array2, s1, s2);

	return 0;
}

void print(int* arr, int size) //Функция вывода массива в консоль
{
	for (int i = 0; i < size; i++) cout << *(arr + i) << " ";
	cout << "\n\n";
}
void fill(int* arr, int size) // Функция заполнения массива случайными числами
{
	for (int i = 0; i < size; i++) *(arr + i) = rand() % 100;
}
void fun1(int* arr1, int* arr2, int size1, int size2) // Элементы обоих массивов (вперемешку)
{
	for (int i = 0; i < size1; i++) cout << *(arr1 + i) << " ";
	for (int i = 0; i < size2; i++) cout << *(arr2 + i) << " ";
	cout << "\n\n";
}
void fun2(int* arr1, int* arr2, int size1, int size2) // Вывод общих элементов двух массивов
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (*(arr1 + i) == *(arr2 + j)) cout << *(arr1 + i) << " ";
		}
	}
	cout << "\n\n";
}
void fun3(int* arr1, int* arr2, int size1, int size2) // Элементы одного массива, которые не входят в другой массив
{
	for (int i = 0; i < size1; i++)
	{
		int flag = 0;
		for (int j = 0; j < size2; j++)
		{
			if (*(arr1 + i) == *(arr2 + j)) flag++;
		}
		if (flag == 0) cout << *(arr1 + i) << " ";
	}
	cout << "\n\n";
}
void fun4(int* arr1, int* arr2, int size1, int size2) // Элементы массивов А и В, которые не являются общими для них
{
	for (int i = 0; i < size1; i++)
	{
		int flag = 0;
		for (int j = 0; j < size2; j++)
		{
			if (*(arr1 + i) == *(arr2 + j)) flag++;
		}
		if (flag == 0) cout << *(arr1 + i) << " ";
	}
	for (int a = 0; a < size2; a++)
	{
		int flag2 = 0;
		for (int b = 0; b < size1; b++)
		{
			if (*(arr2 + a) == *(arr1 + b)) flag2++;
		}
		if (flag2 == 0) cout << *(arr2 + a) << " ";
	}
	cout << "\n\n";
}
