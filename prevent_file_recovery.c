#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    long size;

    if (argc != 2) {
        printf("Usage: pfr <filename>\n");
        return 1;
    }

    char *filename = argv[1];

    printf("This will permanently destroy '%s'. Continue? (y/n): ", filename);
    char choice;
    scanf(" %c", &choice);

    if (choice != 'y' && choice != 'Y') {
        printf("Aborted.\n");
        return 0;
    }

    fp = fopen(filename, "rb+");
    if (!fp) {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    for (long i = 0; i < size; i++) {
        fputc(0, fp);
    }

    fclose(fp);

    if (remove(filename) == 0) {
        printf("File '%s' securely destroyed.\n", filename);
    } else {
        printf("Error deleting file.\n");
    }

    return 0;
}

