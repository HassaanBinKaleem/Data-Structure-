#include<stdio.h>

int linearSearch(int arr[] , int size , int element)
{
	int i;
	for(i = 0 ; i<=size ; i++)
	{
		if(arr[i] == element)
		{
			return i;
		}
	}
	return -1;
}

int binarySearch(int arr[] , int size ,  int element)
{
	int low , mid , high ,  i;
	low = 0;
	high = size-1;
	
	while(low<=high)
	{
		mid = (low + high)/2;
		if(arr[mid] == element)
		{
			return i;
		}
		if(arr[mid] < element)
		{
			low = mid + 1;
		}
		else
		{
			high = mid-1;
		}
	}
	return -1;
}

void main()
{
	int arr[] = {1,23,45,87,167,286,378,467};
	int size = sizeof(arr)/sizeof(int);
	int element = 378;
	int search = binarySearch(arr , size , element);
	printf("Data: %i is at Index: %i", element , search);
}
