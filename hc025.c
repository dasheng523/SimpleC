/**
 * 字符串
 */
#include <stdio.h>
#include <string.h>


/*

strchr() 在字符串中查找字符
strcmp() 比较字符串
strstr() 在字符串中查找字符串
strcpy() 复制字符串
strlen() 返回字符串长度
strcat() 连接字符串

*/


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
