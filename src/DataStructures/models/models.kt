package models

open class Node<T>(val element: T) {
    var next: Node<T>? = null
}

class ValuePair<K, V>(val key: K, val value: V) {
    override fun toString(): String = "[#$key: $value]"
}


