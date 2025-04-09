#include <stdio.h>
#include <string.h>
void encrypt(char message[], char key[]) {
 char alphabet[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 for (int i = 0; message[i] != '\0'; i++) {
 if (message[i] >= 'A' && message[i] <= 'Z') {
 message[i] = key[message[i] - 'A'];
 } else if (message[i] >= 'a' && message[i] <=
'z') {
 message[i] = key[message[i] - 'a'] + 32;
 }}}
void decrypt(char message[], char key[]) {
 char alphabet[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 for (int i = 0; message[i] != '\0'; i++) {
 if (message[i] >= 'A' && message[i] <= 'Z') {
 for (int j = 0; j < 26; j++) {
 if (message[i] == key[j]) {
 message[i] = alphabet[j];
 break;}}
 } else if (message[i] >= 'a' && message[i] <= 'z') {
 for (int j = 0; j < 26; j++) {
 if (message[i] == key[j] + 32) {
 message[i] = alphabet[j] + 32;
 break;
 } } } } }
 int main() {
 char message[100], key[27];
 printf("Enter the message: ");
 fgets(message, sizeof(message), stdin);
 message[strcspn(message, "\n")] = 0; //Remove newline character
 printf("Enter the substitution key (26 letters):");
 fgets(key, sizeof(key), stdin);
 key[strcspn(key, "\n")] = 0; // Remove newline character
 encrypt(message, key);
 printf("Encrypted message: %s\n", message);
 decrypt(message, key);
 printf("Decrypted message: %s\n", message);
 return 0;
}
