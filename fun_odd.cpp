#include<iostream>
using namespace std;

void RemoveOdd(int *e)
{
	if(*e > 0)
		{
			if(*e%2 == 1)
				*e = 0;
		}
		else{
			if(*e%2 == -1)
				*e = 0;
		}
}

void RemoveEven(int *e)
{
	if(*e != 0)
	{
		if(*e%2 == 0)
			*e = 0;
	}
}

void RemovePositive(int *e)
{
	if(*e > 0)
		*e = 0;
}
void RemoveNegative(int *e)
{
	if(*e < 0)
		*e = 0;

}
void ProcessArray(int *p,int n,void (*pfn)(int*))
{
	for(int i =0;i<n;i++)
	{
		pfn(p++);
	}
}

int main()
{
	int n,ch;
	
	cout<<"Enter the num of array elements:-"<<endl;
	cin>>n;

	int *p = new int(n);
	

	for(int i =0; i < n; i++)
	{
		cout<<"Enter the "<< i+1 <<" element \n";
		cin>>p[i];
	}

//	odd_num(p);
   cout<<"Enter the menu option :-"<<endl;
   cout<<"1. Remove odd numbers from array \n";
   cout<<"2. Remove even numbers from array \n";
   cout<<"3. Remove positive numbers from array \n";
   cout<<"4. Remove negative numbers from array \n";
	cin>>ch;

	
	void (*pfn[4])(int*) = {RemoveOdd,RemoveEven,RemovePositive,RemoveNegative};
	ProcessArray(p,n,*pfn[ch-1]);

	/*switch(ch)
	{
		case 1:
			ProcessArray(p,n,RemoveOdd);
			break;

		case 2:
			ProcessArray(p,n,RemoveEven);
			break;

		case 3:
			ProcessArray(p,n,RemovePositive);
			break;


		case 4:
			ProcessArray(p,n,RemoveNegative);
			break;

		default:
			cout<<"out";
			break;
	}
	*/
	
	//ProcessArray(p,n,*pfn);

	for(int i =0; i < n; i++)
	{
	cout<<p[i]<<","<<endl;
	}
	delete[] p;



	return 0;
}
