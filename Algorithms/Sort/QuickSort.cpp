#include <iostream>
using namespace std;

void qSort(int *list,int low, int high) {
	int l = low;
	int r = high;
	int axis = list[low];
	int tmp = 0;
	if (l > r)
		return;
	while (l != r)
	{
		while (list[r] >= axis && l < r)
			r--;
		while (list[l] <= axis && l < r)
			l++;
		if (l < r) {
			tmp = list[r];
			list[r] = list[l];
			list[l] = tmp;
		}
	}
	list[low] = list[r];
	list[r] = axis;
	qSort(list, low, r-1);
	qSort(list, r+1,high);
}

int main() {
	int list[100];
	int nE = 0;

	cout << "Input the number of need-to-be-sorted elements: ";
	cin >> nE;

	for (int i = 0; i < nE; i++) {
		cin >> list[i];
	}
	qSort(list,0,nE-1);
	for (int i = 0; i < nE; i++)
		cout << list[i] << " ";
	system("pause");
	return 0;
}
