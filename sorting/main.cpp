#include <iostream>
using namespace std;

struct INF
{
	int key;
	char info;
};

void input_array(int* array, int N);
void output_array(int* array, int N);
void sorting_insert(int* array, int N);

void input_array(INF* array, int N);
void output_array(INF* array, int N);
int find_ref_key(INF* array, int i, int j);
int partition(INF* array, int i, int j, int key);
void quick_sort(INF* array, int i, int j);

int main()
{
	srand(time(NULL));
	int* array = new int[10];
	input_array(array, 10);
	cout << "-->task 1" << endl;
	cout << "array before sorting" << endl;
	output_array(array, 10);
	sorting_insert(array, 10);
	cout << "array after sorting" << endl;
	output_array(array, 10);

	int number;
	cout << endl << "enter number" << endl;
	cin >> number;
	INF* array_of_structs = new INF[number];

	input_array(array_of_structs, number);
	cout << endl << "-->task 2" << endl;
	cout << "array before sorting" << endl;
	output_array(array_of_structs, number);
	quick_sort(array_of_structs, 0, number-1);
	cout << "array after sorting" << endl;
	output_array(array_of_structs, number);
}

void input_array(int* array, int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i] = rand() % 10 - 5;
	}
}

void output_array(int* array, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void sorting_insert(int* array, int N)
{
	for (int i = 0, j = 0; i < N; i++)
	{
		j = i;
		while (array[j] < array[j - 1])
		{
			swap(array[j], array[j - 1]);
			if (--j == 0) break;
		}
	}
}

void input_array(INF* array, int N)
{
	for (int i = 0; i < N; i++)
	{
		array[i].key = rand() % 15;
		array[i].info = char(rand() % 25 + 65);
	}
}

void output_array(INF* array, int N)
{
	for (int i = 0; i < N; i++)
	{
		(i == N - 1)?(cout << array[i].key << " " << array[i].info << "\n"): (cout << array[i].key << " " << array[i].info << ", ");
	}
}

int find_ref_key(INF* array, int i, int j)
{
	int first_key = array[i].key;

	for (int k = i + 1; k <= j; k++)
	{
		if (array[k].key > first_key)
			return k;
		else if (array[k].key < first_key)
			return i;
	}
	return -1;
}

int partition(INF* array, int i, int j, int key)
{
	int left = i, right = j;

	do
	{
		swap(array[left], array[right]);
		if(array[left].key < key)
		{
			left++;
		}
		else if(array[right].key >= key)
		{
			right--;
		}	
	} while (left <= right);
	return left;
}

void quick_sort(INF* array, int i, int j)
{
	int k, ref_key, ref_key_index;

	ref_key_index = find_ref_key(array, i, j);
	if (ref_key_index != -1)
	{
		ref_key = array[ref_key_index].key;
		k = partition(array, i, j, ref_key);
		quick_sort(array, i, k - 1);
		quick_sort(array, k, j);
	}
}