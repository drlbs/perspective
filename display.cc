
#ifndef DISPLAY
#define DISPLAY

#include "opengl.h"
#include "structs.h"

#include "prototypes.h"


void display(void)
{
   const int DIMENSION=4;
//   struct vertex box[7*4];  // 7 Sides, 4 Vertices per side  

   struct box faces[6];
   
   float *M;
   int i, j;
   

   defineBox(&faces[0]);

   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

/* ONLY MODIFY CODE BELOW */

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();             /* clear the matrix */

   glTranslatef(0.0, 0.0, -10.0);
   glFrustum(-1.0, 1.0, -1.0, 1.0, 0.0, 10.0);

   gluLookAt (6.0, 5.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);


/* DO NOT MODIFY ANYTHING ELSE */

   /* Draw a coordinate axis */

   glEnable(GL_DEPTH_TEST);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   drawAxes(5);


   drawBox(&faces[0]);


   glFlush();

}

#endif
