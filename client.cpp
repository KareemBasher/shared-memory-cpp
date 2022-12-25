#include <sys/shm.h>
#include <iostream>

using namespace std;

int main()
{
    // Connect to the shared memory segment with the specified ID
    int shm_id = shmget(12345, sizeof(int) * 10, 0666);
    if (shm_id == -1)
    {
        cout << "Error connecting to shared memory segment" << endl;
        return 1;
    }

    // Attach the shared memory segment to the address space of the process
    int* array = (int*)shmat(shm_id, NULL, 0);
    if (array == (int*)-1)
    {
        cout << "Error attaching shared memory segment" << endl;
        return 1;
    }

    // Print out a message indicating that the even numbers are being printed
    cout << "Even numbers received from the array: ";

    bool foundEven = false;

    // Print out only the even numbers in the array
    for (int i = 0; i < 10; i++)
    {
        if (array[i] % 2 == 0)
        {
            cout << array[i] << " ";
            foundEven = true;
        }
    }

    cout << endl;

    if (!foundEven) cout << "Array does not contain even numbers" << endl;

    // Detach the shared memory segment from the address space of the process
    if (shmdt(array) == -1)
    {
        cout << "Error detaching shared memory segment" << endl;
        return 1;
    }

    return 0;
}
