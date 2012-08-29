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

	    -15.0, -15.0,  0, // 0
  		 15.0, -15.0,  0, // 1
		 15.0, -25.0,  0, // 2
		-15.0, -25.0,  0, // 3
		-15.0, -15.0,  5, // 4
		 15.0, -15.0,  5, // 5
		 15.0, -25.0,  5, // 6
		-15.0, -25.0,  5  // 7

};


static const float cubeColors[NUM_CUBE_OBJECT_VERTEX * 4] = {
//                               0.0,  1.0,  0.0,  1.0,
//                               0.0,  1.0,  0.0,  1.0,
//                               1.0,  0.5,  0.0,  1.0,
//                               1.0,  0.5,  0.0,  1.0,
//                               1.0,  0.0,  0.0,  1.0,
//                               1.0,  0.0,  0.0,  1.0,
//                               0.0,  0.0,  1.0,  1.0,
//                               1.0,  0.0,  1.0,  1.0
                               0.0,  1.0,  0.0,  1.0,
                               0.0,  1.0,  0.0,  1.0,
                               0.0,  1.0,  0.0,  1.0,
                               0.0,  1.0,  0.0,  1.0,
                               0.0,  1.0,  0.0,  1.0,
                               0.0,  1.0,  0.0,  1.0,
                               0.0,  1.0,  0.0,  1.0,
                               0.0,  1.0,  0.0,  1.0,
                            };

static const unsigned short cubeIndices[NUM_CUBE_OBJECT_INDEX] =
{
		  0, 4, 5, 0, 5, 1,
		  1, 5, 6, 1, 6, 2,
		  2, 6, 7, 2, 7, 3,
		  3, 7, 4, 3, 4, 0,
		  4, 7, 6, 4, 6, 5,
		  3, 0, 1, 3, 1, 2

};

#endif // _QCAR_CUBE_OBJECT_H_
