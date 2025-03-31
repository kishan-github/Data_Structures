/*
You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.
*/
/*
// Definition for a Node.
public class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
}
*/

public class Solution {
    public Node Flatten(Node head) {
        getLast(head);
        return head;
    }

    public Node getLast(Node head)
    {
        Node node = head, temp = null, prev = null;

        while(node != null)
        {
            prev = node;
            if(node.child != null)
            {
                temp = getLast(node.child);
                if(node.next == null)
                {
                    node.next = node.child;
                    node.child.prev = node;
                    prev = temp;
                }
                else
                {
                    node.next.prev = temp;
                    node.child.prev = node;
                    temp.next = node.next;
                    node.next = node.child;
                }
                node.child = null;
                node = temp.next;
            }
            else
            {
                node = node.next;
            }
        }

        return prev;
    }
}
