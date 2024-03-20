#include <stdio.h>
const char* c[] = { "Welcome", "to", "Beautiful", "Edoyun" };
const char** cp[] = { c + 3, c + 2, c + 1, c };
const char*** cpp = cp;
int main()
{
printf("%s\n", **++cpp);
printf("%s\n ", *-- * ++cpp + 3);
printf("%s\n", *cpp[-2] + 3);
printf("%s\n", cpp[-1][-1] + 1);
printf("\n");
return 0;
}
