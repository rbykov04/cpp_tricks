#include <iostream>
#include <algorithm>
#include <stack>


using namespace std;

ostream& operator<<(ostream& os, stack<int>& st){
	if (st.empty()){
		return os;
	}
	int e = st.top();
	os<<e<<" ";
	st.pop();
	os<<st;
	st.push(e);
	return os;
}

stack<int> merge_stack(stack<int> &a, stack<int> &b){
	stack<int> inv;
	stack<int> res;
	while(!a.empty() && !b.empty()){
		inv.push(min(a.top(), b.top()));
		if (a.top() < b.top()){
			a.pop();
		}else{
			b.pop();
		}
	}
	while(!a.empty()){
		inv.push(a.top());
		a.pop();
	}
	
	while(!b.empty()){
		inv.push(b.top());
		b.pop();
	}
	while(!inv.empty()){
		res.push(inv.top());
		inv.pop();
	}

	return res;
}
void sort_stack(stack<int> &st){
	if (st.empty()){
		return;
	}
	int e = st.top();
	st.pop();
	if (st.empty()){
		st.push(e);
		return;
	}
	st.push(e);
	stack<int> a;
	stack<int> b;

	while(!st.empty()){
		a.push(st.top());
		st.pop();
		if (st.empty()){
			break;
		}
		b.push(st.top());
		st.pop();
	}
	sort_stack(a);
	sort_stack(b);
	st = merge_stack(a, b);

}
int main(){
	stack<int> st;
	st.push(1);
	st.push(10);
	st.push(33);
	st.push(144);
	st.push(22);

	cout<<st<<"->"<<"\n";
	sort_stack(st);
	cout<<st<<"\n";
	return 0;
}