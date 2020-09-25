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
	for (int i = 1; (i + 1 < power_of_number(2, row_of_tree - 1)); i++)
	{
		if (numbers[current_index] > numbers[i])
		{
			numbers[current_index] = numbers[current_index] + numbers[i];
			numbers[i] = numbers[current_index] - numbers[i];
			numbers[current_index] = numbers[current_index] - numbers[i];
		}

		if (power_of_number(2, row_of_tree) <= i + 2)
		{
			row_of_tree++;
		}
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
	for (int i = 0; i < lenght_of_array; i++)
	{
		numbers[i] = rand();
	}



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