extern volatile unsigned int __flexsoc_test_status;
int main(void) {
  __flexsoc_test_status = 0x46534F43u;
  __asm__ volatile ("fence rw, rw" ::: "memory");
  for (;;) __asm__ volatile ("wfi");
}
