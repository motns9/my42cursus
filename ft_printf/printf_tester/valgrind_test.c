#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "../ft_printf_bonus.h"

int main(void) {
    int ret;
    char *str = "Hello, World!";
    char *null_str = NULL;
    void *ptr = &str;
    void *null_ptr = NULL;
    
    // Test avec toutes les conversions
    ret = ft_printf("Test complex: %c %s %p %d %i %u %x %X %%\n", 
                   'A', "Hello", ptr, 42, -42, UINT_MAX, 42, 42);
    printf("Return: %d\n", ret);
    
    // Test avec flags standards
    ret = ft_printf("Test flags: %-10.5d %#10x %+10d % 10d %#10X\n", 
                   42, 42, 42, 42, 42);
    printf("Return: %d\n", ret);
    
    // Test avec des cas spéciaux (NULL)
    ret = ft_printf("Test NULL: %s %p\n", null_str, null_ptr);
    printf("Return: %d\n", ret);
    
    // Test avec des valeurs limites
    ret = ft_printf("Test limits: %d %d %u %x\n", INT_MIN, INT_MAX, UINT_MAX, UINT_MAX);
    printf("Return: %d\n", ret);
    
    // Test avec précision 0 et valeur 0
    ret = ft_printf("Test precision 0: %.0d %5.0d %#.0x\n", 0, 0, 0);
    printf("Return: %d\n", ret);
    
    // Test avec beaucoup de caractères
    ret = ft_printf("Test long string: %s%s%s%s%s\n", 
                   "This is a very long string. ", 
                   "This is a very long string. ",
                   "This is a very long string. ",
                   "This is a very long string. ",
                   "This is a very long string. ");
    printf("Return: %d\n", ret);
    
    // Test avec plusieurs appels successifs
    for (int i = 0; i < 10; i++) {
        ret = ft_printf("Test iteration %d: %d\n", i, i);
    }
    
    printf("Valgrind test completed.\n");
    return 0;
}
