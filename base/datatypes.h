#ifndef DATATYPES_H_
#define DATATYPES_H_
/** \addtogroup apistruct
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

// definition of size_t
#include <stdlib.h>
#include <stdint.h>
#ifndef _MSC_VER
#include <stdbool.h>
#endif

#ifdef __unix__
#define DllExport
#ifndef MAX_PATH
#define MAX_PATH 1024
#endif
#else
#include <windows.h>
#define DllExport __declspec(dllexport)
#endif


typedef enum {
	LICENSE_OK = 0,  // OK
	LICENSE_FILE_NOT_FOUND = 1,  // license file not found
	LICENSE_SERVER_NOT_FOUND = 2,  // license server can't be contacted
	ENVIRONMENT_VARIABLE_NOT_DEFINED = 3,  // environment variable not defined
	FILE_FORMAT_NOT_RECOGNIZED = 4,  // license file has invalid format (not .ini file)
	LICENSE_MALFORMED = 5,  // some mandatory field are missing, or data can't be fully read.
	PRODUCT_NOT_LICENSED = 6,  // this product was not licensed
	PRODUCT_EXPIRED = 7,    //!< PRODUCT_EXPIRED
	LICENSE_CORRUPTED = 8,  // License signature didn't match with current license
	IDENTIFIERS_MISMATCH = 9,  // Calculated identifier and the one provided in license didn't match

	LICENSE_SPECIFIED = 100,  // license location was specified
	LICENSE_FOUND = 101,  // License file has been found or license data has been located
	PRODUCT_FOUND = 102,  // License has been loaded and the declared product has been found
	SIGNATURE_VERIFIED = 103//!< SIGNATURE_VERIFIED
} LCC_EVENT_TYPE;

typedef enum {
	LCC_LOCAL,
	LCC_REMOTE  // remote licenses are not supported now.
} LCC_LICENSE_TYPE;

typedef enum { SVRT_INFO, SVRT_WARN, SVRT_ERROR } LCC_SEVERITY;


typedef enum {
	/**
	 * A list of absolute path separated by ';' containing the eventual location
	 * of the license files. Can be NULL.
	 */
	LICENSE_PATH,
	/**
	 * The license is provided as plain data
	 */
	LICENSE_PLAIN_DATA,
	/**
	 * The license is encoded
	 */
	LICENSE_ENCODED
} LCC_LICENSE_DATA_TYPE;


typedef enum { BARE_TO_METAL, VMWARE, VIRTUALBOX, V_XEN, KVM, HV, PARALLELS, V_OTHER } LCC_API_VIRTUALIZATION_DETAIL;

typedef enum {
	PROV_UNKNOWN = 0,
	ON_PREMISE = 1,
	GOOGLE_CLOUD = 2,
	AZURE_CLOUD = 3,
	AWS = 4,
	/**
	 * "/sys/class/dmi/id/bios_vendor" SeaBIOS
	 * "/sys/class/dmi/id/sys_vendor" Alibaba Cloud
	 * modalias
	 * "dmi:bvnSeaBIOS:bvrrel-1.7.5-0-ge51488c-20140602_164612-nilsson.home.kraxel.org:bd04/01/2014:svnAlibabaCloud:pnAlibabaCloudECS:pvrpc-i440fx-2.1:cvnAlibabaCloud:ct1:cvrpc-i440fx-2.1:"
	 */
	ALI_CLOUD = 5
} LCC_API_CLOUD_PROVIDER;

typedef enum { NONE, CONTAINER, VM } LCC_API_VIRTUALIZATION_SUMMARY;

typedef struct {
	LCC_API_CLOUD_PROVIDER cloud_provider;
	LCC_API_VIRTUALIZATION_SUMMARY virtualization;
	LCC_API_VIRTUALIZATION_DETAIL virtualization_detail;
} ExecutionEnvironmentInfo;

#ifdef __cplusplus
}
#endif

/**
 * @}
 */
#endif
