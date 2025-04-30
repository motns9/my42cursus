#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include "../ft_printf_bonus.h"

int main(void) {
    int printf_ret, ft_printf_ret;
    int pass_count = 0, fail_count = 0;
    char *str = "Hello, World!";
    void *ptr = &str;
    void *null_ptr = NULL;
    
    printf("======== TESTS AVANCÉS ========\n\n");
    
    // Tests de combinaisons standards
    printf("Test 1: Combinaison left-align avec précision\n");
    printf("printf    : ");
    printf_ret = printf("%-10.5d", 42);
    printf(" (ret: %d)\n", printf_ret);
    printf("ft_printf : ");
    ft_printf_ret = ft_printf("%-10.5d", 42);
    printf(" (ret: %d)\n", ft_printf_ret);
    if (printf_ret == ft_printf_ret) {
        printf("Résultat: \033[32mOK\033[0m\n\n");
        pass_count++;
    } else {
        printf("Résultat: \033[31mKO\033[0m\n\n");
        fail_count++;
    }
    
    // Tests avec valeurs limites
    printf("Test 2: INT_MIN\n");
    printf("printf    : ");
    printf_ret = printf("%d", INT_MIN);
    printf(" (ret: %d)\n", printf_ret);
    printf("ft_printf : ");
    ft_printf_ret = ft_printf("%d", INT_MIN);
    printf(" (ret: %d)\n", ft_printf_ret);
    if (printf_ret == ft_printf_ret) {
        printf("Résultat: \033[32mOK\033[0m\n\n");
        pass_count++;
    } else {
        printf("Résultat: \033[31mKO\033[0m\n\n");
        fail_count++;
    }
    
    // Test avec précision 0 et valeur 0
    printf("Test 3: Precision 0, value 0\n");
    printf("printf    : ");
    printf_ret = printf("%.0d", 0);
    printf(" (ret: %d)\n", printf_ret);
    printf("ft_printf : ");
    ft_printf_ret = ft_printf("%.0d", 0);
    printf(" (ret: %d)\n", ft_printf_ret);
    if (printf_ret == ft_printf_ret) {
        printf("Résultat: \033[32mOK\033[0m\n\n");
        pass_count++;
    } else {
        printf("Résultat: \033[31mKO\033[0m\n\n");
        fail_count++;
    }
    
    // Test avec mélange de conversions
    printf("Test 4: Mixed format\n");
    printf("printf    : ");
    printf_ret = printf("Char: %c, String: %s, Int: %d", 'A', "Hello", 42);
    printf(" (ret: %d)\n", printf_ret);
    printf("ft_printf : ");
    ft_printf_ret = ft_printf("Char: %c, String: %s, Int: %d", 'A', "Hello", 42);
    printf(" (ret: %d)\n", ft_printf_ret);
    if (printf_ret == ft_printf_ret) {
        printf("Résultat: \033[32mOK\033[0m\n\n");
        pass_count++;
    } else {
        printf("Résultat: \033[31mKO\033[0m\n\n");
        fail_count++;
    }
    
    // Test avec forme alternative
    printf("Test 5: Alternative form\n");
    printf("printf    : ");
    printf_ret = printf("%#x", 42);
    printf(" (ret: %d)\n", printf_ret);
    printf("ft_printf : ");
    ft_printf_ret = ft_printf("%#x", 42);
    printf(" (ret: %d)\n", ft_printf_ret);
    if (printf_ret == ft_printf_ret) {
        printf("Résultat: \033[32mOK\033[0m\n\n");
        pass_count++;
    } else {
        printf("Résultat: \033[31mKO\033[0m\n\n");
        fail_count++;
    }
    
    // Afficher le récapitulatif
    printf("======== RÉCAPITULATIF TESTS AVANCÉS ========\n");
    printf("Tests passés: %d\n", pass_count);
    printf("Tests échoués: %d\n", fail_count);
    printf("Total: %d\n", pass_count + fail_count);
    
    if (fail_count == 0) {
        printf("\n\033[32mTous les tests avancés ont passé !\033[0m\n");
        return 0;
    } else {
        printf("\n\033[31mCertains tests avancés ont échoué...\033[0m\n");
        return 1;
    }
}
