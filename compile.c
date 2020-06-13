#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
#include <sys/time.h>
 
double time_diff(struct timeval x , struct timeval y);
double time_dif(struct timeval m , struct timeval n);
double time_difff(struct timeval p , struct timeval q);
//#define size 7
/* Function Prototypes */
 
int is_sorted(int *, int); //
void shuffle(int *, int);  //
void bogosort(int *, int); //
void ShellSort(int *, int);//
//void binary_tree_sort(int*, int);

 
int main()
{	
	struct timeval before , after;
	struct timeval beforee , afterr;
	struct timeval bbeforee , aafterr;

	int size=10;
	int nums[100]; 
//	int TAB[10]; 
    FILE *fp1,*fout;      //file pointer
    int i;
    time_t  ti;
 
    //******************  code starts here ***************
    for(i=0;i<10;i++)   //initialize array with 0
        nums[i]=0;
    i=0;        //clean up and initialize LCV
  	fp1=fopen("file_10.txt","r");
  	fout=fopen("Output.txt","a");
  	
  	ti = time(NULL);
  	
  	fprintf(fout, "%s\n",asctime(localtime(&ti)) );
  	//fclose(fout);
  	
    while((fscanf(fp1,"%d",&nums[i]))!=EOF) //scanf and check EOF
        {
            printf("%d\n",nums[i]);
            i++;
        }
	fclose(fp1);

	fout=fopen("Output.txt","a");	
	gettimeofday(&beforee , NULL);
	bogosort(nums, size); 
	gettimeofday(&afterr , NULL); 
   
    printf("The array after sorting is:\n");
    for (i = 0;i < size;i++)
    {
       printf("%d\n", nums[i]);
    }
    printf("\n");
//	printf("Total time elapsed in bogosort: %.0lf us\n%d\t" , time_diff(beforee , afterr) );
	fprintf(fout,"Time taken by bogosort-%.0lf us\n%d\t",time_diff(before , after));
	fclose(fout);

    
    int a[100];   //up to 50 element int array
    FILE *fp3;      //file pointer
    int l=10;
 
    //******************  code starts here ***************
    for(i=0;i<10;i++)   //initialize array with 0
        a[i]=0;
    i=0;        //clean up and initialize LCV
  	fp3=fopen("file_10.txt","r");
    while((fscanf(fp3,"%d",&a[i]))!=EOF) //scanf and check EOF
        {
            printf("%d\n",a[i]);
            i++;
        }
    fclose(fp3);
    fout=fopen("Output.txt","a");
    fprintf(fout,"Time taken by shellsort%.0lf us\n%d\t",time_diff(beforee , afterr));
    gettimeofday(&beforee , NULL);

	ShellSort(a,l); //Calling shellsort 
	gettimeofday(&afterr , NULL);
    printf("The sorted elements are ::\n  ");
    for(i = 0; i < l; i++)
        printf("%d \n",a[i]);
    printf("\n");
//	printf("Total time elapsed in shellsort: %.0lf us\n%d\t" , time_dif(beforee , afterr) );
//	fprintf(fout,"Time taken by shellsort%.0lf us\n%d\t",time_diff(before , after));
//	fprintf(fout,"Time taken by shellsort%.0lf us\n%d\t",time_diff(beforee , afterr));

fclose(fout);
  
  //itreative deeping
  	
  	int A[N], temp[N];
//	srand(time(NULL));

	// generate random input of integers
	for (int i = 0; i < N; i++)
		temp[i] = A[i] = (rand() % 20);

	printf("Original Array : ");
	printArray(A);
	fout=fopen("Output.txt","a");
//	fprintf(fout,"Total time elapsed in imsort: %.0lf us\n%d\t" , time_diff(beforee , afterr) );
	fprintf(fout,"Total time elapsed in imsort- %.0lf us\n%d\t" , time_diff(bbeforee , aafterr) );
	// sort array A[0..N-1] using temporary array temp
	fout=fopen("Output.txt","a");
	gettimeofday(&bbeforee , NULL);
	itreativesort(A, temp, 0, N - 1);
	gettimeofday(&aafterr , NULL);	
	printf("Modified Array : ");
	printArray(A);
//	printf("Total time elapsed in imsort: %.0lf us\n%d\t" , time_diff(beforee , afterr) );
//	fprintf(fout,"Total time elapsed in imsort: %.0lf us\n%d\t" , time_diff(bbeforee , aafterr) );
	fclose(fout);
	

	 return 0;
}



