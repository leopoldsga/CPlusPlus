#include <iostream>
#include <string>
using namespace std;

int max(int x, int y) {
	return x > y ? x : y;
}

//Solution#1: Complexity O(2^n)
//int lcs(string strA, string strB, int lenA, int lenB) {
//	if (lenA == 0 || lenB == 0)
//		return 0;
//	else if (strA[lenA-1] == strB[lenB-1])
//		return lcs(strA, strB, lenA - 1, lenB - 1) + 1;
//	else
//		return max(lcs(strA, strB, lenA - 1, lenB), lcs(strA, strB, lenA, lenB - 1));
//}

//Solution#2: Removing overlapping subproblems, complexity O(mn)
int lcs(string strA, string strB, int lenA, int lenB) {
	int** L = new int* [lenA+1];
	for (int i = 0; i <= lenA; i++)
		L[i] = new int[lenB + 1];

	for (int i = 0; i <= lenA;i++) {
		for (int j = 0; j <= lenB; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (strA[i - 1] == strB[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i-1][j],L[i][j-1]);
		}
	}
	return L[lenA][lenB];
}

int main() {
	string strA = "AGGTABEFG";
	string strB = "GXTXAYBEFG";
	int lenA = strA.length();
	int lenB = strB.length();
	cout << "lcs is " << lcs(strA,strB,lenA,lenB) << endl;
	system("pause");
	return 0;
}
