package main

import "fmt"

func main() {
	i, c, sum := [...]int{1, 1}, 0, 0
	for c < 4e6 {
		c = i[0] + i[1]
		i[0] = i[1]
		i[1] = c
		if c%2 == 0 {
			sum += c
		}
	}
	fmt.Printf("Fibonacci of terms is equal to %d\n", sum)
}
