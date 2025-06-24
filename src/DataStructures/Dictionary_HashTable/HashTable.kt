package DataStructures.Dictionary_HashTable
import models.ValuePair
import util.defaultToString

class HashTable<K, V>(private val toStrFn: (K?) -> String = ::defaultToString) {
    private val table = mutableMapOf<Int, ValuePair<K, V>>()

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
            table[position] = ValuePair(key, value)
            return true
        }
        return false
    }
    fun get(key: K): V? {
        val valuePair = table[djb2Hash(key)]
        return valuePair?.value
    }
    fun remove(key: K): Boolean {
        val hash = djb2Hash(key)
        val valuePair = table[djb2Hash(key)]
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