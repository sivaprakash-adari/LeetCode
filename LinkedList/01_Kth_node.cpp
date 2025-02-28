#include<iostream>

using namespace std;

struct ListNode {
   int val;
   ListNode* next;
   ListNode() : val(0),next(nullptr) {}
   ListNode(int val): val(val), next(nullptr) {}
   ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* find_intersection_node(ListNode* headA, ListNode* headB) {
    ListNode* temp_headA = headA;
    ListNode* temp_headB = headB;
    int attach = 0;
   
    while (temp_headA != nullptr) {
         if (attach == 0 && temp_headA->next == nullptr) {
             temp_headA->next = headB;
             attach = 1;
         }
         
         if (temp_headB->next == nullptr)
             temp_headB->next = headA;

        if (temp_headA == temp_headB)
            return temp_headA;

        temp_headA = temp_headA->next;
        temp_headB = temp_headB->next;
    }

    return nullptr;
}

void displayNodes(ListNode* node)  { 
    while(node->next != nullptr) {
        cout << node->val << "->";
        node = node->next;
    }
    cout << node->val << endl;
}

int main() {
    ListNode *headA, *prevA;
    ListNode *headB, *prevB;

    for (int i = 1; i < 20 ; i++) {
        ListNode *node= new ListNode(i);
        if (i < 6) {
            if (i == 1) 
                headA = prevA = node;
            else  {
                prevA->next = node;
                prevA = prevA->next;
            }
        }
        else if (i < 11){
            if (i == 6) 
                headB = prevB = node;
            else  {
                prevB->next = node;
                prevB = prevB->next;
            }
        }
        else {
            prevA->next = node;
            prevB->next = node;
            prevB = prevB->next;
            prevA = prevA->next;
        }
    }
    displayNodes(headA);
    displayNodes(headB);

    ListNode *intersect_node = find_intersection_node(headA, headB);
    
    cout << "Inersection node val = " << intersect_node->val << endl;
}