int main() {
    ListNode* list1;
    for (int i = 0; i < 7; i++) {
        list1->next = new ListNode(i);
        list1 = list1->next;
    }

    return 0;
}

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mlist_ptr;
        
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        
        if (list1->val <= list2->val) {
            mlist_ptr = list1;
            list1 = list1->next;
        } else {
            mlist_ptr = list2;
            list2 = list2->next;
        }
        
        ListNode* head_ptr = mlist_ptr;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                mlist_ptr->next = list1;
                list1 = list1->next;
            } else {
                mlist_ptr->next = list2;
                list2 = list2->next;
            }
            mlist_ptr = mlist_ptr->next;
        }

        if (!list1)
            mlist_ptr->next = list2;
        else
            mlist_ptr->next = list1;

        return head_ptr;
    }