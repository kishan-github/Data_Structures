/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        ListNode nodeA = headA;
        ListNode nodeB = headB;
        int i = 0, lenA = 0, lenB = 0;

        while(nodeA != null)
        {
            lenA++;
            nodeA = nodeA.next;
        }

        while(nodeB != null)
        {
            lenB++;
            nodeB = nodeB.next;
        }

        nodeA = headA;
        nodeB = headB;

        if(lenA < lenB)
        {
            while(i < (lenB - lenA))
            {
                nodeB = nodeB.next;
                i++;
            }
        }
        else
        {
            while(i < (lenA - lenB))
            {
                nodeA = nodeA.next;
                i++;
            }
        }

        while(nodeA != nodeB)
        {
            nodeA = nodeA.next;
            nodeB = nodeB.next;
        }

        return nodeA;
    }
}
