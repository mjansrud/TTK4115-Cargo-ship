#include "__cf_model1b.h"
#include "rt_logging_mmi.h"
#include "model1b_capi.h"
#include <math.h>
#include "model1b.h"
#include "model1b_private.h"
#include "model1b_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 1 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "8.8 (R2015a) 09-Feb-2015" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\model1b\\model1b_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; FrFInfo model1b_gblFrFInfo [ 1 ] ;
#include "simstruc.h"
#include "fixedpoint.h"
void MdlOutputsParameterSampleTime ( int_T tid ) { UNUSED_PARAMETER ( tid ) ;
} B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS
= & model_S ; real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T
lo ; uint32_T hi ; lo = * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ;
if ( lo < hi ) { * u = 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; }
return ( real_T ) * u * 4.6566128752457969E-10 ; } real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { real_T y ; real_T sr ; real_T
si ; do { sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } void MdlInitialize ( void ) { uint32_T tseed ; int32_T r
; int32_T t ; real_T tmp ; tmp = muDoubleScalarFloor ( rtP . WhiteNoise_Seed
) ; if ( muDoubleScalarIsNaN ( tmp ) || muDoubleScalarIsInf ( tmp ) ) { tmp =
0.0 ; } else { tmp = muDoubleScalarRem ( tmp , 4.294967296E+9 ) ; } tseed =
tmp < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp : ( uint32_T ) tmp
; r = ( int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ;
tseed = ( ( ( ( tseed - ( ( uint32_T ) r << 16U ) ) + t ) << 16U ) + t ) + r
; if ( tseed < 1U ) { tseed = 1144108930U ; } else { if ( tseed > 2147483646U
) { tseed = 2147483646U ; } } rtDW . k0ll4r5zkz = tseed ; rtDW . g1tasezcw2 =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . k0ll4r5zkz ) * rtP . WhiteNoise_StdDev
+ rtP . WhiteNoise_Mean ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
sfcnInitializeConditions ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL )
) return ; } rtX . lrn14sssek = rtP . Integrator_IC ; rtX . b3dr1olxrq = rtP
. Integrator1_IC ; } void MdlStart ( void ) { { char fileName [ 509 ] =
"data_wave.mat" ; const char * blockpath =
"model1b/Cargo ship/Wave disturbance" ; if ( slIsRapidAcceleratorSimulating (
) ) { rt_RAccelReplaceFromFilename ( blockpath , fileName ) ; } { void * fp =
( NULL ) ; const char * errMsg = ( NULL ) ; errMsg =
rtwMatFileLoaderCollectionCreateInstance ( 1 , & fp ) ; if ( errMsg != ( NULL
) ) { ssSetErrorStatus ( rtS , errMsg ) ; return ; } rtDW . jfnixd53tp .
PrevTimePtr = fp ; { unsigned char groundValue [ ] = { 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U } ; const int enumNStrings = 0 ; const char * * enumStrings =
( NULL ) ; const int32_T * enumValues = ( NULL ) ; int_T dimensions [ 1 ] = {
1 } ; errMsg = rtwMatFileLoaderCollectionAddElement ( 1 , fp , fileName , ""
, 0 , 0 , 0 , 0 , groundValue , "double" , 0 , 1 , dimensions , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , enumNStrings , enumStrings , enumValues , 1 ,
"model1b/Cargo ship/Wave disturbance" ) ; if ( errMsg != ( NULL ) ) {
ssSetErrorStatus ( rtS , errMsg ) ; return ; } } } } MdlInitialize ( ) ; }
void MdlOutputs ( int_T tid ) { real_T lbm5rybpqj ; real_T iveqbqr0lf ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . k3nrgrep1e = rtP . Output_Gain * rtDW
. g1tasezcw2 * rtP . Gain2_Gain ; } { void * fp = ( void * ) rtDW .
jfnixd53tp . PrevTimePtr ; const char * errMsg = ( NULL ) ; if ( fp != ( NULL
) && ( ssIsMajorTimeStep ( rtS ) || ! 0 ) ) { real_T t = ssGetTaskTime ( rtS
, 0 ) ; { void * y = & lbm5rybpqj ; errMsg =
rtwMatFileLoaderCollectionGetOutput ( 1 , fp , 0 , t , ssIsMajorTimeStep (
rtS ) , & y ) ; if ( errMsg != ( NULL ) ) { ssSetErrorStatus ( rtS , errMsg )
; return ; } } } } iveqbqr0lf = rtP . Gain_Gain * lbm5rybpqj ; lbm5rybpqj =
muDoubleScalarSin ( rtP . u5_Freq * ssGetTaskTime ( rtS , 0 ) + rtP .
u5_Phase ) * rtP . u5_Amp + rtP . u5_Bias ; rtB . o24qnkulls = rtP .
Gain_Gain_irtfyphm0k * lbm5rybpqj ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
h43efgxtdy = rtB . o24qnkulls >= rtP . Ruddersaturation_UpperSat ? 1 : rtB .
o24qnkulls > rtP . Ruddersaturation_LowerSat ? 0 : - 1 ; } rtB . g42ykh0anh =
rtDW . h43efgxtdy == 1 ? rtP . Ruddersaturation_UpperSat : rtDW . h43efgxtdy
== - 1 ? rtP . Ruddersaturation_LowerSat : rtB . o24qnkulls ; { SimStruct *
rts = ssGetSFunction ( rtS , 0 ) ; sfcnOutputs ( rts , 0 ) ; } lbm5rybpqj =
rtP . Gain_Gain_jnev5go0pe * rtB . e5extboo4y + iveqbqr0lf ; rtB . o233pri3cc
= rtB . k3nrgrep1e + lbm5rybpqj ; rtB . aot4m1g5ea = rtX . lrn14sssek ; rtB .
euzoh3akgm = rtX . b3dr1olxrq ; rtB . iyqko5xknu = muDoubleScalarSin (
lbm5rybpqj * 0.017453292519943295 ) * 8.0 ; rtB . guz1minmuw =
muDoubleScalarCos ( lbm5rybpqj * 0.017453292519943295 ) * 8.0 ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW . g1tasezcw2 =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . k0ll4r5zkz ) * rtP . WhiteNoise_StdDev
+ rtP . WhiteNoise_Mean ; } UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives
( void ) { { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; real_T *
sfcndX_fx = ( real_T * ) & ( ( XDot * ) ssGetdX ( rtS ) ) -> nep1oahmuq [ 0 ]
; ssSetdX ( rts , sfcndX_fx ) ; sfcnDerivatives ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { ( ( XDot * ) ssGetdX (
rtS ) ) -> lrn14sssek = rtB . iyqko5xknu ; } { ( ( XDot * ) ssGetdX ( rtS ) )
-> b3dr1olxrq = rtB . guz1minmuw ; } } void MdlProjection ( void ) { } void
MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> foeezhwlja = rtB .
o24qnkulls - rtP . Ruddersaturation_UpperSat ; _rtZCSV -> ebwu5b2nnw = rtB .
o24qnkulls - rtP . Ruddersaturation_LowerSat ; } void MdlTerminate ( void ) {
{ const char * errMsg = ( NULL ) ; void * fp = ( void * ) rtDW . jfnixd53tp .
PrevTimePtr ; if ( fp != ( NULL ) ) { errMsg =
rtwMatFileLoaderCollectionDestroyInstance ( 1 , fp ) ; if ( errMsg != ( NULL
) ) { ssSetErrorStatus ( rtS , errMsg ) ; return ; } } } { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnTerminate ( rts ) ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 5 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
3 ) ; ssSetNumBlocks ( rtS , 23 ) ; ssSetNumBlockIO ( rtS , 10 ) ;
ssSetNumBlockParams ( rtS , 17 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , 0.5 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ; }
void raccel_set_checksum ( SimStruct * rtS ) { ssSetChecksumVal ( rtS , 0 ,
2339146317U ) ; ssSetChecksumVal ( rtS , 1 , 2592342176U ) ; ssSetChecksumVal
( rtS , 2 , 3675079008U ) ; ssSetChecksumVal ( rtS , 3 , 3435404582U ) ; }
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { real_T * x = (
real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * )
x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . B = &
rtBTransTable ; dtInfo . P = & rtPTransTable ; }
model1b_InitializeDataMapInfo ( rtS ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "model1b" ) ; ssSetPath (
rtS , "model1b" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 2500.0 )
; { static RTWLogInfo rt_DataLoggingInfo ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 3 , 1
, 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 } ; static
int_T rt_LoggedStateDimensions [ ] = { 3 , 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ;
static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 } ; static const
char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" } ;
static const char_T * rt_LoggedStateBlockNames [ ] = {
"model1b/Cargo ship/Cargo ship" , "model1b/Cargo ship/Integrator" ,
"model1b/Cargo ship/Integrator1" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 3 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 3 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . nep1oahmuq [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . lrn14sssek ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . b3dr1olxrq ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 1000 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 5 ] ; static
real_T absTol [ 5 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static
uint8_T absTolControl [ 5 ] = { 0U , 0U , 0U , 0U , 0U } ; static uint8_T
zcAttributes [ 2 ] = { ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ;
ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.5 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"ode45" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 2 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 2 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 2339146317U ) ; ssSetChecksumVal ( rtS , 1 ,
2592342176U ) ; ssSetChecksumVal ( rtS , 2 , 3675079008U ) ; ssSetChecksumVal
( rtS , 3 , 3435404582U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 2 ] ; ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo
) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } ssSetNumSFunctions ( rtS , 1 ) ; { static SimStruct
childSFunctions [ 1 ] ; static SimStruct * childSFunctionPtrs [ 1 ] ; ( void
) memset ( ( void * ) & childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions
) ) ; ssSetSFunctions ( rtS , & childSFunctionPtrs [ 0 ] ) ; ssSetSFunction (
rtS , 0 , & childSFunctions [ 0 ] ) ; { SimStruct * rts = ssGetSFunction (
rtS , 0 ) ; static time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ;
static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 ,
sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 ,
sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; {
static struct _ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , &
methods2 ) ; } { static struct _ssSFcnModelMethods3 methods3 ;
ssSetModelMethods3 ( rts , & methods3 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ; ssSetAbsTolVector (
rts , ssGetAbsTolVector ( rtS ) + 0 ) ; ssSetAbsTolControlVector ( rts ,
ssGetAbsTolControlVector ( rtS ) + 0 ) ; } { static struct _ssPortInputs
inputPortInfo [ 2 ] ; _ssSetNumInputPorts ( rts , 2 ) ;
ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; {
ssSetInputPortRequiredContiguous ( rts , 0 , 1 ) ; ssSetInputPortSignal ( rts
, 0 , & rtB . g42ykh0anh ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidth ( rts , 0 , 1 ) ; } { ssSetInputPortRequiredContiguous (
rts , 1 , 1 ) ; ssSetInputPortSignal ( rts , 1 , & rtP . Current1_Value ) ;
_ssSetInputPortNumDimensions ( rts , 1 , 1 ) ; ssSetInputPortWidth ( rts , 1
, 1 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 1 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 1 ) ; { _ssSetOutputPortNumDimensions ( rts , 0
, 1 ) ; ssSetOutputPortWidth ( rts , 0 , 1 ) ; ssSetOutputPortSignal ( rts ,
0 , ( ( real_T * ) & rtB . e5extboo4y ) ) ; } } ssSetContStates ( rts , & rtX
. nep1oahmuq [ 0 ] ) ; ssSetContStateDisabled ( rts , & ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> nep1oahmuq [ 0 ] ) ; ssSetModelName ( rts
, "Cargo ship" ) ; ssSetPath ( rts , "model1b/Cargo ship/Cargo ship" ) ; if (
ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; Cargoship ( rts
) ; sfcnInitializeSizes ( rts ) ; sfcnInitializeSampleTimes ( rts ) ;
ssSetSampleTime ( rts , 0 , 0.0 ) ; ssSetOffsetTime ( rts , 0 , 0.0 ) ;
sfcnTsMap [ 0 ] = 0 ; ssSetNumNonsampledZCs ( rts , 0 ) ;
_ssSetInputPortConnected ( rts , 0 , 1 ) ; _ssSetInputPortConnected ( rts , 1
, 1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ;
_ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort (
rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } } return
rtS ; }
