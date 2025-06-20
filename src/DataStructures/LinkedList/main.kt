package LinkedList
import java.util.LinkedList

fun main() {

}

////////////////////////////////////////////////////////
// Native LinkedLists in Kotlin are doubly linked lists
////////////////////////////////////////////////////////
fun nativeLinkedList() {
    val linkedList = LinkedList<Int>() // creates an empty DataStructure.DataStructure.LinkedList.Set.LinkedList

    linkedList.add(13) // add the element to the end of the list
    linkedList.add(0, 23) // add element at specified position 0
    print("$linkedList")

    linkedList.remove(13) // removes the first occurrence of the specified element
    linkedList.removeAt(0) // removes the element at the specified index from the list

    linkedList.push(32) // add the element to the beginning of the list
    linkedList.push(276) // add the element to the beginning of the list
    print("$linkedList")

    linkedList.clear() // Removing all the elements/nodes in the linked list
    println("$linkedList")

    linkedList.contains(1) // return true if the number exist inside the linked list
    linkedList.contains(6) // return false if the number does not exist inside the linked list

    linkedList.sortDescending() // [5, 4, 3, 2, 1]
    linkedList.sort() // [1, 2, 3, 4, 5]

    linkedList.indexOf(3) // return the index of the value 3
    linkedList.get(2) // return the value in the index 2
}
