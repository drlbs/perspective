#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

const int WINDOW_HEIGHT = 500;
const int WINDOW_WIDTH = 500;

typedef struct vertex {
        float x;
        float y;
        float z;
        float w;
} vertex;

typedef struct colortype {
	float red;
	float green;
	float blue;
} colortype;

typedef struct box {
	vertex point[4];
	colortype color;	
} box;



void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}


void drawAxes(int length)
{   

/* This provides a coordinate axis about the origin. */
   glPointSize(1.0);
   glBegin(GL_LINES);
     glVertex3i(0,length,0);
     glVertex3i(0,-length,0);
   glEnd();
   glBegin(GL_LINES);
     glVertex3i(length,0,0);
     glVertex3i(-length,0,0);
   glEnd();
   glBegin(GL_LINES);
     glVertex3i(0,0,length);
     glVertex3i(0,0,-length);
   glEnd();
}


void defineBox( box *face )
{
	face[0].point[0].x = -1.0;  // Bottom
    face[0].point[0].y = -1.0;
	face[0].point[0].z =  0.0;
	face[0].point[0].w =  1.0;
	face[0].point[1].x = -1.0;
    face[0].point[1].y =  1.0;
	face[0].point[1].z =  0.0;
	face[0].point[1].w =  1.0;
	face[0].point[2].x =  1.0;
    face[0].point[2].y =  1.0;
	face[0].point[2].z =  0.0;
	face[0].point[2].w =  1.0;
	face[0].point[3].x =  1.0;
    face[0].point[3].y = -1.0;
	face[0].point[3].z =  0.0;
	face[0].point[3].w =  1.0;

	face[1].point[0].x = -1.0;  // Left Side
    face[1].point[0].y = -1.0;
	face[1].point[0].z =  0.0;
	face[1].point[0].w =  1.0;
	face[1].point[1].x = -1.0;
    face[1].point[1].y = -1.0;
	face[1].point[1].z =  1.0;
	face[1].point[1].w =  1.0;
	face[1].point[2].x =  1.0;
    face[1].point[2].y = -1.0;
	face[1].point[2].z =  1.0;
	face[1].point[2].w =  1.0;
	face[1].point[3].x =  1.0;
    face[1].point[3].y = -1.0;
	face[1].point[3].z =  0.0;
	face[1].point[3].w =  1.0;

	face[2].point[0].x = -1.0;  // Right Side 
    face[2].point[0].y =  1.0;
	face[2].point[0].z =  0.0;
	face[2].point[0].w =  1.0;
	face[2].point[1].x = -1.0;
    face[2].point[1].y =  1.0;
	face[2].point[1].z =  1.0;
	face[2].point[1].w =  1.0;
	face[2].point[2].x =  1.0;
    face[2].point[2].y =  1.0;
	face[2].point[2].z =  1.0;
	face[2].point[2].w =  1.0;
	face[2].point[3].x =  1.0;
    face[2].point[3].y =  1.0;
	face[2].point[3].z =  0.0;
	face[2].point[3].w =  1.0;
	
	face[3].point[0].x = -1.0;  // Back Side 
    face[3].point[0].y = -1.0;
	face[3].point[0].z =  0.0;
	face[3].point[0].w =  1.0;
	face[3].point[1].x = -1.0;
    face[3].point[1].y = -1.0;
	face[3].point[1].z =  1.0;
	face[3].point[1].w =  1.0;
	face[3].point[2].x = -1.0;
    face[3].point[2].y =  1.0;
	face[3].point[2].z =  1.0;
	face[3].point[2].w =  1.0;
	face[3].point[3].x = -1.0;
    face[3].point[3].y =  1.0;
	face[3].point[3].z =  0.0;
	face[3].point[3].w =  1.0;

	face[4].point[0].x =  1.0;  // Front Side 
    face[4].point[0].y = -1.0;
	face[4].point[0].z =  0.0;
	face[4].point[0].w =  1.0;
	face[4].point[1].x =  1.0;
    face[4].point[1].y = -1.0;
	face[4].point[1].z =  1.0;
	face[4].point[1].w =  1.0;
	face[4].point[2].x =  1.0;
    face[4].point[2].y =  1.0;
	face[4].point[2].z =  1.0;
	face[4].point[2].w =  1.0;
	face[4].point[3].x =  1.0;
    face[4].point[3].y =  1.0;
	face[4].point[3].z =  0.0;
	face[4].point[3].w =  1.0;

	face[5].point[0].x = -1.0;  // Top 
    face[5].point[0].y = -1.0;
	face[5].point[0].z =  1.0;
	face[5].point[0].w =  1.0;
	face[5].point[1].x = -1.0;
    face[5].point[1].y =  1.0;
	face[5].point[1].z =  1.0;
	face[5].point[1].w =  1.0;
	face[5].point[2].x =  1.0;
    face[5].point[2].y =  1.0;
	face[5].point[2].z =  1.0;
	face[5].point[2].w =  1.0;
	face[5].point[3].x =  1.0;
    face[5].point[3].y = -1.0;
	face[5].point[3].z =  1.0;
	face[5].point[3].w =  1.0;


// Define the colors
//
	face[0].color.red   = 1.0;
	face[0].color.green = 0.0;
	face[0].color.blue  = 0.0;
	
	face[1].color.red   = 0.0;
	face[1].color.green = 1.0;
	face[1].color.blue  = 0.0;
	
	face[2].color.red   = 0.0;
	face[2].color.green = 0.0;
	face[2].color.blue  = 1.0;

	face[3].color.red   = 1.0;
	face[3].color.green = 1.0;
	face[3].color.blue  = 0.0;

	face[4].color.red   = 1.0;
	face[4].color.green = 0.0;
	face[4].color.blue  = 1.0;

	face[5].color.red   = 0.0;
	face[5].color.green = 1.0;
	face[5].color.blue  = 1.0;
	
}


void drawBox( struct box *face )
{
	int i, j;

        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_FILL);

    glPushMatrix();
    glTranslatef(0.0,2.0,0.0);
	
	for(j=0;j<6;j++)
	{

 		glColor3f(face[j].color.red,
	        	  face[j].color.green,
	         	  face[j].color.blue);

	        glBegin(GL_POLYGON);
                   for (i=0;i<4;i++)
	           {
	              glVertex3f(face[j].point[i].x,
		                 face[j].point[i].y,
			         face[j].point[i].z);
	           }
	        glEnd();
	}

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,-2.0,0.0);
	
	for(j=0;j<6;j++)
	{

 		glColor3f(face[j].color.red,
	        	  face[j].color.green,
	         	  face[j].color.blue);

	        glBegin(GL_POLYGON);
                   for (i=0;i<4;i++)
	           {
	              glVertex3f(face[j].point[i].x,
		                 face[j].point[i].y,
			         face[j].point[i].z);
	           }
	        glEnd();
	}

    glPopMatrix();

}


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

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DEPTH | GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (WINDOW_HEIGHT, WINDOW_WIDTH); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
