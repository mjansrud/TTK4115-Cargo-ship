#include "__cf_model1b.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . k3nrgrep1e
) , 0 , 0 , 11 } , { ( char_T * ) ( & rtDW . g1tasezcw2 ) , 0 , 0 , 1 } , { (
char_T * ) ( & rtDW . jfnixd53tp . PrevTimePtr ) , 11 , 0 , 2 } , { ( char_T
* ) ( & rtDW . k0ll4r5zkz ) , 7 , 0 , 1 } , { ( char_T * ) ( & rtDW .
h43efgxtdy ) , 10 , 0 , 1 } } ; static DataTypeTransitionTable rtBTransTable
= { 5U , rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = {
{ ( char_T * ) ( & rtP . WhiteNoise_Mean ) , 0 , 0 , 17 } } ; static
DataTypeTransitionTable rtPTransTable = { 1U , rtPTransitions } ;
