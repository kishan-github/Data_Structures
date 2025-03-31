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
    public ListNode OddEvenList(ListNode head) {
        if( (head == null) || (head.next == null) || (head.next.next == null) )
            return head;
        
        ListNode l1 = head, l2 = head.next, prev1 = null, prev2 = null;
        ListNode temp = l2;

        while( (l1 != null) && (l1.next != null) &&
               (l2 != null) && (l2.next != null) ) 
        {
            prev1 = l1;
            prev2 = l2;
            l1 = l1.next.next;
            prev1.next = l1;
            l2 = l2.next.next;
            prev2.next = l2;
        }
        
        l1.next = temp;
        return head;
    }
}
