# philosophers_42

<div align=center> 
	<p>
		The dining philosophers problem is a classic computer science problem that challenges programmers to design a solution for 	multiple philosophers without causing a deadlock. 
	</p>
	<p>
		In this project I learned to work with multipiple threads that share memory and work on the same memory. Now I know, if a variable is accessed by more than one thread It need a mutex to protect it againt data races.
	</p>
</div>

<div>
	<h3>Used functions</h3>
	<div>
		<h4>Mandatory part:</h4>
		<p>Implement dining philosophers with threads and mutexes.</p>
		<ul>
			<li>pthread_create() - creates a new thread</li>
			<li>pthread_join() - waits until certain thread finishes, not to have zombie threads in the end.</li>
			<li>pthread_mutex_init() - creates a mutex</li>
			<li>pthread_mutex_destroy() - destroys a mutex</li>
			<li>pthread_mutex_lock() - locks a mutex</li>
			<li>pthread_mutex_unlock() - unlocks a mutex</li>
			<li>usleep() - makes a thread to sleep for microseconds</li>
			<li>gettimeofday() - returns number of microseconds passed since 1 January 1970</li>
			<li>malloc() - allocates memory on heap</li>
			<li>free() - frees memory from heap</li>
			<li>printf() - prints</li>
		</ul>
	</div>
	<div>
		<h4>Bonus part:</h4>
		<p>Implement dining philosophers with processes, threads and semaphores.</p>
		<ul>
			<li>fork() - creates a new process</li>
			<li>exit() - exits from current process</li>
			<li>waitpid() - waits until a process finishes</li>
			<li>pthread_create() - creates a new thread</li>
			<li>pthread_join() - waits until certain thread finishes, not to have zombie threads in the end.</li>
			<li>sem_open() - creates a semaphore</li>
			<li>sem_close() - closes a semaphore</li>
			<li>sem_wait() - locks a semaphore if it is available, if not it waits until it is available (subtracts 1 from semaphore)</li>
			<li>sem_unlink() - Deletes a semaphore, after program finishes</li>
			<li>sem_post() - unlocks a semaphore (adds 1 to semaphore)</li>
			<li>usleep() - makes a thread to sleep for microseconds</li>
			<li>gettimeofday() - returns number of microseconds passed since 1 January 1970</li>
			<li>malloc() - allocates memory on heap</li>
			<li>free() - frees memory from heap</li>
			<li>printf() - prints</li>
		</ul>
	</div>
</div>

### Resources
I highly recommend watching this <a href="https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2">playlist</a> and repeat after him.

### Explanation
<a href="https://www.youtube.com/watch?v=UGQsvVKwe90&pp=ygUPNDIgcGhpbG9zb3BoZXJz">Here's my video explanation.</a>
<!-- 1. To avoid deadlocks you can:
	a) Make half of philosophers (philosophers with odd ID) sleep for some time (time_to_eat - 10).
	b) Make half of philosophers right-handed and the other half left-handed.
	 -->
