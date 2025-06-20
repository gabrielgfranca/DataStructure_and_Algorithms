package util

fun defaultToString(item: Any?): String {
    return when (item) {
        null -> "null"
        is String -> item
        else -> item.toString()
    }
}
fun <T> defaultEquals(a: T, b: T): Boolean = a == b
