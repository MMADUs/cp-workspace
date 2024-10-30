#include <stdio.h>

int main() {
    char input[100+1];
    scanf("%[^\n]", input);
    printf("#include <stdio.h>\n");
    printf("int main()\n");
    printf("{\n");
    printf("    printf(\"%%s\\n\", \"%s\");\n", input);
    printf("    return 0;\n");
    printf("}\n");

    return 0;
}