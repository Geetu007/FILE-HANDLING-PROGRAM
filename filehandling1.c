#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return;
    }
    fclose(file);
    printf("File created successfully!\n");
}

void writeToFile(const char *filename) {
    FILE *file = fopen(filename, "w"); // Open file for writing
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    fprintf(file, "Hello, this is a test file.\n");
    fprintf(file, "Writing data to a file in C.\n");
    fclose(file);
    printf("Data written successfully!\n");
}

void appendToFile(const char *filename) {
    FILE *file = fopen(filename, "a"); // Open file for appending
    if (file == NULL) {
        printf("Error opening file for appending!\n");
        return;
    }
    fprintf(file, "Appending new data to the file.\n");
    fclose(file);
    printf("Data appended successfully!\n");
}

void readFromFile(const char *filename) {
    FILE *file = fopen(filename, "r"); // Open file for reading
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }
    char buffer[256];
    printf("File contents:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File deleted successfully!\n");
    } else {
        printf("Error deleting file!\n");
    }
}

int main() {
    const char *filename = "sample.txt";
    
    // Create a file
    createFile(filename);
    
    // Write to the file
    writeToFile(filename);
    
    // Append data to the file
    appendToFile(filename);
    
    // Read and display file content
    readFromFile(filename);
    
    // Delete the file
    deleteFile(filename);
    
    return 0;
}
