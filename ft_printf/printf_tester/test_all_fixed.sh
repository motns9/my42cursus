#!/bin/bash

# Couleurs pour une meilleure lisibilité
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[1;37m'
NC='\033[0m' # No Color

# Vérification de valgrind
if ! command -v valgrind &> /dev/null; then
    echo -e "${YELLOW}Attention: valgrind n'est pas installé. Les tests de fuites mémoire seront ignorés.${NC}"
    HAS_VALGRIND=0
else
    HAS_VALGRIND=1
fi

# Bannière de démarrage
echo -e "${BLUE}===================================================================${NC}"
echo -e "${BLUE}                     FT_PRINTF MEGA TESTER                         ${NC}"
echo -e "${BLUE}===================================================================${NC}"
echo
echo -e "${CYAN}Ce script va tester votre implémentation de ft_printf de façon exhaustive.${NC}"
echo -e "${CYAN}Version 1.2 - Created by Claude (Warnings désactivés)${NC}"
echo
echo -e "${YELLOW}Démarrage des tests...${NC}"
echo

# Vérifier l'emplacement du script
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"

echo -e "${CYAN}Répertoire du projet: ${PROJECT_DIR}${NC}"
echo -e "${CYAN}Répertoire de test: ${SCRIPT_DIR}${NC}"
echo

# Définir le nom du fichier d'en-tête
echo -e "${BLUE}Recherche de votre fichier d'en-tête...${NC}"
if [ -f "${PROJECT_DIR}/ft_printf_bonus.h" ]; then
    HEADER_FILE="ft_printf_bonus.h"
    echo -e "${GREEN}Trouvé: ft_printf_bonus.h${NC}"
elif [ -f "${PROJECT_DIR}/ft_printf.h" ]; then
    HEADER_FILE="ft_printf.h"
    echo -e "${GREEN}Trouvé: ft_printf.h${NC}"
else
    echo -e "${RED}ERREUR: Aucun fichier d'en-tête ft_printf.h ou ft_printf_bonus.h trouvé dans ${PROJECT_DIR}${NC}"
    echo -e "${YELLOW}Veuillez entrer le nom exact de votre fichier d'en-tête:${NC}"
    read HEADER_FILE
    if [ ! -f "${PROJECT_DIR}/${HEADER_FILE}" ]; then
        echo -e "${RED}ERREUR: Fichier ${PROJECT_DIR}/${HEADER_FILE} non trouvé.${NC}"
        exit 1
    fi
fi

# Création des fichiers sources pour les tests
echo -e "${BLUE}Création des fichiers de test...${NC}"

# Création du fichier de test basique
cat > "${SCRIPT_DIR}/basic_test.c" << EOL
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "../${HEADER_FILE}"

#define TEST(name, format, ...) \\
    printf("Test %s: ", name); \\
    printf("printf: "); \\
    printf_ret = printf(format, ##__VA_ARGS__); \\
    printf(" (ret: %d) | ft_printf: ", printf_ret); \\
    ft_printf_ret = ft_printf(format, ##__VA_ARGS__); \\
    printf(" (ret: %d) | ", ft_printf_ret); \\
    if (printf_ret == ft_printf_ret) { \\
        printf("\\033[32mOK\\033[0m\\n"); \\
        pass_count++; \\
    } else { \\
        printf("\\033[31mKO\\033[0m\\n"); \\
        fail_count++; \\
    }

int main(void) {
    int printf_ret, ft_printf_ret;
    int pass_count = 0, fail_count = 0;
    char *str = "Hello, World!";
    char *null_str = NULL;
    void *ptr = &str;
    void *null_ptr = NULL;

    printf("======== CONVERSIONS DE BASE ========\\n");
    
    // Char tests
    TEST("char_basic", "%c", 'A');
    TEST("char_null", "%c", '\\0');
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

    printf("\\n======== FLAGS ET MODIFICATEURS ========\\n");
    
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

    printf("\\n======== TESTS COMPLEXES ========\\n");
    
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
    printf("\\n======== RÉCAPITULATIF ========\\n");
    printf("Tests passés: %d\\n", pass_count);
    printf("Tests échoués: %d\\n", fail_count);
    printf("Total: %d\\n", pass_count + fail_count);
    
    if (fail_count == 0) {
        printf("\\n\\033[32mTous les tests ont passé !\\033[0m\\n");
        return 0;
    } else {
        printf("\\n\\033[31mCertains tests ont échoué...\\033[0m\\n");
        return 1;
    }
}
EOL

# Création du fichier de test avancé
cat > "${SCRIPT_DIR}/advanced_test.c" << EOL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include "../${HEADER_FILE}"

int main(void) {
    int printf_ret, ft_printf_ret;
    int pass_count = 0, fail_count = 0;
    char *str = "Hello, World!";
    void *ptr = &str;
    void *null_ptr = NULL;
    
    printf("======== TESTS AVANCÉS ========\\n\\n");
    
    // Tests de combinaisons standards
    printf("Test 1: Combinaison left-align avec précision\\n");
    printf("printf    : ");
    printf_ret = printf("%-10.5d", 42);
    printf(" (ret: %d)\\n", printf_ret);
    printf("ft_printf : ");
    ft_printf_ret = ft_printf("%-10.5d", 42);
    printf(" (ret: %d)\\n", ft_printf_ret);
    if (printf_ret == ft_printf_ret) {
        printf("Résultat: \\033[32mOK\\033[0m\\n\\n");
        pass_count++;
    } else {
        printf("Résultat: \\033[31mKO\\033[0m\\n\\n");
        fail_count++;
    }
    
    // Tests avec valeurs limites
    printf("Test 2: INT_MIN\\n");
    printf("printf    : ");
    printf_ret = printf("%d", INT_MIN);
    printf(" (ret: %d)\\n", printf_ret);
    printf("ft_printf : ");
    ft_printf_ret = ft_printf("%d", INT_MIN);
    printf(" (ret: %d)\\n", ft_printf_ret);
    if (printf_ret == ft_printf_ret) {
        printf("Résultat: \\033[32mOK\\033[0m\\n\\n");
        pass_count++;
    } else {
        printf("Résultat: \\033[31mKO\\033[0m\\n\\n");
        fail_count++;
    }
    
    // Test avec précision 0 et valeur 0
    printf("Test 3: Precision 0, value 0\\n");
    printf("printf    : ");
    printf_ret = printf("%.0d", 0);
    printf(" (ret: %d)\\n", printf_ret);
    printf("ft_printf : ");
    ft_printf_ret = ft_printf("%.0d", 0);
    printf(" (ret: %d)\\n", ft_printf_ret);
    if (printf_ret == ft_printf_ret) {
        printf("Résultat: \\033[32mOK\\033[0m\\n\\n");
        pass_count++;
    } else {
        printf("Résultat: \\033[31mKO\\033[0m\\n\\n");
        fail_count++;
    }
    
    // Test avec mélange de conversions
    printf("Test 4: Mixed format\\n");
    printf("printf    : ");
    printf_ret = printf("Char: %c, String: %s, Int: %d", 'A', "Hello", 42);
    printf(" (ret: %d)\\n", printf_ret);
    printf("ft_printf : ");
    ft_printf_ret = ft_printf("Char: %c, String: %s, Int: %d", 'A', "Hello", 42);
    printf(" (ret: %d)\\n", ft_printf_ret);
    if (printf_ret == ft_printf_ret) {
        printf("Résultat: \\033[32mOK\\033[0m\\n\\n");
        pass_count++;
    } else {
        printf("Résultat: \\033[31mKO\\033[0m\\n\\n");
        fail_count++;
    }
    
    // Test avec forme alternative
    printf("Test 5: Alternative form\\n");
    printf("printf    : ");
    printf_ret = printf("%#x", 42);
    printf(" (ret: %d)\\n", printf_ret);
    printf("ft_printf : ");
    ft_printf_ret = ft_printf("%#x", 42);
    printf(" (ret: %d)\\n", ft_printf_ret);
    if (printf_ret == ft_printf_ret) {
        printf("Résultat: \\033[32mOK\\033[0m\\n\\n");
        pass_count++;
    } else {
        printf("Résultat: \\033[31mKO\\033[0m\\n\\n");
        fail_count++;
    }
    
    // Afficher le récapitulatif
    printf("======== RÉCAPITULATIF TESTS AVANCÉS ========\\n");
    printf("Tests passés: %d\\n", pass_count);
    printf("Tests échoués: %d\\n", fail_count);
    printf("Total: %d\\n", pass_count + fail_count);
    
    if (fail_count == 0) {
        printf("\\n\\033[32mTous les tests avancés ont passé !\\033[0m\\n");
        return 0;
    } else {
        printf("\\n\\033[31mCertains tests avancés ont échoué...\\033[0m\\n");
        return 1;
    }
}
EOL

# Création du fichier de test pour Valgrind
cat > "${SCRIPT_DIR}/valgrind_test.c" << EOL
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "../${HEADER_FILE}"

int main(void) {
    int ret;
    char *str = "Hello, World!";
    char *null_str = NULL;
    void *ptr = &str;
    void *null_ptr = NULL;
    
    // Test avec toutes les conversions
    ret = ft_printf("Test complex: %c %s %p %d %i %u %x %X %%\\n", 
                   'A', "Hello", ptr, 42, -42, UINT_MAX, 42, 42);
    printf("Return: %d\\n", ret);
    
    // Test avec flags standards
    ret = ft_printf("Test flags: %-10.5d %#10x %+10d % 10d %#10X\\n", 
                   42, 42, 42, 42, 42);
    printf("Return: %d\\n", ret);
    
    // Test avec des cas spéciaux (NULL)
    ret = ft_printf("Test NULL: %s %p\\n", null_str, null_ptr);
    printf("Return: %d\\n", ret);
    
    // Test avec des valeurs limites
    ret = ft_printf("Test limits: %d %d %u %x\\n", INT_MIN, INT_MAX, UINT_MAX, UINT_MAX);
    printf("Return: %d\\n", ret);
    
    // Test avec précision 0 et valeur 0
    ret = ft_printf("Test precision 0: %.0d %5.0d %#.0x\\n", 0, 0, 0);
    printf("Return: %d\\n", ret);
    
    // Test avec beaucoup de caractères
    ret = ft_printf("Test long string: %s%s%s%s%s\\n", 
                   "This is a very long string. ", 
                   "This is a very long string. ",
                   "This is a very long string. ",
                   "This is a very long string. ",
                   "This is a very long string. ");
    printf("Return: %d\\n", ret);
    
    // Test avec plusieurs appels successifs
    for (int i = 0; i < 10; i++) {
        ret = ft_printf("Test iteration %d: %d\\n", i, i);
    }
    
    printf("Valgrind test completed.\\n");
    return 0;
}
EOL

echo -e "${GREEN}Fichiers de test créés avec succès !${NC}"
echo

# Compilation de la bibliothèque ft_printf
echo -e "${BLUE}Compilation de votre ft_printf...${NC}"
if ! make -C "${PROJECT_DIR}" all; then
    echo -e "${RED}Erreur lors de la compilation de ft_printf${NC}"
    exit 1
fi
echo -e "${GREEN}ft_printf compilé avec succès !${NC}"
echo

# Verification de l'existence de la bibliothèque
if [ ! -f "${PROJECT_DIR}/libftprintf.a" ]; then
    echo -e "${RED}ERREUR: libftprintf.a n'a pas été créé correctement.${NC}"
    echo -e "${YELLOW}Vérifiez que votre Makefile crée bien libftprintf.a dans le répertoire principal.${NC}"
    exit 1
fi

# Compilation des tests (sans l'option -Werror)
echo -e "${BLUE}Compilation des tests...${NC}"
echo -e "${YELLOW}Compilation du test basique...${NC}"
if ! gcc -Wall -Wextra -o "${SCRIPT_DIR}/basic_test" "${SCRIPT_DIR}/basic_test.c" -L"${PROJECT_DIR}" -lftprintf; then
    echo -e "${RED}Erreur lors de la compilation du test basique.${NC}"
    echo -e "${YELLOW}Vérifiez que votre fichier d'en-tête contient tous les prototypes nécessaires.${NC}"
    exit 1
fi

echo -e "${YELLOW}Compilation du test avancé...${NC}"
if ! gcc -Wall -Wextra -o "${SCRIPT_DIR}/advanced_test" "${SCRIPT_DIR}/advanced_test.c" -L"${PROJECT_DIR}" -lftprintf; then
    echo -e "${RED}Erreur lors de la compilation du test avancé.${NC}"
    echo -e "${YELLOW}Vérifiez que votre fichier d'en-tête contient tous les prototypes nécessaires.${NC}"
    exit 1
fi

echo -e "${YELLOW}Compilation du test valgrind...${NC}"
if ! gcc -Wall -Wextra -g -o "${SCRIPT_DIR}/valgrind_test" "${SCRIPT_DIR}/valgrind_test.c" -L"${PROJECT_DIR}" -lftprintf; then
    echo -e "${RED}Erreur lors de la compilation du test valgrind.${NC}"
    echo -e "${YELLOW}Vérifiez que votre fichier d'en-tête contient tous les prototypes nécessaires.${NC}"
    exit 1
fi

echo -e "${GREEN}Tests compilés avec succès !${NC}"
echo

# Exécution des tests basiques
echo -e "${BLUE}Exécution des tests basiques...${NC}"
echo -e "${WHITE}=======================================================${NC}"
"${SCRIPT_DIR}/basic_test"
BASIC_RESULT=$?
echo -e "${WHITE}=======================================================${NC}"
echo

# Exécution des tests avancés
echo -e "${BLUE}Exécution des tests avancés...${NC}"
echo -e "${WHITE}=======================================================${NC}"
"${SCRIPT_DIR}/advanced_test"
ADVANCED_RESULT=$?
echo -e "${WHITE}=======================================================${NC}"
echo

# Exécution des tests Valgrind si disponible
if [ $HAS_VALGRIND -eq 1 ]; then
    echo -e "${BLUE}Exécution des tests avec Valgrind...${NC}"
    echo -e "${WHITE}=======================================================${NC}"
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes "${SCRIPT_DIR}/valgrind_test" > "${SCRIPT_DIR}/valgrind_results.txt" 2>&1
    
    if grep -q "ERROR SUMMARY: 0 errors" "${SCRIPT_DIR}/valgrind_results.txt"; then
        echo -e "${GREEN}Aucune fuite mémoire détectée !${NC}"
        VALGRIND_RESULT=0
    else
        echo -e "${RED}Valgrind a détecté des problèmes:${NC}"
        grep -A 3 "ERROR SUMMARY" "${SCRIPT_DIR}/valgrind_results.txt"
        VALGRIND_RESULT=1
    fi
    echo -e "${WHITE}=======================================================${NC}"
    echo -e "${YELLOW}Les résultats complets de Valgrind sont disponibles dans ${SCRIPT_DIR}/valgrind_results.txt${NC}"
    echo
else
    VALGRIND_RESULT=0
fi

# Résumé final
echo -e "${BLUE}===================================================================${NC}"
echo -e "${BLUE}                     RÉSUMÉ DES TESTS                              ${NC}"
echo -e "${BLUE}===================================================================${NC}"
echo

if [ $BASIC_RESULT -eq 0 ]; then
    echo -e "${GREEN}✅ Tests basiques: SUCCÈS${NC}"
else
    echo -e "${RED}❌ Tests basiques: ÉCHEC${NC}"
fi

if [ $ADVANCED_RESULT -eq 0 ]; then
    echo -e "${GREEN}✅ Tests avancés: SUCCÈS${NC}"
else
    echo -e "${RED}❌ Tests avancés: ÉCHEC${NC}"
fi

if [ $HAS_VALGRIND -eq 1 ]; then
    if [ $VALGRIND_RESULT -eq 0 ]; then
        echo -e "${GREEN}✅ Tests Valgrind: AUCUNE FUITE MÉMOIRE${NC}"
    else
        echo -e "${RED}❌ Tests Valgrind: FUITES MÉMOIRE DÉTECTÉES${NC}"
    fi
else
    echo -e "${YELLOW}⚠️ Tests Valgrind: NON EXÉCUTÉS (valgrind non disponible)${NC}"
fi

echo

if [ $BASIC_RESULT -eq 0 ] && [ $ADVANCED_RESULT -eq 0 ] && [ $VALGRIND_RESULT -eq 0 ]; then
    echo -e "${GREEN}🎉 FÉLICITATIONS ! Tous les tests ont passé avec succès !${NC}"
    echo -e "${GREEN}Votre ft_printf semble prêt pour la soumission.${NC}"
else
    echo -e "${RED}❌ Certains tests ont échoué. Veuillez corriger les erreurs avant de soumettre.${NC}"
fi

echo
echo -e "${BLUE}===================================================================${NC}"
echo -e "${YELLOW}Note: Vous pouvez relancer des tests spécifiques avec:${NC}"
echo -e "  ${CYAN}${SCRIPT_DIR}/basic_test${NC}      - Pour les tests basiques"
echo -e "  ${CYAN}${SCRIPT_DIR}/advanced_test${NC}   - Pour les tests avancés"
echo -e "  ${CYAN}valgrind ${SCRIPT_DIR}/valgrind_test${NC} - Pour les tests de fuite mémoire"
echo -e "${BLUE}===================================================================${NC}"

exit 0
