package main

import (
	"fmt"
	"sync"
	"time"
)

// Our global variable which we will be performing work on in multiple goroutines
var workNumber int

// Mutates and Prints out 'workNumber' a few times
// Function which sleeps for a bit and after Mutates and Prints out 'workNumber' a few times,
// then signals to the provided wait group that the function has ended
func parallelPrintAndAdd(num int, wg *sync.WaitGroup, mux *sync.Mutex) {
	// Sleep for num + 1 seconds
	time.Sleep(time.Second * time.Duration(num+1))

	// Lock the mutex, then while locked access and mutate 'workNumber'
	mux.Lock()

	myWorkNumber := workNumber

	workNumber += num

	// Unlock the mutex
	mux.Unlock()

	fmt.Printf("Hi, I'm goroutine %d, I slept for %d seconds and after that the first number I saw for workNumber is %d\n", num, num+1, myWorkNumber)

	// Sleep for 10 - (num + 1) seconds
	time.Sleep(time.Second * time.Duration(10-num+1))

	// Lock the mutex again, then while locked access and mutate 'workNumber' again
	mux.Lock()

	myWorkNumber = workNumber

	workNumber += num

	// Unlock the mutex
	mux.Unlock()

	fmt.Printf("Hi, I'm goroutine %d, I slept for %d more seconds and after that the second number I saw for workNumber is %d\n", num, num+1, myWorkNumber)

	wg.Done()
}

func main() {
	// Create a WaitGroup so that our main goroutine does not exit
	// before all other goroutines have finished
	var wg sync.WaitGroup

	// Mutex for handling access and mutation to the global var 'workNumber'
	addMutex := &sync.Mutex{}

	// Declare an int representing the total number of goroutines we would like to perform
	numberOfGoroutines := 10

	// Add the number of goroutines we will be performing to the WaitGroup so that we can
	// Wait for them to finish later on line
	wg.Add(numberOfGoroutines)

	// Create 'numberOfGoroutines' goroutines to perform addition and printing operations on 'workNumber'
	for i := 0; i < numberOfGoroutines; i++ {
		go parallelPrintAndAdd(i, &wg, addMutex)
	}

	// Wait until all items (in this case only one) have fininshed
	// before exiting
	wg.Wait()

	// Print out the ending sum after all goroutines have finished
	fmt.Printf("The total sum is: %d\n", workNumber)
}
