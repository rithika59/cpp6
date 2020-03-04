/* Assignment -1 Implement a program with following functions:
void ReadMatrix(int **p,int n, int m);
void WriteMatrix(const int **p,int n, int m);
void AddMAtrix(int ** result, const int **a, const int **b,int n, int m);
The program will accept X,n,m from user. Will then accept X number of matrices of size nxm. 
*/

#include<iostream>
using namespace std;


		
void ReadMatrix(int **p, int row1, int col1)
{
		
	for(int i=0;i<row1;i++)
	{
		cout<<"Enter "<<i+1<<" row of the marix \n";
		for(int j=0; j<col1;j++)
			cin>>p[i][j];
	}
}

void PrintMatrix(const int **p, int row1, int col1)
{
	cout<<"The matrix is :\n";
	for(int i=0;i<row1;i++)
	{
		for(int j= 0;j<col1;j++)
		{
			cout<<p[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void AddMatrices(int **result,const int **a,const int **b,int row1,int col1)
{
	for(int i=0; i<row1; i++)
	{
		for(int j=0;j<col1; j++)
		{
			result[i][j]= a[i][j]+b[i][j];
		}
	}
}


int main()
{
	int _matrixCount,row,col;
	cout<<"Enter the number of matrices. \n";
	cin>>_matrixCount;
	int ***p = new int**[_matrixCount];
	cout<<"Enter the number of rows and columns in each matrix. \n";
	cin>>row>>col;
	for(int i=0;i<_matrixCount;i++)
	{	
		cout<<"---------------------------------Input "<<i+1<<" matrix ------------------------------------------------- \n";
		p[i] = new int*[row];

		for(int j =0; j < row;j++)
		{
			p[i][j] = new int[col];
			
		}
		ReadMatrix(p[i],row,col);
	}


	int **res = new int*[row];
	for(int x=0;x<row;x++)
	{
		res[x] = new int[col];
	}
	//cout<<"printing second matrix \n";
//	PrintMatrix((const int**)p[1],row,col);
	//AddMatrices(res,(const int**)p[0],(const int**)p[1],row,col);
	res = p[_matrixCount-1];
	PrintMatrix((const int**)res,row,col);
	for(int y=(_matrixCount-2);y>=0;y--)
	{
//		cout<<"adding matrix p[]"<<y;
		AddMatrices(res,(const int**)p[y],(const int**)res,row,col);
	}
//	AddMatrices(res,(const int**)p[)
	cout<<"--------------------------------------Result Matrix is: --------------------------------\n";
	PrintMatrix((const int**)res,row,col);
	delete[] res;
	delete[] p;
	return 0;
}
