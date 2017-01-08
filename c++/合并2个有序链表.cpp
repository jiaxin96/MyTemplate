template<typename E>
Node<E>* merge(LinkedList<E> &l1, LinkedList<E> &l2) {
  Node<E>* mf = 0;
  Node<E>* f1 = l1.first;
  Node<E>* f2 = l2.first;
  Node<E>* temp = 0;
  while (f1 && f2) {
    if (f1->data <= f2->data) {
      if (!mf) {
        mf = f1;
        temp = f1;
      } else {
        temp->next = f1;
        temp = temp->next;
      }
      f1=f1->next;
    } else {
      if (!mf) {
        mf = f2;
        temp = f2;
      } else {
        temp->next = f2;
        temp = temp->next;
      }
      f2=f2->next;
    }
  }
  if (f1) {
    temp->next = f1;
  } else if (f2) {
    temp->next = f2;
  } else {
    temp->next = 0;
  }
  return mf;
}
