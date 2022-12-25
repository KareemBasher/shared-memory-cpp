#include <sys/shm.h>
#include <iostream>

using namespace std;

int main()
{
    // Create a shared memory segment with the specified size and ID
    int shm_id = shmget(12345, sizeof(int) * 10, 0666 | IPC_CREAT);
    if (shm_id == -1)
    {
        cout << "Error creating shared memory segment" << endl;
        return 1;
    }

    // Attach the shared memory segment to the address space of the process
    int* array = (int*)shmat(shm_id, NULL, 0);
    if (array == (int*)-1)
    {
        cout << "Error attaching shared memory segment" << endl;
        return 1;
    }

    // Prompt the user to input the values for the array
    cout << "Enter the values for the array:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> array[i];
    }

    // Detach the shared memory segment from the address space of the process
    if (shmdt(array) == -1)
    {
        cout << "Error detaching shared memory segment" << endl;
        return 1;
    }

    return 0;
}
