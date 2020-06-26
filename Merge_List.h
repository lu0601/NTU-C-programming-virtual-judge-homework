struct node
{
    int value;
    struct node * next;
};
struct node *merge(struct node *list1, struct node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    if (list1->value < list2->value)
    {
        //printf("list1<list2.\n");
        list1->next = merge(list1->next, list2);
        return list1;
    }
    else
    {
        //printf("list1>=list2");
        list2->next = merge(list1, list2->next);
        return list2;
    }
}
