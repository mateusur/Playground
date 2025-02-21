#include <condition_variable>  // Include for using condition variables
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <algorithm>
#include <random>

using namespace std;

queue<int> buffer;
mutex mtx;
condition_variable producer_cv,consumer_cv;
constexpr int max_buffer_size = 5;
void producerfn(int id) {
  while (true)
  {
    unique_lock<mutex> lck(mtx);
    if(buffer.size()<max_buffer_size){
        int a = rand() % 20;
        cout << "Producer " << id << " produced: " << a << endl;
        buffer.push(a);
        consumer_cv.notify_all();
    }
    else{
        cout << "### Producer " << id << " is waiting" << endl;
        producer_cv.wait(lck,[](){return buffer.size()<max_buffer_size;});
    }
    lck.unlock();
    this_thread::sleep_for(chrono::milliseconds(rand() % 400 + 100));
  } 
}

void consumerfn(int id) {
  while (true) {
    unique_lock<mutex> lck(mtx);
    if(!buffer.empty()){
        cout << "Consumer " << id << " ate " << buffer.front() << endl;
        buffer.pop();
        producer_cv.notify_all();
    }
    else {
        cout << "*** Consumer " << id << " is waiting" << endl;
        consumer_cv.wait(lck,[](){return !buffer.empty();});
    }
    lck.unlock();
    this_thread::sleep_for(chrono::milliseconds(rand() % 400 + 800));
  }
}

int main() {

    int consumers_count = 5;
    int producers_count = 3;
    vector<thread> producers;
    vector<thread> consumers;

    for(int i =0; i < producers_count;++i){
        producers.push_back(thread(producerfn,i+1));
    }
    for(int i =0; i < consumers_count;++i){
        consumers.push_back(thread(consumerfn,i+1));
    }
    for(int i =0; i < producers_count;++i){
        producers[i].join();
    }
    for(int i =0; i < consumers_count;++i){
        consumers[i].join();
    }

  return 0;
}