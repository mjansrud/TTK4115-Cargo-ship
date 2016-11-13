#include "__cf_model1b.h"
#ifndef _RTW_HEADER_model1b_cap_host_h__
#define _RTW_HEADER_model1b_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } model1b_host_DataMapInfo_T
;
#ifdef __cplusplus
extern "C" {
#endif
void model1b_host_InitializeDataMapInfo ( model1b_host_DataMapInfo_T *
dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
