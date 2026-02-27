#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen

bool isValid(const char *s) {
    if (s== NULL) {
        return false;
    }

    size_t len = strlen(s);

    // Odd length strings cannot be valid
    if (len % 2 != 0){
        return false;
    }

    // Empty string is valid
    if (len == 0){
        return true;
    }

    // Stack to hold opening brackets
    char stack[len];
    size_t top=0; // points to next free position (stack size)

    for (size_t i = 0; i < len; i++){
        char c = s[i];

        // If opening bracket then push onto stack
        if (c == '(' || c == '[' || c == '{'){
            stack[top++] = c;
        }
        // If closing bracket, then check and pop
        else {
            // Stack must not be empty
            if (top == 0){
                return false;
            }

            char open = stack[--top]; //pop

            // Check matching pairs
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                    return false;
            }
        }
    }

    // Stack must be empty at the end
    return (top == 0);
}
