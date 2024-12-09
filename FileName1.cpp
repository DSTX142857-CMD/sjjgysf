#include<iostream>
#include<string>
using namespace std;
template <class T>
class zhan
{
public:
	int size;//当前元素个数
	int front;
	T arr[100];
	zhan():
		size(0),front(0)
	{}
	void rz(T value)
	{
		if (front == 100)
		{
			
		}
		else
		{
			arr[front] = value;
			front++;
			size++;
			
		}
	}
	T cz()
	{
		if (front == 0)
		{
			
			return '\0';
		}
		else
		{
			
			front--;
			size--;
			return arr[front];
		}
	}
	void print()
	{
		for (int i = 0; i < front; i++)
		{
			cout << arr[i] << endl;
		}
	}
	T return1()
	{
		return arr[front-1];
	}//返回栈顶元素
};
void zzh()
{
	zhan<char> z1;
	string s1 = "2*(3+5)+7/1-4";
	char arr[100];
	int count = 0;
	int l = s1.length();
	for (int i = 0; i < l; i++)
	{
		if (s1[i] == '(')
		{
			z1.rz('(');
		}
		else if (s1[i] == ')')
		{
			while (1)
			{
				char c = z1.cz();
				if (c == '(')
				{
					break;
				}
				else
				{
					arr[count] = c;
					count++;
				}
			}
			
		}
		else if( s1[i] == '*'|| s1[i] == '/')
		{
			while (1)
			{
				if (z1.return1() == '/' || z1.return1() == '*')
				{
					arr[count] = z1.cz();
					count++;
				}
				else
				{
					break;
				}
			}
			z1.rz(s1[i]);
		}
		else if (s1[i] == '+' || s1[i] == '-')
		{
			while (1)
			{
				if (z1.return1() == '/' || z1.return1() == '*' || z1.return1() == '+' || z1.return1() == '-')
				{
					arr[count] = z1.cz();
					count++;
				}
				else
				{
					break;
				}

			}
			
			z1.rz(s1[i]);
		}
		else
		{
			arr[count] = s1[i];
			count++;
		}
		
		
	}
	while (1)
	{
		char c1=z1.cz();
		if (c1 == '\0')
		{
			break;
		}
		arr[count] = c1;
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}
int main()
{
	zzh();
	
	return 0;
}