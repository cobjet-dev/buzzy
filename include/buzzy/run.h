/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the COPYING file in this distribution for license details.
 * ----------------------------------------------------------------------
 */

#ifndef BUZZY_RUN_H
#define BUZZY_RUN_H

#include <libcork/core.h>
#include <libcork/ds.h>


/*-----------------------------------------------------------------------
 * Executing subprocesses
 */

/* Execute the subprocess, wait for it to finish, and capture its stdout and
 * stderr streams into the given buffers.  (The buffers can be NULL, in which
 * case that output stream is ignored.) */
int
bz_subprocess_get_output(const char *program, char * const *params,
                         struct cork_buffer *out, struct cork_buffer *err);

/* Execute the subprocess and wait for it to finish.
 *
 * If verbose is true, then the subprocess's stdout and stderr will be the same
 * as the calling process, so the end user will see the subprocess's output.  If
 * verbose is false, then the subprocess's output will be ignored.
 *
 * If successful is non-NULL, we'll fill it in with whether the subprocess's
 * exit code was 0 (indicating success). */
int
bz_subprocess_run(const char *program, char * const *params, bool verbose,
                  bool *successful);


/*-----------------------------------------------------------------------
 * Mocking subprocesses for test cases
 */

void
bz_subprocess_start_mocks(void);

/* To make it easier to specify the mocks, you provide a full command line,
 * which is the result of concatenating (separated by spaces) the program and
 * params parameters from one of the above subprocess-calling functions. */
void
bz_subprocess_mock(const char *cmd, const char *out, const char *err,
                   int exit_code);

/* Allow a particular command to actually be executed. */
void
bz_subprocess_mock_allow_execute(const char *cmd);


#endif /* BUZZY_RUN_H */
