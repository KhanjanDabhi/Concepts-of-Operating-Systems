## Khanjan Dabhi 0872326 ##
## Umang Shah 0900917##


#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int string_check(char first[], char second[]);
//create functions
int make();
int Duplicate();
int Delete_File();
int Filename_Change();
int Join_file();
int move();
int delete_text();
int Display_Text();
//create help functions
void help_make();
void help_Duplicate();
void help_Delete();
void help_Filename_Change();
void help_Join_file();
void help_move();
void help_delete_text();
void help_Display_Text();




int main()
{
    // Input :
    // E : Exit
    // C : make
    // D : Delete
    // R : Rename
    // O : Duplicate
    // M : Move
    // A : Append
    // T : Delete
    // S : Show
    char Input[256];
    int is_complete = 0;

    printf("Select a Input:\n");
    printf("E : Exit\n");
    printf("C : Create\n");
    printf("D : Delete\n");
    printf("R : Rename\n");
    printf("O : Duplicate\n");
    printf("M : Move\n");
    printf("A : Append Text\n");
    printf("T : Delete Text\n");
    printf("S : Show Text\n");

    while (Input[0] != 'E' && is_complete == 0) {
        printf("Input > ");
        gets(Input);
        if (Input[0] == 'C') {
            char x[256] = "C /h";
            int result = string_check(x, Input);
            if (result == 1) {
                help_make();
            }
            else {
                make();
            }
        }
        else if (Input[0] == 'O') {
            char x[256] = "O /h";
            int result = string_check(x, Input);
            if (result == 1) {
                help_Duplicate();
            }
            else {
                Duplicate();
            }
        }
        else if (Input[0] == 'D') {
            char x[256] = "D /h";
            int result = string_check(x, Input);
            if (result == 1) {
                help_Delete();
            }
            else {
                Delete_File();
            }
        }
        else if (Input[0] == 'R') {
            // Rename
            char x[256] = "R /h";
            int result = string_check(x, Input);
            if (result == 1) {
                help_Filename_Change();
            }
            else {
                Filename_Change();
            }
        }
        else if (Input[0] == 'A') {
            // Append
            char x[256] = "A /h";
            int result = string_check(x, Input);
            if (result == 1) {
                help_Join_file();
            }
            else {
                Join_file();
            }
        }
        else if (Input[0] == 'T') {
            // Append
            char x[256] = "T /h";
            int result = string_check(x, Input);
            if (result == 1) {
                help_delete_text();
            }
            else {
                delete_text();
            }
        }
        else if (Input[0] == 'S') {
            // Append
            char x[256] = "S /h";
            int result = string_check(x, Input);
            if (result == 1) {
                help_Display_Text();
            }
            else {
                Display_Text();
            }
        }
        else if (Input[0] == 'M') {
            // Append
            char x[256] = "M /h";
            int result = string_check(x, Input);
            if (result == 1) {
                help_move();
            }
            else {
                move();
            }
        }
    }
}

