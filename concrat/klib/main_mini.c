/* Generated by CIL v. 1.8.2 */
/* print_CIL_Input is true */
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef union pthread_attr_t pthread_attr_t;
union __anonunion_pthread_mutex_t_335460617 {
   struct __pthread_mutex_s __data ;
   char __size[40] ;
   long __align ;
};
typedef union __anonunion_pthread_mutex_t_335460617 pthread_mutex_t;
union __anonunion_pthread_cond_t_951761805 {
   struct __pthread_cond_s __data ;
   char __size[48] ;
   long long __align ;
};
typedef union __anonunion_pthread_cond_t_951761805 pthread_cond_t;
typedef __int64_t int64_t;
struct kt_for_t ;
struct __anonstruct_ktf_worker_t_495033186 {
   struct kt_for_t *t ;
   long i ;
};
typedef struct __anonstruct_ktf_worker_t_495033186 ktf_worker_t;
struct kt_for_t {
   int n_threads ;
   long n ;
   ktf_worker_t *w ;
   void (*func)(void * , long  , int  ) ;
   void *data ;
};
typedef struct kt_for_t kt_for_t;
struct kt_forpool_t ;
struct __anonstruct_kto_worker_t_407073300 {
   struct kt_forpool_t *t ;
   long i ;
   int action ;
};
typedef struct __anonstruct_kto_worker_t_407073300 kto_worker_t;
struct kt_forpool_t {
   int n_threads ;
   int n_pending ;
   long n ;
   pthread_t *tid ;
   kto_worker_t *w ;
   void (*func)(void * , long  , int  ) ;
   void *data ;
   pthread_mutex_t mutex ;
   pthread_cond_t cv_m ;
   pthread_cond_t cv_s ;
};
typedef struct kt_forpool_t kt_forpool_t;
struct ktp_t ;
struct __anonstruct_ktp_worker_t_323515798 {
   struct ktp_t *pl ;
   int64_t index ;
   int step ;
   void *data ;
};
typedef struct __anonstruct_ktp_worker_t_323515798 ktp_worker_t;
struct ktp_t {
   void *shared ;
   void *(*func)(void * , int  , void * ) ;
   int64_t index ;
   int n_workers ;
   int n_steps ;
   ktp_worker_t *workers ;
   pthread_mutex_t mutex ;
   pthread_cond_t cv ;
};
typedef struct ktp_t ktp_t;
typedef long __off_t;
typedef long __off64_t;

struct __anonstruct_pipeline_t_503116822 {
   FILE *fp ;
   int max_lines ;
   int buf_size ;
   int n_threads ;
   char *buf ;
};
typedef struct __anonstruct_pipeline_t_503116822 pipeline_t;
struct __anonstruct_step_t_216488822 {
   int n_lines ;
   char **lines ;
};
typedef struct __anonstruct_step_t_216488822 step_t;

static void *ktf_worker(void *data ) 
{ 
  ktf_worker_t *w ;
  long i ;

  {
  w = (ktf_worker_t *)data;
  while (1) {
    i = (long )__sync_fetch_and_add(& w->i, (w->t)->n_threads);
    if (i >= (w->t)->n) {
      break;
    }
    (*((w->t)->func))((w->t)->data, i, (int )(w - (w->t)->w));
  }

  pthread_exit((void *)0);
}
}
void kt_for(int n_threads , void (*func)(void * , long  , int  ) , void *data , long n ) 
{ 
  int i ;
  kt_for_t t ;
  pthread_t *tid ;
  void *tmp ;
  void *tmp___0 ;
  long j ;

  {
  if (n_threads > 1) {
    t.func = func;
    t.data = data;
    t.n_threads = n_threads;
    t.n = n;
    tmp = __builtin_alloca((unsigned long )n_threads * sizeof(ktf_worker_t ));
    t.w = (ktf_worker_t *)tmp;
    tmp___0 = __builtin_alloca((unsigned long )n_threads * sizeof(pthread_t ));
    tid = (pthread_t *)tmp___0;
    i = 0;
    while (i < n_threads) {
      (t.w + i)->t = & t;
      (t.w + i)->i = (long )i;
      i ++;
    }
    i = 0;
    while (i < n_threads) {
      pthread_create((pthread_t * __restrict  )(tid + i), (pthread_attr_t const   * __restrict  )0,
                     & ktf_worker, (void * __restrict  )(t.w + i));
      i ++;
    }
    i = 0;
    while (i < n_threads) {
      pthread_join(*(tid + i), (void **)0);
      i ++;
    }
  } else {
    j = 0L;
    while (j < n) {
      (*func)(data, j, 0);
      j ++;
    }
  }
  return;
}
}

