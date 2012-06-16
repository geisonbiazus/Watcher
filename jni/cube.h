/*==============================================================================
            Copyright (c) 2012 QUALCOMM Austria Research Center GmbH.
            All Rights Reserved.
            Qualcomm Confidential and Proprietary
            
@file 
    Teapot.h

@brief
    Geometry for the teapot used in the samples.

==============================================================================*/

#ifndef _QCAR_CUBE_OBJECT_H_
#define _QCAR_CUBE_OBJECT_H_


#define NUM_CUBE_OBJECT_VERTEX 482//8
#define NUM_CUBE_OBJECT_INDEX 1984//36

float width = 20.0;
float height = 20.0;
float depth = 20.0;


static const float cubeVertices[NUM_CUBE_OBJECT_VERTEX * 3] =
{

	    -5.0, -5.0,  0,
  		 5.0, -5.0,  0,
		 5.0,  5.0,  0,
		-5.0,  5.0,  0,
		-5.0, -5.0, 10,
		 5.0, -5.0, 10,
		 5.0,  5.0, 10,
		-5.0,  5.0, 10

//		 -0.010950, 16.800806, 0.004966,
//		 3.010655, -14.479146, -0.596069,
//		 5.916148, -13.580508, -1.174007,
//		 8.593864, -12.121199, -1.706638,
//		 10.940903, -10.157299, -2.173493,
//		 12.867066, -7.764278, -2.556631,
//		 14.298335, -5.034102, -2.841328,
//		 15.179706, -2.071690, -3.016644,
//		 15.477308, 1.009115, -3.075840,
//		 15.179705, 4.089921, -3.016644,
//		 14.298335, 7.052332, -2.841328,
//		 12.867065, 9.782507, -2.556631,
//		 10.940904, 12.175527, -2.173493,
//		 8.593865, 14.139426, -1.706638,
//		 5.916150, 15.598736, -1.174008,
//		 3.010659, 16.497372, -0.596070,
//		 2.835343, 16.497372, -1.174008,
//		 5.572257, 15.598736, -2.307674,
//		 8.094608, 14.139426, -3.352467,
//		 10.305470, 12.175527, -4.268235,
//		 12.119874, 9.782507, -5.019787,
//		 13.468102, 7.052332, -5.578240,
//		 14.298334, 4.089921, -5.922134,
//		 14.578670, 1.009115, -6.038253,
//		 14.298334, -2.071690, -5.922134,
//		 13.468102, -5.034102, -5.578240,
//		 12.119875, -7.764278, -5.019787,
//		 10.305470, -10.157299, -4.268235,
//		 8.094608, -12.121199, -3.352466,
//		 5.572254, -13.580508, -2.307673,
//		 2.835340, -14.479146, -1.174006,
//		 -0.010955, -14.782578, 0.004968,
//		 2.550643, -14.479146, -1.706636,
//		 5.013801, -13.580508, -3.352465,
//		 7.283859, -12.121199, -4.869270,
//		 9.273582, -10.157299, -6.198761,
//		 10.906504, -7.764278, -7.289845,
//		 12.119876, -5.034102, -8.100594,
//		 12.867065, -2.071690, -8.599850,
//		 13.119360, 1.009115, -8.768428,
//		 12.867065, 4.089921, -8.599850,
//		 12.119876, 7.052332, -8.100594,
//		 10.906503, 9.782507, -7.289844,
//		 9.273583, 12.175527, -6.198761,
//		 7.283859, 14.139426, -4.869270,
//		 5.013803, 15.598736, -3.352467,
//		 2.550646, 16.497372, -1.706638,
//		 2.167508, 16.497372, -2.173493,
//		 4.262250, 15.598736, -4.268235,
//		 6.192775, 14.139426, -6.198760,
//		 7.884896, 12.175527, -7.890880,
//		 9.273581, 9.782507, -9.279566,
//		 10.305470, 7.052332, -10.311454,
//		 10.940902, 4.089921, -10.946887,
//		 11.155459, 1.009115, -11.161447,
//		 10.940902, -2.071690, -10.946887,
//		 10.305470, -5.034102, -10.311454,
//		 9.273582, -7.764278, -9.279567,
//		 7.884896, -10.157299, -7.890880,
//		 6.192775, -12.121199, -6.198760,
//		 4.262249, -13.580508, -4.268233,
//		 2.167506, -14.479146, -2.173490,
//		 1.700651, -14.479146, -2.556628,
//		 3.346481, -13.580508, -5.019785,
//		 4.863285, -12.121199, -7.289844,
//		 6.192776, -10.157299, -9.279567,
//		 7.283859, -7.764278, -10.912489,
//		 8.094608, -5.034102, -12.125860,
//		 8.593863, -2.071690, -12.873050,
//		 8.762441, 1.009115, -13.125345,
//		 8.593863, 4.089921, -12.873050,
//		 8.094608, 7.052332, -12.125860,
//		 7.283858, 9.782507, -10.912488,
//		 6.192776, 12.175527, -9.279567,
//		 4.863285, 14.139426, -7.289844,
//		 3.346482, 15.598736, -5.019787,
//		 1.700654, 16.497372, -2.556631,
//		 1.168023, 16.497372, -2.841327,
//		 2.301689, 15.598736, -5.578240,
//		 3.346481, 14.139426, -8.100593,
//		 4.262251, 12.175527, -10.311454,
//		 5.013801, 9.782507, -12.125858,
//		 5.572255, 7.052332, -13.474086,
//		 5.916148, 4.089921, -14.304317,
//		 6.032265, 1.009115, -14.584653,
//		 5.916148, -2.071690, -14.304317,
//		 5.572255, -5.034102, -13.474086,
//		 5.013802, -7.764278, -12.125859,
//		 4.262251, -10.157299, -10.311454,
//		 3.346481, -12.121199, -8.100592,
//		 2.301688, -13.580508, -5.578238,
//		 1.168021, -14.479146, -2.841324,
//		 0.590084, -14.479146, -3.016639,
//		 1.168023, -13.580508, -5.922132,
//		 1.700653, -12.121199, -8.599848,
//		 2.167509, -10.157299, -10.946887,
//		 2.550645, -7.764278, -12.873050,
//		 2.835342, -5.034102, -14.304318,
//		 3.010657, -2.071690, -15.185688,
//		 3.069853, 1.009115, -15.483290,
//		 3.010657, 4.089921, -15.185688,
//		 2.835342, 7.052332, -14.304318,
//		 2.550645, 9.782507, -12.873048,
//		 2.167509, 12.175527, -10.946887,
//		 1.700653, 14.139426, -8.599849,
//		 1.168023, 15.598736, -5.922133,
//		 0.590085, 16.497372, -3.016643,
//		 -0.010950, 16.497372, -3.075840,
//		 -0.010951, 15.598736, -6.038252,
//		 -0.010951, 14.139426, -8.768426,
//		 -0.010950, 12.175527, -11.161446,
//		 -0.010952, 9.782507, -13.125343,
//		 -0.010951, 7.052332, -14.584654,
//		 -0.010952, 4.089921, -15.483291,
//		 -0.010953, 1.009115, -15.786721,
//		 -0.010952, -2.071690, -15.483291,
//		 -0.010951, -5.034102, -14.584654,
//		 -0.010952, -7.764278, -13.125344,
//		 -0.010950, -10.157299, -11.161446,
//		 -0.010951, -12.121199, -8.768425,
//		 -0.010950, -13.580508, -6.038250,
//		 -0.010950, -14.479146, -3.075836,
//		 -0.611985, -14.479146, -3.016639,
//		 -1.189923, -13.580508, -5.922132,
//		 -1.722554, -12.121199, -8.599847,
//		 -2.189409, -10.157299, -10.946886,
//		 -2.572548, -7.764278, -12.873048,
//		 -2.857245, -5.034102, -14.304317,
//		 -3.032561, -2.071690, -15.185687,
//		 -3.091758, 1.009115, -15.483287,
//		 -3.032561, 4.089921, -15.185687,
//		 -2.857245, 7.052332, -14.304317,
//		 -2.572548, 9.782507, -12.873047,
//		 -2.189409, 12.175527, -10.946886,
//		 -1.722555, 14.139426, -8.599848,
//		 -1.189924, 15.598736, -5.922133,
//		 -0.611986, 16.497372, -3.016643,
//		 -1.189924, 16.497372, -2.841327,
//		 -2.323590, 15.598736, -5.578240,
//		 -3.368383, 14.139426, -8.100591,
//		 -4.284150, 12.175527, -10.311453,
//		 -5.035703, 9.782507, -12.125856,
//		 -5.594157, 7.052332, -13.474084,
//		 -5.938050, 4.089921, -14.304316,
//		 -6.054169, 1.009115, -14.584648,
//		 -5.938050, -2.071690, -14.304316,
//		 -5.594157, -5.034102, -13.474084,
//		 -5.035704, -7.764278, -12.125857,
//		 -4.284150, -10.157299, -10.311453,
//		 -3.368382, -12.121199, -8.100591,
//		 -2.323589, -13.580508, -5.578238,
//		 -1.189922, -14.479146, -2.841324,
//		 -1.722552, -14.479146, -2.556627,
//		 -3.368381, -13.580508, -5.019784,
//		 -4.885185, -12.121199, -7.289842,
//		 -6.214675, -10.157299, -9.279566,
//		 -7.305760, -7.764278, -10.912486,
//		 -8.116508, -5.034102, -12.125857,
//		 -8.615765, -2.071690, -12.873047,
//		 -8.784343, 1.009115, -13.125339,
//		 -8.615765, 4.089921, -12.873047,
//		 -8.116508, 7.052332, -12.125857,
//		 -7.305759, 9.782507, -10.912485,
//		 -6.214675, 12.175527, -9.279566,
//		 -4.885186, 14.139426, -7.289842,
//		 -3.368383, 15.598736, -5.019786,
//		 -1.722554, 16.497372, -2.556630,
//		 -2.189408, 16.497372, -2.173492,
//		 -4.284151, 15.598736, -4.268234,
//		 -6.214675, 14.139426, -6.198757,
//		 -7.906795, 12.175527, -7.890879,
//		 -9.295481, 9.782507, -9.279563,
//		 -10.327369, 7.052332, -10.311452,
//		 -10.962802, 4.089921, -10.946884,
//		 -11.177361, 1.009115, -11.161438,
//		 -10.962802, -2.071690, -10.946884,
//		 -10.327369, -5.034102, -10.311452,
//		 -9.295482, -7.764278, -9.279564,
//		 -7.906795, -10.157299, -7.890879,
//		 -6.214674, -12.121199, -6.198758,
//		 -4.284149, -13.580508, -4.268233,
//		 -2.189406, -14.479146, -2.173490,
//		 -2.572544, -14.479146, -1.706636,
//		 -5.035700, -13.580508, -3.352465,
//		 -7.305758, -12.121199, -4.869268,
//		 -9.295482, -10.157299, -6.198760,
//		 -10.928403, -7.764278, -7.289842,
//		 -12.141774, -5.034102, -8.100592,
//		 -12.888964, -2.071690, -8.599846,
//		 -13.141258, 1.009115, -8.768420,
//		 -12.888964, 4.089921, -8.599846,
//		 -12.141774, 7.052332, -8.100592,
//		 -10.928402, 9.782507, -7.289841,
//		 -9.295482, 12.175527, -6.198760,
//		 -7.305759, 14.139426, -4.869267,
//		 -5.035703, 15.598736, -3.352465,
//		 -2.572546, 16.497372, -1.706637,
//		 -2.857243, 16.497372, -1.174007,
//		 -5.594155, 15.598736, -2.307673,
//		 -8.116507, 14.139426, -3.352464,
//		 -10.327369, 12.175527, -4.268234,
//		 -12.141772, 9.782507, -5.019784,
//		 -13.490000, 7.052332, -5.578239,
//		 -14.320231, 4.089921, -5.922131,
//		 -14.600565, 1.009115, -6.038245,
//		 -14.320231, -2.071690, -5.922131,
//		 -13.490000, -5.034102, -5.578239,
//		 -12.141773, -7.764278, -5.019784,
//		 -10.327369, -10.157299, -4.268234,
//		 -8.116507, -12.121199, -3.352465,
//		 -5.594153, -13.580508, -2.307673,
//		 -2.857240, -14.479146, -1.174006,
//		 -3.032555, -14.479146, -0.596068,
//		 -5.938047, -13.580508, -1.174007,
//		 -8.615763, -12.121199, -1.706637,
//		 -10.962802, -10.157299, -2.173493,
//		 -12.888963, -7.764278, -2.556629,
//		 -14.320232, -5.034102, -2.841327,
//		 -15.201601, -2.071690, -3.016640,
//		 -15.499201, 1.009115, -3.075834,
//		 -15.201601, 4.089921, -3.016640,
//		 -14.320232, 7.052332, -2.841327,
//		 -12.888962, 9.782507, -2.556628,
//		 -10.962802, 12.175527, -2.173493,
//		 -8.615762, 14.139426, -1.706636,
//		 -5.938049, 15.598736, -1.174006,
//		 -3.032558, 16.497372, -0.596069,
//		 -3.091754, 16.497372, 0.004966,
//		 -6.054167, 15.598736, 0.004967,
//		 -8.784340, 14.139426, 0.004967,
//		 -11.177361, 12.175527, 0.004966,
//		 -13.141257, 9.782507, 0.004968,
//		 -14.600568, 7.052332, 0.004967,
//		 -15.499204, 4.089921, 0.004968,
//		 -15.802631, 1.009115, 0.004971,
//		 -15.499204, -2.071690, 0.004968,
//		 -14.600568, -5.034102, 0.004967,
//		 -13.141258, -7.764278, 0.004968,
//		 -11.177361, -10.157299, 0.004966,
//		 -8.784341, -12.121199, 0.004967,
//		 -6.054165, -13.580508, 0.004966,
//		 -3.091752, -14.479146, 0.004966,
//		 -3.032555, -14.479146, 0.606001,
//		 -5.938047, -13.580508, 1.183939,
//		 -8.615762, -12.121199, 1.716570,
//		 -10.962801, -10.157299, 2.183424,
//		 -12.888962, -7.764278, 2.566563,
//		 -14.320231, -5.034102, 2.851260,
//		 -15.201600, -2.071690, 3.026576,
//		 -15.499197, 1.009115, 3.085775,
//		 -15.201600, 4.089921, 3.026576,
//		 -14.320231, 7.052332, 2.851260,
//		 -12.888961, 9.782507, 2.566563,
//		 -10.962801, 12.175527, 2.183424,
//		 -8.615761, 14.139426, 1.716571,
//		 -5.938049, 15.598736, 1.183940,
//		 -3.032557, 16.497372, 0.606001,
//		 -2.857242, 16.497372, 1.183939,
//		 -5.594155, 15.598736, 2.317605,
//		 -8.116504, 14.139426, 3.362398,
//		 -10.327368, 12.175527, 4.278166,
//		 -12.141770, 9.782507, 5.029718,
//		 -13.489999, 7.052332, 5.588171,
//		 -14.320229, 4.089921, 5.932065,
//		 -14.600558, 1.009115, 6.048185,
//		 -14.320229, -2.071690, 5.932065,
//		 -13.489999, -5.034102, 5.588171,
//		 -12.141771, -7.764278, 5.029718,
//		 -10.327368, -10.157299, 4.278166,
//		 -8.116505, -12.121199, 3.362397,
//		 -5.594153, -13.580508, 2.317604,
//		 -2.857240, -14.479146, 1.183938,
//		 -2.572543, -14.479146, 1.716568,
//		 -5.035700, -13.580508, 3.362396,
//		 -7.305756, -12.121199, 4.879200,
//		 -9.295481, -10.157299, 6.208691,
//		 -10.928400, -7.764278, 7.299775,
//		 -12.141772, -5.034102, 8.110524,
//		 -12.888960, -2.071690, 8.609780,
//		 -13.141249, 1.009115, 8.778358,
//		 -12.888960, 4.089921, 8.609780,
//		 -12.141772, 7.052332, 8.110524,
//		 -10.928399, 9.782507, 7.299774,
//		 -9.295481, 12.175527, 6.208691,
//		 -7.305755, 14.139426, 4.879200,
//		 -5.035701, 15.598736, 3.362398,
//		 -2.572545, 16.497372, 1.716569,
//		 -2.189407, 16.497372, 2.183423,
//		 -4.284149, 15.598736, 4.278166,
//		 -6.214671, 14.139426, 6.208689,
//		 -7.906794, 12.175527, 7.900810,
//		 -9.295477, 9.782507, 9.289495,
//		 -10.327367, 7.052332, 10.321384,
//		 -10.962797, 4.089921, 10.956817,
//		 -11.177349, 1.009115, 11.171373,
//		 -10.962797, -2.071690, 10.956817,
//		 -10.327367, -5.034102, 10.321384,
//		 -9.295478, -7.764278, 9.289495,
//		 -7.906794, -10.157299, 7.900810,
//		 -6.214672, -12.121199, 6.208690,
//		 -4.284148, -13.580508, 4.278164,
//		 -2.189406, -14.479146, 2.183422,
//		 -1.722552, -14.479146, 2.566559,
//		 -3.368381, -13.580508, 5.029716,
//		 -4.885183, -12.121199, 7.299773,
//		 -6.214674, -10.157299, 9.289496,
//		 -7.305756, -7.764278, 10.922417,
//		 -8.116507, -5.034102, 12.135790,
//		 -8.615759, -2.071690, 12.882978,
//		 -8.784331, 1.009115, 13.135270,
//		 -8.615759, 4.089921, 12.882978,
//		 -8.116507, 7.052332, 12.135790,
//		 -7.305755, 9.782507, 10.922417,
//		 -6.214674, 12.175527, 9.289496,
//		 -4.885181, 14.139426, 7.299772,
//		 -3.368381, 15.598736, 5.029717,
//		 -1.722553, 16.497372, 2.566561,
//		 -1.189923, 16.497372, 2.851257,
//		 -2.323589, 15.598736, 5.588170,
//		 -3.368378, 14.139426, 8.110519,
//		 -4.284150, 12.175527, 10.321383,
//		 -5.035698, 9.782507, 12.135786,
//		 -5.594154, 7.052332, 13.484015,
//		 -5.938044, 4.089921, 14.314246,
//		 -6.054157, 1.009115, 14.594576,
//		 -5.938044, -2.071690, 14.314246,
//		 -5.594154, -5.034102, 13.484015,
//		 -5.035699, -7.764278, 12.135786,
//		 -4.284150, -10.157299, 10.321383,
//		 -3.368380, -12.121199, 8.110521,
//		 -2.323588, -13.580508, 5.588169,
//		 -1.189922, -14.479146, 2.851255,
//		 -0.611984, -14.479146, 3.026571,
//		 -1.189923, -13.580508, 5.932062,
//		 -1.722552, -12.121199, 8.609776,
//		 -2.189408, -10.157299, 10.956817,
//		 -2.572544, -7.764278, 12.882976,
//		 -2.857242, -5.034102, 14.314247,
//		 -3.032555, -2.071690, 15.195616,
//		 -3.091747, 1.009115, 15.493211,
//		 -3.032555, 4.089921, 15.195616,
//		 -2.857242, 7.052332, 14.314247,
//		 -2.572543, 9.782507, 12.882976,
//		 -2.189408, 12.175527, 10.956817,
//		 -1.722551, 14.139426, 8.609775,
//		 -1.189923, 15.598736, 5.932064,
//		 -0.611985, 16.497372, 3.026572,
//		 -0.010950, 16.497372, 3.085769,
//		 -0.010949, 15.598736, 6.048182,
//		 -0.010948, 14.139426, 8.778353,
//		 -0.010950, 12.175527, 11.171375,
//		 -0.010948, 9.782507, 13.135271,
//		 -0.010949, 7.052332, 14.594583,
//		 -0.010946, 4.089921, 15.493217,
//		 -0.010943, 1.009115, 15.796642,
//		 -0.010946, -2.071690, 15.493217,
//		 -0.010949, -5.034102, 14.594583,
//		 -0.010949, -7.764278, 13.135271,
//		 -0.010950, -10.157299, 11.171375,
//		 -0.010949, -12.121199, 8.778355,
//		 -0.010950, -13.580508, 6.048181,
//		 -0.010950, -14.479146, 3.085767,
//		 0.590085, -14.479146, 3.026570,
//		 1.168023, -13.580508, 5.932062,
//		 1.700654, -12.121199, 8.609776,
//		 2.167509, -10.157299, 10.956816,
//		 2.550647, -7.764278, 12.882975,
//		 2.835344, -5.034102, 14.314246,
//		 3.010662, -2.071690, 15.195614,
//		 3.069860, 1.009115, 15.493208,
//		 3.010662, 4.089921, 15.195614,
//		 2.835344, 7.052332, 14.314246,
//		 2.550648, 9.782507, 12.882974,
//		 2.167509, 12.175527, 10.956816,
//		 1.700655, 14.139426, 8.609774,
//		 1.168023, 15.598736, 5.932063,
//		 0.590085, 16.497372, 3.026572,
//		 1.168022, 16.497372, 2.851257,
//		 2.301689, 15.598736, 5.588169,
//		 3.346482, 14.139426, 8.110517,
//		 4.262250, 12.175527, 10.321383,
//		 5.013803, 9.782507, 12.135783,
//		 5.572256, 7.052332, 13.484013,
//		 5.916151, 4.089921, 14.314241,
//		 6.032269, 1.009115, 14.594569,
//		 5.916151, -2.071690, 14.314241,
//		 5.572256, -5.034102, 13.484013,
//		 5.013802, -7.764278, 12.135784,
//		 4.262250, -10.157299, 10.321383,
//		 3.346481, -12.121199, 8.110518,
//		 2.301688, -13.580508, 5.588168,
//		 1.168022, -14.479146, 2.851255,
//		 1.700652, -14.479146, 2.566558,
//		 3.346480, -13.580508, 5.029715,
//		 4.863284, -12.121199, 7.299770,
//		 6.192775, -10.157299, 9.289495,
//		 7.283857, -7.764278, 10.922414,
//		 8.094607, -5.034102, 12.135786,
//		 8.593864, -2.071690, 12.882973,
//		 8.762441, 1.009115, 13.135260,
//		 8.593864, 4.089921, 12.882973,
//		 8.094607, 7.052332, 12.135786,
//		 7.283858, 9.782507, 10.922412,
//		 6.192775, 12.175527, 9.289495,
//		 4.863284, 14.139426, 7.299767,
//		 3.346481, 15.598736, 5.029716,
//		 1.700653, 16.497372, 2.566560,
//		 2.167507, 16.497372, 2.183422,
//		 4.262249, 15.598736, 4.278164,
//		 6.192772, 14.139426, 6.208683,
//		 7.884894, 12.175527, 7.900809,
//		 9.273579, 9.782507, 9.289490,
//		 10.305467, 7.052332, 10.321381,
//		 10.940900, 4.089921, 10.956810,
//		 11.155456, 1.009115, 11.171361,
//		 10.940900, -2.071690, 10.956810,
//		 10.305467, -5.034102, 10.321381,
//		 9.273579, -7.764278, 9.289492,
//		 7.884894, -10.157299, 7.900809,
//		 6.192773, -12.121199, 6.208686,
//		 4.262248, -13.580508, 4.278163,
//		 2.167506, -14.479146, 2.183421,
//		 2.550643, -14.479146, 1.716567,
//		 5.013800, -13.580508, 3.362396,
//		 7.283856, -12.121199, 4.879197,
//		 9.273581, -10.157299, 6.208689,
//		 10.906500, -7.764278, 7.299770,
//		 12.119872, -5.034102, 8.110520,
//		 12.867061, -2.071690, 8.609773,
//		 13.119351, 1.009115, 8.778344,
//		 12.867061, 4.089921, 8.609773,
//		 12.119872, 7.052332, 8.110520,
//		 10.906499, 9.782507, 7.299768,
//		 9.273581, 12.175527, 6.208689,
//		 7.283855, 14.139426, 4.879195,
//		 5.013801, 15.598736, 3.362396,
//		 2.550644, 16.497372, 1.716568,
//		 2.835340, 16.497372, 1.183938,
//		 5.572254, 15.598736, 2.317604,
//		 8.094602, 14.139426, 3.362391,
//		 10.305468, 12.175527, 4.278164,
//		 12.119868, 9.782507, 5.029712,
//		 13.468098, 7.052332, 5.588168,
//		 14.298327, 4.089921, 5.932058,
//		 14.578656, 1.009115, 6.048171,
//		 14.298327, -2.071690, 5.932058,
//		 13.468098, -5.034102, 5.588168,
//		 12.119869, -7.764278, 5.029714,
//		 10.305468, -10.157299, 4.278164,
//		 8.094604, -12.121199, 3.362394,
//		 5.572253, -13.580508, 2.317603,
//		 2.835339, -14.479146, 1.183937,
//		 3.010654, -14.479146, 0.606000,
//		 5.916146, -13.580508, 1.183938,
//		 8.593859, -12.121199, 1.716567,
//		 10.940901, -10.157299, 2.183423,
//		 12.867059, -7.764278, 2.566559,
//		 14.298329, -5.034102, 2.851256,
//		 15.179698, -2.071690, 3.026569,
//		 15.477291, 1.009115, 3.085761,
//		 15.179698, 4.089921, 3.026569,
//		 14.298329, 7.052332, 2.851256,
//		 12.867057, 9.782507, 2.566557,
//		 10.940901, 12.175527, 2.183423,
//		 8.593856, 14.139426, 1.716565,
//		 5.916147, 15.598736, 1.183938,
//		 3.010656, 16.497372, 0.606000,
//		 3.069852, 16.497372, 0.004966,
//		 6.032265, 15.598736, 0.004965,
//		 8.762433, 14.139426, 0.004962,
//		 11.155459, 12.175527, 0.004964,
//		 13.119351, 9.782507, 0.004962,
//		 14.578665, 7.052332, 0.004963,
//		 15.477299, 4.089921, 0.004961,
//		 15.780723, 1.009115, 0.004958,
//		 15.477299, -2.071690, 0.004961,
//		 14.578665, -5.034102, 0.004963,
//		 13.119354, -7.764278, 0.004964,
//		 11.155459, -10.157299, 0.004964,
//		 8.762437, -12.121199, 0.004964,
//		 6.032264, -13.580508, 0.004965,
//		 3.069851, -14.479146, 0.004965



};

