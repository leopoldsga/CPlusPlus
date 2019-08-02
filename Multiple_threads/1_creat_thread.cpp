#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex th_lock;

void func (){
	th_lock.lock();
	cout<<"My thread id = "<<this_thread::get_id()<<endl;
	cout<<"Sun"<<endl;
	cout<<"Exiting hread "<<this_thread::get_id()<<endl<<endl;
	th_lock.unlock();
}

int main(){
	thread th1(func);
	thread th2(func);
	thread th3(func);
	th1.join();
	th2.join();
	th3.join();
	return 0;
}
