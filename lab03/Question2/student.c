#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      if (head == NULL || head->next == NULL)
            return head;

      struct ListNode *prev = NULL;
      struct ListNode *curr = head;

      head = head->next;

      while(curr != NULL && curr->next != NULL){

            struct ListNode *first = curr;
            struct ListNode *second = curr->next;

            first->next = second->next;
            second->next = first;

            if(prev != NULL)
            prev->next = second;

            prev = first;
            curr = first->next;

      }
      
      return head;
}