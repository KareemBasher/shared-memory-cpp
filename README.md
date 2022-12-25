## Server code

This program creates a shared memory segment and initializes it with values input by the user.

### Dependencies

- `sys/shm.h`: header file for shared memory functions
- `iostream`: header file for input/output streams

### Functions

- `shmget`: function that creates a shared memory segment with the specified size and ID
- `shmat`: function that attaches the shared memory segment to the address space of the process
- `shmdt`: function that detaches the shared memory segment from the address space of the process

### Steps

1. Create a shared memory segment with the specified size and ID using `shmget`.
2. Attach the shared memory segment to the address space of the process using `shmat`.
3. Prompt the user to input the values for the array.
4. Detach the shared memory segment from the address space of the process using `shmdt`.

## Client code

This program connects to a shared memory segment and prints out the even numbers in the array.

### Dependencies

- `sys/shm.h`: header file for shared memory functions
- `iostream`: header file for input/output streams

### Functions

- `shmget`: function that connects to a shared memory segment with the specified ID
- `shmat`: function that attaches the shared memory segment to the address space of the process
- `shmdt`: function that detaches the shared memory segment from the address space of the process

### Steps

1. Connect to the shared memory segment with the specified ID using `shmget`.
2. Attach the shared memory segment to the address space of the process using `shmat`.
3. Print out a message indicating that the even numbers are being printed.
4. Print out only the even numbers in the array.
5. Detach the shared memory segment from the address space of the process using `shmdt`.
