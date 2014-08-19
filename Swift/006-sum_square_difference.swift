func squareDifference() -> Int {
    var sumOfSquare: Int = 0
    var squareOfSum: Int = 0

    for (var i = 1; i <= 100; i++) {
        sumOfSquare += i*i
        squareOfSum += i
    }
    return ((squareOfSum * squareOfSum) - sumOfSquare)
}

println(squareDifference())
