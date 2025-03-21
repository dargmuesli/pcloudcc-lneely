/*
   Copyright (c) 2014 Anton Titov.

   Copyright (c) 2014 pCloud Ltd.  All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met: Redistributions of source code must retain the above
   copyright notice, this list of conditions and the following
   disclaimer.  Redistributions in binary form must reproduce the
   above copyright notice, this list of conditions and the following
   disclaimer in the documentation and/or other materials provided
   with the distribution.  Neither the name of pCloud Ltd nor the
   names of its contributors may be used to endorse or promote
   products derived from this software without specific prior written
   permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
   FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL pCloud
   Ltd BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
   OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
   USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
   DAMAGE.
*/

#ifndef _PSYNC_FSXATTR_H
#define _PSYNC_FSXATTR_H

#include <stddef.h>

#include "pfoldersync.h"

#define PFS_XATTR_IGN

int psync_fs_setxattr(const char *path, const char *name, const char *value,
                      size_t size, int flags PFS_XATTR_IGN);
int psync_fs_getxattr(const char *path, const char *name, char *value,
                      size_t size PFS_XATTR_IGN);
int psync_fs_listxattr(const char *path, char *list, size_t size);
int psync_fs_removexattr(const char *path, const char *name);

void psync_fs_file_deleted(psync_fileid_t fileid);
void psync_fs_folder_deleted(psync_folderid_t folderid);
void psync_fs_task_deleted(uint64_t taskid);

void psync_fs_task_to_file(uint64_t taskid, psync_fileid_t fileid);
void psync_fs_task_to_folder(uint64_t taskid, psync_folderid_t folderid);
void psync_fs_static_to_task(uint64_t statictaskid, uint64_t taskid);
void psync_fs_file_to_task(psync_fileid_t fileid, uint64_t taskid);

#endif
