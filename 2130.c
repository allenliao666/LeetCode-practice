struct ListNode {
    int val;
    struct ListNode *next;
};

int pairSum(struct ListNode* head) {
    struct ListNode *p = head, *slow = head, *fast = head, *rightHead = NULL, *temp;
    int max = 0, sum = 0;
    //find the beginning position of second list
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    //reverse the second list
    while(slow){
        temp = slow->next;
        slow->next = rightHead;
        rightHead = slow;        
        slow = temp;
    }

    while(rightHead){
        sum = head->val + rightHead->val;
        if(max < sum) max = sum;
        head = head->next;
        rightHead = rightHead->next;
    }
    return max;
}



// int pairSum(struct ListNode* head) {
//     // allocate an array to store ListNode->val
//     int res[100000] = {0};
//     struct ListNode *p = head;
//     int i = 0, max = 0, temp = 0;
//     while(p){
//         res[i] = p->val;
//         i++;
//         p = p->next;
//     }

//     for(int j = 0; j < i/2;j++){
//         temp = res[j] + res[i - j - 1];
//         if(max < temp) max = temp;
//     }
//     return max;
// }