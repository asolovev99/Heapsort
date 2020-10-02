#include <iostream>

#include <vector>

#include <ctime>
int power_of_number(int number, int power)
{
	int result = 1;
	for (int i = 1; i <= power; i++)
	{
		result *= number;
	}
	return result;
}
void turn_to_tree(int * numbers, int lenght_of_array, int current_index)
{
	int row_of_tree = 1;
	int row_of_current_index = 2;

	printf("\ncurrent_index = %d\n", current_index);

	for (; current_index > power_of_number(2, row_of_current_index) - 2; row_of_current_index++); // Нахождение строки, в которой находится элемент дерева с индексом current_index

	for (int i = 0; /*(i + 1 < power_of_number(2, row_of_tree - 1))*/ (i + 1 < power_of_number(2, row_of_current_index - 1)); i++)
	{
		if (numbers[current_index] > numbers[i]) 
		{
			numbers[current_index] = numbers[current_index] + numbers[i];
			numbers[i] = numbers[current_index] - numbers[i];
			numbers[current_index] = numbers[current_index] - numbers[i]; // Поменяли местами числа

			printf("\nChanged index: i = %d и current_index = %d, Changed numbers: i = %d и current_index = %d\n\n", i, current_index, numbers[i], numbers[current_index]); // test
			int row = 1;// test
			for (int j = 0; j < lenght_of_array; j++)// test
			{// test
				printf("%3d. %5d", j, numbers[j]);// test
				if (power_of_number(2, row) <= j + 2)// test
				{ // test
					printf("\n"); // test
					row++; // test
				} // test
			} // test
			printf("\n\n"); // test

			i = power_of_number(2, row_of_tree - 1) - 2; // Возвращаемся в начало строки дерева
		}

		printf("\n\nrow_of_tree = %d, row_of_current_index = %d, i = %d\n", row_of_tree, row_of_current_index, i); // test

		if (power_of_number(2, row_of_tree) <= i + 2)
		{
			row_of_tree++;
		}

		printf("row_of_tree = %d\n\n", row_of_tree); // test

	}

	printf("Current_index = %d\n", current_index); // test
	int row = 1;// test
	for (int j = 0; j < lenght_of_array; j++)// test
	{// test
		printf("%3d. %5d", j, numbers[j]);// test
		if (power_of_number(2, row) <= j + 2)// test
		{ // test
			printf("\n"); // test
			row++; // test
		} // test
	} // test
	//for (int i = 0; i < lenght_of_array; i++) // test
	//{ // test
	//	printf("%d ", numbers[i]); // test
	//} // test
	//printf("\n"); // test

	if (current_index < lenght_of_array)
	{
		printf("\n\n\n\n\n\nCALL FUNCTION\n"); // test
		turn_to_tree(numbers, lenght_of_array, current_index + 1); 
	}




}
//void swap(std::vector<int>* v, int n, int m)
//
//{
//
//	int tmp = (*v)[n];
//
//	(*v)[n] = (*v)[m];
//
//	(*v)[m] = tmp;
//
//	/*
//
//	for (int i = 0; i < (*v).size(); i++)
//
//	{
//
//		std::cout << (*v)[i] << " ";
//
//	}
//
//	std::cout << std::endl;
//
//	*/
//
//}

int main()
{
	const int lenght_of_array = 100;
	int numbers[lenght_of_array];

	srand(time(0));

	printf("0\n"); // test
	while (true) // test
	{ // test

		for (int i = 0; i < lenght_of_array; i++)
		{
			numbers[i] = rand();

			printf("%d ", numbers[i]); // test

		}
		printf("\n"); // test

		turn_to_tree(numbers, lenght_of_array, 1);

		printf("END:\n"); // test
		int row = 1;// test
		for (int i = 0; i < lenght_of_array; i++)// test
		{// test
			printf(" %5d", numbers[i]);// test
			if (power_of_number(2, row) <= i + 2)// test
			{ // test
				printf("\n"); // test
				row++; // test
			} // test
		} // test

		for (int i = 0; i <= 49; i++) // test
		{ // test
			if ((numbers[i] < numbers[2 * i + 1]) || (numbers[i] < numbers[2 * i + 2])) // test
			{ // test
				printf("\n\n\n\n\n\n\n\n\n\nERROR: (numbers[i] < numbers[2 * i + 1]) || (numbers[i] < numbers[2 * i + 1]) == FALSE"); // test
				system("pause"); // test
			} // test
		} // test
	} // test


//{ Спасибо Википедия, но не понял.
//
//	std::vector<int> arr;
//
//	const int N = 20;
//
//	srand(time(0));
//
//	for (int i = 0; i < N; i++)
//
//	{
//
//		arr.push_back((int)rand() % 100);
//
//		std::cout << arr[i] << " ";
//
//	}
//
//	std::cout << std::endl;
//
//	for (int j = 0; j < N; j++)
//
//	{
//
//		for (int i = N / 2 - 1 - j / 2; i > -1; i--)
//
//		{
//
//			if (2 * i + 2 <= N - 1 - j)
//
//			{
//
//				if (arr[2 * i + 1] > arr[2 * i + 2])
//
//				{
//
//					if (arr[i] < arr[2 * i + 1])
//
//					{
//
//						swap(&arr, i, 2 * i + 1);
//
//						//std::cout <<j<<" "<< i << " " << 2 * i + 1 << std::endl;
//
//					}
//
//				}
//
//				else
//
//					if (arr[i] < arr[2 * i + 2])
//
//					{
//
//						swap(&arr, i, 2 * i + 2);
//
//						//std::cout <<j<<" "<< i << " " << 2 * i + 2 << std::endl;
//
//					}
//
//			}
//
//			else
//
//				if (2 * i + 1 <= N - 1 - j)
//
//					if (arr[i] < arr[2 * i + 1])
//
//						swap(&arr, i, 2 * i + 1);
//
//		}
//
//		swap(&arr, 0, N - 1 - j);
//
//		//std::cout << j << " " << 0 << " " << N-1-j << std::endl;
//
//	}
//
//	for (int i = 0; i < N; i++)
//
//	{
//
//		std::cout << arr[i] << " ";
//
//	}
//
//	std::cout << std::endl;

}