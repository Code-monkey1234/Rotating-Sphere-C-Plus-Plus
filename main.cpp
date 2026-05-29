#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

float A, B;
float r = 10;
float K1 = 40;
float x,y,z;

int distanceFromCam = 60;
int width = 160;
int height = 44;

float zBuffer[160 * 44];
char buffer[160 * 44];
char outputBuffer[160 * 44 + 44];

float calculateX(float i, float j, float k) {
    return i * cos(B) + j * sin(A) * sin(B) - k * cos(A) * sin(B);
}

float calculateY(float i, float j, float k) {
    return j * cos(A) + k * sin(A);
}

float calculateZ(float i, float j, float k) {
    return i * sin(B) - j * sin(A) * cos(B) + k * cos(A) * cos(B);
}

void calculateForSurface(float pointX, float pointY, float pointZ, int ch) {
    float x = calculateX(pointX, pointY, pointZ);
    float y = calculateY(pointX, pointY, pointZ);
    float z = calculateZ(pointX, pointY, pointZ) + distanceFromCam;

    float ooz = 1 / z;
    int xp = (int)(width / 2 + K1 * ooz * x * 4);
    int yp = (int)(height / 2 + K1 * ooz * y * 2);

    int idx = xp + yp * width;
    if (idx >= 0 && idx < width * height) {
        if (ooz > zBuffer[idx]) {
            zBuffer[idx] = ooz;
            buffer[idx] = ch;
        }
    }
}

int main() {
    printf("\x1b[?25l");
    printf("\x1b[2J");

    while(1) {
        memset(buffer, ' ', width * height);
        memset(zBuffer, 0, sizeof(zBuffer));

        // sphere loop
        for(float phi = -M_PI/2; phi <= M_PI/2; phi += 0.05f) {
            for(float theta = 0; theta <= 2*M_PI; theta += 0.05f) {
                x = r * cos(phi) * cos(theta);
                y = r * cos(phi) * sin(theta);
                z = r * sin(phi);
                // light direction (just a fixed vector pointing toward viewer)
              float lightX = 0;
              float lightY = 0.707f;
              float lightZ = -0.707f;

              // normal is just the sphere point normalized
              float nx = x / r;
              float ny = y / r;
              float nz = z / r;

              // dot product = brightness
              float brightness = nx * lightX + ny * lightY + nz * lightZ;

              char shading[] = ".,-~:;=!*#$@";
              int numShades = 12;

              if (brightness > 0) {
                  int shadeIdx = (int)(brightness * (numShades - 1));
                  calculateForSurface(x, y, z, shading[shadeIdx]);
              } else {
                  calculateForSurface(x, y, z, '.');  // dark side
}
            }
        }

        // render frame
        int outIdx = 0;
        printf("\x1b[H");
        for(int k = 0; k < width * height; k++) {
            if(k % width == 0 && k != 0)
                outputBuffer[outIdx++] = '\n';
            outputBuffer[outIdx++] = buffer[k];
        }
        fwrite(outputBuffer, 1, outIdx, stdout);
        fflush(stdout);

        A += 0.03;
        B += 0.008;

        usleep(16000);
    }
}