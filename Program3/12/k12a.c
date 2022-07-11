#include <stdio.h>
#include <math.h>

#define FNAME "k12a-out.txt"

void func(FILE *fp){
  //printf("fp->_bf       :%x\n",fp->_bf);
  printf("fp->_blksize  :%d\n",fp->_blksize);
  //printf("fp->_close    :%d\n",fp->_close);
  //printf("fp->_cookie   :%x\n",fp->_cookie);
  //printf("fp->_extra)   :%x\n",fp->_extra);
  //printf("fp->_file     :%x\n",fp->_file);
  printf("fp->_flags    :%d\n",fp->_flags);
  //printf("fp->_lb       :%x\n",fp->_lb);
  printf("fp->_lbfsize  :%d\n",fp->_lbfsize);
  printf("fp->_nbuf     :%s\n",fp->_nbuf);
  //printf("fp->_offset   :%x\n",fp->_offset);
  printf("fp->_p        :%p\n",fp->_p);
  printf("fp->_r        :%d\n",fp->_r);
  //printf("fp->_read     :%d\n",fp->_read);
  //printf("fp->_seek     :%x\n",fp->_seek);
  //printf("fp->_ub       :%x\n",fp->_ub);
  printf("fp->_ubuf     :%s\n",fp->_ubuf);
  printf("fp->_ur       :%d\n",fp->_ur);
  printf("fp->_w        :%d\n",fp->_w);
  //printf("fp->_write    :%d\n",fp->_write);
}

int main(void) {
  FILE *fp = NULL;
  if ((fp = fopen(FNAME, "w")) == NULL) {
    fprintf(stderr, "CANNOT OPEN TO WRITE: %s\n", FNAME);
    return 1;
  }

  for (int x = 1; x < 5; x++) {
    func(fp);
    printf("\n");
    fprintf(fp, "%8.5f %8.5f %8.5f %10.4e %10.4e\n",
                log(x), sqrt(x), (double)x, pow(x, 1.2), pow(x, 2.0));
  }
  fclose(fp);
  return 0;
}


