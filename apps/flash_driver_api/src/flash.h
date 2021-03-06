/*
 * Copyright (c) 2013-2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _FLASH_H_
#define _FLASH_H_




#include <stdint.h>
#include <stdbool.h>

//! @addtogroup flash_api
//! @{

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! @brief Construct a status code value from a group and code number.
#define MAKE_STATUS(group,code) ((((group) * 100) + (code)))

//! @brief Build a 32-bit code from four character values.
//!
//! The resulting value is built with a byte order such that the string
//! being readable in expected order when viewed in a hex editor, if the value
//! is treated as a 32-bit little endian value.
#define FOUR_CHAR_CODE(a,b,c,d) (((d) << 24) | ((c) << 16) | ((b) << 8) | ((a)))

//! @brief Status group numbers.
enum _status_groups
{
    kStatusGroup_Generic = 0,           //!< Group number for generic status codes.
    kStatusGroup_FlashDriver = 1,       //!< Flash driver status group number.
};

//! @brief Generic status return codes.
enum _generic_status
{
    kStatus_Success         = MAKE_STATUS(kStatusGroup_Generic, 0),
    kStatus_Fail            = MAKE_STATUS(kStatusGroup_Generic, 1),
    kStatus_ReadOnly        = MAKE_STATUS(kStatusGroup_Generic, 2),
    kStatus_OutOfRange      = MAKE_STATUS(kStatusGroup_Generic, 3),
    kStatus_InvalidArgument = MAKE_STATUS(kStatusGroup_Generic, 4)
};

//! @brief Type used for all status and error return values.
typedef int32_t status_t;

//! @brief Flash driver status codes.
enum _flash_status
{
    kStatus_FlashSizeError = MAKE_STATUS(kStatusGroup_FlashDriver, 0),
    kStatus_FlashAlignmentError = MAKE_STATUS(kStatusGroup_FlashDriver, 1),
    kStatus_FlashAddressError = MAKE_STATUS(kStatusGroup_FlashDriver, 2),
    kStatus_FlashAccessError = MAKE_STATUS(kStatusGroup_FlashDriver, 3),
    kStatus_FlashProtectionViolation = MAKE_STATUS(kStatusGroup_FlashDriver, 4),
    kStatus_FlashCommandFailure = MAKE_STATUS(kStatusGroup_FlashDriver, 5),
    kStatus_FlashUnknownProperty = MAKE_STATUS(kStatusGroup_FlashDriver, 6),
    kStatus_FlashEraseKeyError = MAKE_STATUS(kStatusGroup_FlashDriver, 7),
    kStatus_FlashRegionExecuteOnly = MAKE_STATUS(kStatusGroup_FlashDriver, 8),
    kStatus_FlashApiNotSupported   = MAKE_STATUS(kStatusGroup_FlashDriver, 15),
};

//! @brief Enumeration for flash driver API keys.
enum _flash_driver_api_keys
{
    //! @brief Key value used to validate all flash erase APIs.
    kFlashEraseKey = FOUR_CHAR_CODE('k', 'f', 'e', 'k')
};

//! @brief Enumeration for supported flash margin levels.
typedef enum _flash_margin_value {
    kFlashMargin_Normal,
    kFlashMargin_User,
    kFlashMargin_Factory,

    // Not real margin level, Used to determine the range of valid margin level.
    kFlashMargin_Invalid
} flash_margin_value_t;

//! @brief Enumeration for the three possible flash security states.
typedef enum _flash_security_state {
    kFlashNotSecure,
    kFlashSecureBackdoorEnabled,
    kFlashSecureBackdoorDisabled
} flash_security_state_t;

//! @brief Enumeration for the three possible flash protection levels.
typedef enum _flash_protection_state {
    kFlashProtection_Unprotected,
    kFlashProtection_Protected,
    kFlashProtection_Mixed
} flash_protection_state_t;


//! @brief Enumeration for the three possible flash execute access levels.
typedef enum _flash_execute_only_access_state {
    kFlashAccess_UnLimited,
    kFlashAccess_ExecuteOnly,
    kFlashAccess_Mixed
} flash_execute_only_access_state_t;

//! @brief Enumeration for various flash properties.
typedef enum _flash_property {
    kFlashProperty_SectorSize = 0,
    kFlashProperty_TotalFlashSize = 1,
    kFlashProperty_BlockCount = 3,
    kFlashProperty_FlashBlockBaseAddr,
    kFlashProperty_FlashFacSupport,
    kFlashProperty_FlashAccessSegmentSize,
    kFlashProperty_FlashAccessSegmentCount,
    kFlashProperty_Version,
} flash_property_t;


//! @brief callback type used for pflash block
typedef void (* flash_callback_t)(void);


//! @brief Flash driver state information.
//!
//! An instance of this structure is allocated by the user of the flash driver and
//! passed into each of the driver APIs.
typedef struct _flash_driver {
    uint32_t PFlashBlockBase;           //!< Base address of the first PFlash block
    uint32_t PFlashTotalSize;           //!< Size of all combined PFlash block.
    uint32_t PFlashBlockCount;          //!< Number of PFlash blocks.
    uint32_t PFlashSectorSize;          //!< Size in bytes of a sector of PFlash.
    flash_callback_t PFlashCallback;    //!< Callback function for flash API.
    uint32_t PFlashAccessSegmentSize;   //!< Size in bytes of a access segment of PFlash.
    uint32_t PFlashAccessSegmentCount;  //!< Number of PFlash access segments.
} flash_driver_t;


//! @brief Enumeration for the tow possible options of flash read resource command.
typedef enum _flash_read_resource_option
{
    kFlashResource_ProgramIFR = 0,
    kFlashResource_VersionID = 1
} flash_read_resource_option_t;


////////////////////////////////////////////////////////////////////////////////
// API
////////////////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
extern "C" {
#endif

//! @name Initialization
//@{

/*!
 * @brief Initializes global flash properties structure members
 *
 * This function checks and initializes Flash module for the other Flash APIs.
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @return An error code or kStatus_Success
 */
