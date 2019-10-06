#include <iostream>
#include <algorithm>

template<class NODE, class VALUE>
struct forward_list_wrapper{
    NODE *head;
    NODE *tail;
    forward_list_wrapper():head(0), tail(0){
        
    }
    forward_list_wrapper(NODE* _head):head(_head), tail(0){
        
    }
    void push_back(VALUE v){
        NODE *d = new NODE(v);
        if (tail){
            tail->next=d;
            tail = d;
            return;
        }
        if (head){
        	tail = head;
        	while(tail->next){
        		tail = tail->next;
        	}
        }
        head = d;
        tail = d;
    }
    struct iterator: public std::iterator<
						std::input_iterator_tag,   // iterator_category
						NODE,                      // value_type
						NODE,                      // difference_type
						const NODE*,               // pointer
						NODE                       // reference
									  >{
		NODE *c = 0;
		explicit iterator(NODE *_c = 0) : c(_c) {}

		iterator& operator++() {
			c = c->next;
			return *this;
		}
		iterator operator++(int) {
			iterator retval = *this;
			++(*this);
			return retval;
		}
		bool operator==(iterator other) const {
			return c == other.c;
		}
		bool operator!=(iterator other) const {return !(*this == other);}
		NODE* operator*() const {
			return c;
		}
	};

	iterator begin() {return iterator(head);}
	iterator end() {return iterator(0);}
    
};

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

int main() {
 	forward_list_wrapper<ListNode, int> list;
 	list.push_back(1);
 	list.push_back(1);
 	list.push_back(2);
 	list.push_back(3);
	for(auto v : list) {
		std::cout << v->val <<'\n';
	}




}