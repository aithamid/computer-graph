#include <GL/glut.h>
#include <GL/glu.h>
#include <cmath>

void RenderLine();

void RenderOrthoCenteredTriangle()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(0.0f, 0.5f);
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex2f(-0.5f, -0.5f);
    glEnd();
}

void RenderAnimatedTriangle()
{
    glPushMatrix(); // Save the current matrix

    // Get elapsed time in seconds
    float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
    float angle = time * 50.0f * 3.14159265f / 180.0f; // Convert to radians

    // Define the scaling matrix
    GLfloat scaleMatrix[16] = {
        1.5f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.5f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // Define the rotation matrix (around Z-axis)
    GLfloat rotationMatrix[16] = {
        static_cast<GLfloat>(cos(angle)), static_cast<GLfloat>(-sin(angle)), 0.0f, 0.0f,
        static_cast<GLfloat>(sin(angle)), static_cast<GLfloat>(cos(angle)), 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // Define the translation matrix
    GLfloat translationMatrix[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // Apply the transformations
    glMultMatrixf(translationMatrix); // First apply translation
    glMultMatrixf(rotationMatrix);    // Then apply rotation
    glMultMatrixf(scaleMatrix);       // Finally apply scaling

    // Render the triangle
    RenderOrthoCenteredTriangle();

    glPopMatrix(); // Restore the original matrix
}

void RenderLine()
{
    glPushMatrix(); // Save the current matrix
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // White
    glVertex2f(-0.5f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glEnd();
    glPopMatrix(); // Restore the original matrix
}

void RenderAnimatedLine()
{
    glPushMatrix(); // Save the current matrix

    // Get elapsed time in seconds
    float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
    float angle = time * 50.0f * 3.14159265f / 180.0f; // Convert to radians

    // Define the scaling matrix
    GLfloat scaleMatrix[16] = {
        1.5f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.5f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // Define the rotation matrix (around Z-axis)
    GLfloat rotationMatrix[16] = {
        static_cast<GLfloat>(cos(angle)), static_cast<GLfloat>(-sin(angle)), 0.0f, 0.0f,
        static_cast<GLfloat>(sin(angle)), static_cast<GLfloat>(cos(angle)), 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // Define the translation matrix
    GLfloat translationMatrix[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // Apply the transformations
    glMultMatrixf(translationMatrix); // First apply translation
    glMultMatrixf(rotationMatrix);    // Then apply rotation
    glMultMatrixf(scaleMatrix);       // Finally apply scaling

    // Render the triangle
    RenderLine();

    glPopMatrix(); // Restore the original matrix
}

void RenderRectangle()
{
    glPushMatrix(); // Save the current matrix
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(-0.5f, 0.5f);
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex2f(0.5f, 0.5f);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex2f(0.5f, -0.5f);
    glEnd();
    glPopMatrix(); // Restore the original matrix
}

void RenderAnimatedRectangle()
{
    glPushMatrix(); // Save the current matrix

    // Get elapsed time in seconds
    float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
    float angle = time * 50.0f * 3.14159265f / 180.0f; // Convert to radians

    // Define the scaling matrix
    GLfloat scaleMatrix[16] = {
        1.5f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.5f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // Define the rotation matrix (around Z-axis)
    GLfloat rotationMatrix[16] = {
        static_cast<GLfloat>(cos(angle)), static_cast<GLfloat>(-sin(angle)), 0.0f, 0.0f,
        static_cast<GLfloat>(sin(angle)), static_cast<GLfloat>(cos(angle)), 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // Define the translation matrix
    GLfloat translationMatrix[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // Apply the transformations
    glMultMatrixf(translationMatrix); // First apply translation
    glMultMatrixf(rotationMatrix);    // Then apply rotation
    glMultMatrixf(scaleMatrix);       // Finally apply scaling

    // Render the triangle
    RenderRectangle();

    glPopMatrix(); // Restore the original matrix
}

void RenderLosange()
{
    glPushMatrix(); // Save the current matrix
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(0.0f, 0.8f);
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(-0.5f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex2f(0.5f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex2f(0.0f, -0.8f);
    glEnd();
    glPopMatrix(); // Restore the original matrix
}

void RenderAnimatedLosange()
{
    glPushMatrix(); // Save the current matrix

    // Get elapsed time in seconds
    float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
    float angle = time * 50.0f * 3.14159265f / 180.0f; // Convert to radians

    // Define the scaling matrix
    GLfloat scaleMatrix[16] = {
        1.5f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.5f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // Define the rotation matrix (around Z-axis)
    GLfloat rotationMatrix[16] = {
        static_cast<GLfloat>(cos(angle)), static_cast<GLfloat>(-sin(angle)), 0.0f, 0.0f,
        static_cast<GLfloat>(sin(angle)), static_cast<GLfloat>(cos(angle)), 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // Define the translation matrix
    GLfloat translationMatrix[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    // Apply the transformations
    glMultMatrixf(translationMatrix); // First apply translation
    glMultMatrixf(rotationMatrix);    // Then apply rotation
    glMultMatrixf(scaleMatrix);       // Finally apply scaling

    // Render the triangle
    RenderLosange();

    glPopMatrix(); // Restore the original matrix
}

void SetupOrthoProjection(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void SetupCamera()
{
    gluLookAt(0.0f, 2.0f, 2.0f,  // Camera position
              0.0f, 0.0f, 0.0f,  // Look at point
              0.0f, 1.0f, 0.0f); // Up vector
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glEnable(GL_SCISSOR_TEST);

    // Setup ortho projection for 2D
    int width = 960;
    int height = 540;
    SetupOrthoProjection(width, height);
    
    // Setup camera
    SetupCamera();

    // Apply scaling to ensure visibility in the pixel-based coordinate system
    glScalef(100.0f, 100.0f, 1.0f);

    // Top-left viewport
    glViewport(0, height / 2, width / 2, height / 2);
    glScissor(0, height / 2, width / 2, height / 2);
    glClearColor(1.f, 0.f, 0.f, 1.f); // Red background
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(width / 4 / 100.0f, height / 4 / 100.0f, 0.0f); // Translate to the center of the viewport
    RenderAnimatedTriangle(); // Render the animated triangle
    glPopMatrix();
    
    // Top-right viewport
    glViewport(width / 2, height / 2, width / 2, height / 2);
    glScissor(width / 2, height / 2, width / 2, height / 2);
    glClearColor(0.f, 1.f, 0.f, 1.f); // Green background
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(width / 4 / 100.0f, height / 4 / 100.0f, 0.0f); // Translate to the center of the viewport
    RenderAnimatedRectangle();
    glPopMatrix();
    
    // Bottom-left viewport
    glViewport(0, 0, width / 2, height / 2);
    glScissor(0, 0, width / 2, height / 2);
    glClearColor(0.f, 0.f, 1.f, 1.f); // Blue background
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(width / 4 / 100.0f, height / 4 / 100.0f, 0.0f); // Translate to the center of the viewport
    RenderAnimatedLine();
    glPopMatrix();
    
    // Bottom-right viewport
    glViewport(width / 2, 0, width / 2, height / 2);
    glScissor(width / 2, 0, width / 2, height / 2);
    glClearColor(1.f, 1.f, 0.f, 1.f); // Yellow background
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(width / 4 / 100.0f, height / 4 / 100.0f, 0.0f); // Translate to the center of the viewport
    RenderAnimatedLosange();
    glPopMatrix();

    glDisable(GL_SCISSOR_TEST);
    glFlush();
}

void Idle()
{
    glutPostRedisplay(); // Mark the current window as needing to be redisplayed
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(960, 540);
    glutCreateWindow("Multiple Viewports with Ortho Projection");
    glutDisplayFunc(Display);
    glutIdleFunc(Idle); // Register the idle callback function
    glutMainLoop();
    return 0;
}
