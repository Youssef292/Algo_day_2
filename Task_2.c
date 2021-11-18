#include<stdio.h>
#include<time.h>
int size = 100000;
int array [100000];
void Random(int array[])
{
	int i;
	srand(time(NULL));
	for (i = 0 ; i<size ;i++)
	{
		array[i] = rand()%100000+1;
	}
}
void insertion (int arr[] , int size)
{
	int i , comp , j;
	for (i = 1 ; i < size ;i++)
	{
		comp = arr[i];
		j = i-1;
		while (j >= 0 && arr[j] > comp)
		{
			arr[j+1] = arr[j];
			j = j-1;
			
		}
		arr[j+1] = comp;
	}
	printf("\n the array is sorted using intsertion sort in %u seconds",
	clock());
}

void Array (int arr[] , int size)
{
	int i;
	for (i=0 ; i < size ; i++)
	{
		printf("%d",arr[i]);
		printf("\n");
		
	}
	
}
void swapping (int * i , int * j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}
int chunk (int array[], int low , int high)
{
	int pivot = array[high];
	int i = (low - 1);
	int j ;
	for (j = low ; j < high;j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swapping(&array[i] , array[j]);
		}
	}
	swapping(&array[i+1], &array[high]);
	return (i+1);
}

void quickSort(int array[],int low,int high)
{
	if (low < high)
	{
		int pi = chunk(array,low,high);
		
		quickSort(array , low , pi-1);
		quickSort (array , pi+1 , high);
	}
}
int main ()
{
	int i;
	srand(time(NULL));
	for (i = 0 ; i < size ; i++){
		array [i] = rand() %100000+1;
	}
	Random(array);
	
	printf("Array of 100000 random numbers is initialized\n");
	
	quickSort(array , 0 , size-1);
	printf("The array is sorted using quickSort in %u seconds",clock());
	insertion (array , size);
	return 0;
}
