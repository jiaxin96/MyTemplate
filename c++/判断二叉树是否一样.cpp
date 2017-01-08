typedef struct node {datatype data; struct node *lchild,*rchild;} bitree;
int judgebitree(bitree *bt1,bitree *bt2)
{
	if (bt1==0 && bt2==0) return(1);
	else if (bt1==0 || bt2==0 ||bt1->data!=bt2->data) return(0);
	else return(judgebitree(bt1->lchild,bt2->lchild)*judgebitree(bt1->rchild,bt2->rchild));
}