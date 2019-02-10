#include "ofApp.h"

//--------------------------------------------------------------
int getXSamples(float xmin, float xmax, float step, float x[])
{
    int i, n;
    n = ((xmax -  xmin) / step)+ 1;
    for(i=0;i<n;i++)
    {
        x[i] = xmin + (i * step);
    }
    return(n);
}
//------------------------------------------------------------------------
void getDampedCosSamples(int n, float x[], float y[], float alpha, float w)
{

    int i;
    for(i=0;i<n;i++)
    {
        y[i] = exp(-alpha*x[i]) * cos(w*x[i]);
    }
}
//------------------------------------------------------------------------
float myMap(float in, float inMin, float inMax, float outMin, float outMax)
{

    int slope, intercept, result;
    slope = (outMax - outMin) / (inMax - inMin);
    intercept = outMax - (slope * inMax);
    result = (slope * in) + intercept;
    return (result);
}
//------------------------------------------------------------------------
void map_vec(int n, float in[], float out[], float inMin, float inMax, float outMin, float outMax)
{
    int i;
    for(i=0;i<n;i++)
    {
        out[i]= myMap(in[i], inMin, inMax, outMin, outMax);
    }

}
//------------------------------------------------------------------------
float getMin(int n, float x[])
{
    int i, result;
    for(i=0;i<n;i++)
    {
        if (result > x[i]) result = x[i];
    }
    return (result);
}
//------------------------------------------------------------------------
float getMax(int n, float x[])
{
    int i, result;
    for(i=0;i<n;i++)
    {
        if (result < x[i]) result = x[i];
    }
    return (result);
}
//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetBackgroundAuto(FALSE);
    ofSetBackgroundColor(255, 255 ,255, 255);
    step = 0.05;
    xmin = 0;
    xmax = 10;
    w = 10;
    alpha = 0.5;

    n = getXSamples(xmin, xmax, step, x);
    getDampedCosSamples(n, x, y, alpha, w);
    ymin = getMin(n, y);
    ymax = getMax(n, y);
    map_vec(n, x, outx, xmin, xmax, 250, 750);
    map_vec(n, y, outy, ymin, ymax, 300, 200);

}
//--------------------------------------------------------------
void ofApp::draw()
{
    glReadBuffer(GL_FRONT);
    ofSetColor(0,0,255);

    for(i=1; i<n ; i++)
    {
        ofLine(outx[i-1], outy[i-1], outx[i], outy[i]);
    }
}

