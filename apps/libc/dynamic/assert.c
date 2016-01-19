/*++

Copyright (c) 2013 Minoca Corp. All Rights Reserved

Module Name:

    assert.c

Abstract:

    This module implements assertion support for the C library.

Author:

    Evan Green 27-May-2013

Environment:

    User Mode C Library

--*/

//
// ------------------------------------------------------------------- Includes
//

#include "libcp.h"
#include <stdio.h>

//
// ---------------------------------------------------------------- Definitions
//

//
// ------------------------------------------------------ Data Type Definitions
//

//
// ----------------------------------------------- Internal Function Prototypes
//

//
// -------------------------------------------------------------------- Globals
//

//
// ------------------------------------------------------------------ Functions
//

LIBC_API
void
_assert (
    char *Expression,
    char *File,
    int Line
    )

/*++

Routine Description:

    This routine implements the underlying assert function that backs the
    assert macro.

Arguments:

    File - Supplies a pointer to the null terminated string describing the file
        the assertion failure occurred in.

    Line - Supplies the line number the assertion failure occurred on.

    Expression - Supplies a pointer to the string representation of the
        source expression that failed.

Return Value:

    This routine does not return.

--*/

{

    ClpFlushAllStreams(TRUE, NULL);
    RtlRaiseAssertion(Expression, File, Line);
    return;
}

//
// --------------------------------------------------------- Internal Functions
//

