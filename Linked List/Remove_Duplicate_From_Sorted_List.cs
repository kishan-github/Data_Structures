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
    public ListNode DeleteDuplicates(ListNode head) {
        ListNode newHead = head, prev = null;

        while(head != null)
        {
            int val = head.val;
            ListNode node = head;
            while( (node != null) && (val == node.val) )
                node = node.next;

            if(head.next != node)
            {
                if(prev != null)
                {
                    prev.next = node;
                }
                else
                {
                    newHead = node;
                }
            }
            else
            {
                prev = head;
            }
            head = node;
        }

        return newHead;
    }
}
