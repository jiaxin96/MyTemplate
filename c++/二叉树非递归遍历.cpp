    void noRePreorder() {
        stack<node *> s;
        node * p = root;
        while (p || s.size()) {
            if (p) {
                s.push(p);
                cout << p->data << " ";
                p = p->lChild;
            } else {
                p = s.top();
                s.pop();
                p = p->rChild;
            }
        }
    }