static const float cubeColors[NUM_CUBE_OBJECT_VERTEX * 4] = {
                               0.0,  1.0,  0.0,  1.0,
                               0.0,  1.0,  0.0,  1.0,
                               1.0,  0.5,  0.0,  1.0,
                               1.0,  0.5,  0.0,  1.0,
                               1.0,  0.0,  0.0,  1.0,
                               1.0,  0.0,  0.0,  1.0,
                               0.0,  0.0,  1.0,  1.0,
                               1.0,  0.0,  1.0,  1.0
                            };

static const unsigned short cubeIndices[NUM_CUBE_OBJECT_INDEX] =
{
		  0, 4, 5, 0, 5, 1,
		  1, 5, 6, 1, 6, 2,
		  2, 6, 7, 2, 7, 3,
		  3, 7, 4, 3, 4, 0,
		  4, 7, 6, 4, 6, 5,
		  3, 0, 1, 3, 1, 2

//		 482, 32, 2,
//		 481, 482, 2, 3,
//		 480, 481, 3, 4,
//		 479, 480, 4, 5,
//		 478, 479, 5, 6,
//		 477, 478, 6, 7,
//		 476, 477, 7, 8,
//		 475, 476, 8, 9,
//		 474, 475, 9, 10,
//		 473, 474, 10, 11,
//		 472, 473, 11, 12,
//		 471, 472, 12, 13,
//		 470, 471, 13, 14,
//		 469, 470, 14, 15,
//		 468, 469, 15, 16,
//		 1, 468, 16,
//		 1, 16, 17,
//		 16, 15, 18, 17,
//		 15, 14, 19, 18,
//		 14, 13, 20, 19,
//		 13, 12, 21, 20,
//		 12, 11, 22, 21,
//		 11, 10, 23, 22,
//		 10, 9, 24, 23,
//		 9, 8, 25, 24,
//		 8, 7, 26, 25,
//		 7, 6, 27, 26,
//		 6, 5, 28, 27,
//		 5, 4, 29, 28,
//		 4, 3, 30, 29,
//		 3, 2, 31, 30,
//		 2, 32, 31,
//		 31, 32, 33,
//		 30, 31, 33, 34,
//		 29, 30, 34, 35,
//		 28, 29, 35, 36,
//		 27, 28, 36, 37,
//		 26, 27, 37, 38,
//		 25, 26, 38, 39,
//		 24, 25, 39, 40,
//		 23, 24, 40, 41,
//		 22, 23, 41, 42,
//		 21, 22, 42, 43,
//		 20, 21, 43, 44,
//		 19, 20, 44, 45,
//		 18, 19, 45, 46,
//		 17, 18, 46, 47,
//		 1, 17, 47,
//		 1, 47, 48,
//		 47, 46, 49, 48,
//		 46, 45, 50, 49,
//		 45, 44, 51, 50,
//		 44, 43, 52, 51,
//		 43, 42, 53, 52,
//		 42, 41, 54, 53,
//		 41, 40, 55, 54,
//		 40, 39, 56, 55,
//		 39, 38, 57, 56,
//		 38, 37, 58, 57,
//		 37, 36, 59, 58,
//		 36, 35, 60, 59,
//		 35, 34, 61, 60,
//		 34, 33, 62, 61,
//		 33, 32, 62,
//		 62, 32, 63,
//		 61, 62, 63, 64,
//		 60, 61, 64, 65,
//		 59, 60, 65, 66,
//		 58, 59, 66, 67,
//		 57, 58, 67, 68,
//		 56, 57, 68, 69,
//		 55, 56, 69, 70,
//		 54, 55, 70, 71,
//		 53, 54, 71, 72,
//		 52, 53, 72, 73,
//		 51, 52, 73, 74,
//		 50, 51, 74, 75,
//		 49, 50, 75, 76,
//		 48, 49, 76, 77,
//		 1, 48, 77,
//		 1, 77, 78,
//		 77, 76, 79, 78,
//		 76, 75, 80, 79,
//		 75, 74, 81, 80,
//		 74, 73, 82, 81,
//		 73, 72, 83, 82,
//		 72, 71, 84, 83,
//		 71, 70, 85, 84,
//		 70, 69, 86, 85,
//		 69, 68, 87, 86,
//		 68, 67, 88, 87,
//		 67, 66, 89, 88,
//		 66, 65, 90, 89,
//		 65, 64, 91, 90,
//		 64, 63, 92, 91,
//		 63, 32, 92,
//		 92, 32, 93,
//		 91, 92, 93, 94,
//		 90, 91, 94, 95,
//		 89, 90, 95, 96,
//		 88, 89, 96, 97,
//		 87, 88, 97, 98,
//		 86, 87, 98, 99,
//		 85, 86, 99, 100,
//		 84, 85, 100, 101,
//		 83, 84, 101, 102,
//		 82, 83, 102, 103,
//		 81, 82, 103, 104,
//		 80, 81, 104, 105,
//		 79, 80, 105, 106,
//		 78, 79, 106, 107,
//		 1, 78, 107,
//		 1, 107, 108,
//		 107, 106, 109, 108,
//		 106, 105, 110, 109,
//		 105, 104, 111, 110,
//		 104, 103, 112, 111,
//		 103, 102, 113, 112,
//		 102, 101, 114, 113,
//		 101, 100, 115, 114,
//		 100, 99, 116, 115,
//		 99, 98, 117, 116,
//		 98, 97, 118, 117,
//		 97, 96, 119, 118,
//		 96, 95, 120, 119,
//		 95, 94, 121, 120,
//		 94, 93, 122, 121,
//		 93, 32, 122,
//		 122, 32, 123,
//		 121, 122, 123, 124,
//		 120, 121, 124, 125,
//		 119, 120, 125, 126,
//		 118, 119, 126, 127,
//		 117, 118, 127, 128,
//		 116, 117, 128, 129,
//		 115, 116, 129, 130,
//		 114, 115, 130, 131,
//		 113, 114, 131, 132,
//		 112, 113, 132, 133,
//		 111, 112, 133, 134,
//		 110, 111, 134, 135,
//		 109, 110, 135, 136,
//		 108, 109, 136, 137,
//		 1, 108, 137,
//		 1, 137, 138,
//		 137, 136, 139, 138,
//		 136, 135, 140, 139,
//		 135, 134, 141, 140,
//		 134, 133, 142, 141,
//		 133, 132, 143, 142,
//		 132, 131, 144, 143,
//		 131, 130, 145, 144,
//		 130, 129, 146, 145,
//		 129, 128, 147, 146,
//		 128, 127, 148, 147,
//		 127, 126, 149, 148,
//		 126, 125, 150, 149,
//		 125, 124, 151, 150,
//		 124, 123, 152, 151,
//		 123, 32, 152,
//		 152, 32, 153,
//		 151, 152, 153, 154,
//		 150, 151, 154, 155,
//		 149, 150, 155, 156,
//		 148, 149, 156, 157,
//		 147, 148, 157, 158,
//		 146, 147, 158, 159,
//		 145, 146, 159, 160,
//		 144, 145, 160, 161,
//		 143, 144, 161, 162,
//		 142, 143, 162, 163,
//		 141, 142, 163, 164,
//		 140, 141, 164, 165,
//		 139, 140, 165, 166,
//		 138, 139, 166, 167,
//		 1, 138, 167,
//		 1, 167, 168,
//		 167, 166, 169, 168,
//		 166, 165, 170, 169,
//		 165, 164, 171, 170,
//		 164, 163, 172, 171,
//		 163, 162, 173, 172,
//		 162, 161, 174, 173,
//		 161, 160, 175, 174,
//		 160, 159, 176, 175,
//		 159, 158, 177, 176,
//		 158, 157, 178, 177,
//		 157, 156, 179, 178,
//		 156, 155, 180, 179,
//		 155, 154, 181, 180,
//		 154, 153, 182, 181,
//		 153, 32, 182,
//		 182, 32, 183,
//		 181, 182, 183, 184,
//		 180, 181, 184, 185,
//		 179, 180, 185, 186,
//		 178, 179, 186, 187,
//		 177, 178, 187, 188,
//		 176, 177, 188, 189,
//		 175, 176, 189, 190,
//		 174, 175, 190, 191,
//		 173, 174, 191, 192,
//		 172, 173, 192, 193,
//		 171, 172, 193, 194,
//		 170, 171, 194, 195,
//		 169, 170, 195, 196,
//		 168, 169, 196, 197,
//		 1, 168, 197,
//		 1, 197, 198,
//		 197, 196, 199, 198,
//		 196, 195, 200, 199,
//		 195, 194, 201, 200,
//		 194, 193, 202, 201,
//		 193, 192, 203, 202,
//		 192, 191, 204, 203,
//		 191, 190, 205, 204,
//		 190, 189, 206, 205,
//		 189, 188, 207, 206,
//		 188, 187, 208, 207,
//		 187, 186, 209, 208,
//		 186, 185, 210, 209,
//		 185, 184, 211, 210,
//		 184, 183, 212, 211,
//		 183, 32, 212,
//		 212, 32, 213,
//		 211, 212, 213, 214,
//		 210, 211, 214, 215,
//		 209, 210, 215, 216,
//		 208, 209, 216, 217,
//		 207, 208, 217, 218,
//		 206, 207, 218, 219,
//		 205, 206, 219, 220,
//		 204, 205, 220, 221,
//		 203, 204, 221, 222,
//		 202, 203, 222, 223,
//		 201, 202, 223, 224,
//		 200, 201, 224, 225,
//		 199, 200, 225, 226,
//		 198, 199, 226, 227,
//		 1, 198, 227,
//		 1, 227, 228,
//		 227, 226, 229, 228,
//		 226, 225, 230, 229,
//		 225, 224, 231, 230,
//		 224, 223, 232, 231,
//		 223, 222, 233, 232,
//		 222, 221, 234, 233,
//		 221, 220, 235, 234,
//		 220, 219, 236, 235,
//		 219, 218, 237, 236,
//		 218, 217, 238, 237,
//		 217, 216, 239, 238,
//		 216, 215, 240, 239,
//		 215, 214, 241, 240,
//		 214, 213, 242, 241,
//		 213, 32, 242,
//		 242, 32, 243,
//		 241, 242, 243, 244,
//		 240, 241, 244, 245,
//		 239, 240, 245, 246,
//		 238, 239, 246, 247,
//		 237, 238, 247, 248,
//		 236, 237, 248, 249,
//		 235, 236, 249, 250,
//		 234, 235, 250, 251,
//		 233, 234, 251, 252,
//		 232, 233, 252, 253,
//		 231, 232, 253, 254,
//		 230, 231, 254, 255,
//		 229, 230, 255, 256,
//		 228, 229, 256, 257,
//		 1, 228, 257,
//		 1, 257, 258,
//		 257, 256, 259, 258,
//		 256, 255, 260, 259,
//		 255, 254, 261, 260,
//		 254, 253, 262, 261,
//		 253, 252, 263, 262,
//		 252, 251, 264, 263,
//		 251, 250, 265, 264,
//		 250, 249, 266, 265,
//		 249, 248, 267, 266,
//		 248, 247, 268, 267,
//		 247, 246, 269, 268,
//		 246, 245, 270, 269,
//		 245, 244, 271, 270,
//		 244, 243, 272, 271,
//		 243, 32, 272,
//		 272, 32, 273,
//		 271, 272, 273, 274,
//		 270, 271, 274, 275,
//		 269, 270, 275, 276,
//		 268, 269, 276, 277,
//		 267, 268, 277, 278,
//		 266, 267, 278, 279,
//		 265, 266, 279, 280,
//		 264, 265, 280, 281,
//		 263, 264, 281, 282,
//		 262, 263, 282, 283,
//		 261, 262, 283, 284,
//		 260, 261, 284, 285,
//		 259, 260, 285, 286,
//		 258, 259, 286, 287,
//		 1, 258, 287,
//		 1, 287, 288,
//		 287, 286, 289, 288,
//		 286, 285, 290, 289,
//		 285, 284, 291, 290,
//		 284, 283, 292, 291,
//		 283, 282, 293, 292,
//		 282, 281, 294, 293,
//		 281, 280, 295, 294,
//		 280, 279, 296, 295,
//		 279, 278, 297, 296,
//		 278, 277, 298, 297,
//		 277, 276, 299, 298,
//		 276, 275, 300, 299,
//		 275, 274, 301, 300,
//		 274, 273, 302, 301,
//		 273, 32, 302,
//		 302, 32, 303,
//		 301, 302, 303, 304,
//		 300, 301, 304, 305,
//		 299, 300, 305, 306,
//		 298, 299, 306, 307,
//		 297, 298, 307, 308,
//		 296, 297, 308, 309,
//		 295, 296, 309, 310,
//		 294, 295, 310, 311,
//		 293, 294, 311, 312,
//		 292, 293, 312, 313,
//		 291, 292, 313, 314,
//		 290, 291, 314, 315,
//		 289, 290, 315, 316,
//		 288, 289, 316, 317,
//		 1, 288, 317,
//		 1, 317, 318,
//		 317, 316, 319, 318,
//		 316, 315, 320, 319,
//		 315, 314, 321, 320,
//		 314, 313, 322, 321,
//		 313, 312, 323, 322,
//		 312, 311, 324, 323,
//		 311, 310, 325, 324,
//		 310, 309, 326, 325,
//		 309, 308, 327, 326,
//		 308, 307, 328, 327,
//		 307, 306, 329, 328,
//		 306, 305, 330, 329,
//		 305, 304, 331, 330,
//		 304, 303, 332, 331,
//		 303, 32, 332,
//		 332, 32, 333,
//		 331, 332, 333, 334,
//		 330, 331, 334, 335,
//		 329, 330, 335, 336,
//		 328, 329, 336, 337,
//		 327, 328, 337, 338,
//		 326, 327, 338, 339,
//		 325, 326, 339, 340,
//		 324, 325, 340, 341,
//		 323, 324, 341, 342,
//		 322, 323, 342, 343,
//		 321, 322, 343, 344,
//		 320, 321, 344, 345,
//		 319, 320, 345, 346,
//		 318, 319, 346, 347,
//		 1, 318, 347,
//		 1, 347, 348,
//		 347, 346, 349, 348,
//		 346, 345, 350, 349,
//		 345, 344, 351, 350,
//		 344, 343, 352, 351,
//		 343, 342, 353, 352,
//		 342, 341, 354, 353,
//		 341, 340, 355, 354,
//		 340, 339, 356, 355,
//		 339, 338, 357, 356,
//		 338, 337, 358, 357,
//		 337, 336, 359, 358,
//		 336, 335, 360, 359,
//		 335, 334, 361, 360,
//		 334, 333, 362, 361,
//		 333, 32, 362,
//		 362, 32, 363,
//		 361, 362, 363, 364,
//		 360, 361, 364, 365,
//		 359, 360, 365, 366,
//		 358, 359, 366, 367,
//		 357, 358, 367, 368,
//		 356, 357, 368, 369,
//		 355, 356, 369, 370,
//		 354, 355, 370, 371,
//		 353, 354, 371, 372,
//		 352, 353, 372, 373,
//		 351, 352, 373, 374,
//		 350, 351, 374, 375,
//		 349, 350, 375, 376,
//		 348, 349, 376, 377,
//		 1, 348, 377,
//		 1, 377, 378,
//		 377, 376, 379, 378,
//		 376, 375, 380, 379,
//		 375, 374, 381, 380,
//		 374, 373, 382, 381,
//		 373, 372, 383, 382,
//		 372, 371, 384, 383,
//		 371, 370, 385, 384,
//		 370, 369, 386, 385,
//		 369, 368, 387, 386,
//		 368, 367, 388, 387,
//		 367, 366, 389, 388,
//		 366, 365, 390, 389,
//		 365, 364, 391, 390,
//		 364, 363, 392, 391,
//		 363, 32, 392,
//		 392, 32, 393,
//		 391, 392, 393, 394,
//		 390, 391, 394, 395,
//		 389, 390, 395, 396,
//		 388, 389, 396, 397,
//		 387, 388, 397, 398,
//		 386, 387, 398, 399,
//		 385, 386, 399, 400,
//		 384, 385, 400, 401,
//		 383, 384, 401, 402,
//		 382, 383, 402, 403,
//		 381, 382, 403, 404,
//		 380, 381, 404, 405,
//		 379, 380, 405, 406,
//		 378, 379, 406, 407,
//		 1, 378, 407,
//		 1, 407, 408,
//		 407, 406, 409, 408,
//		 406, 405, 410, 409,
//		 405, 404, 411, 410,
//		 404, 403, 412, 411,
//		 403, 402, 413, 412,
//		 402, 401, 414, 413,
//		 401, 400, 415, 414,
//		 400, 399, 416, 415,
//		 399, 398, 417, 416,
//		 398, 397, 418, 417,
//		 397, 396, 419, 418,
//		 396, 395, 420, 419,
//		 395, 394, 421, 420,
//		 394, 393, 422, 421,
//		 393, 32, 422,
//		 422, 32, 423,
//		 421, 422, 423, 424,
//		 420, 421, 424, 425,
//		 419, 420, 425, 426,
//		 418, 419, 426, 427,
//		 417, 418, 427, 428,
//		 416, 417, 428, 429,
//		 415, 416, 429, 430,
//		 414, 415, 430, 431,
//		 413, 414, 431, 432,
//		 412, 413, 432, 433,
//		 411, 412, 433, 434,
//		 410, 411, 434, 435,
//		 409, 410, 435, 436,
//		 408, 409, 436, 437,
//		 1, 408, 437,
//		 1, 437, 438,
//		 437, 436, 439, 438,
//		 436, 435, 440, 439,
//		 435, 434, 441, 440,
//		 434, 433, 442, 441,
//		 433, 432, 443, 442,
//		 432, 431, 444, 443,
//		 431, 430, 445, 444,
//		 430, 429, 446, 445,
//		 429, 428, 447, 446,
//		 428, 427, 448, 447,
//		 427, 426, 449, 448,
//		 426, 425, 450, 449,
//		 425, 424, 451, 450,
//		 424, 423, 452, 451,
//		 423, 32, 452,
//		 452, 32, 453,
//		 451, 452, 453, 454,
//		 450, 451, 454, 455,
//		 449, 450, 455, 456,
//		 448, 449, 456, 457,
//		 447, 448, 457, 458,
//		 446, 447, 458, 459,
//		 445, 446, 459, 460,
//		 444, 445, 460, 461,
//		 443, 444, 461, 462,
//		 442, 443, 462, 463,
//		 441, 442, 463, 464,
//		 440, 441, 464, 465,
//		 439, 440, 465, 466,
//		 438, 439, 466, 467,
//		 1, 438, 467,
//		 1, 467, 468,
//		 467, 466, 469, 468,
//		 466, 465, 470, 469,
//		 465, 464, 471, 470,
//		 464, 463, 472, 471,
//		 463, 462, 473, 472,
//		 462, 461, 474, 473,
//		 461, 460, 475, 474,
//		 460, 459, 476, 475,
//		 459, 458, 477, 476,
//		 458, 457, 478, 477,
//		 457, 456, 479, 478,
//		 456, 455, 480, 479,
//		 455, 454, 481, 480,
//		 454, 453, 482, 481,
//		 453, 32, 482
};

#endif // _QCAR_CUBE_OBJECT_H_
