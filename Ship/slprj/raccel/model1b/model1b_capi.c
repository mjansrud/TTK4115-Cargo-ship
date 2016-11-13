#include "__cf_model1b.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "model1b_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "model1b.h"
#include "model1b_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"model1b/Cargo ship/Fcn" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1
, 0 , TARGET_STRING ( "model1b/Cargo ship/Fcn1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "model1b/Cargo ship/Gain2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 3 , 0 , TARGET_STRING (
"model1b/Cargo ship/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 4 , 0 , TARGET_STRING ( "model1b/Cargo ship/Integrator1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"model1b/Cargo ship/Rudder saturation" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 6 , 0 , TARGET_STRING ( "model1b/Cargo ship/Cargo ship" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"model1b/Cargo ship/Sum2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
8 , 0 , TARGET_STRING ( "model1b/Cargo ship/Subsystem1/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 9 , TARGET_STRING ( "model1b/0.05 " ) ,
TARGET_STRING ( "Amplitude" ) , 0 , 0 , 0 } , { 10 , TARGET_STRING (
"model1b/0.05 " ) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 11 ,
TARGET_STRING ( "model1b/0.05 " ) , TARGET_STRING ( "Frequency" ) , 0 , 0 , 0
} , { 12 , TARGET_STRING ( "model1b/0.05 " ) , TARGET_STRING ( "Phase" ) , 0
, 0 , 0 } , { 13 , TARGET_STRING ( "model1b/Cargo ship/Current1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 14 , TARGET_STRING (
"model1b/Cargo ship/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 15 ,
TARGET_STRING ( "model1b/Cargo ship/Gain2" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 16 , TARGET_STRING ( "model1b/Cargo ship/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 17 , TARGET_STRING (
"model1b/Cargo ship/Integrator1" ) , TARGET_STRING ( "InitialCondition" ) , 0
, 0 , 0 } , { 18 , TARGET_STRING ( "model1b/Cargo ship/Rudder saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 19 , TARGET_STRING (
"model1b/Cargo ship/Rudder saturation" ) , TARGET_STRING ( "LowerLimit" ) , 0
, 0 , 0 } , { 20 , TARGET_STRING (
"model1b/Cargo ship/Measurement noise/Output" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 21 , TARGET_STRING (
"model1b/Cargo ship/Measurement noise/White Noise" ) , TARGET_STRING ( "Mean"
) , 0 , 0 , 0 } , { 22 , TARGET_STRING (
"model1b/Cargo ship/Measurement noise/White Noise" ) , TARGET_STRING (
"StdDev" ) , 0 , 0 , 0 } , { 23 , TARGET_STRING (
"model1b/Cargo ship/Measurement noise/White Noise" ) , TARGET_STRING ( "Seed"
) , 0 , 0 , 0 } , { 24 , TARGET_STRING ( "model1b/Cargo ship/Subsystem1/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 25 , TARGET_STRING (
"model1b/Cargo ship/Subsystem2/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0
} , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . iyqko5xknu , & rtB . guz1minmuw ,
& rtB . k3nrgrep1e , & rtB . aot4m1g5ea , & rtB . euzoh3akgm , & rtB .
g42ykh0anh , & rtB . e5extboo4y , & rtB . o233pri3cc , & rtB . o24qnkulls , &
rtP . u5_Amp , & rtP . u5_Bias , & rtP . u5_Freq , & rtP . u5_Phase , & rtP .
Current1_Value , & rtP . Gain_Gain , & rtP . Gain2_Gain , & rtP .
Integrator_IC , & rtP . Integrator1_IC , & rtP . Ruddersaturation_UpperSat ,
& rtP . Ruddersaturation_LowerSat , & rtP . Output_Gain , & rtP .
WhiteNoise_Mean , & rtP . WhiteNoise_StdDev , & rtP . WhiteNoise_Seed , & rtP
. Gain_Gain_irtfyphm0k , & rtP . Gain_Gain_jnev5go0pe , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 0.5 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , 2 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 9 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 17 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2339146317U , 2592342176U , 3675079008U , 3435404582U } , ( NULL ) , 0 ,
0 } ; const rtwCAPI_ModelMappingStaticInfo * model1b_GetCAPIStaticMap ( ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void model1b_InitializeDataMapInfo ( SimStruct * const rtS ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void model1b_host_InitializeDataMapInfo ( model1b_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
