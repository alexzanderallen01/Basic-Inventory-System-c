#include <raylib.h>


class inventory
{
public:
    inventory(int winWidth, int winHeight);
private:
    Texture2D stashTab = LoadTexture("Textures/Inventory_Interface/Card X3/inventoryTab.png");
    Vector2 screenPos{};

    float width{};
    float height{};
};