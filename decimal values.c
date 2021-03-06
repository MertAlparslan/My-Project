// Test.cpp: Konsol uygulamas�n�n giri� noktas�n� tan�mlar.

#include <stdbool.h>

bool IsItEven(long int num);
void SumOfOddAndEvenNumbers(int one_ref, int num);
bool IsItNegative(long int num);
void DivisibleBy5(int zero_ref, unsigned int num);
bool IsItEqual(long int num1, long int num2);
int SumOfDigit(long int num);
int ConvertBinaryToDecimal(long int binary_val);
int* ConvertDecimalToBinary(int decimal_val, int size);
void ConvertDaysToYearWeekDay(unsigned int ndays);
void ReverseInteger(int arr[], int arr_size);

int main()
{
	long int num = 1001122;
	bool tutucu;
	tutucu=IsItEven(num);
	printf("%d\n", tutucu);

	int one = 1;
	int num2 = 20;
	SumOfOddAndEvenNumbers(one, num2);

	bool tutucu2;
	long int numara = -2018;
	tutucu2=IsItNegative(numara);
	printf("%d\n", tutucu2);

	int zero = 0;
	unsigned int num3 = 15;
	DivisibleBy5(0, num3);

	long num4 = 20002;
	long num5 = 20002;
	bool tutucu3;
	tutucu3=IsItEqual(num4, num5);
	printf("%d\n", tutucu3);

	int int_tutucu;
	long int sayi = 212345;
	int_tutucu=SumOfDigit(sayi);
	printf("%d\n", int_tutucu);

	long int binary_val = 100100;
	int tutucu4;
	tutucu4=ConvertBinaryToDecimal(binary_val);
	printf("%d\n", tutucu4);

	int decimal_val = 100;
	ConvertDecimalToBinary(decimal_val, 7);
	getchar();
    return 0;
}

bool IsItEven(long int num)
{
	int remainder, two = 2;
	remainder = num % two;

	if (remainder == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SumOfOddAndEvenNumbers(int one_ref, int num)
{
	int i, odd_sum = 0, even_sum = 0, two = 2;
	for (i = 1;i < num;i++)
	{
		if (i%two == 0)
		{
			even_sum = even_sum + i;
		}
		else
		{
			odd_sum = odd_sum + i;
		}
	}
	printf("Odd numbers sum is %d\n", odd_sum);
	printf("Even numbers sum is %d\n", even_sum);
}

bool IsItNegative(long int num)
{
	if (num < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DivisibleBy5(int zero_ref, unsigned int num)
{
	int i, five = 5;
	for (i = 0;i <= num;i++)
	{
		if (i % 5 == 0)
		{
			printf("%d\n", i);
		}
	}
}

bool IsItEqual(long int num1, long int num2)
{
	if (num1 == num2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int SumOfDigit(long int num)
{
	int remainder, digit_sum = 0, temp;

	temp = num;
	while (temp > 0)
	{
		remainder = temp % 10;
		digit_sum = digit_sum + remainder;
		temp = temp / 10;
	}
	return digit_sum;
}

int ConvertBinaryToDecimal(long int binary_val)
{
	int base = 1, decimal_val = 0, remainder, temp;
	temp = binary_val;

	while (temp > 0)
	{
		remainder = temp % 2;
		decimal_val = decimal_val + base * remainder;
		base = base * 2;
		temp = temp / 10;
	}
	return decimal_val;
}

int* ConvertDecimalToBinary(int decimal_val,int size)
{
	int binary_val[size];
	int remainder, base = 1, temp, quotinent;

	temp = decimal_val;
	int i = 0;
	do
	{
		remainder = temp % 2;
		binary_val[i++] = remainder;
		quotinent = temp / 2;
		temp = temp / 2;
	} while (temp > 0);

	binary_val[size-1++] = quotinent;
	return *binary_val; //Array d�nd�rmek istedim nas�l d�nd�r�cem ?...
}

void ConvertDaysToYearWeekDay(unsigned int ndays)
{
	unsigned int year, week, days;

	year = ndays / 365;
	week = (ndays % 365) / 7;
	days = (ndays % 365) / 7 % 7;

	printf("%d days is %d year %d weeks %d days", ndays, year, week, days);
}

int BinaryToOctal(long int binary_val,int size)
{
	int decimal_val = 0, remainder, base = 1, temp;
	temp = binary_val;

	while (temp > 0)
	{
		remainder = temp % 10;
		decimal_val = decimal_val + base * remainder;
		base = base * 2;
		temp = temp / 10;
	}

	int octal_val_arr[size];

	int i = 0, quotinent;
	do
	{
		remainder = decimal_val % 8;
		octal_val_arr[i++] = remainder;
		decimal_val = decimal_val / 8;
	} while (decimal_val > 0);

	quotinent = decimal_val / 8;
	octal_val_arr[0] = quotinent;
}

void ReverseInteger(int arr[],int arr_size)
{
	int *pstart = &arr[0];
	int *pend = &arr[arr_size];

	int holder_arr[arr_size];
	int *pholder = NULL;


	for (*pholder = *pend;*pholder >= *pstart;*pholder--)
	{
		holder_arr[*pstart++] = arr[*pholder];
		arr[*pholder] = holder_arr[*pstart++];
	}
}

void Segregate0And1s(int arr[], int size,int low,int high)
{
	low = 0;
	high = size;

	while (arr[low] == 0)
	{
		low++;
	}

	while (arr[high] == 1)
	{
		high--;
	}

	if (low < high)
	{
		arr[low] = 0;
		arr[high] = 1;
		low++;
		high--;
	}
}

void ConvertOctalToDecimal(int octal_num,int size)
{
	int decimal_val = 0, remainder, temp, base = 1;
	temp = octal_num;

	while (temp > 0)
	{
		remainder = temp % 10;
		decimal_val = decimal_val + remainder * base;
		base = base * 8;
		temp = temp / 10;
	}

	int i = 0;
	int binary_val[size];
	int quotient;

	while (decimal_val > 0)
	{
		remainder = decimal_val % 2;
		binary_val[i++] = remainder;
		decimal_val = decimal_val / 2;
	}
	quotient = decimal_val / 2;
	binary_val[0] = quotient;
}

long int ConvertHexadecimalToBinary(char* hexadecimal_val,int size)
{
	int i = 0, remainder, temp, base = 1;
	int decimal_val[size];

	while (hexadecimal_val[i]>(char)0)
	{
		switch (hexadecimal_val[i]<=(char)9)
		{
		case '0':
			remainder = hexadecimal_val[i] % 10;
			decimal_val[i] = decimal_val[i] + remainder * base;
			base = base * 15;
			(int)hexadecimal_val = (int)hexadecimal_val / 10;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case 'A': //Behave like 10 how i'm gonna achieve that ?
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		default:
			printf("Enter valid hexadecimal expression\n");
		}
		i++;
	}
}
