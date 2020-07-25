const val INF64 = 1e18.toLong()

fun main(args: Array<String>) {
    val tc = readLine()!!.toInt()
    for (t in 1..tc) {
        val (n, a, b) = readLine()!!.split(' ').map { it.toInt() }
        val s = readLine()!!

        val d = Array(n + 1) { arrayOf(INF64, INF64) }
        d[0][0] = b.toLong()

        for (pos in 0 until n) {
            if (s[pos] == '0') {
                d[pos + 1][0] = minOf(d[pos + 1][0], d[pos][0] + a + b)
                d[pos + 1][1] = minOf(d[pos + 1][1], d[pos][0] + 2 * (a + b))

                d[pos + 1][1] = minOf(d[pos + 1][1], d[pos][1] + a + 2 * b)
                d[pos + 1][0] = minOf(d[pos + 1][0], d[pos][1] + 2 * a + b)
            } else {
                d[pos + 1][1] = minOf(d[pos + 1][1], d[pos][1] + a + 2 * b)
            }
        }
        println(d[n][0])
    }
}
