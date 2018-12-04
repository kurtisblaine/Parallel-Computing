package main

import (
	"fmt"
	"sync"
	"time"
)

// Function that waits five seconds and then prints out the provided string,
// then signals to the provided wait group that the function has ended
func parallelPrint(str string, wg *sync.WaitGroup) {
	time.Sleep(time.Second * 5)

	fmt.Println(str)

	// Signal to the WaitGroup that one of the items has finished
	wg.Done()
}

func main() {
	// Create a WaitGroup so that our main goroutine does not exit
	// before all other goroutines have finished
	var wg sync.WaitGroup

	// We will be instanting 1 additional goroutine, so we indicate
	// that to the WaitGroup 'wg', which will then wait for it's '.Done()'
	// method to be called once so it can stop '.Wait()'ing on line 38
	wg.Add(1)

	// Start 'parallelPrint' with the parameters provided in another goroutine
	go parallelPrint("World!", &wg)

	// Print "Hello" in the main goroutine
	fmt.Println("Hello")

	// Wait until all items (in this case only one) have fininshed
	// before exiting
	wg.Wait()
}
