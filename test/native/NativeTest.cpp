/**
 * ChaiLove: Native Tests
 *
 * Tests some of the usage of ChaiLove without the need of scripts.
 *
 * Usage: make test-native
 */

#ifdef __HAVE_TESTS__

#include "NativeTest.h"
#include "../../src/ChaiLove.h"

using love::config;

void NativeTest::conf(config& t) {
	t.window.width = 1080;
	t.window.height = 768;
}

bool NativeTest::load() {
	ChaiLove* app = ChaiLove::getInstance();
	app->filesystem.mount("test", "/");
	secondfont = app->graphics.newFont("assets/Raleway-Regular.ttf", 60);
	thefont = app->graphics.newFont("assets/c64_16x16.png", 16, 16, "\x7f !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");

	img = app->graphics.newImage("assets/graphics_draw.png");
	jump = app->sound.newSoundData("assets/jump.wav");
}

void NativeTest::update(float delta) {
	ChaiLove* app = ChaiLove::getInstance();
	if (app->joystick.isDown(0, 0) && !jump->isPlaying()) {
		app->audio.play(jump);
	}
}

void NativeTest::draw() {
	ChaiLove* app = ChaiLove::getInstance();
	app->graphics.setColor(77, 182, 172);
	app->graphics.ellipse("fill", 0, 768, 200, 180);

	int width = thefont->getWidth("Bitmap Commodore Font!");
	int height = app->graphics.getHeight() / 2.0f - thefont->getHeight() / 2.0f;

	app->graphics.setColor(100, 181, 246);
	app->graphics.setFont(thefont);
	app->graphics.print("Bitmap Commodore Font!", app->graphics.getWidth() / 2.0f - width / 2.0f, 200);

	app->graphics.setColor(255, 181, 0);
	app->graphics.setFont(secondfont);

	width = secondfont->getWidth("TTF Font here!");
	height = app->graphics.getHeight() / 2.0f - secondfont->getHeight() / 2.0f;
	app->graphics.print("TTF Font here!", app->graphics.getWidth() / 2.0f - width / 2.0f, height);

	app->graphics.draw(img, 100, 100);
}

#endif
