// typedef struct node {datatype data; struct node *lchild,*rchild;} bitree;
// bitree *q[20]; int r=0,f=0,flag=0;
// void preorder(bitree *bt, char x)
// {
//   if (bt!=0 && flag==0)
// if (bt->data==x) { flag=1; return;}
// else {r=(r+1)% 20; q[r]=bt; preorder(bt->lchild,x); preorder(bt->rchild,x); }
// }
// void parent(bitree *bt,char x)
// {
//    int i;
//    preorder(bt,x);
//    for(i=f+1; i<=r; i++) if (q[i]->lchild->data==x || q[i]->rchild->data) break;
//    if (flag==0) printf("not found x\n");
//    else if (i<=r) printf("%c",bt->data); else printf("not parent");
// }


直接层次遍历吧