/*
 *
 * Copyright 2015-2016, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef GRPC_CORE_IOMGR_IOCP_WINDOWS_H
#define GRPC_CORE_IOMGR_IOCP_WINDOWS_H

#include <grpc/support/sync.h>

#include "src/core/iomgr/socket_windows.h"

typedef enum {
  GRPC_IOCP_WORK_WORK,
  GRPC_IOCP_WORK_TIMEOUT,
  GRPC_IOCP_WORK_KICK
} grpc_iocp_work_status;

grpc_iocp_work_status grpc_iocp_work(grpc_exec_ctx *exec_ctx,
                                     gpr_timespec deadline);
void grpc_iocp_init(void);
void grpc_iocp_kick(void);
void grpc_iocp_flush(void);
void grpc_iocp_shutdown(void);
void grpc_iocp_add_socket(grpc_winsocket *);

void grpc_socket_notify_on_write(grpc_exec_ctx *exec_ctx,
                                 grpc_winsocket *winsocket,
                                 grpc_closure *closure);

void grpc_socket_notify_on_read(grpc_exec_ctx *exec_ctx,
                                grpc_winsocket *winsocket,
                                grpc_closure *closure);

#endif /* GRPC_CORE_IOMGR_IOCP_WINDOWS_H */
