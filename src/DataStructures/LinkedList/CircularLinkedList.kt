package LinkedList
import util.defaultEquals
import models.Node

class CircularLinkedList<T> (equalsFn: (T, T) -> Boolean = ::defaultEquals) : LinkedList<T>(equalsFn) {

    override fun push(element: T) {
        val node = Node(element)
        var current: Node<T>?
        if (head == null) head = node
        else {
            current = super.getElementAt(super.size() - 1)
            current?.next = node
        }
        node.next = head
        count++
    }
    override fun insert(element: T, index: Int): Boolean {
        if (index >= 0 && index <= count) {
            val node = Node(element)
            var current = head
            if (index == 0) {
                if (head == null) {
                    head = node
                    node.next = head
                } else {
                    node.next = current
                    current = super.getElementAt(super.size() - 1)
                    head = node
                    current?.next = head
                }
            } else {
                val prev = super.getElementAt(index - 1)
                node.next = prev?.next
                prev?.next = node
            }
            count++
            return true
        }
        return false
    }
    override fun removeAt(index: Int): T? {
        if (index >= 0 && index < count) {
            var current = head
            if (index == 0) {
                if (super.size() == 1) head = null
                else {
                    val removed = head
                    current = super.getElementAt(super.size() - 1)
                    head = head?.next
                    current?.next = head
                    current = removed
                }
            } else {
                val prev = super.getElementAt(index - 1)
                current = prev?.next
                prev?.next = current?.next
            }
            count--
            return current?.element
        }
        return null
    }
}