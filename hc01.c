/**
 * 计算牌盒数量的程序
 */
#include <stdio.h>

int main() {
  int decks;
  puts("输入有几副牌");
  scanf("%i",&decks );
  if(decks < 1){
    puts("无效的副数");
    return 1;
  }
  printf("一共有%i张牌\n",decks );
  return 0;
}
