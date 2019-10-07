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
        d->next = 0;
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
        	tail = d;
            return;
        }
        head = d;
        tail = d;
    }


    NODE *slice_head(){
         NODE * res = head;
         head = head->next;
         return res;
    }

    void push_back(NODE *d){
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
            tail = d;
            return;
        }
        head = d;
        tail = d;
    }
    void push_front(NODE *d){
        if (head){
        	d->next = head;
        	head = d;
        	return;
        }
        head = d;
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

		VALUE operator*() const{
			return c->val;
		}

		NODE* ref(){
			return *c;
		}
	};

	iterator begin() {return iterator(head);}
	iterator end() {return iterator(0);}

	NODE * insert_after(iterator i, NODE *d){
		NODE * next = i.c->next;
		i.c->next = d;
		d->next = next;
		return d;
    }  
    
};
template<class NODE, class VALUE>
void merge_from_sort_list(forward_list_wrapper<NODE, VALUE>& a, forward_list_wrapper<NODE, VALUE>& b){
	auto current = std::begin(a);
	while (std::begin(b) != std::end(b)){
		auto after = current;
		while(after != std::end(a) && *after < *std::begin(b)){
			current = after;
			after++;
		}
		
		if (current == std::end(a)){
			a.push_back(b.head);
			b.head = 0;
			b.tail = 0;
			return;
		}

		NODE * head = b.slice_head();
		// std::cout << *current <<"add slice "<<head->val<<"\n";
		if (current == std::begin(a) && head->val < *current){
			a.push_front(head);
		}else{

			a.insert_after(after, head);
		}
		// current++;

	}
}

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

int main() {
	forward_list_wrapper<ListNode, int> res;
 	forward_list_wrapper<ListNode, int> list;
 	list.push_back(0);
 	list.push_back(4);
 	list.push_back(5);

 	forward_list_wrapper<ListNode, int> list2;
 	list2.push_back(1);
 	list2.push_back(3);
 	list2.push_back(4);

 	forward_list_wrapper<ListNode, int> list3;
 	list3.push_back(0);
 	list3.push_back(6);
	merge_from_sort_list(res, list);
	merge_from_sort_list(res, list2);
 	merge_from_sort_list(res, list3);
	for(auto v : res) {
		std::cout << v <<"\n";
	}




}