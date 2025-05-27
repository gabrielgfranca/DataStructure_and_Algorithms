package DataStructure.LinkedList

class StackLinkedList<T> {
    private val items = DoublyLinkedList<T>()

    fun push(element: T) = items.push(element)
    fun pop(): T? {
        if (items.isEmpty()) return null
        val result = items.removeAt(size() - 1)
        return result
    }
    fun peek(): T? {
        if (items.isEmpty()) return null
        return items.getElementAt(size() - 1)?.element
    }
    fun isEmpty(): Boolean = items.isEmpty()
    fun size(): Int = items.size()
    fun clear() = items.clear()
    override fun toString() = items.toString()
}