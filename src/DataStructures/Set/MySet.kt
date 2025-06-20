package Set

class MySet<T> {
    private val items: MutableMap<T, T> = mutableMapOf()

    fun has(value: T) = items.containsKey(value)
    fun add(element: T): Boolean {
        if (!has(element)) {
            items[element] = element
            return true
        }
        return false
    }
    fun delete(element: T): Boolean {
        if (has(element)) {
            items.remove(element)
            return true
        }
        return false
    }
    fun union(otherSet: MySet<T>): MySet<T> {
        val unionSet = MySet<T>()
        this.valuesOfSet().forEach { value -> unionSet.add(value) }
        otherSet.valuesOfSet().forEach { value -> unionSet.add(value) }
        return unionSet
    }
    fun intersection(otherSet: MySet<T>): MySet<T> {
        val intersectionSet = MySet<T>()
        val values = this.valuesOfSet()
        val otherValues = otherSet.valuesOfSet()
        var biggerSet = values
        var smallerSet = otherValues
        if (otherValues.size - values.size > 0) {
            biggerSet = otherValues
            smallerSet = values
        }
        smallerSet.forEach {value ->
            if (biggerSet.contains(value)) {
                intersectionSet.add(value)
            }
        }
        return intersectionSet
    }
    fun difference(otherSet: MySet<T>): MySet<T> {
        val differenceSet = MySet<T>()
        this.valuesOfSet().forEach { value -> {
            if (!otherSet.has(value)) {
                differenceSet.add(value)
            }
        } }
        return differenceSet
    }
    fun isSubsetOf(otherSet: MySet<T>): Boolean {
        if (this.sizeOfSet() > otherSet.sizeOfSet()) return false
        for (value in this.valuesOfSet()) {
            if (!otherSet.has(value)) {
                return false
            }
        }
        return true
    }
    fun isEmpty(): Boolean = this.sizeOfSet() == 0
    fun clearSet() =  items.clear()
    fun sizeOfSet(): Int = items.size
    fun valuesOfSet() = items.values.toList()
    override fun toString(): String {
        if (isEmpty()) return "[]"
        val values = valuesOfSet()
        var objString = values[0].toString()
        for (i in 1 until values.size) {
            objString += "," + values[i].toString()
        }
        return objString
    }

}