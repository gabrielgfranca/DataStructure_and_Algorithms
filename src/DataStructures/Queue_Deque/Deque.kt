package DataStructures.Queue_Deque

class Deque<T> {
    private val items = ArrayDeque<T>()

    fun addBack(element: T) = items.addLast(element)
    fun addFront(element: T) = items.addFirst(element)
    fun removeFront(): T? =
        if (items.isEmpty()) null
        else items.removeFirst()
    fun removeBack(): T? =
        if (items.isEmpty()) null
        else items.removeLast()
    fun peekFront(): T? = items.firstOrNull()
    fun peekBack(): T? = items.lastOrNull()
    override fun toString(): String =
        if (items.isEmpty()) "[]"
        else items.joinToString(", ")
}