//all the functions start from here 
int string_check(char first[], char second[]) {
    int i = 0;
    while (i < sizeof(first) && i < sizeof(second)) {
        if (first[i] != second[i])
            return 0;
        i++;
    }
    return 1;
}
int Delete_File() {
    printf("Enter the name of file \nfilename > ");
    char path[100];
    int ret;

    scanf("%s", path);
    FILE* fp;

    ret = remove(path);

    if (ret == 0)
    {
        printf("File deleted successfully");
        return 0;
    }
    else
    {
        printf("Error: unable to delete the file");
        return 1;
    }

}
int make() {
    printf("Enter the name of file \nfilename > ");
    char path[100];

    scanf("%s", path);

    FILE* fptr;
    char there_was_error = 0;
    char opened_in_read = 1;
    fptr = fopen(path, "rb+");
    if (fptr == NULL) //if file does not exist, make it
    {
        opened_in_read = 0;
        fptr = fopen(path, "wb");
        if (fptr == NULL)
            there_was_error = 1;
    }
    else {
        printf("The file already exists");
        return 0;
    }
    if (there_was_error)
    {
        printf("Disc full or no permission\n");
        return EXIT_FAILURE;
    }
    printf("The file has been made and the path is %s", path);
    return EXIT_SUCCESS;
}
int move()
{
    char source[100], target[100];
    printf("Enter the file name that is  to be copied: ");
    scanf("%s", source);
    printf("Enter the destination address for that file: ");
    scanf("%s", target);
    int source_size = (int)strlen(source);
    int target_size = (int)strlen(target);
    target[target_size] = '/';
    target[target_size + 1] = '\0';
    target_size++;
    int i;
    for (i = 0; i < source_size; i++) {
        target[target_size++] = source[i];
    }
    target[target_size] = '\0';
    FILE* read, * write;
    read = fopen(source, "r");
    if (!read) {
        printf("Source file could not be opened. Duplicate process is cancelled.\n");
        return -1;
    }
    if (fopen(target, "r")) {
        printf("Destination includes same file named with %s, press 1 to Replace, press 2 to cancel Duplicate process: ", source);
        int a = -1;
        scanf("%d", &a);
        if (a == 1) {
            write = fopen(target, "w");
        }
        else if (a == 2) {
            printf("Duplicate process is cancelled.\n");
            return -1;
        }
        else {
            printf("Invalid choice. Duplicate process is cancelled.\n");
            return -1;
        }
    }
    else {
        write = fopen(target, "w");
    }
    if (!write) {
        printf("Destination could not be accessed. Duplicate process is cancelled.\n");
        return -1;
    }
    char c;
    while (!feof(read)) {
        c = getc(read);
        if (feof(read)) {
            break;
        }
        fputc(c, write);
    }
    fclose(read);
    fclose(write);
    printf("Duplicate process is completed successfuly.\n");
    remove(source);
}
int Display_Text() {
    printf("Enter the name of file \nfilename > ");
    char path[100];
    char fn[50];
    scanf("%s", path);
    FILE* fptr;
    char there_was_error = 0;
    char opened_in_read = 1;
    fptr = fopen(path, "r");
    if (fptr == NULL) //if file does not exist
    {
        printf("The file does not exists");
        if (fptr == NULL)
            there_was_error = 1;
    }
    else {
        opened_in_read = 0;
        int x;
        while ((x = fgetc(fptr)) != EOF) {
            putchar(x);
        }
        printf("\n");
        fclose(fptr);
        return 0;
    }
    if (there_was_error)
    {
        printf("Disc full or no permission\n");
        return EXIT_FAILURE;
    }
    printf("The file has been made and the path is %s", path);
    return EXIT_SUCCESS;
}
int delete_text() {
    printf("Enter the name of file \nfilename > ");
    char path[100];
    char fn[50];
    scanf("%s", path);
    FILE* fptr;
    char there_was_error = 0;
    char opened_in_read = 1;
    fptr = fopen(path, "w+");
    if (fptr == NULL) //if file does not exist
    {
        printf("The file does not exists");
        if (fptr == NULL)
            there_was_error = 1;
    }
    else {
        opened_in_read = 0;
        fclose(fptr);
        printf("Text int the file was deleted successfully");
        return 0;
    }
    if (there_was_error)
    {
        printf("Disc full or no permission\n");
        return EXIT_FAILURE;
    }
    printf("The file has been made and the path is %s", path);
    return EXIT_SUCCESS;
}
int Join_file() {
    printf("Enter the name of file \nfilename > ");
    char path[100];
    char fn[50];
    scanf("%s", path);
    FILE* fptr;
    char there_was_error = 0;
    char opened_in_read = 1;
    fptr = fopen(path, "a");
    if (fptr == NULL) //if file does not exist
    {
        printf("The file does not exists");
        if (fptr == NULL)
            there_was_error = 1;
    }
    else {
        opened_in_read = 0;
        char* appendText = malloc(100);
        printf("Enter a text ->\n");
        scanf(" %[^\n]s ", appendText);
        if (appendText[0] != '\0') {
            fprintf(fptr, "%s", appendText);
        }
        fclose(fptr);
        return 0;
    }
    if (there_was_error)
    {
        printf("Disc full or no permission\n");
        return EXIT_FAILURE;
    }
    printf("The file has been made and the path is %s", path);
    return EXIT_SUCCESS;
}
int Duplicate() {
    char source[100], target[100];
    printf("Enter the file name to be copied: ");
    scanf("%s", source);
    printf("Enter the destination that file will be pasted: ");
    scanf("%s", target);
    int source_size = (int)strlen(source);
    int target_size = (int)strlen(target);
    target[target_size] = '/';
    target[target_size + 1] = '\0';
    target_size++;
    int i;
    for (i = 0; i < source_size; i++) {
        target[target_size++] = source[i];
    }
    target[target_size] = '\0';
    FILE* read, * write;
    read = fopen(source, "r");
    if (!read) {
        printf("Source file could not be opened. Duplicate process is cancelled.\n");
        return -1;
    }
    if (fopen(target, "r")) {
        printf("Destination includes same file named with %s, press 1 to replace, press 2 to cancel Duplicate process: ", source);
        int a = -1;
        scanf("%d", &a);
        if (a == 1) {
            write = fopen(target, "w");
        }
        else if (a == 2) {
            printf("Duplicate process is cancelled.\n");
            return -1;
        }
        else {
            printf("Invalid choice. Duplicate process is cancelled.\n");
            return -1;
        }
    }
    else {
        write = fopen(target, "w");
    }
    if (!write) {
        printf("Destination could not be accessed. Duplicate process is cancelled.\n");
        return -1;
    }
    char c;
    while (!feof(read)) {
        c = getc(read);
        if (feof(read)) {
            break;
        }
        fputc(c, write);
    }
    fclose(read);
    fclose(write);
    printf("Duplicate process is completed successfuly.\n");
}
int Filename_Change() {
    int result;
    printf("Enter the name of file you want to rename \nfilename > ");
    char file_path_to_rename[100];
    scanf("%s", file_path_to_rename);

    printf("Enter the name of file you want to rename as \nfilename > ");
    char file_name_to_rename[100];
    scanf("%s", file_name_to_rename);

    result = rename(file_path_to_rename, file_name_to_rename);
    if (result == 0)
    {
        printf("File renamed successfully");
        return 0;
    }
    else
    {
        printf("Error: unable to rename the file");
        return 1;
    }
}

// all the help functions starts from here
void help_make() {
    printf("help for make\n");
}
void help_Delete() {
    printf("help for delete");
}
void help_move()
{
    printf("help for move file\n");
}
void help_Display_Text()
{
    printf("help for Display Text\n");
}
void help_delete_text() {
    printf("help for delete text\n");
}
void help_Join_file() {
    printf("help for append\n");
}
void help_Duplicate() {
    printf("help for Duplicate");
}
void help_Filename_Change() {
    printf("help for rename");
}
