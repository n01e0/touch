#include <stdio.h>
#include <stdlib.h>
//#include <errno.h>

int main(int argc, char **argv){
    if (argc < 2) {
        fprintf(stderr, "%s: file operand not found\n", argv[0]);
        fprintf(stderr, "Try '%s --help' for mare information.\n", argv[0]);
    }
    
    FILE* fp;
    for (int i = 0; i < argc; i++) {
       fp = fopen(argv[i], "r");
       if (fp == NULL) {
           if((fp = fopen(argv[i], "w+")) == NULL){
                fprintf(stderr, "%s: Can't touch %s\n", argv[0], argv[i]);
                exit(1);
           }
       }
       fclose(fp);
    }
    return 0;
}
