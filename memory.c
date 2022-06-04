#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// get the current time
void get_time(char *time_str) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(time_str, "%d-%02d-%02d %02d:%02d:%02d",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
}


int main() {
    // Create input buffer
    char buffer[4096], time_str[32];
    get_time(time_str);

    printf("Type something: (Press ENTER to add and ctrl+c or type -exit to quit)\n");

    // Open File
    FILE *file = fopen("C:\\Users\\tinyk\\OneDrive\\Documents\\memories", "a+");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (true) {
        // getting input from user
        fgets(buffer, 4096, stdin);
        if (strcmp(buffer, "-exit\n") == 0) {
            break;
        } else {

        }
        // writing to file
        fputs(time_str, file);
        fputs("\n", file);
        fputs(buffer, file);
        fputs("\n\n", file);

    }




}