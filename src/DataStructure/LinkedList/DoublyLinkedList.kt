package DataStructure.LinkedList

class DoublyLinkedList<T>(equalsFn: (T, T) -> Boolean = ::defaultEquals) : LinkedList<T>(equalsFn) {
    class DoublyNode<T>(element: T) : Node<T>(element) { var previous: DoublyNode<T>? = null }
    private var tail: DoublyNode<T>? = null

    override fun push(element: T) {
        val node = DoublyNode(element)
        if (head == null) {
            head = node
            tail = node
        } else {
            tail?.next= node
            node.previous = tail
            tail = node
        }
        count++
    }
    override fun getElementAt(index: Int): DoublyNode<T>? = super.getElementAt(index) as? DoublyNode<T>
    override fun insert(element: T, index: Int): Boolean {
        if (index >= 0 && index <= count) {
            val node = DoublyNode(element)
            var current = head as? DoublyNode<T>
            if (index == 0) {
                if (head == null) {
                    head = node
                    tail = node
                } else {
                    node.next = head
                    current?.previous = node
                    head = node
                }
            } else if (index == count) {
                current = tail
                current?.next = node
                node.previous = current
                tail = node
            } else {
                val prev = getElementAt(index - 1)
                current = prev?.next as? DoublyNode<T>
                node.next = current
                prev?.next = node
                current?.previous = node
                node.previous = prev
            }
            count++
            return true
        }
        return false
    }
    override fun removeAt(index: Int): T? {
        if (index >= 0 && index < count) {
            var current = head as? DoublyNode<T>
            if (index == 0) {
                head = head?.next
                if (count == 1) tail = null
                else (head as? DoublyNode<T>)?.previous = null
            } else if (index == count - 1) {
                current = tail
                tail = current?.previous
                tail?.next = null
            } else {
                current = getElementAt(index)
                val prev = current?.previous
                prev?.next = current.next
                (current?.next as? DoublyNode<T>)?.previous = prev
            }
            count--
            return current?.element
        }
        return null
    }
    override fun indexOf(element: T): Int {
        var current = head
        var index = 0
        while (current != null) {
            if (equalsFn(element, current.element)) return index
            index++
            current = current.next
        }
        return -1
    }
    override fun getHead(): DoublyNode<T>? = head as? DoublyNode<T>
    fun getTail(): DoublyNode<T>? = tail
    override fun clear() {
        super.clear()
        tail = null
    }
    override fun toString(): String {
        if (head == null) return "null"
        var objString = "${head?.element}"
        var current = head?.next
        while (current != null) {
            objString += " ,${current.element}"
            current = current.next
        }
        return objString
    }
    fun inverseToString(): String {
        if (tail == null) return "null"
        var objString = "${tail?.element}"
        var prev = tail?.previous
        while (prev != null) {
            objString += " ,${prev.element}"
            prev = prev.previous
        }
        return objString
    }
}