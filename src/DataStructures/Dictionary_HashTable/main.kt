package DataStructures.Dictionary_HashTable

fun main() {
    val hash = HashTable<String, String>()
    hash.put("Gandalf", "gandalf@gmail.com")
    hash.put("John", "john@gmail.com")
    hash.put("Tyrion", "tyrion@gmail.com")
    print("${hash.hashCode("Gandalf")} - Gandalf")
    print("\n")
    print("${hash.hashCode("John")} - John")
    print("\n")
    print("${hash.hashCode("Tyrion")} - Tyrion")
}