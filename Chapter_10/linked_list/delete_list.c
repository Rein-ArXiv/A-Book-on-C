/* In file delete_list.c */

/* Recursive deletion of a list. */

void delete_list(LINK head)
{
    if (head != NULL) {
        delete_list(head -> next);
        free(head);             // release stoarge
    }
}