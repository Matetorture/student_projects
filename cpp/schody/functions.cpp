#include <iostream>
#include <cmath>

using namespace std;

struct StairsResult {
    int num_steps;
    double step_height;
    double step_depth;

    //operator ==
    bool operator==(const StairsResult& other) const {
	return num_steps == other.num_steps &&
	    step_height == other.step_height &&
	    step_depth == other.step_depth;
    }
};

StairsResult calculate_stairs(double Sh, double Sl) {
    int min_height = 16;
    int max_height = 19;
    int min_depth = 25;
    int max_depth = 32;

    double chcek_number = 0.01;

    int bestSteps = 0;
    double bestHeight = 0, bestDepth = 0;
    double minDepthDiff = std::numeric_limits<double>::max();

    for (double stepHeight = min_height; stepHeight <= max_height; stepHeight += chcek_number) {
        int steps = static_cast<int>(Sh / stepHeight);

        //if (steps * stepHeight == Sh) {
            for (double stepDepth = min_depth; stepDepth <= max_depth; stepDepth += chcek_number) {
                double totalDepth = steps * stepDepth;

                if (totalDepth <= Sl) {
                    double depthDiff = Sl - totalDepth;

                    if (depthDiff < minDepthDiff) {
                        minDepthDiff = depthDiff;
                        bestSteps = steps;
                        bestHeight = stepHeight;
                        bestDepth = stepDepth;
                    }
                }
            }
        //}
    }

    return {bestSteps, bestHeight, bestDepth};
}
