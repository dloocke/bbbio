/*++

Header Name:

	BBBIO.c
	
Header Description:

	This file contains the public interface for applications to do IO
	with the BeagleBone Black pins.
	
Author:

	Michael Soliterman (msoliter@berkeley.edu) 30-Apr-2013
	
Environment:

	Ångström Distribution on BeagleBone Black (Revision A52)
	
--*/

//
// ------------------------------------------------------------------- Includes
//

//
// ---------------------------------------------------------------- Definitions
//

//
// ----------------------------------------------------------- Type Definitions
//

//
// ------------------------------------------------- Public Function Prototypes
//


bool
BBBIOPut (
	BBBIO_PIN Pin,
	BBBIO_VALUE Value
	);
	
/*++

Routine Description:

	This routine sets a pin to the specified value.
	
Arguments:

	Pin - supplies the pin to be set
	
	Value - supplies the new value for the pin
	
Return Value:

	True if the pin was successfully updated, false otherwise.

--*/

bool
BBBIOGet (
	BBBIO_PIN Pin
	BBBIO_VALUE* Value
	);
	
/*++

Routine Description:

	This routine gets the value of a pin.
	
Arguments:

	Pin - supplies the pin whose value to get
	
	Value - supplies a buffer where the value may be written
	
Return Value:

	True if the pin's value was written to the buffer, false otherwise.

--*/

