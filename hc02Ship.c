/**
 * 船 游戏
 */
#include <stdio.h>

void goSouthEast(int* lat, int* lng){
  *lat = *lat - 1;
  *lng = *lng + 1;
}

int main(int argc, char const *argv[]) {
  int latitude = 32;
  int longitude = -64;

  goSouthEast(&latitude,&longitude);
  printf("停！当前位置：[%i,%i]\n", latitude,longitude);
  return 0;
}
