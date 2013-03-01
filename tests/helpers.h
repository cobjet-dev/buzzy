/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2011-2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the COPYING file in this distribution for license details.
 * ----------------------------------------------------------------------
 */

#ifndef TESTS_HELPERS_H
#define TESTS_HELPERS_H

#include <string.h>

#include "libcork/core/error.h"

#include "buzzy/action.h"
#include "buzzy/run.h"
#include "buzzy/version.h"

#if !defined(PRINT_EXPECTED_FAILURES)
#define PRINT_EXPECTED_FAILURES  1
#endif

#if PRINT_EXPECTED_FAILURES
#define print_expected_failure() \
    printf("[expected: %s]\n", cork_error_message());
#else
#define print_expected_failure()  /* do nothing */
#endif


#define DESCRIBE_TEST \
    fprintf(stderr, "--- %s\n", __func__);


#define fail_if_error(call) \
    do { \
        call; \
        if (cork_error_occurred()) { \
            fail("%s", cork_error_message()); \
        } \
    } while (0)

#define fail_unless_error(call, ...) \
    do { \
        call; \
        if (!cork_error_occurred()) { \
            fail(__VA_ARGS__); \
        } else { \
            print_expected_failure(); \
        } \
        cork_error_clear(); \
    } while (0)

#define fail_unless_equal(what, format, expected, actual) \
    (fail_unless((expected) == (actual), \
                 "%s not equal (expected " format \
                 ", got " format ")", \
                 (what), (expected), (actual)))

#define fail_unless_streq(what, expected, actual) \
    (fail_unless(strcmp((expected), (actual)) == 0, \
                 "%s not equal (expected \"%s\", got \"%s\")", \
                 (char *) (what), (char *) (expected), (char *) (actual)))


CORK_ATTR_UNUSED
static void
test_and_free_version(struct bz_version *version, const char *expected)
{
    fail_unless_streq("Versions", expected, bz_version_to_string(version));
    bz_version_free(version);
}


CORK_ATTR_UNUSED
static void
verify_commands_run(const char *expected_commands)
{
    fail_unless_streq("Executed commands", expected_commands,
                      bz_subprocess_mocked_commands_run());
}


CORK_ATTR_UNUSED
static void
test_action_phase(struct bz_action_phase *phase, const char *expected_actions)
{
    bz_action_start_mocks();
    fail_if_error(bz_action_phase_perform(phase));
    fail_unless_streq("Action list", expected_actions,
                      bz_action_mock_results());
}


CORK_ATTR_UNUSED
static void
test_action(struct bz_action *action, const char *expected_actions)
{
    struct bz_action_phase  *phase;
    bz_action_start_mocks();
    phase = bz_action_phase_new("Test actions");
    bz_action_phase_add(phase, action);
    test_action_phase(phase, expected_actions);
    bz_action_phase_free(phase);
}


#endif /* TESTS_HELPERS_H */
