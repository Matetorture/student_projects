#include <iostream>
#include <cmath>

using namespace std;

struct StairsResult {
    int num_steps;
    float step_height;
    float step_depth;

    //operator ==
    bool operator==(const StairsResult& other) const {
	return num_steps == other.num_steps &&
	    step_height == other.step_height &&
	    step_depth == other.step_depth;
    }
};

StairsResult calculate_stairs(float Sh, float Sl) {
    int min_height = 16;
    int max_height = 19;
    int min_depth = 25;
    int max_depth = 32;

    float chcek_number = 0.01;

    int bestSteps = 0;
    float bestHeight = 0, bestDepth = 0;
    float minDepthDiff = Sl;

    for (float stepHeight = min_height; stepHeight <= max_height; stepHeight += chcek_number) {
        int steps = static_cast<int>(Sh / stepHeight) + 1;
	
        if (round(steps * stepHeight * 100)/100 == Sh) {
            for (float stepDepth = min_depth; stepDepth <= max_depth; stepDepth += chcek_number) {
                float totalDepth = steps * stepDepth;
                if (round(totalDepth * 100)/100 <= Sl) {
                    float depthDiff = Sl - totalDepth;

                    if (depthDiff < minDepthDiff) {
                        minDepthDiff = depthDiff;
                        bestSteps = round(steps * 100)/100;
                        bestHeight = round(stepHeight * 100)/100;
                        bestDepth = round(stepDepth * 100)/100;
                    }
                }
            }
        }
    }

    return {bestSteps, bestHeight, bestDepth};
}
