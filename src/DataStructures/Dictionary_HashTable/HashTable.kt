package DataStructures.Dictionary_HashTable
import models.ValuePair
import util.defaultToString

class HashTable<K, V>(private val toStrFn: (K?) -> String = ::defaultToString) {
    private val table = mutableMapOf<Int, ValuePair<K, V>>()

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
            table[position] = ValuePair(key, value)
            return true
        }
        return false
    }
    fun get(key: K): V? {
        val valuePair = table[hashCode(key)]
        return valuePair?.value
    }
    fun remove(key: K): Boolean {
        val hash = hashCode(key)
        val valuePair = table[hashCode(key)]
        if (valuePair != null) {
            table.remove(hash)
            return true
        }
        return false
    }
    fun getTable(): MutableMap<Int, ValuePair<K, V>> = table
    fun isEmpty(): Boolean = table.isEmpty()
    fun size(): Int = table.size
    fun clear() = table.clear()
    override fun toString(): String {
        if (isEmpty()) return "{}"
        val keys = table.keys.toList()
        val firstKey = keys.first()
        var objString = "{$firstKey => ${table[firstKey].toString()}}"
        for (i in 1 until keys.size) {
            val key = keys[i]
            objString += ",{$key => ${table[key].toString()}}"
        }
        return objString
    }
}