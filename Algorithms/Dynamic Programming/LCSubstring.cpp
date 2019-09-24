#include <iostream>
#include <string>
using namespace std;

int max(int x, int y) {
	return x > y ? x : y;
}

//Solution#1: complexity O(mn)
int lcsuffix(string strA, string strB, int lenA, int lenB) {
	int** L = new int* [lenA+1];
	int result = 0;
	for (int i = 0; i <= lenA; i++)
		L[i] = new int[lenB + 1];

	for (int i = 0; i <= lenA;i++) {
		for (int j = 0; j <= lenB; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (strA[i - 1] == strB[j - 1]) {
				L[i][j] = L[i - 1][j - 1] + 1;
				result = max(result, L[i][j]);
			}
			else
				L[i][j] = 0;
		}
	}
	return result;
}

int main() {
	string strA = "dqhwudhqwohdknqwd;nqp";
	string strB = "dhqohdpqwdpkqwn";
	int lenA = strA.length();
	int lenB = strB.length();
	cout << "lcs is " << lcsuffix(strA,strB,lenA,lenB) << endl;
	system("pause");
	return 0;
}
