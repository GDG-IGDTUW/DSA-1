import java.util.HashMap;

class LRUCache {

    // Doubly Linked List Node
    class Node {
        int key;
        int value;
        Node prev;
        Node next;

        Node(int k, int v) {
            key = k;
            value = v;
        }
    }

    private int capacity;
    private HashMap<Integer, Node> map;

    // Dummy head and tail
    private Node head;
    private Node tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>();

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head.next = tail;
        tail.prev = head;
    }

    // ================= GET =================
    public int get(int key) {
        if (!map.containsKey(key))
            return -1;

        Node node = map.get(key);

        // move to front
        remove(node);
        insertAfterHead(node);

        return node.value;
    }

    // ================= PUT =================
    public void put(int key, int value) {

        if (map.containsKey(key)) {
            Node node = map.get(key);
            node.value = value;

            remove(node);
            insertAfterHead(node);
        } else {

            if (map.size() == capacity) {
                // remove LRU node
                Node lru = tail.prev;
                remove(lru);
                map.remove(lru.key);
            }

            Node newNode = new Node(key, value);
            insertAfterHead(newNode);
            map.put(key, newNode);
        }
    }

    // ================= DLL helpers =================

    private void remove(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    private void insertAfterHead(Node node) {
        node.next = head.next;
        node.prev = head;

        head.next.prev = node;
        head.next = node;
    }
}
