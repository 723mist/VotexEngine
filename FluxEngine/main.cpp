#include "Vector/vec.h"
#include "flux_engine.h"

int main() {
    Window Window;
    Map map("map");

    Window.create();

    Sprite player;
    player.position = vec2(400, 300);
    player.size = vec2(50, 50);
    player.setTexture("Content/wall.jpg");

    Object box("box");
    box.setTexture("Content/wall.jpg");

    map.addObject(box);
    Window.addSprite(player);
    Window.setMap(&map);
    Window.render();
    Window.close();

    return 0;
}
