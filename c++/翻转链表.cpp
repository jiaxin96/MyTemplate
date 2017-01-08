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