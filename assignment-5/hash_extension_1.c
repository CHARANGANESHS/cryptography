#include <stdio.h>
#include <openssl/md5.h>

int main(int argc, const char *argv[])
{
  MD5_CTX c;
  unsigned char buffer[MD5_DIGEST_LENGTH];
  int i;

  // First part of the message: secret + data
  MD5_Init(&c);
  MD5_Update(&c, "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE041", 80);  // secret + data
  MD5_Update(&c, "My full name is S. Charan Ganesh", 32);  // data

  MD5_Final(buffer, &c);  // Compute H(secret || data)

  printf("H(secret || data): ");
  for (i = 0; i < 16; i++) {
    printf("%02x", buffer[i]);
  }
  printf("\n");

  // Second part of the message: secret + data + append
  MD5_Init(&c);
  MD5_Update(&c, "Hello, World!. This is a demonstration of message extension attacks. SE21UCSE041", 80);  // secret + data
  MD5_Update(&c, "My full name is S. Charan Ganesh", 32);  // data
  MD5_Update(&c, "SE21UCSE041", 11);  // append

  MD5_Final(buffer, &c);  // Compute H(secret || data || append)

  printf("H(secret || data || append): ");
  for (i = 0; i < 16; i++) {
    printf("%02x", buffer[i]);
  }
  printf("\n");

  return 0;
}