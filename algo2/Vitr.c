#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int delka(char *word) {
    int i = 0;
    while(word[i] != '\0') {
        i++;
    }
    return i;
}

int sum33(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (int)pow(33, i);
    }
    return sum;
}

int hash(char *h) {
    int i = 0;
    int ascii = h[i];
    int w = 0;
    while (h[i] != '\0') {
        w = w + (int)pow(33, delka(h) - 1) * 5381 + sum33(delka(h)-1 - i) * ascii;
        i++;
    }
    return w;
}

int hashinsert(int *hashmap, int num, int len) {
    int start = num % len;
    for (int i = 0; i < len; i++) {
        int n = (start + i * i) % len;
        if (hashmap[n] == -1) {
            hashmap[n] = num;
            return 1;
        }
    }
    printf("Hashmapa je plná, slovo nelze přidat\n");
    return 0;
}

int hashremove(int *hashmap, char *word, int len) {
    int help = hash(word);
    for (int i = 0; i < len; i++) {
        if (help == hashmap[i]) {
            hashmap[i] = -1;
            return 1;  
        }
    }
    return 0; 
}



int hashsearch(int *hashmap, char *word, int len) {
    int help = hash(word);
    for (int i = 0; i < len; i++) {
        if (help == hashmap[i]) {
            printf("klíč slova %s je %d\n",word,hash(word));
            return 1;
        }
    }
    printf("Slovo %s není v hashmapě\n",word);
    return 0;
}


int hprint(int *hashmap,int len){
    for (int i = 0; i < len; i++)
    {
        if (hashmap[i]!=-1)
        {
            printf("%d. %d\n",i,hashmap[i]);
        }
        else{
            printf("%d. -\n",i);
        }
    }
    
}


int main() {
    char h[] = "car";
    char b[] = "cheese";
    char word1[] = "frog";
    char word2[] = "cake";
    char word3[] = "hill";
    char word4[] = "star";
    char word5[] = "moon";
    char word6[] = "chair";

    int hashmap[] = {-1, -1, -1, -1, -1, -1, -1};
    int len = sizeof(hashmap)/sizeof(hashmap[0]);
    
    int result = hashinsert(hashmap, hash(h),len);

    int result3 = hashinsert(hashmap, hash(word1),len);
    
    int result4 = hashinsert(hashmap, hash(word2),len);
    
    int result5 = hashinsert(hashmap, hash(word3),len);
    
    int result6 = hashinsert(hashmap, hash(word4),len);
    
    int result7 = hashinsert(hashmap, hash(word5),len);
   
    int result2 = hashinsert(hashmap, hash(word6),len);

    int removeResult = hashremove(hashmap, word5,len);
    
    int searchResult = hashsearch(hashmap, h,len);
    int searchResult2 = hashsearch(hashmap, b,len);

    printf("Hashmap: \n");
    hprint(hashmap,len);

    return 0;
}
