/* Generated by CIL v. 1.8.2 */
/* print_CIL_Input is true */

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <sched.h>
#include <unistd.h>
#include <time.h>
#include <stdint.h>

struct __anonstruct_ElogTagLvlFilter_993067413 {
   uint8_t level ;
   char tag[17] ;
   _Bool tag_use_flag ;
};
typedef struct __anonstruct_ElogTagLvlFilter_993067413 ElogTagLvlFilter;
struct __anonstruct_ElogFilter_816931338 {
   uint8_t level ;
   char tag[17] ;
   char keyword[17] ;
   ElogTagLvlFilter tag_lvl[5] ;
};
typedef struct __anonstruct_ElogFilter_816931338 ElogFilter;
struct __anonstruct_EasyLogger_153854292 {
   ElogFilter filter ;
   size_t enabled_fmt_set[6] ;
   _Bool init_ok ;
   _Bool output_enabled ;
   _Bool output_lock_enabled ;
   _Bool output_is_locked_before_enable ;
   _Bool output_is_locked_before_disable ;
   _Bool text_color_enabled ;
};
typedef struct __anonstruct_EasyLogger_153854292 EasyLogger;
enum __anonenum_ElogErrCode_773224215 {
    ELOG_NO_ERR = 0
} ;
typedef enum __anonenum_ElogErrCode_773224215 ElogErrCode;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list___0;
struct sched_param {
   int sched_priority ;
};


struct __anonstruct_ElogFileCfg_211102680 {
   char *name ;
   size_t max_size ;
   int max_rotate ;
};
typedef struct __anonstruct_ElogFileCfg_211102680 ElogFileCfg;

struct sembuf {
   unsigned short sem_num ;
   short sem_op ;
   short sem_flg ;
};

ElogErrCode elog_init(void) ;

void elog_start(void) ;

void elog_set_output_enabled(_Bool enabled ) ;
void elog_set_filter_lvl(uint8_t level ) ;
void elog_output_lock_enabled(_Bool enabled ) ;
void (*elog_assert_hook)(char const   *expr , char const   *func , size_t line )  ;
void elog_hexdump(char const   *name , uint8_t width , void const   *buf , uint16_t size ) ;
void elog_async_enabled(_Bool enabled ) ;
static EasyLogger elog  ;
static char log_buf[512]  = {      (char)0};

void elog_port_output_lock(void) ;
void elog_port_output_unlock(void) ;
ElogErrCode elog_port_init(void) ;
ElogErrCode elog_async_init(void) ;
ElogErrCode elog_init(void) 
{ 
  ElogErrCode result ;

  {
  result = (ElogErrCode )0;
  result = elog_port_init();
  result = elog_async_init();
  elog_output_lock_enabled((_Bool)1);
  elog.output_is_locked_before_enable = (_Bool)0;
  elog.output_is_locked_before_disable = (_Bool)0;

  elog_set_filter_lvl((uint8_t )5);

  elog.init_ok = (_Bool)1;
  return (result);
}
}
void elog_port_deinit(void) ;
void elog_start(void) 
{ 


  {
  if (! elog.init_ok) {
    return;
  }
  elog_set_output_enabled((_Bool)1);
  elog_async_enabled((_Bool)1);
  return;
}
}

void elog_set_output_enabled(_Bool enabled ) 
{ 


  {
  elog.output_enabled = enabled;
  return;
}
}

void elog_set_filter_lvl(uint8_t level ) 
{ 


  {
  elog.filter.level = level;
  return;
}
}

void elog_output_unlock(void) 
{ 
  {
  if (elog.output_lock_enabled) {
    elog_port_output_unlock();
    elog.output_is_locked_before_disable = (_Bool)0;
  } else {
    elog.output_is_locked_before_enable = (_Bool)0;
  }
  return;
}
}

void elog_async_output(uint8_t level , char const   *log , size_t size ) ;
void elog_output_lock_enabled(_Bool enabled ) 
{ 


  {
  elog.output_lock_enabled = enabled;
  return;
}
}

