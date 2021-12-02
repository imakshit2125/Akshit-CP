#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

long double rand_0_1()
{
	//srand(time(0));
	return (long double)(rand()%1000000)/1000000 + 0.0000001;

}

void create_csv(char *filename,long double a[1200][1200],int n)
{
	 
	FILE *fp; 
	int i,j;
	 
	fp=fopen(filename,"w+");
	 
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	        fprintf(fp,"%Lf,",a[i][j]);
	    fprintf(fp, "\n" );
	 
	}
	 
	fclose(fp);
	 
}

void getCofactor(long double A[1200][1200], long double temp[][1200], int p, int q, int n)
{
    int i = 0, j = 0;
    for(int row = 0; row < n-1; row++)
    {
        for(int col = 0; col < n-1; col++)
        {
            if(row != p && col != q)
            {
                temp[i][j++] = A[row][col];
                if(j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

long double determinant(long double A[1200][1200], int n)
{
    long double D = 0;
	if (n == 1)
		return A[0][0];
	
    long double temp[1200][1200];
 
    int sign = 1;
    for (int f = 0; f < n; f++)
    {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
 
    return D;
}

void adjoint(long double A[1200][1200],long double adj[1200][1200],int n)
{
    if (n == 1)
    {
        adj[0][0] = 1;
        return;
    }
    int sign = 1;
    long double temp[1200][1200];
 
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            getCofactor(A, temp, i, j, n);
            sign = ((i+j)%2==0)? 1: -1;
            adj[j][i] = (sign)*(determinant(temp, n-1));
        }
    }
}

void inverse(long double A[1200][1200], long double inverse[1200][1200],int n)
{
    long double  det = determinant(A, n);
    long double  adj[1200][1200];
    adjoint(A, adj, n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            inverse[i][j] = adj[i][j]/(long double)(det);
}

int main()
{
	int i,j,k,l,n;
	static long double A[10][1200][1200];
	static long double B[10][1200][1200];
	static long double A_T[10][1200][1200];
	static long double B_T[10][1200][1200];
	static long double n_id[1200][1200] = {0};
	static long double f[10][1200];
	static long double X[10][1200] = {0};
	static long double Y[10][1200] = {0};
	static long double Z[1200] = {0};
	static long double mat_mul[1200][1200] = {0};
	static long double mat_sum[1200][1200] = {0};

	printf("Enter the size of matrix: ");
	scanf("%d",&n); 

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				A[i][j][k] = rand_0_1();
				B[i][j][k] = rand_0_1();
				
				A_T[i][k][j] = A[i][j][k];
				B_T[i][k][j] = B[i][j][k];
			}
			f[i][j] = rand_0_1();
		}
	}

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i == j)
				n_id[i][j] = n;
		}
	}

	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(k = 0; k < n; k++)
			{
				A[i][j][k] = ((A[i][j][k] + A_T[i][j][k])/2 + n_id[j][k])/(n+1);
				B[i][j][k] = ((B[i][j][k] + B_T[i][j][k])/2 + n_id[j][k])/(n+1);
			}
		}
	}


	// Part (I)

	long double sum_trace = 0;
	for(i = 0; i < 10; i++)
	{
		long double sum_A = 0, sum_B = 0;
		for(j = 0; j < n; j++)
		{
			sum_A = sum_A + A[i][j][j];
			sum_B = sum_B + B[i][j][j];
		}
		sum_trace = sum_trace + sum_A*sum_B;
	}
	printf("The answer of question 1.i is %Lf \n",sum_trace);


	// Part (II)

	for(l = 0; l < 10; l++)
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				for(k = 0; k < n; k++)
				{
					mat_mul[i][j] = mat_mul[i][j] + A[l][i][k]*B[l][k][j];
				}
				mat_sum[i][j] = mat_sum[i][j] + mat_mul[i][j];
			}
		}
	}

	printf("The answer of question 1.ii is \n");

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%Lf\t",mat_sum[i][j]);
		}
		printf("\n");
	}


	// Part (IV)



	for(i = 0; i < 10; i++)
	{
		char filename[100] = "A_";
		sprintf(filename,"A(%dx%d)_%d.csv",n,n,i+1);
		create_csv(filename,A[i],n);
	}

	for(i = 0; i < 10; i++)
	{
		char filename[100] = "B_";
		sprintf(filename,"B(%dx%d)_%d.csv",n,n,i+1);
		create_csv(filename,B[i],n);
	}


	// Part(VI)


	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < n; j++)
		{
			for(k = 0; k < n; k++)
			{
				X[i][j] = X[i][j] + A_T[i][j][k]*f[i][k];
				Y[i][j] = Y[i][j] + B_T[i][j][k]*f[i][k];
			}
		}
	}

	printf("The answer of question 1.vi is \n");
	for(i = 0; i < 10; i++)
	{
		printf("X_%d = ",i);
		for(j = 0; j < n; j++)
		{
			printf("%Lf, ", X[i][j]);
		}
		printf("\n");
	}
	for(i = 0; i < 10; i++)
	{
		printf("Y_%d = ",i);
		for(j = 0; j < n; j++)
		{
			printf("%Lf, ", Y[i][j]);
		}
		printf("\n");
	}


	// Part (VII)



	for(i = 0; i < n; i++)
	{
		for(j = 0; j < 10; j++)
		{
			Z[i] = Z[i] + X[j][i]*Y[j][i] + 2*X[j][i]*Y[j][i];
		}
	}
	printf("The answer of question 1.vii is \n");
	for(i = 0; i < n; i++)
	{
		printf("%Lf  ", Z[i]);
	}

	// Part (V)


	printf("The data files are written in csv format.\nFile name shows the size of array\n");
	for(i = 0; i < 10; i++)
	{

		inverse(A[i], A_T[i], n);
		inverse(B[i], B_T[i], n);
	}

	
	return 0;
}