 template <typename E>

class list
{
private:
	struct Node
	{
		E data;
		Node * prev;
		Node * next;
	};
	
	int nodeCount;
	Node * first;
	
	void clear() {
		while (nodeCount > 0) {
			pop_front();
		}
	}	
	
public:

	list() {
		nodeCount = 0;
	}
	
	~list() {
		clear();
	}
	
	int size() {
		return nodeCount;
	}
	
	bool empty() {
		return nodeCount == 0;
	}

	E front() {
		if (nodeCount == 0)
			throw runtime_error("The first element does not exist.");
		return first->data;
	}
	
	E back() {
		if (nodeCount == 0)
			throw runtime_error("The last element does not exist.");
		return first->prev->data;
	}
	
	void push_back(E e) {
		push_front(e);
		first = first->next;
	}

	void pop_back() {
		if (nodeCount == 0)
			throw runtime_error("The last element does not exist.");
		first = first->prev;
		pop_front();
	}
	
// TODO: You should just submit the function, not the class or the main function.
	list(const list & that);
	list & operator= (const list & that);
	void push_front(E e);
	void pop_front();
};

template<typename E>
list<E>::list(const list & that) {
	nodeCount = 0;
	if (that.nodeCount == 0) {
		nodeCount = 0;
		return;
	}
	Node *it = that.first;
	for (int i = 0; i < that.nodeCount; ++i)
	{
		push_back(it->data);
		it= it->next;
	}
}

template<typename E>
list<E> & list<E>::operator=(const list<E> &that) {
	clear();
	if (that.nodeCount == 0) {
		nodeCount = 0;
		first = 0;
		return *this;
	}
	Node *it = that.first;
	for (int i = 0; i < that.nodeCount; ++i)
	{
		push_back(it->data);
		it= it->next;
	}
	return *this;
}

template<typename E>
void list<E>::push_front(E e) {
	if (!nodeCount) {
		first = new Node;
		first->data = e;
		first->prev = first->next = first;
		nodeCount++;
		return;
	}
	Node * tril = first->prev;
	Node * px  = new Node;
	px->data =e;
	px ->next = first;
	px->prev = first->prev;
	first->prev->next = px;
	first->prev = px;
	first = px;
	nodeCount++;
}

template<typename E>
void list<E>::pop_front() {
	if (nodeCount == 0)
		throw runtime_error("The first element does not exist.");
	if (nodeCount == 1) {
		nodeCount--;
		delete first;
		first == 0;
		return;
	}
	Node * np =first->next;
	Node * tr = first->prev;
	np->prev = tr;
	tr->next = np;
	delete first;
	first = np;
	nodeCount--;

}