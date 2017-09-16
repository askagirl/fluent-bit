/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit
 *  ==========
 *  Copyright (C) 2015-2017 Treasure Data Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef FLB_METRICS_H
#define FLB_METRICS_H

struct flb_metric {
    int id;
    char title[32];
    size_t val;
    struct mk_list _head;
};

struct flb_metrics {
    char title[32];        /* Title or id for this metrics context */
    int count;             /* Total count of metrics registered */
    struct mk_list list;   /* Head of metrics list */
};

struct flb_metrics *flb_metrics_create(char *title);
struct flb_metric *flb_metrics_get_id(int id, struct flb_metrics *metrics);
int flb_metrics_add(int id, char *title, struct flb_metrics *metrics);
int flb_metrics_sum(int id, size_t val, struct flb_metrics *metrics);
int flb_metrics_print(struct flb_metrics *metrics);
int flb_metrics_destroy(struct flb_metrics *metrics);

#endif
