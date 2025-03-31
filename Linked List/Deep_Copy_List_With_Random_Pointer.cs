/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;
    
    public Node(int _val) {
        val = _val;
        next = null;
        random = null;
    }
}
*/

public class Solution {
    public Node CopyRandomList(Node head) {
        Dictionary<Node, Node> map = new Dictionary<Node, Node>();
        Node node = head;

        if(head == null)
            return null;

        while(node != null)
        {
            Node temp = new Node(node.val);
            map[node] = temp;
            node = node.next;
        }

        node = head;
        while(node != null)
        {
            Node temp = map[node];
            temp.next = node.next == null ? null : map[node.next];
            temp.random = node.random == null ? null : map[node.random];
            node = node.next;
        }

        return map[head];
    }
}
