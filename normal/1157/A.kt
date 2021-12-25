private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    var n = readInt()
    val reached = HashSet<Int>()
    var ans = 0
    while(reached.contains(n) == false){
        reached.add(n);
        ans++
        n++;
        while(n%10 == 0)
            n /= 10
    }
    println(ans)
}