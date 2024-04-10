package main

import "fmt"

func main() {
	var hour, minute, timeToAdd int
	fmt.Scanf("%d %d", &hour, &minute)
	fmt.Scanf("%d", &timeToAdd)

	hour = (hour + (minute+timeToAdd)/60) % 24
	minute = (minute + timeToAdd) % 60

	fmt.Printf("%02d %02d\n", hour, minute)
}
