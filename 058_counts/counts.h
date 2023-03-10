#ifndef __COUNTS_H__
#define __COUNTS_H__
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _one_count_t {
  //DEFINE ME                                                                                                                                         
  char * value;
  size_t times;
};
typedef struct _one_count_t one_count_t;

struct _counts_t {
  //DEFINE ME
  one_count_t ** type;
  size_t len;
  size_t times_unknown;                                                                                                                                         
};
typedef struct _counts_t counts_t;

counts_t * createCounts(void);
void addCount(counts_t * c, const char * name);
void printCounts(counts_t * c, FILE * outFile);

void freeCounts(counts_t * c);

#endif