void elog_hexdump(char const   *name , uint8_t width , void const   *buf , uint16_t size ) 
{ 
  uint16_t i ;
  uint16_t j ;
  uint16_t log_len ;
  uint8_t const   *buf_p ;
  char dump_string[8] ;
  unsigned int tmp ;
  int fmt_result ;
  char *tmp___0 ;
  size_t tmp___1 ;
  size_t tmp___2 ;
  size_t tmp___3 ;
  int tmp___4 ;
  size_t tmp___5 ;
  size_t tmp___6 ;
  size_t tmp___7 ;
  size_t tmp___8 ;
  {
  log_len = (uint16_t )0;
  buf_p = (uint8_t const   *)buf;
  dump_string[0] = (char)0;
  tmp = 1U;
  while (! (tmp >= 8U)) {
    dump_string[tmp] = (char)0;
    tmp ++;
  }
  if (! elog.output_enabled) {
    return;
  }
  if (4 > (int )elog.filter.level) {
    return;
  } else {
    tmp___0 = strstr(name, (char const   *)(elog.filter.tag));
    if (! tmp___0) {
      return;
    }
  }
  i = (uint16_t )0;
  while ((int )i < (int )size) {
    fmt_result = snprintf((char * __restrict  )(log_buf), (size_t )512, (char const   * __restrict  )"D/HEX %s: %04X-%04X: ",
                          name, (int )i, ((int )i + (int )width) - 1);
    if (fmt_result > -1) {
      if (fmt_result <= 512) {
        log_len = (uint16_t )fmt_result;
      } else {
        log_len = (uint16_t )512;
      }
    } else {
      log_len = (uint16_t )512;
    }
    j = (uint16_t )0;
    while ((int )j < (int )width) {
      if ((int )i + (int )j < (int )size) {
        snprintf((char * __restrict  )(dump_string), sizeof(dump_string), (char const   * __restrict  )"%02X ",
                 (int const   )*(buf_p + ((int )i + (int )j)));
      } else {
        strncpy((char * __restrict  )(dump_string), (char const   * __restrict  )"   ",
                sizeof(dump_string));
      }
      log_len = (uint16_t )((size_t )log_len + tmp___1);
      if (((int )j + 1) % 8 == 0) {
        log_len = (uint16_t )((size_t )log_len + tmp___2);
      }
      j = (uint16_t )((int )j + 1);
    }
    log_len = (uint16_t )((size_t )log_len + tmp___3);
    j = (uint16_t )0;
    while ((int )j < (int )width) {
      if ((int )i + (int )j < (int )size) {
        if ((unsigned int )((int const   )*(buf_p + ((int )i + (int )j)) - 32) < 95U) {
          tmp___4 = (int const   )*(buf_p + ((int )i + (int )j));
        } else {
          tmp___4 = (int const   )'.';
        }
        snprintf((char * __restrict  )(dump_string), sizeof(dump_string), (char const   * __restrict  )"%c",
                 tmp___4);
        log_len = (uint16_t )((size_t )log_len + tmp___5);
      }
      j = (uint16_t )((int )j + 1);
    }
    tmp___7 = strlen("\n");
    if ((size_t )log_len + tmp___7 > 512UL) {
      tmp___6 = strlen("\n");
      log_len = (uint16_t )(512UL - tmp___6);
    }
    log_len = (uint16_t )((size_t )log_len + tmp___8);
    elog_async_output((uint8_t )4, (char const   *)(log_buf), (size_t )log_len);
    i = (uint16_t )((int )i + (int )width);
  }
  elog_output_unlock();
  return;
}
}
size_t elog_async_get_log(char *log , size_t size ) ;

