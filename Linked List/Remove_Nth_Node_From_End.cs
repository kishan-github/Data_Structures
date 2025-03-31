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
    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode node1 = dummy, node2 = dummy;

        for(int i = 0; i <= n; i++)
        {
            node1 = node1.next;
        }

        while(node1 != null)
        {
            node1 = node1.next;
            node2 = node2.next;
        }

        node2.next = node2.next.next;

        return dummy.next;
    }
}
