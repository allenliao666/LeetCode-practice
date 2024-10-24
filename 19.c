struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p = head, *temp = head;
    int num = 0;
    if(!(head->next)) return NULL;
    //calculate length of input
    while(p){
        num++;
        p = p->next;
    }
    p = head->next;
    if(num == n){
        return p;   
    }
    for(int i = 0; i < num - n - 1; i++){
        p = p->next;
        temp = temp->next;
    }
    temp->next = p->next;
    p->next = NULL;
    return head;
}