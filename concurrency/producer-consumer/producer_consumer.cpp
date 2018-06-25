#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include "ItemRepo.h"

using namespace std;

ItemRepo::ItemRepo()
{
    limit = repo_size;
}

void ItemRepo::Produce(int item)
{
    unique_lock<mutex> mlock(mtx); // get lock

    cout << "Produce " << item << " ...";

    while( items.size() == limit ) {
        cond.wait(mlock); // give lock and wait
    }
    // regain lock
    items.push(item);
    cout << "Done." << endl;

    mlock.unlock();
    
    cond.notify_one();
}

int ItemRepo::Consume()
{
    unique_lock<mutex> mlock(mtx);

    cout << "Consume ..." ;

    while( items.empty() ) {
        cond.wait(mlock);
    }
    int item = items.top();
    items.pop();

    cout << "Done." << endl;

    mlock.unlock();
    cond.notify_one();
}

void ProducerTask(ItemRepo& ir)
{
    for(int i=0;i<num_produce;i++) {
        this_thread::sleep_for(chrono::milliseconds(1));
        ir.Produce(i);
    }
}

void ConsumerTask(ItemRepo& ir)
{
    for(int i=0;i<num_produce;i++) {
        this_thread::sleep_for(chrono::milliseconds(1));
        ir.Consume();
    }
}


int main()
{
    ItemRepo ir;
    thread p1(ProducerTask, ref(ir));
    thread p2(ProducerTask, ref(ir));
    thread p3(ProducerTask, ref(ir));
    thread p4(ProducerTask, ref(ir));

    thread c1(ConsumerTask, ref(ir));
    thread c2(ConsumerTask, ref(ir));
    thread c3(ConsumerTask, ref(ir));
    thread c4(ConsumerTask, ref(ir));

    p1.join();
    p2.join();
    p3.join();
    p4.join();

    c1.join();
    c2.join();
    c3.join();
    c4.join();
}