static sem_t output_notice  ;
static pthread_t async_output_thread  ;
static _Bool init_ok  =    (_Bool)0;
static _Bool thread_running  =    (_Bool)0;
static _Bool is_enabled  =    (_Bool)0;
static char log_buf___0[25600]  = {      (char)0};
static size_t write_index  =    (size_t )0;
static size_t read_index  =    (size_t )0;
static _Bool buf_is_full  =    (_Bool)0;
static _Bool buf_is_empty  =    (_Bool)1;
void elog_port_output(char const   *log , size_t size ) ;
static size_t elog_async_get_buf_used(void) 
{ 
  {
  if (write_index > read_index) {
    return (write_index - read_index);
  } else
  if (! buf_is_full) {
    if (! buf_is_empty) {
      return (25600UL - (read_index - write_index));
    } else {
      goto _L;
    }
  } else
  _L: /* CIL Label */ 
  if (buf_is_full) {
    return ((size_t )25600);
  } else {
    return ((size_t )0);
  }
}
}
static size_t async_get_buf_space(void) 
{ 
  size_t tmp ;
  {
  tmp = elog_async_get_buf_used();
  return (25600UL - tmp);
}
}
static size_t async_put_log(char const   *log , size_t size ) 
{ 
  size_t space ;
  {
  space = (size_t )0;
  space = async_get_buf_space();
  if (! space) {
    size = (size_t )0;
    goto __exit;
  }
  if (space <= size) {
    size = space;
    buf_is_full = (_Bool)1;
  }
  if (write_index + size < 25600UL) {
    memcpy((void * __restrict  )(log_buf___0 + write_index), (void const   * __restrict  )log,
           size);
    write_index += size;
  } else {
    memcpy((void * __restrict  )(log_buf___0 + write_index), (void const   * __restrict  )log,
           25600UL - write_index);
    memcpy((void * __restrict  )(log_buf___0), (void const   * __restrict  )((log + 25600) - write_index),
           size - (25600UL - write_index));
    write_index += size - 25600UL;
  }
  buf_is_empty = (_Bool)0;
  __exit: 
  return (size);
}
}
size_t elog_async_get_log(char *log , size_t size ) 
{ 
  size_t used ;
  {
  used = (size_t )0;
  used = elog_async_get_buf_used();
  if (! used) {
    size = (size_t )0;
    goto __exit;
  } else
  if (used <= size) {
    size = used;
    buf_is_empty = (_Bool)1;
  }
  if (read_index + size < 25600UL) {
    memcpy((void * __restrict  )log, (void const   * __restrict  )(log_buf___0 + read_index),
           size);
    read_index += size;
  } else {
    memcpy((void * __restrict  )log, (void const   * __restrict  )(log_buf___0 + read_index),
           25600UL - read_index);
    memcpy((void * __restrict  )((log + 25600) - read_index), (void const   * __restrict  )(log_buf___0),
           size - (25600UL - read_index));
    read_index += size - 25600UL;
  }
  buf_is_full = (_Bool)0;
  __exit: 
  elog_output_unlock();
  return (size);
}
}
void elog_async_output_notice(void) ;
void elog_async_output(uint8_t level , char const   *log , size_t size ) 
{ 
  size_t put_size ;
  {
  if (is_enabled) {
    if ((int )level >= 4) {
      put_size = async_put_log(log, size);
      if (put_size > 0UL) {
        elog_async_output_notice();
      }
    }
  } else {
    elog_port_output(log, size);
  }
  return;
}
}
void elog_async_output_notice(void) 
{ 
  {
  sem_post(& output_notice);
  return;
}
}
static char poll_get_buf[25596]  ;
static void *async_output(void *arg ) 
{ 
  size_t get_log_size ;
  {
  get_log_size = (size_t )0;
  while (thread_running) {
    sem_wait(& output_notice);
    while (1) {
      get_log_size = elog_async_get_log(poll_get_buf, (size_t )25596);
      if (get_log_size) {
        elog_port_output((char const   *)(poll_get_buf), get_log_size);
      } else {
        break;
      }
    }
  }
}
}
void elog_async_enabled(_Bool enabled ) 
{ 
  {
  is_enabled = enabled;
  return;
}
}
ElogErrCode elog_async_init(void) 
{ 
  ElogErrCode result ;
  pthread_attr_t thread_attr ;
  struct sched_param thread_sched_param ;
  int tmp ;
  {
  result = (ElogErrCode )0;
  sem_init(& output_notice, 0, 0U);
  thread_running = (_Bool)1;
  pthread_attr_init(& thread_attr);
  pthread_attr_setstacksize(& thread_attr, (size_t )1024);
  pthread_attr_setschedpolicy(& thread_attr, 2);
  tmp = sched_get_priority_max(2);
  thread_sched_param.sched_priority = tmp - 1;
  pthread_attr_setschedparam((pthread_attr_t * __restrict  )(& thread_attr), (struct sched_param  const  * __restrict  )(& thread_sched_param));
  pthread_create((pthread_t * __restrict  )(& async_output_thread), (pthread_attr_t const   * __restrict  )(& thread_attr),
                 & async_output, (void * __restrict  )((void *)0));
  pthread_attr_destroy(& thread_attr);
  init_ok = (_Bool)1;
  return (result);
}
}

