class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    private Node head, tail;
    int size;

    public boolean isEmpty() {
        return (head == null);
    }

    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public void add(int element) {
        Node newNode = new Node(element);
        newNode.next = head;
        head = newNode;
        size++;
        if (tail == null) {
            tail = head;
        }
    }

    public void removeAll(int element) {
        if (isEmpty()) {
            System.out.println("List is empty.");
            return;
        }
        while (head != null && head.data == element) {
            head = head.next;
            size--;
        }
        if (head == null) {
            tail = null;
            return;
        }
        Node current = head;
        while (current != null && current.next != null) {
            if (current.next.data == element) {
                current.next = current.next.next;
                size--;
            } else {
                current = current.next;
            }
        }
    }

    public void removeMin() {
        if (head == null) {
            return;
        }

        Node current = head;
        Node minNode = head;
        Node minPrev = null;
        Node prev = null;

        while (current != null) {
            if (current.data < minNode.data) {
                minNode = current;
                minPrev = prev;
            }
            prev = current;
            current = current.next;
        }

        if (minPrev == null) {
            head = head.next;
        } else {
            minPrev.next = minNode.next; 
        }

        size--; 
    }

    public boolean equals(LinkedList list) {
        if (this.size != list.size) { 
            return false;
        }

        Node current1 = this.head;
        Node current2 = list.head;

        while (current1 != null) {
            if (current1.data != current2.data) {
                return false;
            }
            current1 = current1.next;
            current2 = current2.next;
        }

        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.add(5);
        list.add(3);
        list.add(5);
        list.add(2);
        list.add(5);

        System.out.println("Initial list:");
        list.display();

        System.out.println("After removing all 5:");
        list.removeAll(5);
        list.display();

        System.out.println("After removing minimum:");
        list.removeMin();
        list.display();
    }
}