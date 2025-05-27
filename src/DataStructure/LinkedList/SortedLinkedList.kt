package DataStructure.LinkedList

object Compare {
    const val LESS_THAN = -1
    const val BIGGER_THAN = 1
    const val EQUALS = 0
}
fun <T : Comparable<T>> defaultCompare(a: T, b: T): Int {
    return when {
        a == b -> Compare.EQUALS
        a < b  -> Compare.LESS_THAN
        else   -> Compare.BIGGER_THAN
    }
}

class SortedLinkedList<T : Comparable<T>>(
    equalsFn: (T, T) -> Boolean = ::defaultEquals,
    private val compareFn: (T, T) -> Int = ::defaultCompare
) : LinkedList<T>(equalsFn)  {

    override fun insert(element: T, index: Int): Boolean {
        if (isEmpty()){
            return super.insert(element, if(index == 0) index else 0)
        }
        val pos = getIndexNextSortedElement(element)
        return super.insert(element, pos)
    }
    fun getIndexNextSortedElement(element: T): Int {
        var current = head
        val i = 0
        while (i < size() && current != null) {
            val comp = compareFn(element, current.element)
            if (comp == Compare.LESS_THAN) return i
            current = current.next
        }
        return i
    }
}