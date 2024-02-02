void createtree(NODE BST[MAX])
{
    int ele,choice;
    printf("enter the element");
    scanf("%d",&ele);
    bst[0].info=ele;
    bst[0].used=1;
    while(i<MAX  &&bst[i].used)
    {
        if(ele<bst[i].info)
            i=2*i+1;
        else
            i=2*i+2;

    }
    bst[i].info=ele;
    bst[i].used=1;

}
void levelorder(NODE bst[MAX])
{
    for(int i;i<MAX;i++)
    {
        if(bst[i].used==1)
        {
            printf("%d",bst[i].info);
        }
    }
}
void inorder(NODE bst[MAX],int i)
{
    if(i<MAX && bst[i].used)
    {
        inorder(bst,2*i+1);
        printf("%d",bst[i].info);
        inorder(bst,2*i+2);
    }
}

void postorder(NODE bst[MAX],int i)
{
    if(i<MAX && bst[i].used)
    {
        postorder(bst,2*i+1);
        postorder(bst,2*i+2);
        printf("%d",bst[i].info);
    }
}