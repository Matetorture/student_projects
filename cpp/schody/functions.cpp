#include <iostream>
#include <cmath>

using namespace std;

struct StairsResult {
    int num_steps;
    double step_height;
    double step_depth;
    bool success;
    string message;

    //operator ==
    bool operator==(const StairsResult& other) const {
	return num_steps == other.num_steps &&
	    step_height == other.step_height &&
	    step_depth == other.step_depth;
    }
};

StairsResult calculate_stairs(double Sh, double Sl) {
    double min_height = 15.0;
    double max_height = 19.0;
    double min_depth = 50.0;
    double max_depth = 70.0;

    int num_steps = static_cast<int>(Sh / max_height);

    if (fmod(Sh, max_height) != 0) {
        num_steps += 1;
    }

    double step_height = Sh / num_steps;

    if (step_height < min_height || step_height > max_height) {
        return {0, 0, 0, false, "Nie można dopasować wysokości schodów do wymaganych warunków."};
    }

    double total_depth = min_depth * num_steps;

    if (total_depth > Sl) {
        return {0, 0, 0, false, "Całkowita głębokość schodów przekracza dopuszczalną."};
    }

    double step_depth = Sl / num_steps;

    if (step_depth < min_depth || step_depth > max_depth) {
        return {0, 0, 0, false, "Nie można dopasować głębokości schodów do wymaganych warunków."};
    }

    return {num_steps, step_height, step_depth, true, "Sukces"};
}
