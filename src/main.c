#include <greetings.h>
#include <stdio.h>

int main(int argc, char * argv []) {
    printf("Hola,OS II. Welcome to 2024 course!\n");
    greetings();
    printf("Calling shared lib from main program: %zu\n", shared_lib_function("Hello, OS II"));
    printf("Calling static lib from main program: %zu\n", static_lib_function("Bye, OS II"));
    return 0;
}
