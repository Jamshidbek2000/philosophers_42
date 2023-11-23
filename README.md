# Philosophers_42

## What is the project about?
The dining philosophers problem is a classic computer science challenge that requires programmers to design a solution for multiple philosophers running without causing a deadlock, each philoospher being a separate thread.

## What have I learned from the project?
Working with multiple threads was something interesting and new for me. I learned to work with multiple threads that share memory and run concurrently. It taught me the importance of using mutexes to protect shared variables against data races.

## Instructions
1. cd to philo or philo_bonus
2. make
3. For philo: ./philo 4 410 200 200 5 
	* 4 - number of philos
	* 410 - time to die
	* 200 - time to eat
	* 200 - time to sleep
	* 5 - number of meals until finishing. Program can run without this argument (./philo 4 410 200 200)
4. For philo_bonus: ./philo_bonus 4 410 200 200 5
	* 4 - number of philos
	* 410 - time to die
	* 200 - time to eat
	* 200 - time to sleep
	* 5 - number of meals until finishing. Program can run without this argument (./philo_bonus 4 410 200 200)

## Used Functions

### Mandatory Part:

- `pthread_create()`: Creates a new thread.
- `pthread_join()`: Waits until a specific thread finishes to avoid having zombie threads.
- `pthread_mutex_init()`: Creates a mutex.
- `pthread_mutex_destroy()`: Destroys a mutex.
- `pthread_mutex_lock()`: Locks a mutex.
- `pthread_mutex_unlock()`: Unlocks a mutex.
- `usleep()`: Makes a thread sleep for a specified number of microseconds.
- `gettimeofday()`: Returns the number of microseconds passed since January 1, 1970.
- `malloc()`: Allocates memory on the heap.
- `free()`: Frees memory from the heap.
- `printf()`: Prints messages.

### Bonus Part:

- `fork()`: Creates a new process.
- `exit()`: Exits the current process.
- `waitpid()`: Waits until a specific process finishes.
- `pthread_create()`: Creates a new thread.
- `pthread_join()`: Waits until a specific thread finishes to avoid having zombie threads.
- `sem_open()`: Creates a semaphore.
- `sem_close()`: Closes a semaphore.
- `sem_wait()`: Locks a semaphore if available, or waits until it becomes available (subtracts 1 from the semaphore).
- `sem_unlink()`: Deletes a semaphore after the program finishes.
- `sem_post()`: Unlocks a semaphore (adds 1 to the semaphore).
- `usleep()`: Makes a thread sleep for a specified number of microseconds.
- `gettimeofday()`: Returns the number of microseconds passed since January 1, 1970.
- `malloc()`: Allocates memory on the heap.
- `free()`: Frees memory from the heap.
- `printf()`: Prints messages.

## Resources

I highly recommend watching this [playlist](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2) and repeating after the instructor.

[Phiosophers-visualizer](https://nafuka11.github.io/philosophers-visualizer/) can help you understand how your program is acting.
<img width="1465" alt="Screen Shot 2023-10-25 at 8 44 28 AM" src="https://github.com/Jamshidbek2000/philosophers_42/assets/106934634/545f16f3-419a-4e73-8788-a6d7b09672c6">

## Explanation

For a detailed explanation, watch [my video explanation](https://www.youtube.com/watch?v=UGQsvVKwe90&pp=ygUPNDIgcGhpbG9zb3BoZXJz).

<img width="1098" alt="Screen Shot 2023-10-25 at 8 55 00 AM" src="https://github.com/Jamshidbek2000/philosophers_42/assets/106934634/848ffb05-fbfc-416d-ab60-3fee48fc9dda">
