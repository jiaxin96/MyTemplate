template <typename E>
class LinkedList
{
private:

  // inner class: linked-list node
  class Node
  {
  public:
    E data;
    Node * next;
  };

  Node * first;

public:
  LinkedList() {
    first = 0;
  }

  ~LinkedList() {
    while (first != 0) {
      removeFirst();
    }
  }

  E getFirst() const{
    return first->data;
  }

  bool isEmpty() const{
    return first == 0;
  }
  void inverseList();
// You should just submit the function, not the class or the main function.
  LinkedList(const LinkedList & that);
  LinkedList & operator= (const LinkedList & that);
  void removeFirst() ;
  void addFirst(E data);
};

template <typename E>
LinkedList<E>::LinkedList(const LinkedList & that) {
  if (!that.first) {
    first = 0;
    return;
  }
  first  = new Node;
  first->data = that.first->data;
  Node * tf = that.first;
  Node * mf = first;
  while (tf->next) {
    tf = tf->next;
    mf->next = new Node;
    mf->next->data = tf->data;
    mf = mf->next;
  }
  mf->next = 0;
}

template <typename E>
LinkedList<E> & LinkedList<E>::operator=(const LinkedList<E> &that) {
  while (first != 0) {
    removeFirst();
  }
  if (!that.first) {
    first = 0;
    return *this;
  }
  first  = new Node;
  first->data = that.first->data;
  Node * tf = that.first;
  Node * mf = first;
  while (tf->next) {
    tf = tf->next;
    mf->next = new Node;
    mf->next->data = tf->data;
    mf = mf->next;
  }
  mf->next = 0; 
  return *this;
}

template<typename E>
void LinkedList<E>::removeFirst() {
  if (!first) return;
  Node * temp = first->next;
  delete first;
  first = temp;
}
template<typename E>
void LinkedList<E>::addFirst(E data) {
  if (!first) {
    first = new Node;
    first->data = data;
    first->next = 0;
    return;
  }
  Node * temp = new Node;
  temp->data =data;
  temp->next =first;
  first =temp;
}
template<typename E>
void LinkedList<E>::inverseList() {
  if (!first) return;
  Node* p = first->next;
  Node* r = first;
  Node* q = 0;
  while (p) {
    r->next = q;
    q = r;
    r = p;
    p = p->next;
  }
  r->next = q;
  first = r;
}