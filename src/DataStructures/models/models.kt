package models

open class Node<T>(val element: T) {
    var next: Node<T>? = null
}

open class ValuePair<K, V>(
    open val key: K,
    open val value: V
) {
    override fun toString(): String = "[#$key: $value]"
}

class ValuePairLazy<K, V>(
    override val key: K,
    override val value: V,
    var isDeleted: Boolean = false
) : ValuePair<K, V>(key = key, value = value)


