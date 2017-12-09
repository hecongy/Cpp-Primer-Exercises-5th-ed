int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int* p = arr;
	for(int i = 0; i<10; i++)
	{
		*(p+i) = 0;
	}
	return 0;
}