int is_sorted(int *a, int n)
{
	while (--n >= 1)
    {
        if (a[n] < a[n - 1])
        {
            return 0;
          }
    }
      return 1;
}
 

void shuffle(int *a, int n)
{
    int i, t, temp;
    for (i = 0;i < n;i++)
    {
        t = a[i];
        temp = rand() % n;    
        a[i] = a[temp];
        a[temp] = t;
    }
}
 
void bogosort(int *a, int n)
{
    while (!is_sorted(a, n))
    {
        shuffle(a, n);
    }
}



void ShellSort(int a[], int n)
{
    int i, j, increment, tmp;
    for(increment = n/2; increment > 0; increment /= 2)
    {
        for(i = increment; i < n; i++)
        {
            tmp = a[i];
            for(j = i; j >= increment; j -= increment)
            {
                if(tmp < a[j-increment])
                    a[j] = a[j-increment];
                else
                    break;
            }
            a[j] = tmp;
        }
    }
}

int min(int x, int y)
{
	return (x < y) ? x : y;
}

// Merge two sorted subarrays A[from .. mid] and A[mid + 1 .. to]
void deeping(int A[], int temp[], int from, int mid, int to)
{
	int k = from, i = from, j = mid + 1;

	// loop till there are elements in the left and right runs
	while (i <= mid && j <= to)
	{
		if (A[i] < A[j])
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];
	}

	// Copy remaining elements
	while (i < N && i <= mid)
		temp[k++] = A[i++];

	// Don't need to copy second half

	// copy back to the original array to reflect sorted order
	for (int i = from; i <= to; i++)
		A[i] = temp[i];
}

// Iteratively sort array A[low..high] using temporary array
void itreativesort(int A[], int temp[], int low, int high)
{
	// divide the array into blocks of size m
	// m = [1, 2, 4, 8, 16...]
	for (int m = 1; m <= high - low; m = 2*m)
	{
		// for m = 1, i = 0, 2, 4, 6, 8
		// for m = 2, i = 0, 4, 8
		// for m = 4, i = 0, 8
		// ...
		for (int i = low; i < high; i += 2*m)
		{
			int from = i;
			int mid = i + m - 1;
			int to = min(i + 2*m - 1, high);

			deeping(A, temp, from, mid, to);
		}
	}
}

// Utility function to print an given array
int printArray(int A[])
{
	for (int i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}

	printf("\n");
}
double time_diff(struct timeval x , struct timeval y)
{
    double x_ms , y_ms , diff;
 
    x_ms = (double)x.tv_sec + (double)x.tv_usec;
    y_ms = (double)y.tv_sec + (double)y.tv_usec;
 
    diff = (double)y_ms - (double)x_ms;
 
    return diff;
}
double time_dif(struct timeval m , struct timeval n)
{

    double m_ms , n_ms , dif;
 
    m_ms = (double)m.tv_sec + (double)m.tv_usec;
    n_ms = (double)n.tv_sec + (double)n.tv_usec;
 
    dif = (double)n_ms - (double)m_ms;
 
    return dif;
}

double time_difff(struct timeval p , struct timeval q)
{
    double p_ms , q_ms , difff;
 
    p_ms = (double)p.tv_sec + (double)p.tv_usec;
    q_ms = (double)q.tv_sec + (double)q.tv_usec;
 
    difff = (double)q_ms - (double)p_ms;
 
    return difff;
}
