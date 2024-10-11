struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head) {
    // if number of node is 0, 1, 2 return head
    if(!head || !head->next || !head->next->next) return head;
    struct ListNode *even = head->next,*evenHead = head->next, *odd = head;
    
    //traverse the list, divide into 2 list(odd and even)
    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    // Two lists finished, link oddTail to evenHead
    odd->next = evenHead;
    return head;
}