#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // if the user doesn't provide the 2nd argument
    if(argc != 2)
    {
       printf("Please enter file name\n");
       return 1;
    }

    // useful in closing as well as opening a new JPEG file whenever found.
    int JPEG_found = 0;

    // used for nameing the file
    int JPEG_count = 0;
    char JPEG_name[8];

    //defining data type where value of each element is 1 Byte/ 8-bits
    typedef uint8_t BYTE;

    // an array of 512 elements with each element of 1 byte.
    // Used in fread to read and in fwrite to write to a single memory block of 512 bytes at time
    BYTE buffer[512];

    //if the user provides an unsupported file for recovery
    FILE *mem = fopen(argv[1], "r");
    if (mem == NULL)
    {
        printf("File format not supported\n");
        return 2;
    }

    // useful in command line 49 to avoid getting error use of undeclared identifier 'img'
    FILE *img = NULL;

    // Reading(Iterating over) a single block of 512 bytes at a time (1 block at a time/ 1 buffer per loop)
    // Storing it in the buffer array for each loop. The loop continues until we reach the end of the memory card/input file.
    // fread returns the no. of sizeof(buffer) elements found. Thus, if a block is not of 512 bytes that means we have reached the end of file.
    // buffer is an array so its already a pointer
    // fread(buffer, sizeof(BYTE), 512, mem) == 512) this is also the same, just that it reads one element of the block at a time rather than the entire block
    while ((fread(buffer, 512, 1, mem) == 1))
    {
        // if we were working on already found a JPEG in the previous loop
        //  and now we have found a new JPEGwe need to close the previous JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 && JPEG_found == 1)
        {
            fclose(img);
        }

        // Checking if we have found a JPEG
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            JPEG_found = 1;

            // creating a filename in which JPEG data will be stored
            sprintf(JPEG_name, "%03i.jpg", JPEG_count);

            // updating the JPEG count
            JPEG_count = JPEG_count + 1;

            // opening the newly created JPEG file
            img = fopen(JPEG_name, "w");
        }

        if (JPEG_found == 1)
        {
            // Writing the memory data found from fread in the newly created and already opened JPEG in 512 bytes memory block
            // until we again find the JPEG format header
            // fwrite(buffer, sizeof(BYTE), 512, img)  could have also used this
            fwrite(buffer, 512, 1, img);
        }
    }
    // closing the last created JPEG file
    fclose(img);
    // closing the memory card
    fclose(mem);
    return 0;
}


