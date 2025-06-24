package LinkedList
import util.defaultEquals
import models.Node


open class LinkedList<T>(val equalsFn: (T, T) -> Boolean = ::defaultEquals) {
    protected var count: Int = 0
    protected open var head: Node<T>? = null

    open fun push(element: T) {
        val node = Node(element)
        var current: Node<T>?
        if (head == null) {
            head = node // Catches null & undefined
        } else {
            current = head
            while (current?.next != null) {
                current = current.next
            }
            current?.next = node
        }
        count++
    }
    open fun getElementAt(index: Int): Node<T>? {
        if (index >= 0 && index < count) {
            var node = head
            for (i in 0 until index) {
                if (node == null) break
                node = node.next
            }
            return node
        }
        return null
    }
    open fun insert(element: T, index: Int): Boolean {
        if (index >= 0 && index <= count) {
            val node = Node(element)
            if (index == 0) {
                val current = head
                node.next = current
                head = node
            } else {
                val previous = getElementAt(index - 1)
                node.next = previous?.next
                previous?.next = node
            }
            count++
            return true
        }
        return false
    }
    open fun removeAt(index: Int): T? {
        if (index >= 0 && index < count) {
            var current = head
            if (index == 0) {
                head = current?.next
            } else {
                val previous = getElementAt(index - 1)
                current = previous?.next
                previous?.next = current?.next
            }
            count--
            return current?.element
        }
        return null
    }
    fun remove(element: T): T? {
        val index = indexOf(element)
        return removeAt(index)
    }
    open fun indexOf(element: T): Int {
        var current = head
        for (i in 0 until count) {
            if (current == null) break
            if (equalsFn(element, current.element))
                return i
            current = current.next
        }
        return -1
    }
    fun isEmpty(): Boolean = size() == 0
    fun size(): Int = count
    open fun getHead(): Node<T>? = head
    open fun clear() {
        head = null
        count = 0
    }
    override fun toString(): String {
        if (head == null) return "null"
        var objString = "${head?.element}"
        var current = head?.next
        for (i in 1 until count) {
            if  (current == null) break
            objString += " ,${current.element}"
            current = current.next
        }
        return objString
    }
}