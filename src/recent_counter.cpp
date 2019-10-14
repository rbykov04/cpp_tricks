#include <queue>
using namespace std;
template<typename T, size_t MAX_COUNT>
class CycledQueue{
    T q[MAX_COUNT];
    size_t first;
    size_t after;
    size_t count;
public:
    CycledQueue(): first(0), after(0), count(0){};
    
    void push(int t){
        q[first] = t;
        first++;
        count++;
        if (first == MAX_COUNT){
            first = 0;
        }
    }
    const T& front() const{
        return q[after];
    }
    void pop(){
        after++;
        if (after == MAX_COUNT){
            after = 0;
        }
        count--;
    }
    size_t size() const{
        return count;
    }
};

class RecentCounter {
    CycledQueue<int, 3002> q;
public:
    int ping(int t) {
        q.push(t);
        while(q.front() < t - 3000){
            q.pop();
        }
        
        return (int)q.size();
        
    }
};

int main() {
	RecentCounter counter;
//  i<100000000:    1,30s user 0,00s system 99% cpu 1,305 total
//  i<100000000:    12,99s user 0,00s system 99% cpu 12,995 total

	int i = 3001;
    for (int i = 3001; i<=1000000000; ++i){
		counter.ping(i);
	}

}