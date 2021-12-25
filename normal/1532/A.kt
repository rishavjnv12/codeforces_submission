import java.util.Scanner
fun main() {
    var reader = Scanner(System.`in`)
    var t = reader.nextInt()
    repeat(t){
        var a = reader.nextInt()
        var b = reader.nextInt()
        println(a+b)
    }
}