status_t flash_init(flash_driver_t * driver);

/*!
 * @brief Register the desired flash callback function
 * @param driver    Pointer to storage for the driver runtime state.
 * @param callback  callback function to be stored in driver
 *
 * @return An error code or kStatus_Success
 */
status_t flash_register_callback(flash_driver_t * driver, flash_callback_t callback);

//@}

//! @name Erasing
//@{

/*!
 * @brief Erases entire flash
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @param key value used to validate all flash erase APIs.
 *
 * @return An error code or kStatus_Success
 */
status_t flash_erase_all(flash_driver_t * driver, uint32_t key);

/*!
 * @brief Erases flash sectors encompassed by parameters passed into function
 *
 * This function erases the appropriate number of flash sectors based on the
 * desired start address and length.
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be erased.
 *        The start address does not need to be sector aligned but must be word-aligned.
 * @param lengthInBytes The length, given in bytes (not words or long-words)
 *        to be erased. Must be word aligned.
 * @param key value used to validate all flash erase APIs.
 *
 * @return An error code or kStatus_Success
 */
status_t flash_erase(flash_driver_t * driver, uint32_t start, uint32_t lengthInBytes, uint32_t key);


/*!
 * @brief Erases entire flash, including protected sectors.
 *
 * @param driver Pointer to storage for the driver runtime state
 * @param key value used to validate all flash erase APIs.
 * 
 * @return An error code or kStatus_Success
 */
status_t flash_erase_all_unsecure(flash_driver_t * driver, uint32_t key);
//@}

//! @name Programming
//@{

/*!
 * @brief Programs flash with data at locations passed in through parameters
 *
 * This function programs the flash memory with desired data for a given
 * flash area as determined by the start address and length.
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be programmed. Must be
 *              word-aligned.
 * @param lengthInBytes The length, given in bytes (not words or long-words)
 *        to be programmed. Must be word-aligned.
 * @param src Pointer to the source buffer of data that is to be programmed
 *        into the flash.
 *
 * @return An error code or kStatus_Success
 */
status_t flash_program(flash_driver_t * driver, uint32_t start, uint32_t * src, uint32_t lengthInBytes);

/*!
 * @brief Programs Program Once Field through parameters
 *
 * This function programs the Program Once Field with desired data for a given
 * flash area as determined by the index and length.
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @param index The index indicating which area of Program Once Field to be programmed.
 * @param lengthInBytes The length, given in bytes (not words or long-words)
 *        to be programmed. Must be word-aligned.
 * @param src Pointer to the source buffer of data that is to be programmed
 *        into the Program Once Field.
 *
 * @return An error code or kStatus_Success
 */
status_t flash_program_once(flash_driver_t * driver, uint32_t index, uint32_t * src, uint32_t lengthInBytes);

//@}

//! @name Reading
//@{

/*!
 * @brief Read resource with data at locations passed in through parameters
 *
 * This function reads the flash memory with desired location for a given
 * flash area as determined by the start address and length.
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be programmed. Must be
 *              word-aligned.
 * @param lengthInBytes The length, given in bytes (not words or long-words)
 *        to be read. Must be word-aligned.
 * @param dst Pointer to the destination buffer of data that is used to store
 *        data to be read.
 * @param option The resource option which indicates which area should be read back.
 *
 * @return An error code or kStatus_Success
 */
