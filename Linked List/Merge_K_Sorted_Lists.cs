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
    public ListNode MergeKLists(ListNode[] lists) {
        int finishedListCount = 0, numberOfLists = lists.Length, minValue = 0, minIndex = 0;
        ListNode curr = null;
        ListNode finalList = null;

        while (true)
        {
            finishedListCount = 0;
            minValue = int.MaxValue;
            minIndex = 0;
            for (int i = 0; i < numberOfLists; i++)
            {
                if (lists[i] == null)
                {
                    finishedListCount++;
                    continue;
                }
                if (minValue > lists[i].val)
                {
                    minValue = lists[i].val;
                    minIndex = i;
                }
            }
            if (finishedListCount == numberOfLists)
                break;
            
            lists[minIndex] = lists[minIndex].next;
            if (finalList == null)
            {
                curr = new ListNode(minValue);
                finalList = curr;
            }
            else
            {
                curr.next = new ListNode(minValue);
                curr = curr.next;
            }
        }

        return finalList;
    }
}
