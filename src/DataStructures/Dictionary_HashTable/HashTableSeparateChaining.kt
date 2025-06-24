package DataStructures.Dictionary_HashTable
import LinkedList.LinkedList
import models.ValuePair
import util.defaultToString

class HashTableSeparateChaining<K, V>(private val toStrFn: (K?) -> String = ::defaultToString) {
    private val table = mutableMapOf<Int, LinkedList<ValuePair<K, V>>>()

    fun djb2Hash(key: K): Int {
        val tableKey = toStrFn(key)
        var hash = 5381L
        for (char in tableKey) {
            hash = ((hash shl 5) + char.code)
        }
        return (hash and 0xffffffff).toInt()
    }
    fun put(key: K, value: V): Boolean {
        if (key != null && value != null) {
            val position = djb2Hash(key)
            if (table[position] == null) {
                table[position] = LinkedList()
            }
            table[position]?.push(ValuePair(key, value))
            return true
        }
        return false
    }
    fun get(key: K): V? {
        val position = djb2Hash(key)
        val linkedList = table[position]
        if (linkedList != null && !linkedList.isEmpty()) {
            var current = linkedList.getHead()
            while (current != null) {
                if (current.element.value == key) {
                    return current.element.value
                }
                current = current.next
            }
        }
        return null
    }
    fun remove(key: K): Boolean {
        val position = djb2Hash(key)
        val linkedList = table[position]
        if (linkedList != null && !linkedList.isEmpty()) {
            var current = linkedList.getHead()
            while (current != null) {
                if (current.element.key == key) {
                    linkedList.remove(current.element)
                    if (linkedList.isEmpty()) {
                        table.remove(position)
                    }
                    return true
                }
                current = current.next
            }
        }
        return false
    }
    fun size(): Int {
        var count = 0
        for (linkedList in table.values) {
            count += linkedList.size()
        }
        return count
    }
    fun isEmpty(): Boolean = size() == 0
    fun clear() = table.clear()
    fun getTable(): Map<Int, LinkedList<ValuePair<K, V>>> = table
    override fun toString(): String {
        if (isEmpty()) return "[]"
        val keys = table.keys.toList()
        var objString = "{${keys[0]} => ${table[keys[0]].toString()}}"
        for (i in 1 until keys.size) {
            objString += ",{${keys[i]} => ${table[keys[i]].toString()}}"
        }
        return objString
    }
}