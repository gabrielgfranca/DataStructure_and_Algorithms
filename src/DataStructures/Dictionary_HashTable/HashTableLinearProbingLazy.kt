package DataStructures.Dictionary_HashTable
import models.ValuePairLazy
import util.defaultToString

class HashTableLinearProbingLazy<K, V>(private val toStrFn: (K?) -> String = ::defaultToString) {
    private val table = mutableMapOf<Int, ValuePairLazy<K, V>>()

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
            val current = table[position]
            if (current == null || current.isDeleted) {
                table[position] = ValuePairLazy(key, value)
            } else {
                var index = position + 1
                while (table[index] != null && table[index]?.isDeleted == false) {
                    index++
                }
                table[index] = ValuePairLazy(key, value)
            }
            return true
        }
        return false
    }
    fun get(key: K): V? {
        val position = djb2Hash(key)
        val current = table[position]
        if (current != null) {
            if (current.key == key && !current.isDeleted) {
                return current.value
            }
            var index = position + 1
            while (table[index] != null &&
                (table[index]?.key!= key || table[index]?.isDeleted == true )
            ) {
                if (table[index]?.key == key && table[index]?.isDeleted == true) {
                    return null
                }
                index++
            }
            val candidate = table[index]
            if (candidate != null && candidate.key == key && !candidate.isDeleted) {
                return candidate.value
            }
        }
        return null
    }
    fun remove(key: K): Boolean {
        val position = djb2Hash(key)
        val current = table[position]
        if (current != null) {
            if (current.key == key && !current.isDeleted) {
                current.isDeleted = true
                return true
            }
            var index = position + 1
            while (table[index] != null &&
                (table[index]?.key != key || table[index]?.isDeleted == true )
            ) {
                index++
            }
            val candidate = table[index]
            if (candidate != null && candidate.key == key && !candidate.isDeleted) {
                candidate.isDeleted = true
                return true
            }
        }
        return false
    }
    fun isEmpty(): Boolean = table.isEmpty()
    fun size(): Int = table.values.count { it.isDeleted }
    fun clear() = table.clear()
    fun getTable(): Map<Int, ValuePairLazy<K, V>> = table
    override fun toString(): String {
        if (isEmpty()) return "[]"
        val entries = table.entries
            .filter { !it.value.isDeleted }
            .map { (key, value) -> "$key => $value" }
        return entries.joinToString(",")
    }
}