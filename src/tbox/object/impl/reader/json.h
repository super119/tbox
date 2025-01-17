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
 * @file        json.h
 * @ingroup     object
 *
 */
#ifndef TB_OBJECT_IMPL_READER_JSON_H
#define TB_OBJECT_IMPL_READER_JSON_H

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_enter__

/* //////////////////////////////////////////////////////////////////////////////////////
 * types
 */

/// the json reader type
typedef struct __tb_oc_json_reader_t
{
    /// the stream
    tb_stream_ref_t              stream;

}tb_oc_json_reader_t;

/// the json reader func type
typedef tb_object_ref_t      (*tb_oc_json_reader_func_t)(tb_oc_json_reader_t* reader, tb_char_t type);

/* //////////////////////////////////////////////////////////////////////////////////////
 * interfaces
 */

/*! the json object reader
 *
 * @return                      the json object reader
 */
tb_oc_reader_t*                 tb_oc_json_reader(tb_noarg_t);

/*! hook the json reader
 *
 * @param type                  the object type name
 * @param func                  the reader func
 *
 * @return                      tb_true or tb_false
 */
tb_bool_t                       tb_oc_json_reader_hook(tb_char_t type, tb_oc_json_reader_func_t func);

/*! the json reader func
 *
 * @param type                  the object type name
 *
 * @return                      the object reader func
 */
tb_oc_json_reader_func_t        tb_oc_json_reader_func(tb_char_t type);

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_leave__

#endif