status_t flash_read_resource(flash_driver_t * driver, uint32_t start, uint32_t *dst, uint32_t lengthInBytes, flash_read_resource_option_t option);

/*!
 * @brief Read Program Once Field through parameters
 *
 * This function reads the read once feild with given index and length
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @param index The index indicating the area of program once field to be read.
 * @param lengthInBytes The length, given in bytes (not words or long-words)
 *        to be programmed. Must be word-aligned.
 * @param dst Pointer to the destination buffer of data that is used to store
 *        data to be read.
 *
 * @return An error code or kStatus_Success
 */
status_t flash_read_once(flash_driver_t * driver, uint32_t index, uint32_t *dst, uint32_t lengthInBytes);

//@}



//! @name Security
//@{

/*!
 * @brief Returns the security state via the pointer passed into the function
 *
 * This function retrieves the current Flash security status, including the
 * security enabling state and the backdoor key enabling state.
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @param state Pointer to the value returned for the current security status code:
 *          - #kFlashNotSecure
 *          - #kFlashSecureBackdoorEnabled
 *          - #kFlashSecureBackdoorDisabled
 *
 * @return kStatus_Success
 */
status_t flash_get_security_state(flash_driver_t * driver, flash_security_state_t * state);

/*!
 * @brief Allows user to bypass security with a backdoor key
 *
 * If the MCU is in secured state, this function will unsecure the MCU by
 * comparing the provided backdoor key with ones in the Flash Configuration
 * Field.
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @param backdoorKey Pointer to the user buffer containing the backdoor key.
 *
 * @return An error code or kStatus_Success
 */
status_t flash_security_bypass(flash_driver_t * driver, const uint8_t * backdoorKey);

//@}

//! @name Verification
//@{

/*!
 * @brief Verifies erasure of entire flash at specified margin level
 *
 * This function will check to see if the flash have been erased to the
 * specified read margin level.
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @param margin Read margin choice as follows: #kFlashMargin_Normal,
 *        #kFlashMargin_User, or #kFlashMargin_Factory
 *
 * @return An error code or kStatus_Success
 */
status_t flash_verify_erase_all(flash_driver_t * driver, flash_margin_value_t margin);

/*!
 * @brief Verifies erasure of desired flash area at specified margin level
 *
 * This function will check the appropriate number of flash sectors based on
 * the desired start address and length to see if the flash have been erased
 * to the specified read margin level.
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be verified.
 *        The start address does not need to be sector aligned but must be word-aligned.
 * @param lengthInBytes The length, given in bytes (not words or long-words)
 *        to be verified. Must be word-aligned.
 * @param margin Read margin choice as follows: #kFlashMargin_Normal,
 *        #kFlashMargin_User, or #kFlashMargin_Factory
 *
 * @return An error code or kStatus_Success
 */
status_t flash_verify_erase(flash_driver_t * driver, uint32_t start, uint32_t lengthInBytes, flash_margin_value_t margin);

/*!
 * @brief Verifies programming of desired flash area at specified margin level
 *
 * This function verifies the data programed in the flash memory using the
 * Flash Program Check Command and compares it with expected data for a given
 * flash area as determined by the start address and length.
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @param start The start address of the desired flash memory to be verified. Must be word-aligned.
 * @param lengthInBytes The length, given in bytes (not words or long-words)
 *        to be verified. Must be word-aligned.
 * @param expectedData Pointer to the expected data that is to be
 *        verified against.
 * @param margin Read margin choice as follows: kFlashMargin_User or
 *        kFlashMargin_Factory
 * @param failedAddress Pointer to returned failing address.
 * @param failedData Pointer to returned failing data.  Some derivitives do
 *        not included failed data as part of the FCCOBx registers.  In this
 *        case, zeros are returned upon failure.
 *
 * @return An error code or kStatus_Success
 */
status_t flash_verify_program(flash_driver_t * driver, uint32_t start, uint32_t lengthInBytes,
                              const uint8_t * expectedData, flash_margin_value_t margin,
                              uint32_t * failedAddress, uint32_t * failedData);

//@}


//! @name Properties
//@{

/*!
 * @brief Returns the desired flash property.
 *
 * @param driver Pointer to storage for the driver runtime state.
 * @param whichProperty The desired property from the list of properties in
 *        enum flash_property_t
 * @param value Pointer to the value returned for the desired flash property
 *
 * @return An error code or kStatus_Success
 */
status_t flash_get_property(flash_driver_t * driver, flash_property_t whichProperty, uint32_t * value);

//@}



#if defined(__cplusplus)
}
#endif

//! @}

#endif // _FLASH_H_
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
