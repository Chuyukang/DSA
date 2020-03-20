const int SIZE = 100;

void countSort(int array[],int n)
{
	int bucket[SIZE];
	for(int i=0;i<SIZE;i++)
		bucket[i] = 0;

	for(int i=0;i<n;i++)
		bucket[array[i]]++;
    for(int i=1;i<SIZE;i++)
        bucket[i] = bucket[i-1] + bucket[i];

	int *temp = new int[n];
	for(int i=0;i<n;i++)
		temp[i] = array[i];

	for(int i=n-1;i>=0;i--)
	{
        //有n个元素小于等于x，则x应排在第n-1位
        //有1个元素小于等于x，则x应排在第0位
		array[bucket[temp[i]]-1] = temp[i];
		bucket[temp[i]]--;
	}

    delete[] temp;
}

void sort(int array[],int n)
{
    countSort(array,n);
}