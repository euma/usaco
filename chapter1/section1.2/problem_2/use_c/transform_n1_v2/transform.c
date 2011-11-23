#include<stdio.h>

int main() {

  int size=1;
  char before='@'; char after='-';
  //char before='@'; char after='@';
  //char before='-'; char after='-';

  if (size==1) {
    if (before==after) {
      if (before=='-') {
        printf("#2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.");
      }
      else {
        printf("#6: No Change: The original pattern was not changed.");
      }
    }
    else {
      printf("#7: Invalid Transformation: The new pattern was not obtained by any of the above methods.");
    }
  }

  return 0;
}
