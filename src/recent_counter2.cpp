#include <queue>
using namespace std;


class RecentCounter {
    queue<int> q;
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
//  i<100000000:	5,75s user 0,00s system 99% cpu 5,769 total
//  i<1000000000: 	57,33s user 0,00s system 99% cpu 57,330 total

	int i = 3001;
    for (int i = 3001; i<=1000000000; ++i){ 
		counter.ping(i);
	}

}