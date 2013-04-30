/*++

File Name:

	BBBIO.c
	
File Description:

	This file contains routines for accessing and updating the IO pins
	on the BeagleBone Black.
	
Author:

	Michael Soliterman (msoliter@berkeley.edu) 30-Apr-2013
	
Environment:

	Ångström Distribution on BeagleBone Black (Revision A52)
	
--*/

//
// ------------------------------------------------------------------- Includes
//

#include <stdbool.h>
#include "pBBBIO.h"

//
// ------------------------------------------------ Private Function Prototypes
//

//
// ------------------------------------------------ Public Function Definitions
//

bool
IOPut (
	PIN Pin,
	VALUE Value
	)
	
/*++

Routine Description:

	This routine sets a pin to the specified value.
	
Arguments:

	Pin - supplies the pin to be set
	
	Value - supplies the new value for the pin
	
Return Value:

	True if the pin was successfully updated, false otherwise.

--*/

{

	// Check if the pin is a valid one by looking it up in the dictionary.
	// Get the pin's write location depending on what it is.
	// Call the pin's write routine using the given value.
	// Return false if an error occurred; else, return true.
	return false;
}

bool
IOGet (
	PIN Pin
	VALUE* Value
	)
	
/*++

Routine Description:

	This routine gets the value of a pin.
	
Arguments:

	Pin - supplies the pin whose value to get
	
	Value - supplies a buffer where the value may be written
	
Return Value:

	True if the pin's value was written to the buffer, false otherwise.

--*/

{

	// Check if the pin is a valid one by looking it up in the dictionary.
	// Get the pin's read location depending on what it is.
	// Call the pin's read routine; write the value into the buffer.
	// Return false if an error occurred; else, return true.
	return false;
}

//
// ----------------------------------------------- Private Function Definitions
//

