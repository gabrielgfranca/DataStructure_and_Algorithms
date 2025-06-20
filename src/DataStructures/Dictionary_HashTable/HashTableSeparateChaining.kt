package DataStructures.Dictionary_HashTable
import LinkedList.LinkedList
import models.ValuePair
import util.defaultToString

class HashTableSeparateChaining<K, V>(private val toStrFn: (K?) -> String = ::defaultToString) {
    private val table = mutableMapOf<Int, LinkedList<ValuePair<K, V>>>()

    fun hashCode(key: K): Int {
        if (key is Number) return key.toInt()
        val tableKey = toStrFn(key)
        var hash = 0
        for (char in tableKey)
            hash += char.code
        return hash % 37
    }
    fun put(key: K, value: V): Boolean {
        if (key != null && value != null) {
            val position = hashCode(key)
            if (table[position] == null) {
                table[position] = LinkedList()
            }
            table[position]?.push(ValuePair(key, value))
            return true
        }
        return false
    }
}