#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

#define MAXN 50

mutex th_lock;
int counter = 0;

bool isEven (int number){
	if(number%2)
		return false;
	return true;
}

void printEven(){
	while(counter<=MAXN){
		th_lock.lock();
		if(isEven(counter)){
			cout<<this_thread::get_id()<<": "<<counter<<endl;
			counter++;
			th_lock.unlock();
		}
		else{
			th_lock.unlock();
			this_thread::sleep_for(chrono::seconds(1));
		}
	}
}

void printOdd(){
        while(counter<=MAXN){
                th_lock.lock();
                if(!isEven(counter)){
                        cout<<this_thread::get_id()<<": "<<counter<<endl;
                        counter++;
			th_lock.unlock();
                }
                else{
			th_lock.unlock();
                        this_thread::sleep_for(chrono::seconds(1));
		}
        }
	
}

int main(){
	thread thEven(printEven);
	thread thOdd(printOdd);
	thEven.join();
	thOdd.join();
	return 0;
}
