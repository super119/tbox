/*!The Treasure Box Library
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Copyright (C) 2009-2020, TBOOX Open Source Group.
 *
 * @author      ruki
 * @file        ltimer.h
 * @ingroup     platform
 *
 */
#ifndef TB_PLATFORM_LTIMER_H
#define TB_PLATFORM_LTIMER_H

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"
#include "timer.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_enter__

/* //////////////////////////////////////////////////////////////////////////////////////
 * types
 */

/// the timer tick enum
typedef enum __tb_ltimer_tick_e
{
    TB_LTIMER_TICK_100MS    = 100
,   TB_LTIMER_TICK_S        = 1000
,   TB_LTIMER_TICK_M        = 60000
,   TB_LTIMER_TICK_H        = 3600000

}tb_ltimer_tick_e;

/// the ltimer task func type
typedef tb_timer_task_func_t    tb_ltimer_task_func_t;

/// the ltimer ref type
typedef __tb_typeref__(ltimer);

/// the ltimer task ref type
typedef __tb_typeref__(ltimer_task);

/* //////////////////////////////////////////////////////////////////////////////////////
 * interfaces
 */

/*! init timer
 *
 * lower tick and limit range, but faster
 *
 * @param grow          the timer grow
 * @param tick          the timer tick
 * @param ctime         using ctime?
 *
 * @return              the timer
 */
tb_ltimer_ref_t         tb_ltimer_init(tb_size_t grow, tb_size_t tick, tb_bool_t ctime);

/*! exit timer
 *
 * @param timer         the timer
 */
tb_void_t               tb_ltimer_exit(tb_ltimer_ref_t timer);

/*! kill timer for tb_ltimer_loop()
 *
 * @param timer         the timer
 */
tb_void_t               tb_ltimer_kill(tb_ltimer_ref_t timer);

/*! clear timer
 *
 * @param timer         the timer
 */
tb_void_t               tb_ltimer_clear(tb_ltimer_ref_t timer);

/*! the timer limit
 *
 * @param timer         the timer
 *
 * @return              the timer limit range: [now, now + limit)
 */
tb_size_t               tb_ltimer_limit(tb_ltimer_ref_t timer);

/*! the timer delay for spak
 *
 * @param timer         the timer
 *
 * @return              the timer delay, (tb_size_t)-1: error or no task
 */
tb_size_t               tb_ltimer_delay(tb_ltimer_ref_t timer);

/*! spak timer for the external loop at the single thread
 *
 * @code
   tb_void_t tb_ltimer_loop()
   {
        while (1)
        {
            // wait
            wait(tb_ltimer_delay(timer))

            // spak timer
            tb_ltimer_spak(timer);
        }
   }
 * @endcode
 *
 * @param timer         the timer
 *
 * @return              tb_true or tb_false
 */
tb_bool_t               tb_ltimer_spak(tb_ltimer_ref_t timer);

/*! loop timer for the external thread
 *
 * @code
   tb_void_t tb_ltimer_thread(tb_cpointer_t priv)
   {
        tb_ltimer_loop(timer);
   }
 * @endcode
 *
 * @param timer         the timer
 *
 */
tb_void_t               tb_ltimer_loop(tb_ltimer_ref_t timer);

/*! post timer task after delay and will be auto-remove it after be expired
 *
 * @param timer         the timer
 * @param delay         the delay time, ms
 * @param repeat        is repeat?
 * @param func          the timer func
 * @param priv          the timer priv
 *
 */
tb_void_t               tb_ltimer_task_post(tb_ltimer_ref_t timer, tb_size_t delay, tb_bool_t repeat, tb_ltimer_task_func_t func, tb_cpointer_t priv);

/*! post timer task at the absolute time and will be auto-remove it after be expired
 *
 * @param timer         the timer
 * @param when          the absolute time, ms
 * @param period        the period time, ms
 * @param repeat        is repeat?
 * @param func          the timer func
 * @param priv          the timer priv
 *
 */
tb_void_t               tb_ltimer_task_post_at(tb_ltimer_ref_t timer, tb_hize_t when, tb_size_t period, tb_bool_t repeat, tb_ltimer_task_func_t func, tb_cpointer_t priv);

/*! run timer task after the relative time and will be auto-remove it after be expired
 *
 * @param timer         the timer
 * @param after         the after time, ms
 * @param period        the period time, ms
 * @param repeat        is repeat?
 * @param func          the timer func
 * @param priv          the timer priv
 *
 */
tb_void_t               tb_ltimer_task_post_after(tb_ltimer_ref_t timer, tb_hize_t after, tb_size_t period, tb_bool_t repeat, tb_ltimer_task_func_t func, tb_cpointer_t priv);

/*! init and post timer task after delay and need remove it manually
 *
 * @param timer         the timer
 * @param delay         the delay time, ms
 * @param repeat        is repeat?
 * @param func          the timer func
 * @param priv          the timer priv
 *
 * @return              the timer task
 */
tb_ltimer_task_ref_t    tb_ltimer_task_init(tb_ltimer_ref_t timer, tb_size_t delay, tb_bool_t repeat, tb_ltimer_task_func_t func, tb_cpointer_t priv);

/*! init and post timer task at the absolute time and need remove it manually
 *
 * @param timer         the timer
 * @param when          the absolute time, ms
 * @param period        the period time, ms
 * @param repeat        is repeat?
 * @param func          the timer func
 * @param priv          the timer priv
 *
 * @return              the timer task
 */
tb_ltimer_task_ref_t    tb_ltimer_task_init_at(tb_ltimer_ref_t timer, tb_hize_t when, tb_size_t period, tb_bool_t repeat, tb_ltimer_task_func_t func, tb_cpointer_t priv);

/*! init and post timer task after the relative time and need remove it manually
 *
 * @param timer         the timer
 * @param after         the after time, ms
 * @param period        the period time, ms
 * @param repeat        is repeat?
 * @param func          the timer func
 * @param priv          the timer priv
 *
 * @return              the timer task
 */
tb_ltimer_task_ref_t    tb_ltimer_task_init_after(tb_ltimer_ref_t timer, tb_hize_t after, tb_size_t period, tb_bool_t repeat, tb_ltimer_task_func_t func, tb_cpointer_t priv);

/*! exit timer task, the task will be not called if have been not called
 *
 * @param timer         the timer
 * @param task          the timer task
 */
tb_void_t               tb_ltimer_task_exit(tb_ltimer_ref_t timer, tb_ltimer_task_ref_t task);

/*! kill timer task, the task will be called immediately if have been not called
 *
 * @param timer         the timer
 * @param task          the timer task
 */
tb_void_t               tb_ltimer_task_kill(tb_ltimer_ref_t timer, tb_ltimer_task_ref_t task);

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_leave__

#endif
