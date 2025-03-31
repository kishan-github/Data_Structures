public class Node {
    public int key;
    public int val;
    public Node next;
    public Node prev;
    public Node(int key, int val) {
        this.key = key;
        this.val = val;
        this.next = this.prev = null;
    }
}

public class LRUCache {
    private int capacity;
    private Dictionary<int, Node> cache;
    private Node head;
    private Node tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.cache = new Dictionary<int, Node>();
        this.head = this.tail = null;
    }
    
    public int Get(int key) {
        Node node;

        // Check if key exists in dictionary
        if(!this.cache.TryGetValue(key, out node)) {
            return -1;
        }

        MoveToHead(node);
        return node.val;
    }
    
    public void Put(int key, int value) {
        Node node;

        // If found in dictionary, update the value.
        if(this.cache.TryGetValue(key, out node)) {
            node.val = value;
            MoveToHead(node);
            return;
        }

        // If capacity reached, evict the last used item.
        if(this.capacity == this.cache.Count) {
            evict();
        }

        // Add new node.
        node = new Node(key, value);
        node.next = this.head;
        if(this.head != null)
            this.head.prev = node;
        else
            this.tail = node;
        this.head = node;
        this.cache[key] = node;
    }

    private void MoveToHead(Node node) {
        // No need to update if this node is already head.
        if(node == this.head)
            return;
        
        // remove this node.
        node.prev.next = node.next;
        if(node.next != null)
            node.next.prev = node.prev;
        else
            this.tail = node.prev;
        
        // set this node as head.
        node.next = this.head;
        if(this.head != null)
            this.head.prev = node;
        
        // Update the head.
        this.head = node;
    }

    private void evict() {
        Node node = this.tail;
        
        // Remove key from dictionary.
        this.cache.Remove(node.key);

        // Update tail and head.
        if(node.prev != null) {
            node.prev.next = null;
            this.tail = node.prev;
        } else {
            this.tail = null;
            this.head = null;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */
