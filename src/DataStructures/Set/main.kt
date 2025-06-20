package Set

fun main() {
    val mySet = MySet<Int>() // Create a Set to hold strings

    mySet.add(1)
    mySet.add(2)
    mySet.add(3)

    println(mySet.has(1))
}