static void *ktp_worker(void *data ) 
{ 
  ktp_worker_t *w ;
  ktp_t *p ;
  int i ;
  void *tmp ;
  int64_t tmp___0 ;

  {
  w = (ktp_worker_t *)data;
  p = w->pl;
  while (w->step < p->n_steps) {
    pthread_mutex_lock(& p->mutex);
    while (1) {
      i = 0;
      while (i < p->n_workers) {
        if ((unsigned long )w == (unsigned long )(p->workers + i)) {
          goto __Cont;
        }
        if ((p->workers + i)->step <= w->step) {
          if ((p->workers + i)->index < w->index) {
            break;
          }
        }
        __Cont: /* CIL Label */ 
        i ++;
      }
      if (i == p->n_workers) {
        break;
      }
      pthread_cond_wait((pthread_cond_t * __restrict  )(& p->cv), (pthread_mutex_t * __restrict  )(& p->mutex));
    }
    pthread_mutex_unlock(& p->mutex);
    if (w->step) {
      tmp = w->data;
    } else {
      tmp = (void *)0;
    }
    w->data = (*(p->func))(p->shared, w->step, tmp);
    pthread_mutex_lock(& p->mutex);
    if (w->step == p->n_steps - 1) {
      w->step = (w->step + 1) % p->n_steps;
    } else
    if (w->data) {
      w->step = (w->step + 1) % p->n_steps;
    } else {
      w->step = p->n_steps;
    }
    if (w->step == 0) {
      tmp___0 = p->index;
      (p->index) ++;
      w->index = tmp___0;
    }
    pthread_cond_broadcast(& p->cv);
    pthread_mutex_unlock(& p->mutex);
  }
  pthread_exit((void *)0);
}
}
void kt_pipeline(int n_threads , void *(*func)(void * , int  , void * ) , void *shared_data ,
                 int n_steps ) 
{ 
  ktp_t aux ;
  pthread_t *tid ;
  int i ;
  void *tmp ;
  ktp_worker_t *w ;
  int64_t tmp___0 ;
  void *tmp___1 ;

  {
  if (n_threads < 1) {
    n_threads = 1;
  }
  aux.n_workers = n_threads;
  aux.n_steps = n_steps;
  aux.func = func;
  aux.shared = shared_data;
  aux.index = (int64_t )0;
  pthread_mutex_init(& aux.mutex, (pthread_mutexattr_t const   *)0);
  pthread_cond_init((pthread_cond_t * __restrict  )(& aux.cv), (pthread_condattr_t const   * __restrict  )0);
  tmp = __builtin_alloca((unsigned long )n_threads * sizeof(ktp_worker_t ));
  aux.workers = (ktp_worker_t *)tmp;
  i = 0;
  while (i < n_threads) {
    w = aux.workers + i;
    w->step = 0;
    w->pl = & aux;
    w->data = (void *)0;
    tmp___0 = aux.index;
    (aux.index) ++;
    w->index = tmp___0;
    i ++;
  }
  tmp___1 = __builtin_alloca((unsigned long )n_threads * sizeof(pthread_t ));
  tid = (pthread_t *)tmp___1;
  i = 0;
  while (i < n_threads) {
    pthread_create((pthread_t * __restrict  )(tid + i), (pthread_attr_t const   * __restrict  )0,
                   & ktp_worker, (void * __restrict  )(aux.workers + i));
    i ++;
  }
  i = 0;
  while (i < n_threads) {
    pthread_join(*(tid + i), (void **)0);
    i ++;
  }
  pthread_mutex_destroy(& aux.mutex);
  pthread_cond_destroy(& aux.cv);
  return;
}
}

