#include "minunit.h"
#include "../ValidacionDePassword/ValidacionDePassword.h"

#define MINUNIT_EPSILON 1E-12

MU_TEST(test_prueba1) {
  char *s="password";
mu_assert_int_eq(8, counts(s));
}
MU_TEST(test_prueba2) {
 char *s="hola";
mu_assert_int_eq(4, counts(s));
}
MU_TEST(test_prueba3) {
 char *s="password17";
mu_assert_int_eq(10, counts(s));
}

MU_TEST(test_prueba4) {
 char *s="Gratis17";
mu_assert_int_eq(8,counts(s));
}
MU_TEST(test_prueba5) {
 char *s="computadora";
mu_assert_int_eq(1, minimo(s));
}
MU_TEST(test_prueba6) {
 char *s="";
mu_assert_int_eq(0, counts(s));
}
MU_TEST(test_prueba7) {
 char *s="OSORIA";
mu_assert_int_eq(1, may(s));
}
MU_TEST(test_prueba8) {
 char *s="mochila";
mu_assert_int_eq(1, minimo(s));
}
MU_TEST(test_prueba9) {
 char *s="JeanCarlos";
mu_assert_int_eq(1, may(s));
}
MU_TEST(test_prueba10) {
 char *s="COMPUTADORA";
mu_assert_int_eq(1, may(s));
}



MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_prueba1);
	MU_RUN_TEST(test_prueba2);
    MU_RUN_TEST(test_prueba3);
    MU_RUN_TEST(test_prueba4);
    MU_RUN_TEST(test_prueba5);
    MU_RUN_TEST(test_prueba6);
    MU_RUN_TEST(test_prueba7);
    MU_RUN_TEST(test_prueba8);
    MU_RUN_TEST(test_prueba9);
    MU_RUN_TEST(test_prueba10);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