ElogErrCode elog_file_init(void) ;
void elog_file_write(char const   *log , size_t size ) ;
static _Bool init_ok___0  =    (_Bool)0;
static FILE *fp  =    (FILE *)((void *)0);
static ElogFileCfg local_cfg  ;
ElogErrCode elog_file_init(void) 
{ 
  ElogErrCode result ;
  ElogFileCfg cfg ;
  {
  result = (ElogErrCode )0;
  if (init_ok___0) {
    goto __exit;
  }
  cfg.name = (char *)"/tmp/elog_file.log";
  cfg.max_size = (size_t )1048576;
  cfg.max_rotate = 5;

  init_ok___0 = (_Bool)1;
  __exit: 
  return (result);
}
}
static _Bool elog_file_rotate(void) 
{ 
  int n ;
  int err ;
  char oldpath[256] ;
  char newpath[256] ;
  size_t base ;
  size_t tmp ;
  _Bool result ;
  FILE *tmp_fp ;
  char const   *tmp___0 ;
  {
  err = 0;
  tmp = strlen((char const   *)local_cfg.name);
  base = tmp;
  result = (_Bool)1;
  memcpy((void * __restrict  )(oldpath), (void const   * __restrict  )local_cfg.name,
         base);
  memcpy((void * __restrict  )(newpath), (void const   * __restrict  )local_cfg.name,
         base);
  fclose(fp);
  n = local_cfg.max_rotate - 1;
  __exit: 
  fp = fopen((char const   * __restrict  )local_cfg.name, (char const   * __restrict  )"a+");
  return (result);
}
}
void elog_file_write(char const   *log , size_t size ) 
{ 
  size_t file_size ;
  long tmp ;
  _Bool tmp___0 ;
  long tmp___1 ;
  {
  file_size = (size_t )0;
  fseek(fp, 0L, 2);
  tmp = ftell(fp);
  file_size = (size_t )tmp;
  tmp___1 = __builtin_expect((long )(! (! (file_size > local_cfg.max_size))), 0L);
  if (tmp___1) {
    tmp___0 = elog_file_rotate();
    if (! tmp___0) {
      goto __exit;
    }
  }
  fwrite((void const   * __restrict  )log, size, (size_t )1, (FILE * __restrict  )fp);
  fflush(fp);
  __exit: 

  return;
}
}
static int semid  =    -1;
static pthread_mutex_t output_lock  ;
ElogErrCode elog_port_init(void) 
{ 
  ElogErrCode result ;
  {
  result = (ElogErrCode )0;
  pthread_mutex_init(& output_lock, (pthread_mutexattr_t const   *)((void *)0));
  elog_file_init();
  return (result);
}
}
void elog_port_output(char const   *log , size_t size ) 
{ 
  {
  printf((char const   * __restrict  )"%.*s", (int )size, log);
  elog_file_write(log, size);
  return;
}
}
void elog_port_output_unlock(void) 
{ 
  {
  pthread_mutex_unlock(& output_lock);
  return;
}
}
static char cur_system_time[24]  = {      (char)0};
static char cur_process_info[10]  = {      (char)0};
static char cur_thread_info[10]  = {      (char)0};

static void test_elog(void) ;
int main(void) 
{ 
  {
  elog_init();
  elog_start();
  test_elog();
}
}
static void test_elog(void) 
{ 
  uint8_t buf[256] ;
  unsigned int tmp ;
  int i ;
  {
  buf[0] = (uint8_t )0;
  tmp = 1U;
  while (! (tmp >= 256U)) {
    buf[tmp] = (unsigned char)0;
    tmp ++;
  }
  i = 0;
  i = 0;
  while ((unsigned long )i < sizeof(buf)) {
    buf[i] = (uint8_t )i;
    i ++;
  }
  while (1) {

    elog_hexdump("test", (uint8_t )16, (void const   *)(buf), (uint16_t )sizeof(buf));
    sleep(5U);
  }
}
}