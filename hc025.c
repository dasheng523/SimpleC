/**
 * 字符串
 */
#include <stdio.h>
#include <string.h>

char tracks[][80] = {
  "sdfasdfasdfasdf",
  "4444444444444445",
  "hello world",
  "Test myCode",
  "你好吗？"
};

void findTrack(char searchFor[]){
  int i;
  for(i=0 ; i<5 ;i++){
    if(strstr(tracks[i],searchFor)){
      printf("Tracks %i:%s\n",i,tracks[i] );
    }
  }
}
/**
int main(int argc, char const *argv[]) {
  char searchFor[80];
  puts("输入要查找的东西：");
  fgets(searchFor,80,stdin);
  searchFor[strlen(searchFor)-1] = '\0';
  findTrack(searchFor);
  return 0;
}
**/

void printReverse(char* s){
  size_t len = strlen(s);
  char* t = s + len -1;
  while (t>=s) {
    printf("%c", *t);
    t = t - 1;
  }
  puts("");
}

int main(int argc, char const *argv[]) {
  char ss[] = "1234sdgdfhdfgh";
  printReverse(ss);
  return 0;
}
