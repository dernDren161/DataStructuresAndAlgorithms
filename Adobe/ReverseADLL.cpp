
void swap(struct Node* node)
{
    struct Node* prev = node->prev;
    node->prev = node->next;
    node->next = prev;
}

void reverseDDL(struct Node** headRef)
{
    struct Node* prev = NULL;
    struct Node* curr = *headRef;

    while (curr != NULL)
    {
        swap(curr);

        prev = curr;

        curr = curr->prev;
    }

    if (prev != NULL) {
        *headRef = prev;
    }
}
