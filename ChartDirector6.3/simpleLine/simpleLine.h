#pragma once
#include <Windows.h> // ShellExecute();
#include "..\..\include\ChartDirector63\chartdir.h"

namespace chart {

	static void _simpleLine(double data[], const char *labels[], const int &_sz, const int &_x, const int &_y, bool _showImage=false) {		
		// Create a XYChart object in PIXELS:
		XYChart *c = new XYChart(_x+80, _y+80);
		// Set the plotarea at (30, 20) and of size 200 x 200 pixels
		c->setPlotArea(30, 20, _x, _y);
		// Add a line chart layer using the given data
		c->addLineLayer(DoubleArray(data, _sz));//(int)(sizeof(data) / sizeof(data[0]))));
		// Set the labels on the x axis.
		c->xAxis()->setLabels(StringArray(labels, _sz));//(int)(sizeof(labels) / sizeof(labels[0]))));
		// Display 1 out of 3 labels on the x-axis.
		c->xAxis()->setLabelStep(1);
		// Output the chart
		c->makeChart("simpleline.png");
		if(_showImage)
			ShellExecute(NULL, "open", "simpleline.png", NULL, NULL, SW_SHOWDEFAULT);
		//free up resources
		delete c;
	}

	static void _simpleLineUsage() {
		// The data for the line chart
		double data[] = {30, 28, 40, 55, 75, 68, 54, 60, 50, 62, 75, 65, 75, 91, 60, 55, 53, 35, 50, 66,
			56, 48, 52, 65, 62};
		// The labels for the line chart
		const char *labels[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12",
			"13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24"};

		int sz = 25;
		_simpleLine(data, labels, sz, 500, 500, true);
	}

}

