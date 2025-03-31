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
    public ListNode RotateRight(ListNode head, int k) {
        if ( (head == null) || (k == 0) )
            return head;

        int length = LengthOfList(head);
        if ( (length < 2) || (k == length) )
            return head;
        int actualRotate = length - (k % length) ;
        if (actualRotate == length)
            return head;

        int curr = 1;
        ListNode node1 = head, node2 = head, node3 = head;

        while (curr < actualRotate) {
            node2 = node2.next;
            curr++;
        }

        node1 = node2;
        if (node2.next == null) {
            head.next = null;
            node2.next = head;
            return node2;
        } else {
            node3 = node2.next;
        }

        while (node2.next != null) {
            node2 = node2.next;
        }

        node2.next = head;
        node1.next = null;
        return node3;
    }

    public int LengthOfList(ListNode head) {
        int length = 0;
        while (head != null)
        {
            length++;
            head = head.next;
        }

        return length;
    }
}
