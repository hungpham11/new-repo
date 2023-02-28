#include <iostream>
#include <algorithm>

using namespace std;

void menu(int);
void inputArray(int, int[]);
void printArray(int, int[]);
void selectionSort(int, int[]);
void insertionSort(int, int[]);
void bubbleSort(int, int[]);

int main()
{
	cout << "----------MENU----------\n";
	cout << "1. Tim max cua 3 so\n";
	cout << "2. Dem so chan le cua day\n";
	cout << "3. Tinh tong cua n so nguyen\n";
	cout << "4. \n";
	cout << "5. Tim phan tu co trong mang hay khong\n";
	cout << "6. Selection sort\n";
	cout << "7. Insertion sort\n";
	cout << "8. Bubble sort\n";
	cout << "Nhan -1 de thoat chuong trinh!\n";
	cout << "Moi chon: ";
	int opt;
	cin >> opt;
	while (opt < -1){
		cout << "Nhap lai: ";
		cin >> opt;
	}
	menu(opt);
	return 0;
}

void inputArray(int n, int a[])
{
	cout << "Nhap cac phan tu cua ma tran: ";
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
}

void printArray(int n, int a[])
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
}

void selectionSort(int n, int a[])
{
	int min_index;
	for (int i = 0; i < n - 1; ++i)
	{
		min_index = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < a[min_index])
				min_index = j;
		}
		if (min_index != i)
		swap(a[i], a[min_index]);
	}
	
}

void insertionSort(int n, int a[])
{
	int temp;
	for (int i = 1; i < n; ++i)
	{
		temp = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = temp;
	}
}

void bubbleSort(int n, int a[])
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}

void menu(int x)
{
	int n;
	switch (x)
	{
	case -1:
		cout << "Thoat chuong trinh!\n";
		return;
	case 1:
	{
		int a, b, c;
		cout << "Nhap vao 3 so: ";
		cin >> a >> b >> c;
		int max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
		cout << "Max = " << max;
		break;
	}
	case 2:
	{
		int countc = 0;
		cout << "Nhap so phan tu cua day:";
		cin >> n;
		int arr[n];
		cout << "Nhap vao day so: ";
		inputArray(n, arr);
		for (int i = 0; i < n; ++i)
		{
			if (arr[i] % 2 == 0)
				countc++;
		}
		cout << "So chan: " << countc;
		cout << "\nSo le: " << n - countc;
		break;
	}
	case 3:
	{
		int sum = 0, x;
		cout << "Nhap vao n so nguyen: ";
		cin >> n;
		cout << "Nhap " << n << " so vao chuong trinh: ";
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			sum += x;
		}
		cout << "Sum = " << sum;
		break;
	}
	case 4:
	{
		cout << "Chua lam :))";
		break;
	}
	case 5:
	{
		int k, index = -1;
		cout << "Nhap so phan tu cua mang: ";
		cin >> n;
		int a[n];
		cout << "Nhap danh dach mang:";
		inputArray(n, a);
		cout << "Nhap phan tu can tim: ";
		cin >> x;
		for (int i = 0; i < n; ++i)
		{
			if (x == a[i])
			{
				index = i;
				break;
			}
		}
		if (index == -1)
			cout << "Khong tim thay phan tu";
		else
			cout << "Phan tu co tai vi tri " << index;
		break;
	}
	case 6:
	{
		cout << "Nhap so phan tu cua mang: ";
		cin >> n;
		int a[n];
		inputArray(n,a);
		selectionSort(n,a);
		cout << "Mang duoc sap xep theo Selection Sort: ";
		printArray(n,a);
		break;
	}
	case 7:
	{
		cout << "Nhap so phan tu cua mang: ";
		cin >> n;
		int a[n];
		inputArray(n,a);
		insertionSort(n,a);
		cout << "Mang duoc sap xep theo Insertion Sort: ";
		printArray(n,a);
		break;
	}
	case 8:
	{
		cout << "Nhap so phan tu cua mang: ";
		cin >> n;
		int a[n];
		inputArray(n,a);
		bubbleSort(n,a);
		cout << "Mang duoc sap xep theo Bubble Sort: ";
		printArray(n,a);
		break;
	}
	default:
		{
			cout << "Lua chon khong hop le.";
			break;
		}
	}
}
