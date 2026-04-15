/************************************************************************

  The Matrix Rain Screen Saver

  This code is converted from QBASIC to C.

  QBasic Code from
http://codegolf.stackexchange.com/questions/17285/make-the-matrix-digital-rain-using-the-shortest-amount-of-code

 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <assert.h>

#define DEBUG

#define ANSI_COLOR_RED   31
#define ANSI_COLOR_GREEN 32
#define ANSI_COLOR_WHITE 37
#define ANSI_COLOR_RESET 0

#define W 80
#define H 24

#define NUM 1

static uint64_t get_time_internal() {
  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC_COARSE, &now);
  uint64_t us = now.tv_sec * 1000000 + now.tv_nsec / 1000;
  return us;
}

static inline void usleep(int us) {
  uint64_t now = get_time_internal();
  uint64_t next = now + us;
  while ( get_time_internal()< next) ;
}

static inline void set_color(int c) {
  printf("\033[%dm", c);
}

static inline void print_char(char c, int y, int x) {
  printf("\033[%d;%dH%c", y + 1, x + 1, c);
}

static inline void screen_clear() {
  printf("\033[H\033[J");
}

static inline void screen_refresh() {
}

static inline int screen_tile_height() {
  return 24;
}

static inline int screen_tile_width() {
  return 80;
}

static void sub_d(int p, int s, int x, int y) {
  uint8_t r = (p % 16) * 16;
  uint8_t g = 180 - p;
  if (r < 10) {
    set_color(ANSI_COLOR_RESET);
  }
  else {
    if (g > 170) {
      set_color(ANSI_COLOR_WHITE);
    }
    else if (g < 170) {
      set_color(ANSI_COLOR_GREEN);
    }
  }

  if ((y >= 0) && (y < H) && (x < W)) {
    char c = (r < 10 ? ' ' : 33 + (x * y) % 94);
    print_char(c, y, x);
  }
}

int main() {
  int i, x, y, k, num;
  int* t = (int *)malloc(W * sizeof(int));
	assert(t != NULL);

  screen_clear();

  x = rand();
  for (i = 0; i <= W + 10000000; i++) {
#ifdef DEBUG
		printf("[DEBUG] %s:%d: i = %d\n", __FILE__, __LINE__, i);
#endif
    t[i] = - rand() % 50;
  }

  sub_d(1,1,10,10);

  for(num = 0; num < NUM; num++){
    for (k = 1; k < W; k++) {
      i = rand() % (W - 1);
      if (t[i] > 28)t[i] = 0;
      t[i] = t[i] + 1;
      y = t[i];
      sub_d( 0     , 0, i, y - 6);
      sub_d( 2  + x, 0, i, y - 5);
      sub_d( 2  + x, 0, i, y - 4);
      sub_d( 10 + x, 0, i, y - 3);
      sub_d( 10 + x, 0, i, y - 2);
      sub_d( 11 + x, 0, i, y - 1);
      sub_d( 0     , 2 + x, i, y);
    }

    screen_refresh();
    usleep(100000);
  }

  //free(t);

	return 0;
}

