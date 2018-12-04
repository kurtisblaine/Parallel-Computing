package main

import (
	"fmt"
	"time"
)

// This function computes the sum of the numbers from 'min' to 'max', inclusive,
// then sends the result to the channel 'resultChannel'
func sumFrom(min int64, max int64, resultChannel chan int64) {
	var sum int64

	for i := min; i <= max; i++ {
		sum += i
	}

	resultChannel <- sum
}

// This function computes the product of the numbers from 'min' to 'max', inclusive,
// then sends the result to the channel 'resultChannel'
func prodFrom(min int64, max int64, resultChannel chan int64) {
	var prod int64 = 1

	for i := min; i <= max; i++ {
		prod *= i
	}

	resultChannel <- prod
}

// Print numbers consumed from the given channel
func printNums(consumeChannel chan int) {
	// Continually recieve and print values from the provided channel until it is closed
	for number := range consumeChannel {
		fmt.Println("Got number: ", number)
	}
}

// Print numbers consumed from the given channel, sleeping after every iteration
func printNumsBuffered(consumeChannel chan int, endChannel chan bool) {
	// Continually recieve and print values from the provided channel until it is closed
	for number := range consumeChannel {
		fmt.Println("Got number: ", number)

		time.Sleep(time.Second)
	}

	// Indicate we are finished to the provided channel
	endChannel <- true
}

func main() {
	// Creates two channels for bidirectional communication between threads
	sumChannel := make(chan int64)
	prodChannel := make(chan int64)

	// runs sumFrom on a separate thread
	go sumFrom(1, 1000, sumChannel)

	// runs sumFrom on a separate thread
	go prodFrom(1, 1000, prodChannel)

	// blocks until a value is sent to 'sumChannel' from another thread,
	// that value is then recieved and assigned to 'totalSum'
	totalSum := <-sumChannel

	// blocks until a value is sent to 'prodChannel' from another thread,
	// that value is then recieved and assigned to 'totalProd'
	totalProd := <-prodChannel

	// Prints out totalSum and totalProd
	fmt.Printf("Sum: %d\nProd: %d\n", totalSum, totalProd)

	// Create another channel for sending from the main goroutine to another goroutine
	sendChannel := make(chan int)

	// Start a new goroutine and give it the channel we will use to send to
	go printNums(sendChannel)

	// Send the numbers from 0 - 9 to the channel
	for i := 0; i < 10; i++ {
		sendChannel <- i
	}

	// Close the channel, indicating to goroutines using it that it will no longer be used
	close(sendChannel)

	// Create two more channels, one for sending and one for waiting until a goroutine finishes
	// though we provide a size to the sending channel, thus making it buffered
	sendBufferedChannel := make(chan int, 4)
	finishChannel := make(chan bool)

	// Start a new goroutine and give it the channel we will use to send to,
	// as well as the channel which will indicate that the goroutine will finish
	go printNumsBuffered(sendBufferedChannel, finishChannel)

	// Send the numbers from 0 - 9 to the buffered channel
	for i := 0; i < 10; i++ {
		fmt.Println("I am about to send number ", i)

		sendBufferedChannel <- i
	}

	// Close the channel, indicating to goroutines using it that it will no longer be used
	close(sendBufferedChannel)

	// Wait until the goroutine finishes (this is used in the same way a WaitGroup is used in ../goroutines/goroutineExample.go)
	<-finishChannel
}
