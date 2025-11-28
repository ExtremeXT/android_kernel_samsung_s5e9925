/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * Copyright (c) 2025 Samsung Electronics Co., Ltd.
 *               http://www.samsung.com
 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM power
#if !defined(_SGPU_POWER_TRACE_H_) || defined(TRACE_HEADER_MULTI_READ)
#define _SGPU_POWER_TRACE_H_
#include <linux/stringify.h>
#include <linux/types.h>
#include <linux/tracepoint.h>

TRACE_EVENT(gpu_frequency,
	TP_PROTO(u32 gpu_id, u32 state),
	TP_ARGS(gpu_id, state),
	TP_STRUCT__entry(
		__field(u32, gpu_id)
		__field(u32, state)
	),
	TP_fast_assign(
		__entry->gpu_id = gpu_id;
		__entry->state = state;
	),
	TP_printk("gpu_id:%u, gpu_freq:%u",
		__entry->gpu_id, __entry->state)
);
#endif  /* _SGPU_POWER_TRACE_H_ */

/* This part must be outside protection */
#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH .
#undef TRACE_INCLUDE_FILE
#define TRACE_INCLUDE_FILE sgpu_power_trace
#include <trace/define_trace.h>
