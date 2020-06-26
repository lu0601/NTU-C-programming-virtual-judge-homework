#include <stdio.h>
typedef struct Character
{
    int blood;
    int magic;
    int attack;
} Character;
void write_character(const Character *c, FILE *fp)
{
    int pad[8] = {};
    fputc(c->blood, fp);
    for(int i=0; i<7; i+=1)
    {
        fputc(pad[i], fp);
    }
    fputc(c->magic, fp);
    for(int i=0; i<7; i+=1)
    {
        fputc(pad[i], fp);
    }
    fputc(c->attack, fp);
    for(int i=0; i<7; i+=1)
    {
        fputc(pad[i], fp);
    }
}
int main()
{
    FILE *fp = fopen("monster.bin", "rb");
    if(fp ==0 )
    {
        printf("Cannot open monster.bin.\n");
        return 0;
    }
    int count = 0, c;
    int num=0;
    while ((c = fgetc(fp)) != EOF)
    {
        printf("%02x ", c);
        count++;
        if (count % 8 == 0)
        {
            putchar('\n');
        }
    }
    fclose(fp);
    printf("\nThere are %d bytes in file %s\n", count, "monster.bin");

    fclose(fp);
    num = 1;
    int pad[7] = {};
    FILE *fpout = fopen("monster.bin", "wb");
    if(fpout ==0 )
    {
        printf("Cannot open monster.bin.\n");
        return 0;
    }
    fputc(num, fpout);
    for(int i=0; i<3; i+=1)
    {
        fputc(pad[i], fpout);
    }
    Character monster;
    monster.blood=20;
    monster.magic=0;
    monster.attack=0;
    Character warrior;
    warrior.blood=200;
    warrior.magic=255;
    warrior.attack=255;
    write_character(&warrior, fpout);
    write_character(&monster, fpout);
    for(int i=0; i<30; i+=1)
    {
        fputc(49, fpout);
    }
    return 0;
}
