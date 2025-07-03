package DataStructures.Stack

class Stack<T> {
    private val items = mutableListOf<T>()

    fun push(element: T) = items.add(element)
    fun pop(): T? {
        if (items.isEmpty()) return null
        return items.removeAt(items.lastIndex)
    }
    fun peek(): T? = items.lastOrNull()
    fun clear() = items.clear()
    override fun toString(): String =
        if (items.isEmpty()) "Empty"
        else items.joinToString(", ")
}