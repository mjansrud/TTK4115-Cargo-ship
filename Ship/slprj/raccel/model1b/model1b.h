#include "__cf_model1b.h"
#ifndef RTW_HEADER_model1b_h_
#define RTW_HEADER_model1b_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef model1b_COMMON_INCLUDES_
#define model1b_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sl_fileio_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "model1b_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME model1b
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (10) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (5)   
#elif NCSTATES != 5
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T k3nrgrep1e ; real_T o24qnkulls ; real_T g42ykh0anh ;
real_T e5extboo4y ; real_T o233pri3cc ; real_T aot4m1g5ea ; real_T euzoh3akgm
; real_T iyqko5xknu ; real_T guz1minmuw ; real_T ca2j2iwn0p [ 2 ] ; } B ;
typedef struct { real_T g1tasezcw2 ; struct { void * PrevTimePtr ; }
jfnixd53tp ; struct { void * LoggedData ; } pg5f2xpwn4 ; uint32_T k0ll4r5zkz
; int_T h43efgxtdy ; } DW ; typedef struct { real_T nep1oahmuq [ 3 ] ; real_T
lrn14sssek ; real_T b3dr1olxrq ; } X ; typedef struct { real_T nep1oahmuq [ 3
] ; real_T lrn14sssek ; real_T b3dr1olxrq ; } XDot ; typedef struct {
boolean_T nep1oahmuq [ 3 ] ; boolean_T lrn14sssek ; boolean_T b3dr1olxrq ; }
XDis ; typedef struct { real_T nep1oahmuq [ 3 ] ; real_T lrn14sssek ; real_T
b3dr1olxrq ; } CStateAbsTol ; typedef struct { real_T foeezhwlja ; real_T
ebwu5b2nnw ; } ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T WhiteNoise_Mean ; real_T WhiteNoise_StdDev ;
real_T WhiteNoise_Seed ; real_T Output_Gain ; real_T Gain2_Gain ; real_T
Gain_Gain ; real_T u5_Amp ; real_T u5_Bias ; real_T u5_Freq ; real_T u5_Phase
; real_T Gain_Gain_irtfyphm0k ; real_T Ruddersaturation_UpperSat ; real_T
Ruddersaturation_LowerSat ; real_T Current1_Value ; real_T
Gain_Gain_jnev5go0pe ; real_T Integrator_IC ; real_T Integrator1_IC ; } ;
extern P rtP ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB
; extern X rtX ; extern DW rtDW ; extern const rtwCAPI_ModelMappingStaticInfo
* model1b_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern
const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const
int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern
const char * gblInportFileName ; extern const int_T gblNumRootInportBlks ;
extern const int_T gblNumModelInputs ; extern const int_T
gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ; extern
const int_T gblInportComplex [ ] ; extern const int_T gblInportInterpoFlag [
] ; extern const int_T gblInportContinuous [ ] ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
