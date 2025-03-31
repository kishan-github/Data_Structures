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
    public ListNode ReverseKGroup(ListNode head, int k) {
        return ReverseList(head, k);
    }

    public ListNode ReverseList(ListNode head, int k)
    {
        int i = 1;
        ListNode curr = head;
        while ( (i < k) && (curr != null) )
        {
            curr = curr.next;
            i++;
        }

        if ( (i < k) || (curr == null) )
            return head;

        ListNode prev = ReverseList(curr.next, k);
        ReverseKNodes(head, 0, k);
        head.next = prev;
        return curr;
    }

    public ListNode ReverseKNodes(ListNode head, int index, int k)
    {
        if (index >= (k - 1) )
            return head;
        
        ListNode prev = ReverseKNodes(head.next, index + 1, k);
        prev.next = head;
        return head;
    }
}
