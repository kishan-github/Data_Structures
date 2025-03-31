/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public void ReorderList(ListNode head) {
        if( (head == null) || (head.next == null) || (head.next.next == null) )
            return;

        ListNode slow = head, fast = head, list1 = head, prev = null;

        while( (slow != null) && (fast != null) && (fast.next != null) ) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        prev.next = null;

        ListNode list2 = Reverse(slow), next = null;
        while( (list1 != null) && (list2 != null) ) {
            next = list1.next;
            list1.next = list2;
            list1 = next;
            next = list2.next;
            if(list1 != null)
                list2.next = list1;
            list2 = next;
        }
    }

    private ListNode Reverse(ListNode head) {
        ListNode curr = head, prev = null, next = head;

        while(curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
}
