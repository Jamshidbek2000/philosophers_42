# Philosophers_42

## What is the project is about?
The dining philosophers problem is a classic computer science challenge that requires programmers to design a solution for multiple philosophers running without causing a deadlock, each philoospher being a separate thread.

## What have I learned from the project?
Working with multiple threads was something interesting and new for me. I learned to work with multiple threads that share memory and run concurrently. It taught me the importance of using mutexes to protect shared variables against data races.

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

## Explanation

For a detailed explanation, watch [my video explanation](https://www.youtube.com/watch?v=UGQsvVKwe90&pp=ygUPNDIgcGhpbG9zb3BoZXJz).
