#include "minunit.h"
#include "../Snake/Snake.h"


#define MINUNIT_EPSILON 1E-12

MU_TEST(test_prueba1) {
 head.y==3;

mu_assert_int_eq(1, Perder_2());
}
MU_TEST(test_prueba2) {

head.y==23;
mu_assert_int_eq(1, Perder_2());
}
MU_TEST(test_prueba3) {

head.x==20;
mu_assert_int_eq(1, Perder_2());
}

MU_TEST(test_prueba4) {
head.y==3;
mu_assert_int_eq(1,Perder_2());
}
MU_TEST(test_prueba5) {
head.x==21;
mu_assert_int_eq(1, Perder_2());
}
MU_TEST(test_prueba6) {
head.y==3;
mu_assert_int_eq(1, Perder());
}
MU_TEST(test_prueba7) {
 head.x==77;
mu_assert_int_eq(1, Perder());
}
MU_TEST(test_prueba8) {
 head.x==2;
mu_assert_int_eq(1, Perder());
}
MU_TEST(test_prueba9) {
 head.y==23;
mu_assert_int_eq(1, Perder());
}
MU_TEST(test_prueba10) {
head.x==24;
mu_assert_int_eq(1, Perder());
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
