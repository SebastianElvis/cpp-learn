#include <mutex>
#include <condition_variable>
#include <stack>

using namespace std;

const int repo_size = 100;
const int num_produce = 1000;

class ItemRepo {
public:
    void Produce(int item);
    int Consume();
    ItemRepo();

private:
    stack<int> items;
    int limit;
    mutex mtx;
    condition_variable cond;
};
