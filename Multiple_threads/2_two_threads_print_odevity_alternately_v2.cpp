#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#define maxnumber 100
using namespace std;

mutex twolock;
int counter = 0;

int isEven(int num) {
	if (num % 2)
		return 0;
	return 1;
}

void printEven() {
	while (counter < maxnumber) {
		if (!isEven(counter)) {
			twolock.lock();
			cout << ++counter << " in thread " << this_thread::get_id() << endl;
			twolock.unlock();
		}
		else
			this_thread::sleep_for(chrono::microseconds(500));
	}
}

void printOdd() {
	while (counter < maxnumber) {
		if (isEven(counter)) {
			twolock.lock();
			cout << ++counter << " in thread " << this_thread::get_id() << endl;
			twolock.unlock();
		}
		else
			this_thread::sleep_for(chrono::microseconds(500));
	}
}

int main() {
	thread eventh(printEven);
	thread oddth(printOdd);
	eventh.join();
	oddth.join();
	system("pause");
	return 0;
}
