#pragma once



class ofApp : public ofBaseApp{
	public:
		void setup();
		void draw();

		float step;
        float xmin;
        float xmax;
        float w;
        float alpha;
        int n;
        int i;
        float x[1000];
        float y[1000];
        float ymin;
        float ymax;
        float outx[1000];
        float outy[1000];


};
