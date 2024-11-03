struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode * reverse(struct ListNode *head){
    struct ListNode *tail = NULL, *temp;
    while(head){
        temp = head->next;
        head->next = tail;
        tail = head;
        head = temp;
    }
    return tail;
}

struct ListNode* removeNodes(struct ListNode* head) {
    struct ListNode *temp, *tail;

    //reverse linked list
    head = reverse(head);
    tail = head;
    //compare value of head and temp, if head < temp , temp move on
    temp = head->next;
    while(temp){
        if(head->val <= temp->val) {
            head->next = temp;
            head = temp;
        }
        temp = temp->next;        
    }
    head->next = temp;

    //reverse again
    return reverse(tail);
}