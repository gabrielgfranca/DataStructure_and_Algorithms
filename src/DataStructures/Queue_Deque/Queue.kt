package DataStructures.Queue_Deque

class Queue<T> {
    private val items = ArrayDeque<T>()

    fun enqueue(element: T) = items.addLast(element)
    fun dequeue(): T? =
        if (items.isEmpty()) null
        else items.removeFirst()
    fun peek(): T? = items.firstOrNull()
    override fun toString(): String =
        if (items.isEmpty()) "[]"
        else items.joinToString(", ")

}