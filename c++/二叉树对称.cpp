typedef struct node {int data; struct node *lchild,*rchild;} bitree;
void swapbitree(bitree *bt)
{
	bitree *p;
	if(bt==0) return;
	swapbitree(bt->lchild);
	swapbitree(bt->rchild);
	p=bt->lchild;
	bt->lchild=bt->rchild;
	bt->rchild=p;
}