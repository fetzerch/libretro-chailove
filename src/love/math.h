#ifndef SRC_LOVE_MATH_H_
#define SRC_LOVE_MATH_H_

#include <string>

namespace love {
/**
 * @brief Provides system-independent mathematical functions.
 */
class math {
	public:
	bool load();
	/**
	 * @brief Get uniformly distributed pseudo-random number, between the given numbers.
	 *
	 * @param min (0.0f) The minimum value.
	 * @param max (1.0f) The max value.
	 *
	 * @return a number between the two given min and max values.
	 */
	float random(float min, float max);
	float random(float max);
	float random();
	int random(int min, int max);
	int random(int max);
	double random(double min, double max);
	double random(double max);

	/**
	 * @brief Sets the random seed to a random seed between the given min and max values.
	 *
	 * @param min The lower 32 bits of the seed value.
	 * @param high The higher 32 bits of the seed value.
	 *
	 * @return The math module, to allow for method chaining.
	 *
	 * @see love.math.getRandomSeed
	 */
	math& setRandomSeed(int min, int max);

	/**
	 * @brief Sets the seed of the random number generator.
	 *
	 * @param seed The integer number with which you want to seed the randomization.
	 *
	 * @return The math module, to allow for method chaining.
	 *
	 * @see love.math.getRandomSeed
	 */
	math& setRandomSeed(int seed);

	/**
	 * @brief Gets the seed of the random number generator.
	 *
	 * @see love.math.setRandomSeed
	 */
	int getRandomSeed();

	/**
	 * @brief Converts from degrees to radians.
	 *
	 * @see love.math.degrees
	 */
	float rad(float degrees);

	/**
	 * @brief Converts from radians to degrees.
	 *
	 * @see love.math.rad
	 */
	float degrees(float rad);

	std::string compress(const std::string& str);

	/**
	 * @brief Compresses a string or data using a specific compression level.
	 *
	 * @param str The raw (un-compressed) string to compress.
	 * @param level (-1) The level of compression to use, between 0 and 9. -1 indicates the default level.
	 *
	 * @return Compressed data in the form of a string.
	 *
	 * @see love.math.decompress
	 */
	std::string compress(const std::string& str, int level);

	/**
	 * @brief Decompresses a compressed string.
	 *
	 * @param str A string containing data previously compressed with math.compress().
	 *
	 * @return A string containing the raw decompressed data.
	 *
	 * @see love.math.compress
	 */
	std::string decompress(const std::string& str);

	/**
	 * @brief e
	 *
	 * @see https://en.wikipedia.org/wiki/E_(mathematical_constant)
	 */
	const float e = 2.718281828459045f;

	/**
	 * @brief pi
	 *
	 * @see https://en.wikipedia.org/wiki/Pi
	 */
	const float pi = 3.14159265358979323846f;

	int m_seed = 0;
};

}  // namespace love

#endif  // SRC_LOVE_MATH_H_
