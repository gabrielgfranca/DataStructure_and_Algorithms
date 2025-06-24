package DataStructures.Dictionary_HashTable
import LinkedList.LinkedList
import models.ValuePair
import util.defaultToString

class HashTableLinearProbing<K, V>(private val toStrFn: (K?) -> String = ::defaultToString) {
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
            var position = djb2Hash(key)
            while (table[position] != null) {
                position++
            }
            table[position] = ValuePair(key, value)
            return true
        }
        return false
    }
    fun get(key: K): V? {
        var position = djb2Hash(key)
        var valuePair = table[position]
        while (valuePair != null && valuePair.key != null) {
            position++
            valuePair = table[position]
        }
        return valuePair?.value
    }
    fun remove(key: K): Boolean {
        val position = djb2Hash(key)
        val valuePair = table[position]
        if (valuePair != null) {
            if (valuePair.key != null) {
                table.remove(position)
                verifyRemoveSideEffect(key, position)
                return true
            }
            var index = position + 1
            while (table[index] != null && table[index]?.key != null) {
                index++
            }
            if (table[index]?.key == key) {
                table.remove(index)
                verifyRemoveSideEffect(key, position)
                return true
            }
        }
        return false
    }
    private fun verifyRemoveSideEffect(key: K, removedPosition: Int) {
        val hash = djb2Hash(key)
        var index = removedPosition + 1
        var currentRemovedPosition = removedPosition
        while (table[index] != null) {
            val posHash = djb2Hash((table[index]!!.key))
            if (posHash <= hash || posHash <= currentRemovedPosition) {
                table[currentRemovedPosition] = table[index]!!
                table.remove(posHash)
                currentRemovedPosition = posHash
            }
            index++
        }
    }
    fun isEmpty(): Boolean = table.isEmpty()
    fun size(): Int = table.size
    fun clear() = table.clear()
    fun getTable(): Map<Int, ValuePair<K, V>> = table
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