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
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode root = null;
        ListNode prevNode = null;

        while (l1 != null && l2 != null)
        {
            int temp = l1.val + l2.val + carry;
            carry = temp / 10;
            ListNode currNode = new ListNode(temp % 10);

            if (prevNode != null)
                prevNode.next = currNode;
            
            prevNode = currNode;
            if (root == null)
                root = currNode;
            
            l1 = l1.next;
            l2 = l2.next;
        }

        while (l1 != null)
        {
            int temp = l1.val + carry;
            carry = temp / 10;
            ListNode currNode = new ListNode(temp % 10);

            if (prevNode != null)
                prevNode.next = currNode;
            prevNode = currNode;
            l1 = l1.next;
        }

        while (l2 != null)
        {
            int temp = l2.val + carry;
            carry = temp / 10;
            ListNode currNode = new ListNode(temp % 10);

            if (prevNode != null)
                prevNode.next = currNode;
            prevNode = currNode;
            l2 = l2.next;
        }

        if (carry > 0)
        {
            ListNode currNode = new ListNode(carry);
            prevNode.next = currNode;
        }

        return root;
    }
}
