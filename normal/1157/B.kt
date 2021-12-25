private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readArray() = readLine()!!.trim().split(" ").map { it.toInt() }.toMutableList()

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val str = readLn().map { it.toInt() - '0'.toInt() }.toMutableList()
    val fn = readArray()
    val start = str.indexOfFirst { fn[it - 1] > it }
    if (start != -1) {
        for (i in start until n) {
            if (fn[str[i] - 1] < str[i]) break
            str[i] = fn[str[i] - 1]
        }
    }
    println(str.joinToString(separator = ""))
}