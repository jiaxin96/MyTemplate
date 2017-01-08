void insert(node *& root, int val) {
    if (root == NULL) {
        root = new node(val);
        return;
    }
    if (val > root->v) {
        insert(root->r, val);
        int rh = TreeHeight(root->r);
        int lh = TreeHeight(root->l);
        int detH = (rh > lh ? rh - lh : lh - rh);
        if (detH > 1) {
            int rlh = TreeHeight(root->r->l);
            int rrh = TreeHeight(root->r->r);
            node *k1 = root;
            node *k2 = root->l;
            node *k3 = root->r;
            node *k4 = root->r->l;
            node *k5 = root->r->r;
            if (rlh > rrh) {
                k1->r = k4->l;
                k3->l = k4->r;
                k4->l = k1;
                k4->r = k3;
                root = k4;
            } else {
                k3->l = k1;
                k1->r = k4;
                root = k3;
            }
        }
    } else if (val < root->v) {
        insert(root->l, val);
        int rh = TreeHeight(root->r);
        int lh = TreeHeight(root->l);
        int detH = (rh > lh ? rh - lh : lh - rh);
        if (detH > 1) {
            int llh = TreeHeight(root->l->l);
            int lrh = TreeHeight(root->l->r);
            node *k1 = root;
            node *k2 = root->r;
            node *k3 = root->l;
            node *k4 = root->l->l;
            node *k5 = root->l->r;
            if (lrh > llh) {
                k3->r = k5->l;
                k1->l = k5->r;
                k5->r = k1;
                k5->l = k3;
                root = k5;
            } else {
                k1->l = k5;
                k3->r = k1;
                root = k3;
            }
        }
    }
}
