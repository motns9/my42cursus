#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "../ft_printf_bonus.h"

#define TEST(name, format, ...) \
    printf("Test %s: ", name); \
    printf("printf: "); \
    printf_ret = printf(format, ##__VA_ARGS__); \
    printf(" (ret: %d) | ft_printf: ", printf_ret); \
    ft_printf_ret = ft_printf(format, ##__VA_ARGS__); \
    printf(" (ret: %d) | ", ft_printf_ret); \
    if (printf_ret == ft_printf_ret) { \
        printf("\033[32mOK\033[0m\n"); \
        pass_count++; \
    } else { \
        printf("\033[31mKO\033[0m\n"); \
        fail_count++; \
    }

int main(void) {
    int printf_ret, ft_printf_ret;
    int pass_count = 0, fail_count = 0;
    char *str = "Hello, World!";
    char *null_str = NULL;
    void *ptr = &str;
    void *null_ptr = NULL;

    printf("======== CONVERSIONS DE BASE ========\n");
    
    // Char tests
    TEST("char_basic", "%c", 'A');
    TEST("char_null", "%c", '\0');
    TEST("char_multi", "%c%c%c", 'A', 'B', 'C');
    
    // String tests
    TEST("string_basic", "%s", "Hello");
    TEST("string_empty", "%s", "");
    TEST("string_null", "%s", null_str);
    
    // Pointer tests
    TEST("pointer_basic", "%p", ptr);
    TEST("pointer_null", "%p", null_ptr);
    
    // Decimal tests
    TEST("decimal_positive", "%d", 42);
    TEST("decimal_negative", "%d", -42);
    TEST("decimal_zero", "%d", 0);
    TEST("decimal_max", "%d", INT_MAX);
    TEST("decimal_min", "%d", INT_MIN);
    
    // Integer tests
    TEST("integer_positive", "%i", 42);
    TEST("integer_negative", "%i", -42);
    TEST("integer_zero", "%i", 0);
    
    // Unsigned tests
    TEST("unsigned_basic", "%u", 42);
    TEST("unsigned_max", "%u", UINT_MAX);
    TEST("unsigned_zero", "%u", 0);
    
    // Hex lowercase tests
    TEST("hex_lower_basic", "%x", 42);
    TEST("hex_lower_zero", "%x", 0);
    TEST("hex_lower_max", "%x", UINT_MAX);
    
    // Hex uppercase tests
    TEST("hex_upper_basic", "%X", 42);
    TEST("hex_upper_zero", "%X", 0);
    TEST("hex_upper_max", "%X", UINT_MAX);
    
    // Percent tests
    TEST("percent_basic", "%%");
    TEST("percent_multi", "%%%c%%", 'A');

    printf("\n======== FLAGS ET MODIFICATEURS ========\n");
    
    // Width tests
    TEST("width_char", "%5c", 'A');
    TEST("width_string", "%10s", "Hello");
    TEST("width_int", "%10d", 42);
    
    // Left-align tests
    TEST("left_align_char", "%-5c", 'A');
    TEST("left_align_string", "%-10s", "Hello");
    TEST("left_align_int", "%-10d", 42);
    
    // Zero-padding tests
    TEST("zero_pad_int", "%05d", 42);
    TEST("zero_pad_neg", "%05d", -42);
    
    // Precision tests
    TEST("precision_string", "%.3s", "Hello");
    TEST("precision_int", "%.5d", 42);
    TEST("precision_zero_int", "%.0d", 0);
    
    // Width and precision
    TEST("width_precision_int", "%10.5d", 42);
    TEST("width_precision_neg", "%10.5d", -42);
    
    // Alternative form
    TEST("alt_form_hex_lower", "%#x", 42);
    TEST("alt_form_hex_upper", "%#X", 42);
    
    // Sign flags
    TEST("plus_sign_positive", "%+d", 42);
    TEST("plus_sign_negative", "%+d", -42);
    TEST("space_sign_positive", "% d", 42);
    TEST("space_sign_negative", "% d", -42);
    
    // Combinaisons standards (éviter celles qui génèrent des warnings)
    TEST("combo_width_precision", "%10.5d", 42);
    TEST("combo_left_precision", "%-10.5d", 42);
    TEST("combo_alt_width", "%#10x", 42);
    TEST("combo_plus_width", "%+10d", 42);
    TEST("combo_space_alt", "% #10x", 42);

    printf("\n======== TESTS COMPLEXES ========\n");
    
    // Mixte
    TEST("mixed_basic", "Char: %c, String: %s, Int: %d", 'A', "Hello", 42);
    TEST("mixed_complex", "%c %s %p %d %i %u %x %X %%", 'Z', "test", ptr, 42, -42, UINT_MAX, 42, 42);
    
    // Edge cases
    TEST("edge_null_s", "%s", null_str);
    TEST("edge_null_p", "%p", null_ptr);
    TEST("edge_precision_zero", "%.0d", 0);
    TEST("edge_precision_zero_width", "%5.0d", 0);
    
    // Limites
    TEST("limit_int_min", "%d", INT_MIN);
    TEST("limit_int_max", "%d", INT_MAX);
    TEST("limit_uint_max", "%u", UINT_MAX);

    // Afficher le récapitulatif
    printf("\n======== RÉCAPITULATIF ========\n");
    printf("Tests passés: %d\n", pass_count);
    printf("Tests échoués: %d\n", fail_count);
    printf("Total: %d\n", pass_count + fail_count);
    
    if (fail_count == 0) {
        printf("\n\033[32mTous les tests ont passé !\033[0m\n");
        return 0;
    } else {
        printf("\n\033[31mCertains tests ont échoué...\033[0m\n");
        return 1;
    }
}