static void worker_for(void *_data , long i , int tid ) 
{ 
  step_t *step ;
  char *s ;
  int t ;
  int l ;
  int j ;
  size_t tmp ;

  {
  step = (step_t *)_data;
  s = *(step->lines + i);
  tmp = strlen((char const   *)s);
  l = (int )(tmp - 1UL);
  if (! ((int )*(s + l) == 10)) {
    __assert_fail("s[l] == \'\\n\'", "test/kthread_test2.c", 26U, "worker_for");
  }
  j = 0;
  while (j < l >> 1) {
    t = (int )*(s + j);
    *(s + j) = *(s + ((l - 1) - j));
    *(s + ((l - 1) - j)) = (char )t;
    j ++;
  }
  return;
}
}
static void *worker_pipeline(void *shared , int step , void *in ) 
{ 
  pipeline_t *p ;
  step_t *s ;
  void *tmp ;
  void *tmp___0 ;
  char *tmp___1 ;
  step_t *s___0 ;

  {
  p = (pipeline_t *)shared;
  if (step == 0) {
    tmp = calloc((size_t )1, sizeof(step_t ));
    s = (step_t *)tmp;
    tmp___0 = calloc((size_t )p->max_lines, sizeof(char *));
    s->lines = (char **)tmp___0;
    while (1) {
      tmp___1 = fgets((char * __restrict  )p->buf, p->buf_size, (FILE * __restrict  )p->fp);
      if (! ((unsigned long )tmp___1 != (unsigned long )((char *)0))) {
        break;
      }
      *(s->lines + s->n_lines) = strdup((char const   *)p->buf);
      (s->n_lines) ++;
      if (s->n_lines >= p->max_lines) {
        break;
      }
    }
    if (s->n_lines) {
      return ((void *)s);
    }
  } else
  if (step == 1) {
    kt_for(p->n_threads, & worker_for, in, (long )((step_t *)in)->n_lines);
    return (in);
  } else
  if (step == 2) {
    s___0 = (step_t *)in;
    while (s___0->n_lines > 0) {
      (s___0->n_lines) --;
      fputs((char const   * __restrict  )*(s___0->lines + s___0->n_lines), (FILE * __restrict  )stdout);
      free((void *)*(s___0->lines + s___0->n_lines));
    }
    free((void *)s___0->lines);
    free((void *)s___0);
  }
  return ((void *)0);
}
}
int main(int argc , char **argv ) 
{ 
  pipeline_t pl ;
  int pl_threads ;
  FILE *tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  void *tmp___4 ;

  {
  if (argc == 1) {
    fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"Usage: reverse <in.txt> [pipeline_threads [for_threads]]\n");
    return (1);
  }
  tmp___1 = strcmp((char const   *)*(argv + 1), "-");
  if (tmp___1) {
    tmp___0 = fopen((char const   * __restrict  )*(argv + 1), (char const   * __restrict  )"r");
    pl.fp = tmp___0;
  } else {
    pl.fp = stdin;
  }
  if ((unsigned long )pl.fp == (unsigned long )((FILE *)0)) {
    fprintf((FILE * __restrict  )stderr, (char const   * __restrict  )"ERROR: failed to open the input file.\n");
    return (1);
  }
  if (argc > 2) {
    tmp___2 = atoi((char const   *)*(argv + 2));
    pl_threads = tmp___2;
  } else {
    pl_threads = 3;
  }
  pl.max_lines = 4096;
  pl.buf_size = 65536;
  if (argc > 3) {
    tmp___3 = atoi((char const   *)*(argv + 3));
    pl.n_threads = tmp___3;
  } else {
    pl.n_threads = 1;
  }
  tmp___4 = calloc((size_t )pl.buf_size, (size_t )1);
  pl.buf = (char *)tmp___4;
  kt_pipeline(pl_threads, & worker_pipeline, (void *)(& pl), 3);
  free((void *)pl.buf);
  if ((unsigned long )pl.fp != (unsigned long )stdin) {
    fclose(pl.fp);
  }
  return (0);
}
}
