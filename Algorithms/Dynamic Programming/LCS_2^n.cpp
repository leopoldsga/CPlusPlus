#include <iostream>
#include <string>
using namespace std;

int max(int x, int y) {
	return x > y ? x : y;
}

int lcs(string strA, string strB, int lenA, int lenB) {
	if (lenA == 0 || lenB == 0)
		return 0;
	else if (strA[lenA-1] == strB[lenB-1])
		return lcs(strA, strB, lenA - 1, lenB - 1) + 1;
	else
		return max(lcs(strA, strB, lenA - 1, lenB), lcs(strA, strB, lenA, lenB - 1));
}

int main() {
	string strA = "AGGTAB";
	string strB = "GXTXAYB";
	int lenA = strA.length();
	int lenB = strB.length();
	cout << "lcs is " << lcs(strA,strB,lenA,lenB) << endl;
	system("pause");
	return 0;
}
