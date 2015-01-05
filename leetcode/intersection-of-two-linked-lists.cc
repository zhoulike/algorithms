/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 **/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return nullptr;

        auto lastA = headA, lastB = headB;
        int countA = 1, countB = 1;
        while (lastA->next) {
            ++countA;
            lastA = lastA->next;
        }
        while (lastB->next) {
            ++countB;
            lastB = lastB->next;
        }
        if (lastA != lastB)
            return nullptr;

        if (countA < countB) {  //make headA has more elements
            swap(headA, headB);
            swap(countA, countB);
        }
        int diff = countA - countB;
        while (diff--)
            headA = headA->next;
        while (headA && headB) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
