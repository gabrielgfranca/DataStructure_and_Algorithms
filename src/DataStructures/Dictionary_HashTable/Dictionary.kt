package DataStructures.Dictionary_HashTable
import util.defaultToString
import models.ValuePair

class Dictionary<K, V>(private val toStrFn: (K?) -> String = ::defaultToString) {
    private val table = mutableMapOf<String, ValuePair<K, V>>()

    fun hasKey(key: K): Boolean = toStrFn(key) in table
    fun set(key: K, value: V): Boolean {
        val tableKey = toStrFn(key)
        table[tableKey] = ValuePair(key, value)
        return true
    }
    fun remove(key: K): Boolean {
        if (hasKey(key)) {
            table.remove(toStrFn(key))
            return true
        }
        return false
    }
    fun get(key: K): V? {
        val valuePair = table[toStrFn(key)]
        return valuePair?.value
    }
    fun keyValues(): Collection<ValuePair<K, V>> = table.values
    fun keys(): List<K> = keyValues().map { it.key }
    fun values(): List<V> = keyValues().map { it.value }
    fun forEach(callbackFn: (key: K, value: V) -> Boolean) {
        for (pair in keyValues()) {
            val shouldContinue = callbackFn(pair.key, pair.value)
            if (!shouldContinue) break
        }
    }
    fun size() = table.size
    fun isEmpty() = table.isEmpty()
    fun clear() = table.clear()
    override fun toString(): String = keyValues().joinToString(",")
}
