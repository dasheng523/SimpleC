/**
 * 计算牌面点数的程序
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char cardName[3];
  int count = 0;

  do{
    puts("输入牌名：");
    scanf("%2s", cardName);
    int val = 0;
    switch (cardName[0]) {
      case 'K':
      case 'Q':
      case 'J':
        val = 10;
        break;
      case 'A':
        val = 1;
        break;
      case 'X':
        continue;
      default:
        val = atoi(cardName);
        if(val < 1 || val > 10){
          puts("我无法理解这个值");
          continue;
        }
    }

    if(val>=3 && val<=6){
      count ++;
    }
    else if(val == 10){
      count --;
    }

    printf("当前的计数：%i\n",count);
  }while (cardName[0] != 'X');


  return 0;
}
