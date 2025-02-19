#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length)
{
    printf("\"");
    for (unsigned int j = 0u; j < length; j++)
    {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

void print_help(char *program_name)
{
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[])
{
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count)
    {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size)
{
    FILE *file;
    file = fopen(path, "r");
    unsigned int i = 0;

    if (file == NULL)
    {
        fprintf(stderr, "Error en abrir el archivo.\n");
        exit(EXIT_FAILURE);
    }

    while (!(feof(file)))
    {
        if (i > max_size)
        {
            exit(EXIT_FAILURE);
        }
        fscanf(file, "%u -> *%c* \n", &indexes[i], &letters[i]);
        i++;
    }

    fclose(file);
    return i;
}

void ordenar(unsigned int indexes[], char letters[], char sorted[], unsigned int length)
{

    for (unsigned int i = 0u; i < length; i++)
    {
        //
        sorted[indexes[i]] = letters[i];
    }
}

int main(int argc, char *argv[])
{
    char *path = NULL;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length = 0;

    path = parse_filepath(argc, argv);
    length = data_from_file(path, indexes, letters, MAX_SIZE);

    ordenar(indexes, letters, sorted, length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}