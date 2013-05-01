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
#include <stdio.h>
#include <stdlib.h>
#include "pBBBIO.h"

//
// -------------------------------------------------Global Variable Definitions
//

char CommandBuffer[1024] = "";

//
// ------------------------------------------------ Private Function Prototypes
//

bool
pBBBIOGetValue (
	BBBIO_PIN Pin,
	char* Buffer,
	int Size
	);

bool
pBBBIOSetValue (
	BBBIO_PIN Pin,
	char* Value
	);
	
bool
pBBBIOLockPin (
	BBBIO_PIN Pin
	);

bool
pBBBIOUnlockPin (
	BBBIO_PIN Pin
	);
	
//
// ------------------------------------------------ Public Function Definitions
//

//
// ----------------------------------------------- Private Function Definitions
//

bool
pBBBIOGetValue (
	BBBIO_PIN Pin,
	char* Buffer,
	int Size
	)
	
/*++

Routine Description:

	This routine will get a string value of a particular pin.
	
Arguments:

	Pin - supplies the pin whose value to read
	
	Buffer - supplies a buffer where the value can be written
	
	Size - supplies the size of the provided buffer

Return Value:

	True if the value was successfully written to the buffer, false otherwise.

--*/

{

	int CharactersRead;
	FILE* ValueFile;
	char ValueFileName[256];

	snprintf(ValueFileName,
			 sizeof(ValueFileName),
			 "%s/gpio%d/value",
			 BBBIO_GPIO_DIRECTORY,
			 Pin.Index);
			
	if (BBBIO_DEBUG) {
		printf("Opening %s\n", ValueFileName);
	}	
			
	ValueFile = fopen(ValueFileName, "r");
	if (ValueFile != NULL) {
		CharactersRead = getline(&Buffer,
		  	   				     &Size,
			  					 ValueFile);
							   
	    Buffer[CharactersRead - 1] = '\0';
		fclose(ValueFile);	
		return true;
	}
	
	return false;
}

bool
pBBBIOSetValue (
	BBBIO_PIN Pin,
	char* Value
	)
	
/*++

Routine Description:

	This routine will write a string value to a pin.
	
Arguments:

	Pin - supplies the pin to be written to
	
	Value - supplies the value to write
	
Return Value:

	True if the pin's value was updated successfully, false otherwise.
	
--*/

{

	int Success;
	
	if (Value == NULL) {
		return false;
	}
								  
	snprintf(CommandBuffer,
			 sizeof(CommandBuffer),
			 "echo %s > %s/gpio%d/value 2> /dev/null",
			 Value,
			 BBBIO_GPIO_DIRECTORY,
			 Pin.Index);
	
	if (BBBIO_DEBUG) {
		printf("%s\n", CommandBuffer);
	}	
	
	Success = system(CommandBuffer);
	return (Success == BBBIO_SUCCESS);
}

bool
pBBBIOLockPin (
	BBBIO_PIN Pin
	)
	
/*++

Routine Description:

	This routine will export a pin so that this program can control it.
	
Arguments:

	Pin - supplies the pin to be exported
	
Return Value:

	True if the pin was successfully exported, false otherwise.

--*/

{
	
	int Success;
	
	//
	// Build the export command.
	//
	
	snprintf(CommandBuffer, 
			 sizeof(CommandBuffer),
			 "echo %d > %s 2> /dev/null",
			 Pin.Index,
			 BBBIO_GPIO_EXPORT);
	
	//
	// Execute the export command.
	//
	
	if (BBBIO_DEBUG) {
		printf("%s\n", CommandBuffer);
	}
	
	Success = system(CommandBuffer);
	return (Success == BBBIO_SUCCESS);
}

bool
pBBBIOUnlockPin (
	BBBIO_PIN Pin
	)
	
/*++

Routine Description:

	This routine will unexport a pin so that other programs can use it.
	
Arguments:

	Pin - supplies the pin to be unexported
	
Return Value:

	True if the pin was successfully unexported, false otherwise.

--*/

{
	
	int Success;
	
	//
	// Build the unexport command.
	//
	
	snprintf(CommandBuffer, 
			 sizeof(CommandBuffer),
			 "echo %d > %s 2> /dev/null",
			 Pin.Index,
			 BBBIO_GPIO_UNEXPORT);
	
	//
	// Execute the unexport command.
	//
	
	if (BBBIO_DEBUG) {
		printf("%s\n", CommandBuffer);
	}	
	
	Success = system(CommandBuffer);
	return (Success == BBBIO_SUCCESS);
}

