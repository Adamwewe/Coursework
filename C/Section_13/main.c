#include <stdio.h>



// files are read as a series of bytes
    // first byte is a zero, also has a beginning and an end just like an array
    // for c there are two files:
        // text files
        // binary files
            // image data, music encoding...

// this is done with streams, which is an abstract representation of external sources or destination data

// a program references a file thru a file pointer (or stream pointer, since it works on more than a file)
    // file pointers point to a struct of type FILE which represents a stream
    // shows whether you want to read or write or update the file
    // the address of the buffer in memory to be used for data
    // a pointer to the current position in the file for the next operation
    // the above is all set via I/O operations

// to use several files simultaneously, u need a separate file pointer for each file

// this is done with the fopen() function
    // returns the file pointer for a specific external file
    // here is how it works:
        // FILE *fopen(const char *restrict name, const char *restrict mode);
            // first argument to the function is a pointer to a string that is the name of the external file u want to process
                // u specify the name explicitly or use a char pointer that contains the address of the character string that defines the file name
                // u can obtain the file name thru the command line, as input from the user, or defined as a constant in ur program
            // second argument is a character string that represents the file mode
                // specifies what you want to do with the file
                // file mode specification is a character string between double quotes

            // assuming the call to fopen() is successful
                // the function returns a pointer of type FILE* that can be used to reference the file in further I/O operations
                // if file cannot be open, it returns NULL






int main() {
    return 0;
}

int reader()
{
    FILE *pfile = NULL;
    char *filename = "myfile.txt";

    pfile = fopen(filename, "w"); // open with write rights

    if (pfile == NULL)
        printf("Failed to open %s. \n", filename);

    // you can also rename:
        // int rename(const char *oldname, const char *newname);
    // if(rename(c:\\ path old name, C:\\path new name)
        // printf("SUccessfull")
    // else
        // Unsuccessful

    // you can also close files:
        // fclose() accepts a file pointer as an argument
        // EOF is a special character...
        // fclose(file)
        // pfile = NULL;
        // defined in stdio.h as a negative integer that is usually equivalent to the value -1
    // 0 if successful
// finally, you can also delete files
    // with remove("myfile.txt")
    //


    return 0;
}
